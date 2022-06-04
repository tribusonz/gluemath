/*******************************************************************************
Fast Fourier/Cosine/Sine Transform
    dimension   :two
    data length :power of 2
    decimation  :frequency
    radix       :split-radix, row-column
    data        :inplace
    table       :use
functions
    cdft2d: Complex Discrete Fourier Transform
    rdft2d: Real Discrete Fourier Transform
    ddct2d: Discrete Cosine Transform
    ddst2d: Discrete Sine Transform
function prototypes
    void cdft2d(int, int, int, double **, double *, int *, double *);
    void rdft2d(int, int, int, double **, double *, int *, double *);
    void rdft2dsort(int, int, int, double **);
    void ddct2d(int, int, int, double **, double *, int *, double *);
    void ddst2d(int, int, int, double **, double *, int *, double *);
necessary package
    fftsg.c  : 1D-FFT package
macro definitions
    USE_FFT2D_PTHREADS : default=not defined
        FFT2D_MAX_THREADS     : must be 2^N, default=4
        FFT2D_THREADS_BEGIN_N : default=65536
    USE_FFT2D_WINTHREADS : default=not defined
        FFT2D_MAX_THREADS     : must be 2^N, default=4
        FFT2D_THREADS_BEGIN_N : default=131072
*******************************************************************************/
#include "fftsg.h"
#include "fftsg2d.h"
#include "fftsg_p.h"




#include <stdio.h>
#include <stdlib.h>
#define fft2d_alloc_error_check(p) { \
    if ((p) == NULL) { \
        fprintf(stderr, "fft2d memory allocation error\n"); \
        exit(1); \
    } \
}


#ifdef USE_FFT2D_PTHREADS
# define USE_FFT2D_THREADS
# ifndef FFT2D_MAX_THREADS
#  define FFT2D_MAX_THREADS 4
# endif
# ifndef FFT2D_THREADS_BEGIN_N
#  define FFT2D_THREADS_BEGIN_N 65536
# endif
# include <pthread.h>
# define fft2d_thread_t pthread_t
# define fft2d_thread_create(thp,func,argp) { \
    if (pthread_create(thp, NULL, func, (void *) (argp)) != 0) { \
        fprintf(stderr, "fft2d thread error\n"); \
        exit(1); \
    } \
}
# define fft2d_thread_wait(th) { \
    if (pthread_join(th, NULL) != 0) { \
        fprintf(stderr, "fft2d thread error\n"); \
        exit(1); \
    } \
}
#endif /* USE_FFT2D_PTHREADS */


#ifdef USE_FFT2D_WINTHREADS
# define USE_FFT2D_THREADS
# ifndef FFT2D_MAX_THREADS
#  define FFT2D_MAX_THREADS 4
# endif
# ifndef FFT2D_THREADS_BEGIN_N
#  define FFT2D_THREADS_BEGIN_N 131072
# endif
# include <windows.h>
# define fft2d_thread_t HANDLE
# define fft2d_thread_create(thp,func,argp) { \
    DWORD thid; \
    *(thp) = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) (func), (LPVOID) (argp), 0, &thid); \
    if (*(thp) == 0) { \
        fprintf(stderr, "fft2d thread error\n"); \
        exit(1); \
    } \
}
# define fft2d_thread_wait(th) { \
    WaitForSingleObject(th, INFINITE); \
    CloseHandle(th); \
}
#endif /* USE_FFT2D_WINTHREADS */


// Declare Prototypes of subroutine
static void cdft2d_sub (
 int, int, int, double**, double*, int*, double*);
static void rdft2d_sub (
 int n1, int n2, int isgn, double **a);
static void ddxt2d_sub (
 int n1, int n2, int ics, int isgn, double **a, double *t, int *ip, double *w);
#ifdef USE_FFT2D_THREADS
static void xdft2d0_subth (
 int n1, int n2, int icr, int isgn, double **a, int *ip, double *w);
static void cdft2d_subth (
 int n1, int n2, int isgn, double **a, double *t, int *ip, double *w);
static void ddxt2d0_subth (
 int n1, int n2, int ics, int isgn, double **a, int *ip, double *w);
static void ddxt2d_subth (
 int n1, int n2, int ics, int isgn, double **a, double *t, int *ip, double *w);
