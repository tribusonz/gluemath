/*******************************************************************************
	GLUE-Math Library -- Error Function (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Calculation of Error Function
			by Kenta Kobayashi, Hitotsubashi University
*******************************************************************************/
#ifndef GML_ERF_CORE_FLT_INTERNAL
#define GML_ERF_CORE_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// Uses math library: fabsf(), expf()
#include "../../sys/float/absolute.h"
#include "expf.h"

static inline float
ur_erff(register float x)
{
	static const float sqrt_pi  = 1.772453850905516027298167; /*$\sqrt{\pi}$*/
	static const float sqrt2    = 1.414213562373095048801688; /*$\sqrt{2}$*/
	static const float sqrt2fpi = 0.797884560802865355879892; /*$\sqrt{\frac{2}{\pi}}$*/
	register float absx;
	register float a, c, y;
	absx = fabsf(x);
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
			a = 1 - expf_core(-x * x) / (y + a) * sqrt2fpi;
		}
		return x < 0 ? -a : a;
	}
	return x; // NaN Handling
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ERF_CORE_FLT_INTERNAL */
