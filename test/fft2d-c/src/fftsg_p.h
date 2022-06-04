/*******************************************************************************
Fast Fourier/Cosine/Sine Transform subroutines
*******************************************************************************/
#ifndef FFTSG_PRIVATE_H
#define FFTSG_PRIVATE_H

#if defined(__cplusplus)
extern "C" {
#endif

/* -------- initializing routines -------- */

#include <math.h> // sin, cos, atan

static inline void makeipt(int nw, int *ip);


//   uses math library: sin, cos, atan
//   uses static function:
//     makeipt
static inline void
makewt(int nw, int *ip, double *w)
{
	int j, nwh, nw0, nw1;
	double delta, wn4r, wk1r, wk1i, wk3r, wk3i;
	
	ip[0] = nw;
	ip[1] = 1;
	if (nw > 2)
	{
		nwh = nw >> 1;
		delta = atan(1.0) / nwh;
		wn4r = cos(delta * nwh);
		w[0] = 1;
		w[1] = wn4r;
		if (nwh == 4)
		{
			w[2] = cos(delta * 2);
			w[3] = sin(delta * 2);
		}
		else if (nwh > 4)
		{
			makeipt(nw, ip);
			w[2] = 0.5 / cos(delta * 2);
			w[3] = 0.5 / cos(delta * 6);
			for (j = 4; j < nwh; j += 4)
			{
				w[j] = cos(delta * j);
				w[j + 1] = sin(delta * j);
				w[j + 2] = cos(3 * delta * j);
				w[j + 3] = -sin(3 * delta * j);
			}
		}
		nw0 = 0;
		while (nwh > 2)
		{
			nw1 = nw0 + nwh;
			nwh >>= 1;
			w[nw1] = 1;
			w[nw1 + 1] = wn4r;
			if (nwh == 4)
			{
				wk1r = w[nw0 + 4];
				wk1i = w[nw0 + 5];
				w[nw1 + 2] = wk1r;
				w[nw1 + 3] = wk1i;
			}
			else if (nwh > 4)
			{
				wk1r = w[nw0 + 4];
				wk3r = w[nw0 + 6];
				w[nw1 + 2] = 0.5 / wk1r;
				w[nw1 + 3] = 0.5 / wk3r;
				for (j = 4; j < nwh; j += 4)
				{
					wk1r = w[nw0 + 2 * j];
					wk1i = w[nw0 + 2 * j + 1];
					wk3r = w[nw0 + 2 * j + 2];
					wk3i = w[nw0 + 2 * j + 3];
					w[nw1 + j] = wk1r;
					w[nw1 + j + 1] = wk1i;
					w[nw1 + j + 2] = wk3r;
					w[nw1 + j + 3] = wk3i;
				}
			}
			nw0 = nw1;
		}
	}
}


//   uses math library: (nothing)
//   uses static function: (nothing)
static inline void
makeipt(int nw, int *ip)
{
	int j, l, m, m2, p, q;
	
	ip[2] = 0;
	ip[3] = 16;
	m = 2;
	for (l = nw; l > 32; l >>= 2)
	{
		m2 = m << 1;
		q = m2 << 3;
		for (j = m; j < m2; j++)
		{
			p = ip[j] << 2;
			ip[m + j] = p;
			ip[m2 + j] = p + q;
		}
		m = m2;
	}
}


//   uses math library: sin, cos, atan
//   uses static function: (nothing)
static inline void
makect(int nc, int *ip, double *c)
{
	int j, nch;
	double delta;
	
	ip[1] = nc;
	if (nc > 1)
	{
		nch = nc >> 1;
		delta = atan(1.0) / nch;
		c[0] = cos(delta * nch);
		c[nch] = 0.5 * c[0];
		for (j = 1; j < nch; j++)
		{
			c[j] = 0.5 * cos(delta * j);
			c[nc - j] = 0.5 * sin(delta * j);
		}
	}
}


#if defined(__cplusplus)
}
#endif

#endif /* FFTSG_PRIVATE_H */