static void *xdft2d0_th(void *p);
static void *cdft2d_th(void *p);
static void *ddxt2d0_th(void *p);
static void *ddxt2d_th(void *p);
#endif /* USE_FFT2D_THREADS */


// -------- Complex DFT (Discrete Fourier Transform) --------
//   uses math library: (nothing)
//   uses intern function:
//     cdft, 
//   uses static function:
//     makewt, cdft2d_sub
//     xdft2d0_subth, cdft2d_subth (thread)
void
cdft2d(int n1, int n2, int isgn, double **a, double *t, int *ip, double *w)
{
	int n, itnull, nthread, nt, i;
	
	n = n1 << 1;
	if (n < n2)
	{
		n = n2;
	}
	if (n > (ip[0] << 2))
	{
		makewt(n >> 2, ip, w);
	}
	itnull = 0;
	if (t == NULL)
	{
		itnull = 1;
		nthread = 1;
#ifdef USE_FFT2D_THREADS
		nthread = FFT2D_MAX_THREADS;
#endif /* USE_FFT2D_THREADS */
		nt = 8 * nthread * n1;
		if (n2 == 4 * nthread)
		{
			nt >>= 1;
		}
		else if (n2 < 4 * nthread)
		{
			nt >>= 2;
		}
		t = (double *) malloc(sizeof(double) * nt);
		fft2d_alloc_error_check(t);
	}
#ifdef USE_FFT2D_THREADS
	if ((double) n1 * n2 >= (double) FFT2D_THREADS_BEGIN_N)
	{
		xdft2d0_subth(n1, n2, 0, isgn, a, ip, w);
		cdft2d_subth(n1, n2, isgn, a, t, ip, w);
	}
	else 
#endif /* USE_FFT2D_THREADS */
	{
		for (i = 0; i < n1; i++)
		{
			cdft(n2, isgn, a[i], ip, w);
		}
		cdft2d_sub(n1, n2, isgn, a, t, ip, w);
	}
	if (itnull != 0)
	{
		free(t);
	}
}


// -------- Real DFT / Inverse of Real DFT --------
//   uses math library: (nothing)
//   uses intern function:
//     rdft
//   uses static function:
//     makewt, makect, cdft2d_sub, rdft2d_sub
//     xdft2d0_subth, cdft2d_subth (thread)
void
rdft2d(int n1, int n2, int isgn, double **a, double *t, int *ip, double *w)
{
	int n, nw, nc, itnull, nthread, nt, i;
	
	n = n1 << 1;
	if (n < n2)
	{
		n = n2;
	}
	nw = ip[0];
	if (n > (nw << 2))
	{
		nw = n >> 2;
		makewt(nw, ip, w);
	}
	nc = ip[1];
	if (n2 > (nc << 2))
	{
		nc = n2 >> 2;
		makect(nc, ip, w + nw);
	}
	itnull = 0;
	if (t == NULL)
	{
		itnull = 1;
		nthread = 1;
#ifdef USE_FFT2D_THREADS
		nthread = FFT2D_MAX_THREADS;
#endif /* USE_FFT2D_THREADS */
		nt = 8 * nthread * n1;
		if (n2 == 4 * nthread)
		{
			nt >>= 1;
		}
		else if (n2 < 4 * nthread)
		{
			nt >>= 2;
		}
		t = (double *) malloc(sizeof(double) * nt);
		fft2d_alloc_error_check(t);
	}
#ifdef USE_FFT2D_THREADS
	if ((double) n1 * n2 >= (double) FFT2D_THREADS_BEGIN_N)
	{
		if (isgn < 0)
		{
			rdft2d_sub(n1, n2, isgn, a);
			cdft2d_subth(n1, n2, isgn, a, t, ip, w);
		}
		xdft2d0_subth(n1, n2, 1, isgn, a, ip, w);
		if (isgn >= 0)
		{
			cdft2d_subth(n1, n2, isgn, a, t, ip, w);
			rdft2d_sub(n1, n2, isgn, a);
		}
	}
	else 
#endif /* USE_FFT2D_THREADS */
	{
		if (isgn < 0)
		{
			rdft2d_sub(n1, n2, isgn, a);
			cdft2d_sub(n1, n2, isgn, a, t, ip, w);
		}
		for (i = 0; i < n1; i++)
		{
			rdft(n2, isgn, a[i], ip, w);
		}
		if (isgn >= 0)
		{
			cdft2d_sub(n1, n2, isgn, a, t, ip, w);
			rdft2d_sub(n1, n2, isgn, a);
		}
	}
	if (itnull != 0)
	{
		free(t);
	}
}


