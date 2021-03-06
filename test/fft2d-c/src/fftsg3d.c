/*******************************************************************************
Fast Fourier/Cosine/Sine Transform
    dimension   :three
    data length :power of 2
    decimation  :frequency
    radix       :split-radix, row-column
    data        :inplace
    table       :use
functions
    cdft3d: Complex Discrete Fourier Transform
    rdft3d: Real Discrete Fourier Transform
    ddct3d: Discrete Cosine Transform
    ddst3d: Discrete Sine Transform
function prototypes
    void cdft3d(int, int, int, int, double ***, double *, int *, double *);
    void rdft3d(int, int, int, int, double ***, double *, int *, double *);
    void rdft3dsort(int, int, int, int, double ***);
    void ddct3d(int, int, int, int, double ***, double *, int *, double *);
    void ddst3d(int, int, int, int, double ***, double *, int *, double *);
necessary package
    fftsg.c  : 1D-FFT package
macro definitions
    USE_FFT3D_PTHREADS : default=not defined
        FFT3D_MAX_THREADS     : must be 2^N, default=4
        FFT3D_THREADS_BEGIN_N : default=65536
    USE_FFT3D_WINTHREADS : default=not defined
        FFT3D_MAX_THREADS     : must be 2^N, default=4
        FFT3D_THREADS_BEGIN_N : default=131072
*******************************************************************************/
#include "fftsg.h"
#include "fftsg3d.h"
#include "fftsg_p.h"


#include <stdio.h>
#include <stdlib.h>
#define fft3d_alloc_error_check(p) { \
    if ((p) == NULL) { \
        fprintf(stderr, "fft3d memory allocation error\n"); \
        exit(1); \
    } \
}


#ifdef USE_FFT3D_PTHREADS
# define USE_FFT3D_THREADS
# ifndef FFT3D_MAX_THREADS
#  define FFT3D_MAX_THREADS 4
# endif
# ifndef FFT3D_THREADS_BEGIN_N
#  define FFT3D_THREADS_BEGIN_N 65536
# endif
# include <pthread.h>
# define fft3d_thread_t pthread_t
# define fft3d_thread_create(thp,func,argp) { \
    if (pthread_create(thp, NULL, func, (void *) (argp)) != 0) { \
        fprintf(stderr, "fft3d thread error\n"); \
        exit(1); \
    } \
}
# define fft3d_thread_wait(th) { \
    if (pthread_join(th, NULL) != 0) { \
        fprintf(stderr, "fft3d thread error\n"); \
        exit(1); \
    } \
}
#endif /* USE_FFT3D_PTHREADS */


#ifdef USE_FFT3D_WINTHREADS
# define USE_FFT3D_THREADS
# ifndef FFT3D_MAX_THREADS
#  define FFT3D_MAX_THREADS 4
# endif
# ifndef FFT3D_THREADS_BEGIN_N
#  define FFT3D_THREADS_BEGIN_N 131072
# endif
# include <windows.h>
# define fft3d_thread_t HANDLE
# define fft3d_thread_create(thp,func,argp) { \
    DWORD thid; \
    *(thp) = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) (func), (LPVOID) (argp), 0, &thid); \
    if (*(thp) == 0) { \
        fprintf(stderr, "fft3d thread error\n"); \
        exit(1); \
    } \
}
# define fft3d_thread_wait(th) { \
    WaitForSingleObject(th, INFINITE); \
    CloseHandle(th); \
}
#endif /* USE_FFT3D_WINTHREADS */

// Declare Prototypes of subroutine
static void xdft3da_sub (
 int n1, int n2, int n3, int icr, int isgn, 
 double ***a, double *t, int *ip, double *w);
static void cdft3db_sub (
 int n1, int n2, int n3, int isgn, double ***a, 
 double *t, int *ip, double *w);
static void rdft3d_sub(int n1, int n2, int n3, int isgn, double ***a);
static void ddxt3da_sub (
 int n1, int n2, int n3, int ics, int isgn, 
 double ***a, double *t, int *ip, double *w);
static void ddxt3db_sub (
 int n1, int n2, int n3, int ics, int isgn, 
 double ***a, double *t, int *ip, double *w);
#ifdef USE_FFT3D_THREADS
static void xdft3da_subth (
 int n1, int n2, int n3, int icr, int isgn, 
 double ***a, double *t, int *ip, double *w);
static void cdft3db_subth (
 int n1, int n2, int n3, int isgn, double ***a, 
 double *t, int *ip, double *w);
static void ddxt3da_subth (
 int n1, int n2, int n3, int ics, int isgn, 
 double ***a, double *t, int *ip, double *w);
static void ddxt3db_subth (
 int n1, int n2, int n3, int ics, int isgn, 
 double ***a, double *t, int *ip, double *w);
static void *xdft3da_th(void *p);
static void *cdft3db_th(void *p);
static void *ddxt3da_th(void *p);
static void *ddxt3db_th(void *p);
#endif /* USE_FFT3D_THREADS */


// -------- Complex DFT (Discrete Fourier Transform) --------
//   uses math library: (nothing)
//   uses static function:
//     makewt, xdft3da_sub, cdft3db_sub, 
//     xdft3da_subth, cdft3db_subth (thread)
void
cdft3d(
 int n1, int n2, int n3, int isgn, double ***a, double *t, int *ip, double *w)
{
	int n, itnull, nt;
	
	n = n1;
	if (n < n2)
	{
		n = n2;
	}
	n <<= 1;
	if (n < n3)
	{
		n = n3;
	}
	if (n > (ip[0] << 2))
	{
		makewt(n >> 2, ip, w);
	}
	itnull = 0;
	if (t == NULL)
	{
		itnull = 1;
		nt = n1;
		if (nt < n2)
		{
			nt = n2;
		}
		nt *= 8;
#ifdef USE_FFT3D_THREADS
		nt *= FFT3D_MAX_THREADS;
#endif /* USE_FFT3D_THREADS */
		if (n3 == 4)
		{
			nt >>= 1;
		}
		else if (n3 < 4)
		{
			nt >>= 2;
		}
		t = (double *) malloc(sizeof(double) * nt);
		fft3d_alloc_error_check(t);
	}
#ifdef USE_FFT3D_THREADS
	if ((double) n1 * n2 * n3 >= (double) FFT3D_THREADS_BEGIN_N)
	{
		xdft3da_subth(n1, n2, n3, 0, isgn, a, t, ip, w);
		cdft3db_subth(n1, n2, n3, isgn, a, t, ip, w);
	}
	else 
#endif /* USE_FFT3D_THREADS */
	{
		xdft3da_sub(n1, n2, n3, 0, isgn, a, t, ip, w);
		cdft3db_sub(n1, n2, n3, isgn, a, t, ip, w);
	}
	if (itnull != 0)
	{
		free(t);
	}
}


