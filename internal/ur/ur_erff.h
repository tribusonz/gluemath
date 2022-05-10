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
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
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
	static int check = 0;
	volatile int n;

	if (check == 0)  { get_flt_info(); check = 1; }

	absx = fabsf(x);
	if (absx < 2.4)
	{
		n = 1; c = 1; a = 0;
		do {
			a += x / (2 * n - 1) * c;
			if (fabsf(c) < flt_info.epsilon)  break;
			c = -c * x * x / n;
			n++;
		} while (1);
		return a * 2 / sqrt_pi;
	}
	else if (absx >= 2.4)
	{
		if ((c = expf_core(-x * x)) == 0.0)
			a = 1;
		else
		{
			y = absx * sqrt2;
			a = 0;
			for (n = 40; n >= 1; n--)
				a = n / (y + a);
			a = 1 - c / (y + a) * sqrt2fpi;
		}
		return x < 0 ? -a : a;
	}
	return x; // NaN Handling
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ERF_CORE_FLT_INTERNAL */