//   uses math library: (nothing)
//   uses static function: (nothing)
void
rdft2dsort(int n1, int n2, int isgn, double **a)
{
	int n1h, i;
	double x, y;
	
	n1h = n1 >> 1;
	if (isgn < 0)
	{
		for (i = n1h + 1; i < n1; i++)
		{
			a[i][0] = a[i][n2 + 1];
			a[i][1] = a[i][n2];
		}
		a[0][1] = a[0][n2];
		a[n1h][1] = a[n1h][n2];
	}
	else
	{
		for (i = n1h + 1; i < n1; i++)
		{
			y = a[i][0];
			x = a[i][1];
			a[i][n2] = x;
			a[i][n2 + 1] = y;
			a[n1 - i][n2] = x;
			a[n1 - i][n2 + 1] = -y;
			a[i][0] = a[n1 - i][0];
			a[i][1] = -a[n1 - i][1];
		}
		a[0][n2] = a[0][1];
		a[0][n2 + 1] = 0;
		a[0][1] = 0;
		a[n1h][n2] = a[n1h][1];
		a[n1h][n2 + 1] = 0;
		a[n1h][1] = 0;
	}
}

// -------- DCT (Discrete Cosine Transform) / Inverse of DCT --------
//   uses math library: (nothing)
//   uses intern function:
//     ddct
//   uses static function:
//     makewt, makect, ddxt2d_sub
//     ddxt2d0_subth, ddxt2d_subth (thread)
void
ddct2d(int n1, int n2, int isgn, double **a, double *t, int *ip, double *w)
{
	int n, nw, nc, itnull, nthread, nt, i;
	
	n = n1;
	if (n < n2)
	{
		n = n2;
	}
	nw = ip[0];
	if (n > (nw << 2))
	{
		nw = n >> 2;
		makewt(nw, ip, w);
	}
	nc = ip[1];
	if (n > nc)
	{
		nc = n;
		makect(nc, ip, w + nw);
	}
	itnull = 0;
	if (t == NULL)
	{
		itnull = 1;
		nthread = 1;
#ifdef USE_FFT2D_THREADS
		nthread = FFT2D_MAX_THREADS;
#endif /* USE_FFT2D_THREADS */
		nt = 4 * nthread * n1;
		if (n2 == 2 * nthread)
		{
			nt >>= 1;
		}
		else if (n2 < 2 * nthread)
		{
			nt >>= 2;
		}
		t = (double *) malloc(sizeof(double) * nt);
		fft2d_alloc_error_check(t);
	}
#ifdef USE_FFT2D_THREADS
	if ((double) n1 * n2 >= (double) FFT2D_THREADS_BEGIN_N)
	{
		ddxt2d0_subth(n1, n2, 0, isgn, a, ip, w);
		ddxt2d_subth(n1, n2, 0, isgn, a, t, ip, w);
	}
	else 
#endif /* USE_FFT2D_THREADS */
	{
		for (i = 0; i < n1; i++)
		{
			ddct(n2, isgn, a[i], ip, w);
		}
		ddxt2d_sub(n1, n2, 0, isgn, a, t, ip, w);
	}
	if (itnull != 0)
	{
		free(t);
	}
}