// -------- Real DFT / Inverse of Real DFT --------
//   uses math library: (nothing)
//   uses static function:
//     makewt, makect, xdft3da_sub, cdft3db_sub, rdft3d_sub
//     xdft3da_subth, cdft3db_subth (thread)
void
rdft3d(
 int n1, int n2, int n3, int isgn, double ***a,  double *t, int *ip, double *w)
{
	int n, nw, nc, itnull, nt;
	
	n = n1;
	if (n < n2)
	{
		n = n2;
	}
	n <<= 1;
	if (n < n3)
	{
		n = n3;
	}
	nw = ip[0];
	if (n > (nw << 2))
	{
		nw = n >> 2;
		makewt(nw, ip, w);
	}
	nc = ip[1];
	if (n3 > (nc << 2))
	{
		nc = n3 >> 2;
		makect(nc, ip, w + nw);
	}
	itnull = 0;
	if (t == NULL)
	{
		itnull = 1;
		nt = n1;
		if (nt < n2)
		{
			nt = n2;
		}
		nt *= 8;
#ifdef USE_FFT3D_THREADS
		nt *= FFT3D_MAX_THREADS;
#endif /* USE_FFT3D_THREADS */
		if (n3 == 4)
		{
			nt >>= 1;
		}
		else if (n3 < 4)
		{
			nt >>= 2;
		}
		t = (double *) malloc(sizeof(double) * nt);
		fft3d_alloc_error_check(t);
	}
#ifdef USE_FFT3D_THREADS
	if ((double) n1 * n2 * n3 >= (double) FFT3D_THREADS_BEGIN_N)
	{
		if (isgn < 0)
		{
			rdft3d_sub(n1, n2, n3, isgn, a);
			cdft3db_subth(n1, n2, n3, isgn, a, t, ip, w);
		}
		xdft3da_subth(n1, n2, n3, 1, isgn, a, t, ip, w);
		if (isgn >= 0)
		{
			cdft3db_subth(n1, n2, n3, isgn, a, t, ip, w);
			rdft3d_sub(n1, n2, n3, isgn, a);
		}
	}
	else 
#endif /* USE_FFT3D_THREADS */
	{
		if (isgn < 0)
		{
			rdft3d_sub(n1, n2, n3, isgn, a);
			cdft3db_sub(n1, n2, n3, isgn, a, t, ip, w);
		}
		xdft3da_sub(n1, n2, n3, 1, isgn, a, t, ip, w);
		if (isgn >= 0)
		{
			cdft3db_sub(n1, n2, n3, isgn, a, t, ip, w);
			rdft3d_sub(n1, n2, n3, isgn, a);
		}
	}
	if (itnull != 0)
	{
		free(t);
	}
}

// uses math library: (nothing)
// uses static function: (nothing)
void
rdft3dsort(int n1, int n2, int n3, int isgn, double ***a)
{
	int n1h, n2h, i, j;
	double x, y;
	
	n1h = n1 >> 1;
	n2h = n2 >> 1;
	if (isgn < 0)
	{
		for (i = 0; i < n1; i++)
		{
			for (j = n2h + 1; j < n2; j++)
			{
				a[i][j][0] = a[i][j][n3 + 1];
				a[i][j][1] = a[i][j][n3];
			}
		}
		for (i = n1h + 1; i < n1; i++)
		{
			a[i][0][0] = a[i][0][n3 + 1];
			a[i][0][1] = a[i][0][n3];
			a[i][n2h][0] = a[i][n2h][n3 + 1];
			a[i][n2h][1] = a[i][n2h][n3];
		}
		a[0][0][1] = a[0][0][n3];
		a[0][n2h][1] = a[0][n2h][n3];
		a[n1h][0][1] = a[n1h][0][n3];
		a[n1h][n2h][1] = a[n1h][n2h][n3];
	}
	else
	{
		for (j = n2h + 1; j < n2; j++)
		{
			y = a[0][j][0];
			x = a[0][j][1];
			a[0][j][n3] = x;
			a[0][j][n3 + 1] = y;
			a[0][n2 - j][n3] = x;
			a[0][n2 - j][n3 + 1] = -y;
			a[0][j][0] = a[0][n2 - j][0];
			a[0][j][1] = -a[0][n2 - j][1];
		}
		for (i = 1; i < n1; i++)
		{
			for (j = n2h + 1; j < n2; j++)
			{
				y = a[i][j][0];
				x = a[i][j][1];
				a[i][j][n3] = x;
				a[i][j][n3 + 1] = y;
				a[n1 - i][n2 - j][n3] = x;
				a[n1 - i][n2 - j][n3 + 1] = -y;
				a[i][j][0] = a[n1 - i][n2 - j][0];
				a[i][j][1] = -a[n1 - i][n2 - j][1];
			}
		}
		for (i = n1h + 1; i < n1; i++)
		{
			y = a[i][0][0];
			x = a[i][0][1];
			a[i][0][n3] = x;
			a[i][0][n3 + 1] = y;
			a[n1 - i][0][n3] = x;
			a[n1 - i][0][n3 + 1] = -y;
			a[i][0][0] = a[n1 - i][0][0];
			a[i][0][1] = -a[n1 - i][0][1];
			y = a[i][n2h][0];
			x = a[i][n2h][1];
			a[i][n2h][n3] = x;
			a[i][n2h][n3 + 1] = y;
			a[n1 - i][n2h][n3] = x;
			a[n1 - i][n2h][n3 + 1] = -y;
			a[i][n2h][0] = a[n1 - i][n2h][0];
			a[i][n2h][1] = -a[n1 - i][n2h][1];
		}
		a[0][0][n3] = a[0][0][1];
		a[0][0][n3 + 1] = 0;
		a[0][0][1] = 0;
		a[0][n2h][n3] = a[0][n2h][1];
		a[0][n2h][n3 + 1] = 0;
		a[0][n2h][1] = 0;
		a[n1h][0][n3] = a[n1h][0][1];
		a[n1h][0][n3 + 1] = 0;
		a[n1h][0][1] = 0;
		a[n1h][n2h][n3] = a[n1h][n2h][1];
		a[n1h][n2h][n3 + 1] = 0;
		a[n1h][n2h][1] = 0;
	}
}


