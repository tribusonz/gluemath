/*******************************************************************************
	GLUE-Math Library -- Error Function (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Calculation of Error Function
			by Kenta Kobayashi, Hitotsubashi University
*******************************************************************************/
#ifndef GML_ERF_CORE_LDBL_INTERNAL
#define GML_ERF_CORE_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// Uses math library: fabsl(), expl(), sqrtl()
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/absolute.h"
#include "expl.h"
#include "sqrtl.h"
#include "m_pi.h"

static inline long double
ur_erfl(register long double x)
{
	static long double pi = 0;
	static long double sqrt_pi = 0;
	static long double sqrt2 = 0;
	static long double sqrt2fpi = 0;
	register long double absx;
	register long double a, c, y;
	volatile int n;
	static int check = 0;
	
	if (check == 0)
	{
		pi      = m_pi_ld();
		sqrt_pi = sqrtl_core(pi);
		sqrt2   = sqrtl_core(2);
		sqrt2fpi = sqrtl_core(2.0/pi);
		get_ldbl_info();
		check = 1;
	}
	
	absx = fabsl(x);
	if (absx < 2.4)
	{
		n = 1; c = 1; a = 0;
		do {
			a += x / (2 * n - 1) * c;
			if (fabsl(c) < ldbl_info.epsilon)  break;
			c = -c * x * x / n;
			n++;
		} while (1);
		return a * 2 / sqrt_pi;
	}
	else if (absx >= 2.4)
	{
		if ((c = expl_core(-x * x)) == 0.0)
			a = 1;
		else
		{
			y = absx * sqrt2;
			a = 0;
			for (volatile int n = 40; n >= 1; n--)
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

#endif /* GML_ERF_CORE_LDBL_INTERNAL */