// -------- DCT (Discrete Cosine Transform) / Inverse of DCT --------
//   uses math library: (nothing)
//   uses intern function:
//     ddst
//   uses static function:
//     makewt, makect, ddxt2d_sub
//     ddxt2d0_subth, ddxt2d_subth (thread)
void
ddst2d(int n1, int n2, int isgn, double **a, double *t, int *ip, double *w)
{
	int n, nw, nc, itnull, nthread, nt, i;
	
	n = n1;
	if (n < n2)
	{
		n = n2;
	}
	nw = ip[0];
	if (n > (nw << 2))
	{
		nw = n >> 2;
		makewt(nw, ip, w);
	}
	nc = ip[1];
	if (n > nc)
	{
		nc = n;
		makect(nc, ip, w + nw);
	}
	itnull = 0;
	if (t == NULL)
	{
		itnull = 1;
		nthread = 1;
#ifdef USE_FFT2D_THREADS
		nthread = FFT2D_MAX_THREADS;
#endif /* USE_FFT2D_THREADS */
		nt = 4 * nthread * n1;
		if (n2 == 2 * nthread)
		{
			nt >>= 1;
		}
		else if (n2 < 2 * nthread)
		{
			nt >>= 2;
		}
		t = (double *) malloc(sizeof(double) * nt);
		fft2d_alloc_error_check(t);
	}
#ifdef USE_FFT2D_THREADS
	if ((double) n1 * n2 >= (double) FFT2D_THREADS_BEGIN_N)
	{
		ddxt2d0_subth(n1, n2, 1, isgn, a, ip, w);
		ddxt2d_subth(n1, n2, 1, isgn, a, t, ip, w);
	}
	else 
#endif /* USE_FFT2D_THREADS */
	{
		for (i = 0; i < n1; i++)
		{
			ddst(n2, isgn, a[i], ip, w);
		}
		ddxt2d_sub(n1, n2, 1, isgn, a, t, ip, w);
	}
	if (itnull != 0)
	{
		free(t);
	}
}


/* -------- child routines -------- */


//   uses math library: (nothing)
//   uses intern function:
//     cdft
//   uses static function: (nothing)
static void
cdft2d_sub(int n1, int n2, int isgn, double **a, double *t, int *ip, double *w)
{
	int i, j;
	
	if (n2 > 4)
	{
		for (j = 0; j < n2; j += 8)
		{
			for (i = 0; i < n1; i++)
			{
				t[2 * i] = a[i][j];
				t[2 * i + 1] = a[i][j + 1];
				t[2 * n1 + 2 * i] = a[i][j + 2];
				t[2 * n1 + 2 * i + 1] = a[i][j + 3];
				t[4 * n1 + 2 * i] = a[i][j + 4];
				t[4 * n1 + 2 * i + 1] = a[i][j + 5];
				t[6 * n1 + 2 * i] = a[i][j + 6];
				t[6 * n1 + 2 * i + 1] = a[i][j + 7];
			}
			cdft(2 * n1, isgn, t, ip, w);
			cdft(2 * n1, isgn, &t[2 * n1], ip, w);
			cdft(2 * n1, isgn, &t[4 * n1], ip, w);
			cdft(2 * n1, isgn, &t[6 * n1], ip, w);
			for (i = 0; i < n1; i++)
			{
				a[i][j] = t[2 * i];
				a[i][j + 1] = t[2 * i + 1];
				a[i][j + 2] = t[2 * n1 + 2 * i];
				a[i][j + 3] = t[2 * n1 + 2 * i + 1];
				a[i][j + 4] = t[4 * n1 + 2 * i];
				a[i][j + 5] = t[4 * n1 + 2 * i + 1];
				a[i][j + 6] = t[6 * n1 + 2 * i];
				a[i][j + 7] = t[6 * n1 + 2 * i + 1];
			}
		}
	}
	else if (n2 == 4)
	{
		for (i = 0; i < n1; i++)
		{
			t[2 * i] = a[i][0];
			t[2 * i + 1] = a[i][1];
			t[2 * n1 + 2 * i] = a[i][2];
			t[2 * n1 + 2 * i + 1] = a[i][3];
		}
		cdft(2 * n1, isgn, t, ip, w);
		cdft(2 * n1, isgn, &t[2 * n1], ip, w);
		for (i = 0; i < n1; i++)
		{
			a[i][0] = t[2 * i];
			a[i][1] = t[2 * i + 1];
			a[i][2] = t[2 * n1 + 2 * i];
			a[i][3] = t[2 * n1 + 2 * i + 1];
		}
	}
	else if (n2 == 2)
	{
		for (i = 0; i < n1; i++)
		{
			t[2 * i] = a[i][0];
			t[2 * i + 1] = a[i][1];
		}
		cdft(2 * n1, isgn, t, ip, w);
		for (i = 0; i < n1; i++)
		{
			a[i][0] = t[2 * i];
			a[i][1] = t[2 * i + 1];
		}
	}
}