// -------- DCT (Discrete Cosine Transform) / Inverse of DCT --------
//   uses math library: (nothing)
//   uses static function:
//     makewt, makect, ddxt3da_sub, ddxt3db_sub
//     ddxt3da_subth, ddxt3db_subth (thread)
void
ddct3d(
 int n1, int n2, int n3, int isgn, double ***a, double *t, int *ip, double *w)
{
	int n, nw, nc, itnull, nt;
	
	n = n1;
	if (n < n2)
	{
		n = n2;
	}
	if (n < n3)
	{
		n = n3;
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
		nt = n1;
		if (nt < n2)
		{
			nt = n2;
		}
		nt *= 4;
#ifdef USE_FFT3D_THREADS
		nt *= FFT3D_MAX_THREADS;
#endif /* USE_FFT3D_THREADS */
		if (n3 == 2)
		{
			nt >>= 1;
		}
		t = (double *) malloc(sizeof(double) * nt);
		fft3d_alloc_error_check(t);
	}
#ifdef USE_FFT3D_THREADS
	if ((double) n1 * n2 * n3 >= (double) FFT3D_THREADS_BEGIN_N)
	{
		ddxt3da_subth(n1, n2, n3, 0, isgn, a, t, ip, w);
		ddxt3db_subth(n1, n2, n3, 0, isgn, a, t, ip, w);
	}
	else 
#endif /* USE_FFT3D_THREADS */
	{
		ddxt3da_sub(n1, n2, n3, 0, isgn, a, t, ip, w);
		ddxt3db_sub(n1, n2, n3, 0, isgn, a, t, ip, w);
	}
	if (itnull != 0)
	{
		free(t);
	}
}


// -------- DST (Discrete Sine Transform) / Inverse of DST --------
//   uses math library: (nothing)
//   uses static function:
//     makewt, makect, ddxt3da_sub, ddxt3db_sub
//     ddxt3da_subth, ddxt3db_subth (thread)
void
ddst3d(
 int n1, int n2, int n3, int isgn, double ***a, double *t, int *ip, double *w)
{
	int n, nw, nc, itnull, nt;
	
	n = n1;
	if (n < n2)
	{
		n = n2;
	}
	if (n < n3)
	{
		n = n3;
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
		nt = n1;
		if (nt < n2)
		{
			nt = n2;
		}
		nt *= 4;
#ifdef USE_FFT3D_THREADS
		nt *= FFT3D_MAX_THREADS;
#endif /* USE_FFT3D_THREADS */
		if (n3 == 2)
		{
			nt >>= 1;
		}
		t = (double *) malloc(sizeof(double) * nt);
		fft3d_alloc_error_check(t);
	}
#ifdef USE_FFT3D_THREADS
	if ((double) n1 * n2 * n3 >= (double) FFT3D_THREADS_BEGIN_N)
	{
		ddxt3da_subth(n1, n2, n3, 1, isgn, a, t, ip, w);
		ddxt3db_subth(n1, n2, n3, 1, isgn, a, t, ip, w);
	}
	else 
#endif /* USE_FFT3D_THREADS */
	{
		ddxt3da_sub(n1, n2, n3, 1, isgn, a, t, ip, w);
		ddxt3db_sub(n1, n2, n3, 1, isgn, a, t, ip, w);
	}
	if (itnull != 0)
	{
		free(t);
	}
}


/* -------- child routines -------- */


// uses math library: (nothing)
// uses intern function:
//    cdft, rdft
static void
xdft3da_sub(
 int n1, int n2, int n3, int icr, int isgn, 
 double ***a, double *t, int *ip, double *w)
{
	int i, j, k;
	
	for (i = 0; i < n1; i++)
	{
		if (icr == 0)
		{
			for (j = 0; j < n2; j++)
			{
				cdft(n3, isgn, a[i][j], ip, w);
			}
		}
		else if (isgn >= 0)
		{
			for (j = 0; j < n2; j++)
			{
				rdft(n3, isgn, a[i][j], ip, w);
			}
		}
		if (n3 > 4)
		{
			for (k = 0; k < n3; k += 8)
			{
				for (j = 0; j < n2; j++)
				{
					t[2 * j] = a[i][j][k];
					t[2 * j + 1] = a[i][j][k + 1];
					t[2 * n2 + 2 * j] = a[i][j][k + 2];
					t[2 * n2 + 2 * j + 1] = a[i][j][k + 3];
					t[4 * n2 + 2 * j] = a[i][j][k + 4];
					t[4 * n2 + 2 * j + 1] = a[i][j][k + 5];
					t[6 * n2 + 2 * j] = a[i][j][k + 6];
					t[6 * n2 + 2 * j + 1] = a[i][j][k + 7];
				}
				cdft(2 * n2, isgn, t, ip, w);
				cdft(2 * n2, isgn, &t[2 * n2], ip, w);
				cdft(2 * n2, isgn, &t[4 * n2], ip, w);
				cdft(2 * n2, isgn, &t[6 * n2], ip, w);
				for (j = 0; j < n2; j++)
				{
					a[i][j][k] = t[2 * j];
					a[i][j][k + 1] = t[2 * j + 1];
					a[i][j][k + 2] = t[2 * n2 + 2 * j];
					a[i][j][k + 3] = t[2 * n2 + 2 * j + 1];
					a[i][j][k + 4] = t[4 * n2 + 2 * j];
					a[i][j][k + 5] = t[4 * n2 + 2 * j + 1];
					a[i][j][k + 6] = t[6 * n2 + 2 * j];
					a[i][j][k + 7] = t[6 * n2 + 2 * j + 1];
				}
			}
		}
		else if (n3 == 4)
		{
			for (j = 0; j < n2; j++)
			{
				t[2 * j] = a[i][j][0];
				t[2 * j + 1] = a[i][j][1];
				t[2 * n2 + 2 * j] = a[i][j][2];
				t[2 * n2 + 2 * j + 1] = a[i][j][3];
			}
			cdft(2 * n2, isgn, t, ip, w);
			cdft(2 * n2, isgn, &t[2 * n2], ip, w);
			for (j = 0; j < n2; j++)
			{
				a[i][j][0] = t[2 * j];
				a[i][j][1] = t[2 * j + 1];
				a[i][j][2] = t[2 * n2 + 2 * j];
				a[i][j][3] = t[2 * n2 + 2 * j + 1];
			}
		}
		else if (n3 == 2)
		{
			for (j = 0; j < n2; j++)
			{
				t[2 * j] = a[i][j][0];
				t[2 * j + 1] = a[i][j][1];
			}
			cdft(2 * n2, isgn, t, ip, w);
			for (j = 0; j < n2; j++)
			{
				a[i][j][0] = t[2 * j];
				a[i][j][1] = t[2 * j + 1];
			}
		}
		if (icr != 0 && isgn < 0)
		{
			for (j = 0; j < n2; j++)
			{
				rdft(n3, isgn, a[i][j], ip, w);
			}
		}
	}
}


