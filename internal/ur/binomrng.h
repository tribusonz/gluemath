/*******************************************************************************
	GLUE-Math Library: R.N.G. -- Binomial Distribution

	Authors:
	  Barry Brown, James Lovato (Original FORTRAN77 version)
	  John Burkardt (C version, Modify)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License:
	  GPL + X11(MIT) (Part of modified)
	  John Burkardt's (Original source)
	Reference:
	  John Burkardt's Home Page
*******************************************************************************/
#ifndef GML_RNG_BINOM_INTERNAL
#define GML_RNG_BINOM_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdlib.h> // abs()
// uses math library: fmin(), fabs(), pow(), sqrt(), log()
#include "../../sys/float/comparable.h"
#include "../sys/primitive/float/comparable.h"
#include "../../sys/float/absolute.h"
#include "pow.h"
#include "sqrt.h"
#include "log.h"
#include "uniform.h"

static inline int binomrng_mean30(int, double, double, double);
static inline int binomrng_submain(int, double, double, double, double);

static inline int
binomrng_core(register int n, register double pp)
{
	register double p, q, xnp;

	// Donain error. For this inline, don't do exception-handling
	if (pp != pp || pp <= 0.0 || 1.0 <= pp || n < 1)
		return 0;

	p = fmin(pp, 1.0 - pp);
	q = 1.0 - p;
	xnp = (double)(n) * p;

	if (xnp < 30.0)  return binomrng_mean30(n, pp, p, q);
	return binomrng_submain(n, pp, p, q, xnp);
}

// Sub-main routine
static inline int
binomrng_submain(int n, double pp, double p, double q, double xnp)
{
	const double ffm  = xnp + p;
	const int    m    = ffm;
	const double fm   = m,
	             xnpq = xnp * q,
	             p1   = (int)(2.195 * sqrt_core(xnpq) - 4.6 * q) + 0.5,
	             xm   = fm + 0.5,
	             xl   = xm - p1,
	             xr   = xm + p1,
	             c    = 0.134 + 20.5 / (15.3 + fm),
	             al0  = (ffm - xl) / (ffm - xl * p),
	             xll  = al0 * (1.0 + 0.5 * al0),
	             al1  = (xr - ffm) / (xr * q),
	             xlr  = al1 * (1.0 + 0.5 * al1),
	             p2   = p1 * (1.0 + c + c),
	             p3   = p2 + c / xll,
	             p4   = p3 + c / xlr;
	int ix, k, value;

	/* Generate a variate. */
	for (;;)
	{
		const double u = uniform_core() * p4;
		double v = uniform_core();

		/* Triangle */
		if (u < p1)
		{
			ix = xm - p1 * v + u;
			if (0.5 < pp)  ix = n - ix;
			value = ix;
			return value;
		}

		/* Parallelogram */
		if (u <= p2)
		{
			const double x = xl + (u - p1) / c;
			v = v * c + 1.0 - fabs(xm - x) / p1;

			if (v <= 0.0 || 1.0 < v)  continue;
			ix = x;
		}
		else if (u <= p3)
		{
			ix = xl + log_core(v) / xll;
			if (ix < 0)  continue;

			v = v * (u - p2) * xll;
		}
		else
		{
			ix = xr - log_core(v) / xlr;
			if (n < ix)  continue;
			v = v * (u - p3) * xlr;
		}

		k = abs(ix - m);

		if (k <= 20 || xnpq / 2.0 - 1.0 <= k)
		{
			const double r = p / q,
			             g = (n + 1) * r;
			      double f = 1.0;

			if (m < ix)
			{
				const int mp = m + 1;
				for (volatile int i = mp; i <= ix; i++)
					f = f * (g / i - r);
			}
			else if (ix < m)
			{
				const int ix1 = ix + 1;
				for (volatile int i = ix1; i <= m; i++)
					f = f / (g / i - r);
			}

			if (v <= f)
			{
				if (0.5 < pp)  ix = n - ix;
				value = ix;
				return value;
			}
		}
		else
		{
			const double amaxp = (k / xnpq) * ((k * (k / 3.0
			                     + 0.625) + 0.1666666666666) / xnpq + 0.5),
			             ynorm = -(double)(k * k) / (2.0 * xnpq),
			             alv   = log_core(v);
			      double t;

			if (alv < ynorm - amaxp)
			{
				if (0.5 < pp)  ix = n - ix;
				value = ix;
				return value;
			}

			if (ynorm + amaxp < alv)  continue;

			do {
				const double x1 = (double)(ix + 1),
				             f1 = fm + 1.0,
				             z  = (double)(n + 1) - fm,
				             w  = (double)(n - ix + 1),
				             z2 = z * z,
				             x2 = x1 * x1,
				             f2 = f1 * f1,
				             w2 = w * w;

				t = xm * log_core(f1 / x1) + (n - m + 0.5) * log_core(z / w) 
					+ (double)(ix - m) * log_core(w * p / ( x1 * q ))
					+ (13860.0 - (462.0 - (132.0 - (99.0 - 140.0
					/ f2) / f2) / f2) / f2) / f1 / 166320.0
					+ (13860.0 - (462.0 - (132.0 - (99.0 - 140.0
					/ z2) / z2) / z2) / z2) / z / 166320.0
					+ (13860.0 - (462.0 - (132.0 - (99.0 - 140.0
					/ x2) / x2) / x2) / x2) / x1 / 166320.0
					+ (13860.0 - (462.0 - (132.0 - (99.0 - 140.0
					/ w2) / w2) / w2) / w2) / w / 166320.0;

				break;
			} while (1);

			if (alv <= t)
			{
				if (0.5 < pp)  ix = n - ix;
				value = ix;
				return value;
			}
		}
	}
	return value;
}


// np < 30
static inline int
binomrng_mean30(int n, double pp, double p, double q)
{
	const double qn = pow_core(q, n),
	             r  = p / q,
	             g  = r * (double)(n + 1);

	for (;;)
	{
		int    ix = 0;
		double f  = qn,
		       u  = uniform_core();
		for (;;)
		{
			if (u < f)
			{
				if (0.5 < pp)  ix = n - ix;
				return ix;
			}
			if (110 < ix)  break;
			u = u - f;
			ix = ix + 1;
			f = f * (g / (double)(ix) - r);
		}
	}
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_RNG_BINOM_INTERNAL */