//   uses math library: (nothing)
//   uses static function: (nothing)
static void
rdft2d_sub(int n1, int n2, int isgn, double **a)
{
	int n1h, i, j;
	double xi;
	
	n1h = n1 >> 1;
	if (isgn < 0)
	{
		for (i = 1; i < n1h; i++)
		{
			j = n1 - i;
			xi = a[i][0] - a[j][0];
			a[i][0] += a[j][0];
			a[j][0] = xi;
			xi = a[j][1] - a[i][1];
			a[i][1] += a[j][1];
			a[j][1] = xi;
		}
	}
	else
	{
		for (i = 1; i < n1h; i++)
		{
			j = n1 - i;
			a[j][0] = 0.5 * (a[i][0] - a[j][0]);
			a[i][0] -= a[j][0];
			a[j][1] = 0.5 * (a[i][1] + a[j][1]);
			a[i][1] -= a[j][1];
		}
	}
}


//   uses math library: (nothing)
//   uses intern function:
//     ddct, ddst
//   uses static function: (nothing)
void
ddxt2d_sub(
 int n1, int n2, int ics, int isgn, double **a, double *t, int *ip, double *w)
{
	int i, j;
	
	if (n2 > 2)
	{
		for (j = 0; j < n2; j += 4)
		{
			for (i = 0; i < n1; i++)
			{
				t[i] = a[i][j];
				t[n1 + i] = a[i][j + 1];
				t[2 * n1 + i] = a[i][j + 2];
				t[3 * n1 + i] = a[i][j + 3];
			}
			if (ics == 0)
			{
				ddct(n1, isgn, t, ip, w);
				ddct(n1, isgn, &t[n1], ip, w);
				ddct(n1, isgn, &t[2 * n1], ip, w);
				ddct(n1, isgn, &t[3 * n1], ip, w);
			}
			else
			{
				ddst(n1, isgn, t, ip, w);
				ddst(n1, isgn, &t[n1], ip, w);
				ddst(n1, isgn, &t[2 * n1], ip, w);
				ddst(n1, isgn, &t[3 * n1], ip, w);
			}
			for (i = 0; i < n1; i++)
			{
				a[i][j] = t[i];
				a[i][j + 1] = t[n1 + i];
				a[i][j + 2] = t[2 * n1 + i];
				a[i][j + 3] = t[3 * n1 + i];
			}
		}
	}
	else if (n2 == 2)
	{
		for (i = 0; i < n1; i++)
		{
			t[i] = a[i][0];
			t[n1 + i] = a[i][1];
		}
		if (ics == 0)
		{
			ddct(n1, isgn, t, ip, w);
			ddct(n1, isgn, &t[n1], ip, w);
		}
		else
		{
			ddst(n1, isgn, t, ip, w);
			ddst(n1, isgn, &t[n1], ip, w);
		}
		for (i = 0; i < n1; i++)
		{
			a[i][0] = t[i];
			a[i][1] = t[n1 + i];
		}
	}
}


#ifdef USE_FFT2D_THREADS
struct fft2d_arg_st {
	int nthread;
	int n0;
	int n1;
	int n2;
	int ic;
	int isgn;
	double **a;
	double *t;
	int *ip;
	double *w;
};
typedef struct fft2d_arg_st fft2d_arg_t;

//   uses math library: (nothing)
//   uses static function:
//     *xdft2d0_th
static void
xdft2d0_subth(
 int n1, int n2, int icr, int isgn, double **a, int *ip, double *w)
{
	fft2d_thread_t th[FFT2D_MAX_THREADS];
	fft2d_arg_t ag[FFT2D_MAX_THREADS];
	int nthread, i;
	
	nthread = FFT2D_MAX_THREADS;
	if (nthread > n1)
	{
		nthread = n1;
	}
	for (i = 0; i < nthread; i++)
	{
		ag[i].nthread = nthread;
		ag[i].n0 = i;
		ag[i].n1 = n1;
		ag[i].n2 = n2;
		ag[i].ic = icr;
		ag[i].isgn = isgn;
		ag[i].a = a;
		ag[i].ip = ip;
		ag[i].w = w;
		fft2d_thread_create(&th[i], xdft2d0_th, &ag[i]);
	}
	for (i = 0; i < nthread; i++)
	{
		fft2d_thread_wait(th[i]);
	}
}