//   uses math library: (nothing)
//   uses intern function:
//     cdft
static void
cdft3db_sub(
 int n1, int n2, int n3, int isgn, double ***a, double *t, int *ip, double *w)
{
	int i, j, k;
	
	if (n3 > 4)
	{
		for (j = 0; j < n2; j++)
		{
			for (k = 0; k < n3; k += 8)
			{
				for (i = 0; i < n1; i++)
				{
					t[2 * i] = a[i][j][k];
					t[2 * i + 1] = a[i][j][k + 1];
					t[2 * n1 + 2 * i] = a[i][j][k + 2];
					t[2 * n1 + 2 * i + 1] = a[i][j][k + 3];
					t[4 * n1 + 2 * i] = a[i][j][k + 4];
					t[4 * n1 + 2 * i + 1] = a[i][j][k + 5];
					t[6 * n1 + 2 * i] = a[i][j][k + 6];
					t[6 * n1 + 2 * i + 1] = a[i][j][k + 7];
				}
				cdft(2 * n1, isgn, t, ip, w);
				cdft(2 * n1, isgn, &t[2 * n1], ip, w);
				cdft(2 * n1, isgn, &t[4 * n1], ip, w);
				cdft(2 * n1, isgn, &t[6 * n1], ip, w);
				for (i = 0; i < n1; i++)
				{
					a[i][j][k] = t[2 * i];
					a[i][j][k + 1] = t[2 * i + 1];
					a[i][j][k + 2] = t[2 * n1 + 2 * i];
					a[i][j][k + 3] = t[2 * n1 + 2 * i + 1];
					a[i][j][k + 4] = t[4 * n1 + 2 * i];
					a[i][j][k + 5] = t[4 * n1 + 2 * i + 1];
					a[i][j][k + 6] = t[6 * n1 + 2 * i];
					a[i][j][k + 7] = t[6 * n1 + 2 * i + 1];
				}
			}
		}
	}
	else if (n3 == 4)
	{
		for (j = 0; j < n2; j++)
		{
			for (i = 0; i < n1; i++)
			{
				t[2 * i] = a[i][j][0];
				t[2 * i + 1] = a[i][j][1];
				t[2 * n1 + 2 * i] = a[i][j][2];
				t[2 * n1 + 2 * i + 1] = a[i][j][3];
			}
			cdft(2 * n1, isgn, t, ip, w);
			cdft(2 * n1, isgn, &t[2 * n1], ip, w);
			for (i = 0; i < n1; i++)
			{
				a[i][j][0] = t[2 * i];
				a[i][j][1] = t[2 * i + 1];
				a[i][j][2] = t[2 * n1 + 2 * i];
				a[i][j][3] = t[2 * n1 + 2 * i + 1];
			}
		}
	}
	else if (n3 == 2)
	{
		for (j = 0; j < n2; j++)
		{
			for (i = 0; i < n1; i++)
			{
				t[2 * i] = a[i][j][0];
				t[2 * i + 1] = a[i][j][1];
			}
			cdft(2 * n1, isgn, t, ip, w);
			for (i = 0; i < n1; i++)
			{
				a[i][j][0] = t[2 * i];
				a[i][j][1] = t[2 * i + 1];
			}
		}
	}
}


