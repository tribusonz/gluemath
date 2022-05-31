/*******************************************************************************
	Clenshaw-Curtis-Quadrature Numerical Automatic Integrator
*******************************************************************************/
#include "intcc.h"
#include "fft2f.h"
// uses math library: sqrt(), fabs()
// externing: dfct
#include <math.h>

void
intccini(int lenw, double *w)
{
	void dfct(int, double, double, double *);
	int j, k, l, m;
	double cos2, sin1, sin2, hl;
	
	cos2 = 0;
	sin1 = 1;
	sin2 = 1;
	hl = 0.5;
	k = lenw;
	l = 2;
	while (l < k - l - 1)
	{
		w[0] = hl * 0.5;
		for (j = 1; j <= l; j++)
			w[j] = hl / (1 - 4 * j * j);
		w[l] *= 0.5;
		dfct(l, 0.5 * cos2, sin1, w);
		cos2 = sqrt(2 + cos2);
		sin1 /= cos2;
		sin2 /= 2 + cos2;
		w[k] = sin2;
		w[k - 1] = w[0];
		w[k - 2] = w[l];
		k -= 3;
		m = l;
		while (m > 1)
		{
			m >>= 1;
			for (j = m; j <= l - m; j += (m << 1))
			{
				w[k] = w[j];
				k--;
			}
		}
		hl *= 0.5;
		l *= 2;
	}
}


void
intcc(
 double (*f)(double), double a, double b, double eps,
 int lenw, double *w, double *i, double *err)
{
	int j, k, l;
	double esf, eref, erefh, hh, ir, iback, irback, ba, ss, x, y, fx, 
		errir;
	
	esf = 10;
	ba = 0.5 * (b - a);
	ss = 2 * w[lenw];
	x = ba * w[lenw];
	w[0] = 0.5 * (*f)(a);
	w[3] = 0.5 * (*f)(b);
	w[2] = (*f)(a + x);
	w[4] = (*f)(b - x);
	w[1] = (*f)(a + ba);
	eref = 0.5 * (fabs(w[0]) + fabs(w[1]) + fabs(w[2]) +
	              fabs(w[3]) + fabs(w[4]));
	w[0] += w[3];
	w[2] += w[4];
	ir = w[0] + w[1] + w[2];
	*i = w[0] * w[lenw - 1] + w[1] * w[lenw - 2] + w[2] * w[lenw - 3];
	erefh = eref * sqrt(eps);
	eref *= eps;
	hh = 0.25;
	l = 2;
	k = lenw - 5;
	do {
		iback = *i;
		irback = ir;
		x = ba * w[k + 1];
		y = 0;
		*i = w[0] * w[k];
		for (j = 1; j <= l; j++)
		{
			x += y;
			y += ss * (ba - x);
			fx = (*f)(a + x) + (*f)(b - x);
			ir += fx;
			*i += w[j] * w[k - j] + fx * w[k - j - l];
			w[j + l] = fx;
		}
		ss = 2 * w[k + 1];
		*err = esf * l * fabs(*i - iback);
		hh *= 0.25;
		errir = hh * fabs(ir - 2 * irback);
		l *= 2;
		k -= l + 2;
	} while ((*err > erefh || errir > eref) && k > 4 * l);

	*i *= b - a;
	if (*err > erefh || errir > eref)
		*err *= -fabs(b - a);
	else
		*err = eref * fabs(b - a);

}