//   uses math library: (nothing)
//   uses static function:
//     *cdft2d_th
static void
cdft2d_subth(
 int n1, int n2, int isgn, double **a, double *t, int *ip, double *w)
{
	fft2d_thread_t th[FFT2D_MAX_THREADS];
	fft2d_arg_t ag[FFT2D_MAX_THREADS];
	int nthread, nt, i;
	
	nthread = FFT2D_MAX_THREADS;
	nt = 8 * n1;
	if (n2 == 4 * FFT2D_MAX_THREADS)
	{
		nt >>= 1;
	}
	else if (n2 < 4 * FFT2D_MAX_THREADS)
	{
		nthread = n2 >> 1;
		nt >>= 2;
	}
	for (i = 0; i < nthread; i++)
	{
		ag[i].nthread = nthread;
		ag[i].n0 = i;
		ag[i].n1 = n1;
		ag[i].n2 = n2;
		ag[i].isgn = isgn;
		ag[i].a = a;
		ag[i].t = &t[nt * i];
		ag[i].ip = ip;
		ag[i].w = w;
		fft2d_thread_create(&th[i], cdft2d_th, &ag[i]);
	}
	for (i = 0; i < nthread; i++)
	{
		fft2d_thread_wait(th[i]);
	}
}

//   uses math library: (nothing)
//   uses static function:
//     *ddxt2d0_th
static void
ddxt2d0_subth(
 int n1, int n2, int ics, int isgn, double **a, int *ip, double *w)
{
	fft2d_thread_t th[FFT2D_MAX_THREADS];
	fft2d_arg_t ag[FFT2D_MAX_THREADS];
	int nthread, i;
	
	nthread = FFT2D_MAX_THREADS;
	if (nthread > n1)
	{
		nthread = n1;
	}
	for (i = 0; i < nthread; i++)
	{
		ag[i].nthread = nthread;
		ag[i].n0 = i;
		ag[i].n1 = n1;
		ag[i].n2 = n2;
		ag[i].ic = ics;
		ag[i].isgn = isgn;
		ag[i].a = a;
		ag[i].ip = ip;
		ag[i].w = w;
		fft2d_thread_create(&th[i], ddxt2d0_th, &ag[i]);
	}
	for (i = 0; i < nthread; i++)
	{
		fft2d_thread_wait(th[i]);
	}
}


//   uses math library: (nothing)
//   uses static function: (nothing)
static void
ddxt2d_subth(
 int n1, int n2, int ics, int isgn, double **a, double *t, int *ip, double *w)
{
	fft2d_thread_t th[FFT2D_MAX_THREADS];
	fft2d_arg_t ag[FFT2D_MAX_THREADS];
	int nthread, nt, i;
	
	nthread = FFT2D_MAX_THREADS;
	nt = 4 * n1;
	if (n2 == 2 * FFT2D_MAX_THREADS)
	{
		nt >>= 1;
	}
	else if (n2 < 2 * FFT2D_MAX_THREADS)
	{
		nthread = n2;
		nt >>= 2;
	}
	for (i = 0; i < nthread; i++)
	{
		ag[i].nthread = nthread;
		ag[i].n0 = i;
		ag[i].n1 = n1;
		ag[i].n2 = n2;
		ag[i].ic = ics;
		ag[i].isgn = isgn;
		ag[i].a = a;
		ag[i].t = &t[nt * i];
		ag[i].ip = ip;
		ag[i].w = w;
		fft2d_thread_create(&th[i], ddxt2d_th, &ag[i]);
	}
	for (i = 0; i < nthread; i++)
	{
		fft2d_thread_wait(th[i]);
	}
}


//   uses math library: (nothing)
//   uses intern function:
//     cdft, rdft
static void *
xdft2d0_th(void *p)
{
	int nthread, n0, n1, n2, icr, isgn, *ip, i;
	double **a, *w;
	
	nthread = ((fft2d_arg_t *) p)->nthread;
	n0 = ((fft2d_arg_t *) p)->n0;
	n1 = ((fft2d_arg_t *) p)->n1;
	n2 = ((fft2d_arg_t *) p)->n2;
	icr = ((fft2d_arg_t *) p)->ic;
	isgn = ((fft2d_arg_t *) p)->isgn;
	a = ((fft2d_arg_t *) p)->a;
	ip = ((fft2d_arg_t *) p)->ip;
	w = ((fft2d_arg_t *) p)->w;
	if (icr == 0)
	{
		for (i = n0; i < n1; i += nthread)
		{
			cdft(n2, isgn, a[i], ip, w);
		}
	}
	else
	{
		for (i = n0; i < n1; i += nthread)
		{
			rdft(n2, isgn, a[i], ip, w);
		}
	}
	return (void *) 0;
}


