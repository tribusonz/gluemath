/*******************************************************************************
	GLUE-Math Library -- Error Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Calculation of Error Function
			by Kenta Kobayashi, Hitotsubashi University
*******************************************************************************/
#ifndef GML_ERF_CORE_DBL_INTERNAL
#define GML_ERF_CORE_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// Uses math library: fabs(), exp()
#include "../../sys/float/absolute.h"
#include "exp.h"

static inline double
ur_erf(register double x)
{
	static const double sqrt_pi  = 1.772453850905516027298167; /*$\sqrt{\pi}$*/
	static const double sqrt2    = 1.414213562373095048801688; /*$\sqrt{2}$*/
	static const double sqrt2fpi = 0.797884560802865355879892; /*$\sqrt{\frac{2}{\pi}}$*/
	register double absx;
	register double a, c, y;
	absx = fabs(x);
	if (absx < 2.4)
	{
		c = 1;
		a = 0;
		for(volatile int n = 1; n <= 40; n++)
		{
			a += x / (2 * n - 1) * c;
			c = -c * x * x / n;
		}
		return a * 2 / sqrt_pi;
	}
	else if (absx >= 2.4)
	{
		if (absx > 1.0E50)
			a = 1;
		else
		{
			y = absx * sqrt2;
			a = 0;
			for (volatile int n = 40; n >= 1; n--)
				a = n / (y + a);
			a = 1 - exp_core(-x * x) / (y + a) * sqrt2fpi;
		}
		return x < 0 ? -a : a;
	}
	return x; // NaN Handling
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ERF_CORE_DBL_INTERNAL */
