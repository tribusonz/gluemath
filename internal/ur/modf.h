/*******************************************************************************
	GLUE-Math Library: Modf Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_MODF_DBL_INTERNAL
#define GML_MODF_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: rcm2(), rcm10(), ldexp(), ipow()
#include "../../sys/float/absolute.h"
#include "../../sys/float/signbit.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "../sys/arch/rcm2.h"
#include "../sys/arch/rcm10.h"
#include "ldexp.h"
#include "ur_ipow.h"

static inline double
modf_core(register double x, double *ip)
{
	int base_exp = 0;
	register double frac, eq, s;
	double t;
	
	     if (isnan(x)) { *ip = x; return x; }
	else if (isinf(x)) { *ip = x; return 0; }
	else if (signbit(x))
	{
		frac = modf_core(fabs(x), &t);
		*ip = -t;
		return -frac;
	}
	else if (x >= 0 && x < 1)  { *ip = 0; return x; }
	
	frac = rcm2_core(x, &base_exp); frac--;
	
	s = 0.0; t = 1.0 / 2;

	for (volatile int i = 0; i < base_exp; i++)
	{
		if (frac >= (s + t))  s += t;
		if (s == frac)  break;
		t /= 2;
	}
	
	eq = ldexp_core(1.0, base_exp);
	*ip = eq + eq * s;
	
	return s == frac ? 0.0 : (frac - s) * eq;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_MODF_DBL_INTERNAL */