//   uses math library: (nothing)
//   uses intern function:
//     cdft
static void *
cdft2d_th(void *p)
{
	int nthread, n0, n1, n2, isgn, *ip, i, j;
	double **a, *t, *w;
	
	nthread = ((fft2d_arg_t *) p)->nthread;
	n0 = ((fft2d_arg_t *) p)->n0;
	n1 = ((fft2d_arg_t *) p)->n1;
	n2 = ((fft2d_arg_t *) p)->n2;
	isgn = ((fft2d_arg_t *) p)->isgn;
	a = ((fft2d_arg_t *) p)->a;
	t = ((fft2d_arg_t *) p)->t;
	ip = ((fft2d_arg_t *) p)->ip;
	w = ((fft2d_arg_t *) p)->w;
	if (n2 > 4 * nthread)
	{
		for (j = 8 * n0; j < n2; j += 8 * nthread)
		{
			for (i = 0; i < n1; i++)
			{
				t[2 * i] = a[i][j];
				t[2 * i + 1] = a[i][j + 1];
				t[2 * n1 + 2 * i] = a[i][j + 2];
				t[2 * n1 + 2 * i + 1] = a[i][j + 3];
				t[4 * n1 + 2 * i] = a[i][j + 4];
				t[4 * n1 + 2 * i + 1] = a[i][j + 5];
				t[6 * n1 + 2 * i] = a[i][j + 6];
				t[6 * n1 + 2 * i + 1] = a[i][j + 7];
			}
			cdft(2 * n1, isgn, t, ip, w);
			cdft(2 * n1, isgn, &t[2 * n1], ip, w);
			cdft(2 * n1, isgn, &t[4 * n1], ip, w);
			cdft(2 * n1, isgn, &t[6 * n1], ip, w);
			for (i = 0; i < n1; i++)
			{
				a[i][j] = t[2 * i];
				a[i][j + 1] = t[2 * i + 1];
				a[i][j + 2] = t[2 * n1 + 2 * i];
				a[i][j + 3] = t[2 * n1 + 2 * i + 1];
				a[i][j + 4] = t[4 * n1 + 2 * i];
				a[i][j + 5] = t[4 * n1 + 2 * i + 1];
				a[i][j + 6] = t[6 * n1 + 2 * i];
				a[i][j + 7] = t[6 * n1 + 2 * i + 1];
			}
		}
	}
	else if (n2 == 4 * nthread)
	{
		for (i = 0; i < n1; i++)
		{
			t[2 * i] = a[i][4 * n0];
			t[2 * i + 1] = a[i][4 * n0 + 1];
			t[2 * n1 + 2 * i] = a[i][4 * n0 + 2];
			t[2 * n1 + 2 * i + 1] = a[i][4 * n0 + 3];
		}
		cdft(2 * n1, isgn, t, ip, w);
		cdft(2 * n1, isgn, &t[2 * n1], ip, w);
		for (i = 0; i < n1; i++)
		{
			a[i][4 * n0] = t[2 * i];
			a[i][4 * n0 + 1] = t[2 * i + 1];
			a[i][4 * n0 + 2] = t[2 * n1 + 2 * i];
			a[i][4 * n0 + 3] = t[2 * n1 + 2 * i + 1];
		}
	}
	else if (n2 == 2 * nthread)
	{
		for (i = 0; i < n1; i++)
		{
			t[2 * i] = a[i][2 * n0];
			t[2 * i + 1] = a[i][2 * n0 + 1];
		}
		cdft(2 * n1, isgn, t, ip, w);
		for (i = 0; i < n1; i++)
		{
			a[i][2 * n0] = t[2 * i];
			a[i][2 * n0 + 1] = t[2 * i + 1];
		}
	}
	return (void *) 0;
}


