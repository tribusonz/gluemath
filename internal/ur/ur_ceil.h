/*******************************************************************************
	GLUE-Math Library: Ceiling Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_UR_CEIL_DBL_INTERNAL
#define GML_UR_CEIL_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: rcm2(), rcm10(), ldexp(), ipow()
#include "../sys/arch/rcm2.h"
#include "../sys/arch/rcm10.h"
#include "ldexp.h"
#include "ur_ipow.h"

static inline double
ur_ceil(register double x)
{
	int base_exp = 0;
	register double frac, eq, s, t;
	
	if (x < 2)
		return (int)x == x ? x : (double)(int)(x + 1);
	
	frac = rcm2_core(x, &base_exp); frac--;
	
	s = 0.0; t = 1.0 / 2;

	for (volatile int i = 0; i < base_exp; i++)
	{
		if (frac >= (s + t))  s += t;
		if (s == frac)  break;
		t /= 2;
	}

	eq = ldexp_core(1.0, base_exp);

	return s == frac ? eq + eq * s : eq + eq * (s + 1.0 / eq);
}


#if defined(__cplusplus)
}
#endif

#endif /* GML_UR_CEIL_DBL_INTERNAL */