//   uses math library: (nothing)
//   uses static function: (nothing)
static void
rdft3d_sub(int n1, int n2, int n3, int isgn, double ***a)
{
	int n1h, n2h, i, j, k, l;
	double xi;
	
	n1h = n1 >> 1;
	n2h = n2 >> 1;
	if (isgn < 0)
	{
		for (i = 1; i < n1h; i++)
		{
			j = n1 - i;
			xi = a[i][0][0] - a[j][0][0];
			a[i][0][0] += a[j][0][0];
			a[j][0][0] = xi;
			xi = a[j][0][1] - a[i][0][1];
			a[i][0][1] += a[j][0][1];
			a[j][0][1] = xi;
			xi = a[i][n2h][0] - a[j][n2h][0];
			a[i][n2h][0] += a[j][n2h][0];
			a[j][n2h][0] = xi;
			xi = a[j][n2h][1] - a[i][n2h][1];
			a[i][n2h][1] += a[j][n2h][1];
			a[j][n2h][1] = xi;
			for (k = 1; k < n2h; k++)
			{
				l = n2 - k;
				xi = a[i][k][0] - a[j][l][0];
				a[i][k][0] += a[j][l][0];
				a[j][l][0] = xi;
				xi = a[j][l][1] - a[i][k][1];
				a[i][k][1] += a[j][l][1];
				a[j][l][1] = xi;
				xi = a[j][k][0] - a[i][l][0];
				a[j][k][0] += a[i][l][0];
				a[i][l][0] = xi;
				xi = a[i][l][1] - a[j][k][1];
				a[j][k][1] += a[i][l][1];
				a[i][l][1] = xi;
			}
		}
		for (k = 1; k < n2h; k++)
		{
			l = n2 - k;
			xi = a[0][k][0] - a[0][l][0];
			a[0][k][0] += a[0][l][0];
			a[0][l][0] = xi;
			xi = a[0][l][1] - a[0][k][1];
			a[0][k][1] += a[0][l][1];
			a[0][l][1] = xi;
			xi = a[n1h][k][0] - a[n1h][l][0];
			a[n1h][k][0] += a[n1h][l][0];
			a[n1h][l][0] = xi;
			xi = a[n1h][l][1] - a[n1h][k][1];
			a[n1h][k][1] += a[n1h][l][1];
			a[n1h][l][1] = xi;
		}
	}
	else
	{
		for (i = 1; i < n1h; i++)
		{
			j = n1 - i;
			a[j][0][0] = 0.5 * (a[i][0][0] - a[j][0][0]);
			a[i][0][0] -= a[j][0][0];
			a[j][0][1] = 0.5 * (a[i][0][1] + a[j][0][1]);
			a[i][0][1] -= a[j][0][1];
			a[j][n2h][0] = 0.5 * (a[i][n2h][0] - a[j][n2h][0]);
			a[i][n2h][0] -= a[j][n2h][0];
			a[j][n2h][1] = 0.5 * (a[i][n2h][1] + a[j][n2h][1]);
			a[i][n2h][1] -= a[j][n2h][1];
			for (k = 1; k < n2h; k++)
			{
				l = n2 - k;
				a[j][l][0] = 0.5 * (a[i][k][0] - a[j][l][0]);
				a[i][k][0] -= a[j][l][0];
				a[j][l][1] = 0.5 * (a[i][k][1] + a[j][l][1]);
				a[i][k][1] -= a[j][l][1];
				a[i][l][0] = 0.5 * (a[j][k][0] - a[i][l][0]);
				a[j][k][0] -= a[i][l][0];
				a[i][l][1] = 0.5 * (a[j][k][1] + a[i][l][1]);
				a[j][k][1] -= a[i][l][1];
			}
		}
		for (k = 1; k < n2h; k++)
		{
			l = n2 - k;
			a[0][l][0] = 0.5 * (a[0][k][0] - a[0][l][0]);
			a[0][k][0] -= a[0][l][0];
			a[0][l][1] = 0.5 * (a[0][k][1] + a[0][l][1]);
			a[0][k][1] -= a[0][l][1];
			a[n1h][l][0] = 0.5 * (a[n1h][k][0] - a[n1h][l][0]);
			a[n1h][k][0] -= a[n1h][l][0];
			a[n1h][l][1] = 0.5 * (a[n1h][k][1] + a[n1h][l][1]);
			a[n1h][k][1] -= a[n1h][l][1];
		}
	}
}


//   uses math library: (nothing)
//   uses intern function:
//     ddct, ddst
static void
ddxt3da_sub(
 int n1, int n2, int n3, int ics, int isgn, 
 double ***a, double *t, int *ip, double *w)
{
	int i, j, k;
	
	for (i = 0; i < n1; i++)
	{
		if (ics == 0)
		{
			for (j = 0; j < n2; j++)
			{
				ddct(n3, isgn, a[i][j], ip, w);
			}
		}
		else
		{
			for (j = 0; j < n2; j++)
			{
				ddst(n3, isgn, a[i][j], ip, w);
			}
		}
		if (n3 > 2)
		{
			for (k = 0; k < n3; k += 4)
			{
				for (j = 0; j < n2; j++)
				{
					t[j] = a[i][j][k];
					t[n2 + j] = a[i][j][k + 1];
					t[2 * n2 + j] = a[i][j][k + 2];
					t[3 * n2 + j] = a[i][j][k + 3];
				}
				if (ics == 0)
				{
					ddct(n2, isgn, t, ip, w);
					ddct(n2, isgn, &t[n2], ip, w);
					ddct(n2, isgn, &t[2 * n2], ip, w);
					ddct(n2, isgn, &t[3 * n2], ip, w);
				}
				else
				{
					ddst(n2, isgn, t, ip, w);
					ddst(n2, isgn, &t[n2], ip, w);
					ddst(n2, isgn, &t[2 * n2], ip, w);
					ddst(n2, isgn, &t[3 * n2], ip, w);
				}
				for (j = 0; j < n2; j++)
				{
					a[i][j][k] = t[j];
					a[i][j][k + 1] = t[n2 + j];
					a[i][j][k + 2] = t[2 * n2 + j];
					a[i][j][k + 3] = t[3 * n2 + j];
				}
			}
		}
		else if (n3 == 2)
		{
			for (j = 0; j < n2; j++)
			{
				t[j] = a[i][j][0];
				t[n2 + j] = a[i][j][1];
			}
			if (ics == 0)
			{
				ddct(n2, isgn, t, ip, w);
				ddct(n2, isgn, &t[n2], ip, w);
			}
			else
			{
				ddst(n2, isgn, t, ip, w);
				ddst(n2, isgn, &t[n2], ip, w);
			}
			for (j = 0; j < n2; j++)
			{
				a[i][j][0] = t[j];
				a[i][j][1] = t[n2 + j];
			}
		}
	}
}


//   uses math library: (nothing)
//   uses intern function:
//     ddct, ddst
static void
ddxt3db_sub(
 int n1, int n2, int n3, int ics, int isgn, 
 double ***a, double *t, int *ip, double *w)
{
	int i, j, k;
	
	if (n3 > 2)
	{
		for (j = 0; j < n2; j++)
		{
			for (k = 0; k < n3; k += 4)
			{
				for (i = 0; i < n1; i++)
				{
					t[i] = a[i][j][k];
					t[n1 + i] = a[i][j][k + 1];
					t[2 * n1 + i] = a[i][j][k + 2];
					t[3 * n1 + i] = a[i][j][k + 3];
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
					a[i][j][k] = t[i];
					a[i][j][k + 1] = t[n1 + i];
					a[i][j][k + 2] = t[2 * n1 + i];
					a[i][j][k + 3] = t[3 * n1 + i];
				}
			}
		}
	}
	else if (n3 == 2)
	{
		for (j = 0; j < n2; j++)
		{
			for (i = 0; i < n1; i++)
			{
				t[i] = a[i][j][0];
				t[n1 + i] = a[i][j][1];
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
				a[i][j][0] = t[i];
				a[i][j][1] = t[n1 + i];
			}
		}
	}
}