//   uses math library: (nothing)
//   uses intern function:
//     ddct, ddst
static void *
ddxt2d0_th(void *p)
{
	int nthread, n0, n1, n2, ics, isgn, *ip, i;
	double **a, *w;
	
	nthread = ((fft2d_arg_t *) p)->nthread;
	n0 = ((fft2d_arg_t *) p)->n0;
	n1 = ((fft2d_arg_t *) p)->n1;
	n2 = ((fft2d_arg_t *) p)->n2;
	ics = ((fft2d_arg_t *) p)->ic;
	isgn = ((fft2d_arg_t *) p)->isgn;
	a = ((fft2d_arg_t *) p)->a;
	ip = ((fft2d_arg_t *) p)->ip;
	w = ((fft2d_arg_t *) p)->w;
	if (ics == 0)
	{
		for (i = n0; i < n1; i += nthread)
		{
			ddct(n2, isgn, a[i], ip, w);
		}
	}
	else
	{
		for (i = n0; i < n1; i += nthread)
		{
			ddst(n2, isgn, a[i], ip, w);
		}
	}
	return (void *) 0;
}


//   uses math library: (nothing)
//   uses intern function:
//     ddct, ddst
static void *
ddxt2d_th(void *p)
{
	int nthread, n0, n1, n2, ics, isgn, *ip, i, j;
	double **a, *t, *w;
	
	nthread = ((fft2d_arg_t *) p)->nthread;
	n0 = ((fft2d_arg_t *) p)->n0;
	n1 = ((fft2d_arg_t *) p)->n1;
	n2 = ((fft2d_arg_t *) p)->n2;
	ics = ((fft2d_arg_t *) p)->ic;
	isgn = ((fft2d_arg_t *) p)->isgn;
	a = ((fft2d_arg_t *) p)->a;
	t = ((fft2d_arg_t *) p)->t;
	ip = ((fft2d_arg_t *) p)->ip;
	w = ((fft2d_arg_t *) p)->w;
	if (n2 > 2 * nthread)
	{
		for (j = 4 * n0; j < n2; j += 4 * nthread)
		{
			for (i = 0; i < n1; i++)
			{
				t[i] = a[i][j];
				t[n1 + i] = a[i][j + 1];
				t[2 * n1 + i] = a[i][j + 2];
				t[3 * n1 + i] = a[i][j + 3];
			}
			if (ics == 0)
			{
				ddct(n1, isgn, t, ip, w);
				ddct(n1, isgn, &t[n1], ip, w);
				ddct(n1, isgn, &t[2 * n1], ip, w);
				ddct(n1, isgn, &t[3 * n1], ip, w);
			}
			else
			{
				ddst(n1, isgn, t, ip, w);
				ddst(n1, isgn, &t[n1], ip, w);
				ddst(n1, isgn, &t[2 * n1], ip, w);
				ddst(n1, isgn, &t[3 * n1], ip, w);
			}
			for (i = 0; i < n1; i++)
			{
				a[i][j] = t[i];
				a[i][j + 1] = t[n1 + i];
				a[i][j + 2] = t[2 * n1 + i];
				a[i][j + 3] = t[3 * n1 + i];
			}
		}
	}
	else if (n2 == 2 * nthread)
	{
		for (i = 0; i < n1; i++)
		{
			t[i] = a[i][2 * n0];
			t[n1 + i] = a[i][2 * n0 + 1];
		}
		if (ics == 0)
		{
			ddct(n1, isgn, t, ip, w);
			ddct(n1, isgn, &t[n1], ip, w);
		}
		else
		{
			ddst(n1, isgn, t, ip, w);
			ddst(n1, isgn, &t[n1], ip, w);
		}
		for (i = 0; i < n1; i++)
		{
			a[i][2 * n0] = t[i];
			a[i][2 * n0 + 1] = t[n1 + i];
		}
	}
	else if (n2 == nthread)
	{
		for (i = 0; i < n1; i++)
		{
			t[i] = a[i][n0];
		}
		if (ics == 0)
		{
			ddct(n1, isgn, t, ip, w);
		}
		else
		{
			ddst(n1, isgn, t, ip, w);
		}
		for (i = 0; i < n1; i++)
		{
			a[i][n0] = t[i];
		}
	}
	return (void *) 0;
}
#endif /* USE_FFT2D_THREADS */

