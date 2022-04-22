/*******************************************************************************
	GLUE-Math Library: Modf Function (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_MODF_LDBL_INTERNAL
#define GML_MODF_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: rcm2(), rcm10(), ldexp(), ipow()
#include "../../sys/float/absolute.h"
#include "../../sys/float/signbit.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "../sys/arch/rcm2l.h"
#include "../sys/arch/rcm10l.h"
#include "ldexpl.h"
#include "ur_ipowl.h"

static inline long double
modfl_core(register long double x, long double *ip)
{
	int base_exp = 0;
	register long double frac, eq, s;
	long double t;
	
	     if (isnan(x)) { *ip = x; return x; }
	else if (isinf(x)) { *ip = x; return 0; }
	else if (signbit(x))
	{
		frac = modfl_core(fabsl(x), &t);
		*ip = -t;
		return -frac;
	}
	else if (x >= 0 && x < 1)  { *ip = 0; return x; }
	
	frac = rcm2l_core(x, &base_exp); frac--;
	
	s = 0.L; t = 1.L / 2;

	for (volatile int i = 0; i < base_exp; i++)
	{
		if (frac >= (s + t))  s += t;
		if (s == frac)  break;
		t /= 2;
	}
	
	eq = ldexpl_core(1.L, base_exp);
	*ip = eq + eq * s;
	
	return s == frac ? 0.L : (frac - s) * eq;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_MODF_LDBL_INTERNAL */