#ifdef USE_FFT3D_THREADS
struct fft3d_arg_st
{
	int nthread;
	int n0;
	int n1;
	int n2;
	int n3;
	int ic;
	int isgn;
	double ***a;
	double *t;
	int *ip;
	double *w;
};
typedef struct fft3d_arg_st fft3d_arg_t;


//   uses math library: (nothing)
//   uses static function:
//     *xdft3da_th
static void
xdft3da_subth(
 int n1, int n2, int n3, int icr, int isgn, 
 double ***a, double *t, int *ip, double *w)
{
	fft3d_thread_t th[FFT3D_MAX_THREADS];
	fft3d_arg_t ag[FFT3D_MAX_THREADS];
	int nthread, nt, i;
	
	nthread = FFT3D_MAX_THREADS;
	if (nthread > n1)
	{
		nthread = n1;
	}
	nt = 8 * n2;
	if (n3 == 4)
	{
		nt >>= 1;
	}
	else if (n3 < 4)
	{
		nt >>= 2;
	}
	for (i = 0; i < nthread; i++)
	{
		ag[i].nthread = nthread;
		ag[i].n0 = i;
		ag[i].n1 = n1;
		ag[i].n2 = n2;
		ag[i].n3 = n3;
		ag[i].ic = icr;
		ag[i].isgn = isgn;
		ag[i].a = a;
		ag[i].t = &t[nt * i];
		ag[i].ip = ip;
		ag[i].w = w;
		fft3d_thread_create(&th[i], xdft3da_th, &ag[i]);
	}
	for (i = 0; i < nthread; i++)
	{
		fft3d_thread_wait(th[i]);
	}
}


//   uses math library: (nothing)
//   uses static function:
//     *cdft3db_th
static void
cdft3db_subth(
 int n1, int n2, int n3, int isgn, double ***a, 
 double *t, int *ip, double *w)
{
	fft3d_thread_t th[FFT3D_MAX_THREADS];
	fft3d_arg_t ag[FFT3D_MAX_THREADS];
	int nthread, nt, i;
	
	nthread = FFT3D_MAX_THREADS;
	if (nthread > n2)
	{
		nthread = n2;
	}
	nt = 8 * n1;
	if (n3 == 4)
	{
		nt >>= 1;
	}
	else if (n3 < 4)
	{
		nt >>= 2;
	}
	for (i = 0; i < nthread; i++)
	{
		ag[i].nthread = nthread;
		ag[i].n0 = i;
		ag[i].n1 = n1;
		ag[i].n2 = n2;
		ag[i].n3 = n3;
		ag[i].isgn = isgn;
		ag[i].a = a;
		ag[i].t = &t[nt * i];
		ag[i].ip = ip;
		ag[i].w = w;
		fft3d_thread_create(&th[i], cdft3db_th, &ag[i]);
	}
	for (i = 0; i < nthread; i++)
	{
		fft3d_thread_wait(th[i]);
	}
}


//   uses math library: (nothing)
//   uses static function:
//     *ddxt3da_th
static void
ddxt3da_subth(
 int n1, int n2, int n3, int ics, int isgn, 
 double ***a, double *t, int *ip, double *w)
{
	fft3d_thread_t th[FFT3D_MAX_THREADS];
	fft3d_arg_t ag[FFT3D_MAX_THREADS];
	int nthread, nt, i;
	
	nthread = FFT3D_MAX_THREADS;
	if (nthread > n1)
	{
		nthread = n1;
	}
	nt = 4 * n2;
	if (n3 == 2)
	{
		nt >>= 1;
	}
	for (i = 0; i < nthread; i++)
	{
		ag[i].nthread = nthread;
		ag[i].n0 = i;
		ag[i].n1 = n1;
		ag[i].n2 = n2;
		ag[i].n3 = n3;
		ag[i].ic = ics;
		ag[i].isgn = isgn;
		ag[i].a = a;
		ag[i].t = &t[nt * i];
		ag[i].ip = ip;
		ag[i].w = w;
		fft3d_thread_create(&th[i], ddxt3da_th, &ag[i]);
	}
	for (i = 0; i < nthread; i++)
	{
		fft3d_thread_wait(th[i]);
	}
}


//   uses math library: (nothing)
//   uses static function:
//     *ddxt3db_th
static void
ddxt3db_subth(
 int n1, int n2, int n3, int ics, int isgn, 
 double ***a, double *t, int *ip, double *w)
{
	fft3d_thread_t th[FFT3D_MAX_THREADS];
	fft3d_arg_t ag[FFT3D_MAX_THREADS];
	int nthread, nt, i;
	
	nthread = FFT3D_MAX_THREADS;
	if (nthread > n2)
	{
		nthread = n2;
	}
	nt = 4 * n1;
	if (n3 == 2)
	{
		nt >>= 1;
	}
	for (i = 0; i < nthread; i++)
	{
		ag[i].nthread = nthread;
		ag[i].n0 = i;
		ag[i].n1 = n1;
		ag[i].n2 = n2;
		ag[i].n3 = n3;
		ag[i].ic = ics;
		ag[i].isgn = isgn;
		ag[i].a = a;
		ag[i].t = &t[nt * i];
		ag[i].ip = ip;
		ag[i].w = w;
		fft3d_thread_create(&th[i], ddxt3db_th, &ag[i]);
	}
	for (i = 0; i < nthread; i++)
	{
		fft3d_thread_wait(th[i]);
	}
}


//   uses math library: (nothing)
//   uses intern function:
//     cdft, rdft
static void *
xdft3da_th(void *p)
{
	int nthread, n0, n1, n2, n3, icr, isgn, *ip, i, j, k;
	double ***a, *t, *w;
	
	nthread = ((fft3d_arg_t *) p)->nthread;
	n0 = ((fft3d_arg_t *) p)->n0;
	n1 = ((fft3d_arg_t *) p)->n1;
	n2 = ((fft3d_arg_t *) p)->n2;
	n3 = ((fft3d_arg_t *) p)->n3;
	icr = ((fft3d_arg_t *) p)->ic;
	isgn = ((fft3d_arg_t *) p)->isgn;
	a = ((fft3d_arg_t *) p)->a;
	t = ((fft3d_arg_t *) p)->t;
	ip = ((fft3d_arg_t *) p)->ip;
	w = ((fft3d_arg_t *) p)->w;
	for (i = n0; i < n1; i += nthread)
	{
		if (icr == 0)
		{
			for (j = 0; j < n2; j++)
			{
				cdft(n3, isgn, a[i][j], ip, w);
			}
		}
		else if (isgn >= 0)
		{
			for (j = 0; j < n2; j++)
			{
				rdft(n3, isgn, a[i][j], ip, w);
			}
		}
		if (n3 > 4)
		{
			for (k = 0; k < n3; k += 8)
			{
				for (j = 0; j < n2; j++)
				{
					t[2 * j] = a[i][j][k];
					t[2 * j + 1] = a[i][j][k + 1];
					t[2 * n2 + 2 * j] = a[i][j][k + 2];
					t[2 * n2 + 2 * j + 1] = a[i][j][k + 3];
					t[4 * n2 + 2 * j] = a[i][j][k + 4];
					t[4 * n2 + 2 * j + 1] = a[i][j][k + 5];
					t[6 * n2 + 2 * j] = a[i][j][k + 6];
					t[6 * n2 + 2 * j + 1] = a[i][j][k + 7];
				}
				cdft(2 * n2, isgn, t, ip, w);
				cdft(2 * n2, isgn, &t[2 * n2], ip, w);
				cdft(2 * n2, isgn, &t[4 * n2], ip, w);
				cdft(2 * n2, isgn, &t[6 * n2], ip, w);
				for (j = 0; j < n2; j++)
				{
					a[i][j][k] = t[2 * j];
					a[i][j][k + 1] = t[2 * j + 1];
					a[i][j][k + 2] = t[2 * n2 + 2 * j];
					a[i][j][k + 3] = t[2 * n2 + 2 * j + 1];
					a[i][j][k + 4] = t[4 * n2 + 2 * j];
					a[i][j][k + 5] = t[4 * n2 + 2 * j + 1];
					a[i][j][k + 6] = t[6 * n2 + 2 * j];
					a[i][j][k + 7] = t[6 * n2 + 2 * j + 1];
				}
			}
		}
		else if (n3 == 4)
		{
			for (j = 0; j < n2; j++)
			{
				t[2 * j] = a[i][j][0];
				t[2 * j + 1] = a[i][j][1];
				t[2 * n2 + 2 * j] = a[i][j][2];
				t[2 * n2 + 2 * j + 1] = a[i][j][3];
			}
			cdft(2 * n2, isgn, t, ip, w);
			cdft(2 * n2, isgn, &t[2 * n2], ip, w);
			for (j = 0; j < n2; j++)
			{
				a[i][j][0] = t[2 * j];
				a[i][j][1] = t[2 * j + 1];
				a[i][j][2] = t[2 * n2 + 2 * j];
				a[i][j][3] = t[2 * n2 + 2 * j + 1];
			}
		}
		else if (n3 == 2)
		{
			for (j = 0; j < n2; j++)
			{
				t[2 * j] = a[i][j][0];
				t[2 * j + 1] = a[i][j][1];
			}
			cdft(2 * n2, isgn, t, ip, w);
			for (j = 0; j < n2; j++)
			{
				a[i][j][0] = t[2 * j];
				a[i][j][1] = t[2 * j + 1];
			}
		}
		if (icr != 0 && isgn < 0)
		{
			for (j = 0; j < n2; j++)
			{
				rdft(n3, isgn, a[i][j], ip, w);
			}
		}
	}
	return (void *) 0;
}


//   uses math library: (nothing)
//   uses intern function:
//     cdft
static void *
cdft3db_th(void *p)
{
	int nthread, n0, n1, n2, n3, isgn, *ip, i, j, k;
	double ***a, *t, *w;
	
	nthread = ((fft3d_arg_t *) p)->nthread;
	n0 = ((fft3d_arg_t *) p)->n0;
	n1 = ((fft3d_arg_t *) p)->n1;
	n2 = ((fft3d_arg_t *) p)->n2;
	n3 = ((fft3d_arg_t *) p)->n3;
	isgn = ((fft3d_arg_t *) p)->isgn;
	a = ((fft3d_arg_t *) p)->a;
	t = ((fft3d_arg_t *) p)->t;
	ip = ((fft3d_arg_t *) p)->ip;
	w = ((fft3d_arg_t *) p)->w;
	if (n3 > 4)
	{
		for (j = n0; j < n2; j += nthread)
		{
			for (k = 0; k < n3; k += 8)
			{
				for (i = 0; i < n1; i++)
				{
					t[2 * i] = a[i][j][k];
					t[2 * i + 1] = a[i][j][k + 1];
					t[2 * n1 + 2 * i] = a[i][j][k + 2];
					t[2 * n1 + 2 * i + 1] = a[i][j][k + 3];
					t[4 * n1 + 2 * i] = a[i][j][k + 4];
					t[4 * n1 + 2 * i + 1] = a[i][j][k + 5];
					t[6 * n1 + 2 * i] = a[i][j][k + 6];
					t[6 * n1 + 2 * i + 1] = a[i][j][k + 7];
				}
				cdft(2 * n1, isgn, t, ip, w);
				cdft(2 * n1, isgn, &t[2 * n1], ip, w);
				cdft(2 * n1, isgn, &t[4 * n1], ip, w);
				cdft(2 * n1, isgn, &t[6 * n1], ip, w);
				for (i = 0; i < n1; i++)
				{
					a[i][j][k] = t[2 * i];
					a[i][j][k + 1] = t[2 * i + 1];
					a[i][j][k + 2] = t[2 * n1 + 2 * i];
					a[i][j][k + 3] = t[2 * n1 + 2 * i + 1];
					a[i][j][k + 4] = t[4 * n1 + 2 * i];
					a[i][j][k + 5] = t[4 * n1 + 2 * i + 1];
					a[i][j][k + 6] = t[6 * n1 + 2 * i];
					a[i][j][k + 7] = t[6 * n1 + 2 * i + 1];
				}
			}
		}
	}
	else if (n3 == 4)
	{
		for (j = n0; j < n2; j += nthread)
		{
			for (i = 0; i < n1; i++)
			{
				t[2 * i] = a[i][j][0];
				t[2 * i + 1] = a[i][j][1];
				t[2 * n1 + 2 * i] = a[i][j][2];
				t[2 * n1 + 2 * i + 1] = a[i][j][3];
			}
			cdft(2 * n1, isgn, t, ip, w);
			cdft(2 * n1, isgn, &t[2 * n1], ip, w);
			for (i = 0; i < n1; i++)
			{
				a[i][j][0] = t[2 * i];
				a[i][j][1] = t[2 * i + 1];
				a[i][j][2] = t[2 * n1 + 2 * i];
				a[i][j][3] = t[2 * n1 + 2 * i + 1];
			}
		}
	}
	else if (n3 == 2)
	{
		for (j = n0; j < n2; j += nthread)
		{
			for (i = 0; i < n1; i++)
			{
				t[2 * i] = a[i][j][0];
				t[2 * i + 1] = a[i][j][1];
			}
			cdft(2 * n1, isgn, t, ip, w);
			for (i = 0; i < n1; i++)
			{
				a[i][j][0] = t[2 * i];
				a[i][j][1] = t[2 * i + 1];
			}
		}
	}
	return (void *) 0;
}


//   uses math library: (nothing)
//   uses intern function:
//     ddct, ddst
static void *
ddxt3da_th(void *p)
{
	int nthread, n0, n1, n2, n3, ics, isgn, *ip, i, j, k;
	double ***a, *t, *w;
	
	nthread = ((fft3d_arg_t *) p)->nthread;
	n0 = ((fft3d_arg_t *) p)->n0;
	n1 = ((fft3d_arg_t *) p)->n1;
	n2 = ((fft3d_arg_t *) p)->n2;
	n3 = ((fft3d_arg_t *) p)->n3;
	ics = ((fft3d_arg_t *) p)->ic;
	isgn = ((fft3d_arg_t *) p)->isgn;
	a = ((fft3d_arg_t *) p)->a;
	t = ((fft3d_arg_t *) p)->t;
	ip = ((fft3d_arg_t *) p)->ip;
	w = ((fft3d_arg_t *) p)->w;
	for (i = n0; i < n1; i += nthread)
	{
		if (ics == 0)
		{
			for (j = 0; j < n2; j++)
			{
				ddct(n3, isgn, a[i][j], ip, w);
			}
		}
		else
		{
			for (j = 0; j < n2; j++)
			{
				ddst(n3, isgn, a[i][j], ip, w);
			}
		}
		if (n3 > 2)
		{
			for (k = 0; k < n3; k += 4)
			{
				for (j = 0; j < n2; j++)
				{
					t[j] = a[i][j][k];
					t[n2 + j] = a[i][j][k + 1];
					t[2 * n2 + j] = a[i][j][k + 2];
					t[3 * n2 + j] = a[i][j][k + 3];
				}
				if (ics == 0)
				{
					ddct(n2, isgn, t, ip, w);
					ddct(n2, isgn, &t[n2], ip, w);
					ddct(n2, isgn, &t[2 * n2], ip, w);
					ddct(n2, isgn, &t[3 * n2], ip, w);
				}
				else
				{
					ddst(n2, isgn, t, ip, w);
					ddst(n2, isgn, &t[n2], ip, w);
					ddst(n2, isgn, &t[2 * n2], ip, w);
					ddst(n2, isgn, &t[3 * n2], ip, w);
				}
				for (j = 0; j < n2; j++)
				{
					a[i][j][k] = t[j];
					a[i][j][k + 1] = t[n2 + j];
					a[i][j][k + 2] = t[2 * n2 + j];
					a[i][j][k + 3] = t[3 * n2 + j];
				}
			}
		}
		else if (n3 == 2)
		{
			for (j = 0; j < n2; j++)
			{
				t[j] = a[i][j][0];
				t[n2 + j] = a[i][j][1];
			}
			if (ics == 0)
			{
				ddct(n2, isgn, t, ip, w);
				ddct(n2, isgn, &t[n2], ip, w);
			}
			else
			{
				ddst(n2, isgn, t, ip, w);
				ddst(n2, isgn, &t[n2], ip, w);
			}
			for (j = 0; j < n2; j++)
			{
				a[i][j][0] = t[j];
				a[i][j][1] = t[n2 + j];
			}
		}
	}
	return (void *) 0;
}


//   uses math library: (nothing)
//   uses intern function:
//     ddct, ddst
static void *
ddxt3db_th(void *p)
{
	int nthread, n0, n1, n2, n3, ics, isgn, *ip, i, j, k;
	double ***a, *t, *w;
	
	nthread = ((fft3d_arg_t *) p)->nthread;
	n0 = ((fft3d_arg_t *) p)->n0;
	n1 = ((fft3d_arg_t *) p)->n1;
	n2 = ((fft3d_arg_t *) p)->n2;
	n3 = ((fft3d_arg_t *) p)->n3;
	ics = ((fft3d_arg_t *) p)->ic;
	isgn = ((fft3d_arg_t *) p)->isgn;
	a = ((fft3d_arg_t *) p)->a;
	t = ((fft3d_arg_t *) p)->t;
	ip = ((fft3d_arg_t *) p)->ip;
	w = ((fft3d_arg_t *) p)->w;
	if (n3 > 2)
	{
		for (j = n0; j < n2; j += nthread)
		{
			for (k = 0; k < n3; k += 4)
			{
				for (i = 0; i < n1; i++)
				{
					t[i] = a[i][j][k];
					t[n1 + i] = a[i][j][k + 1];
					t[2 * n1 + i] = a[i][j][k + 2];
					t[3 * n1 + i] = a[i][j][k + 3];
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
					a[i][j][k] = t[i];
					a[i][j][k + 1] = t[n1 + i];
					a[i][j][k + 2] = t[2 * n1 + i];
					a[i][j][k + 3] = t[3 * n1 + i];
				}
			}
		}
	}
	else if (n3 == 2)
	{
		for (j = n0; j < n2; j += nthread)
		{
			for (i = 0; i < n1; i++)
			{
				t[i] = a[i][j][0];
				t[n1 + i] = a[i][j][1];
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
				a[i][j][0] = t[i];
				a[i][j][1] = t[n1 + i];
			}
		}
	}
	return (void *) 0;
}
#endif /* USE_FFT3D_THREADS */

