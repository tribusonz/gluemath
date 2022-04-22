/*******************************************************************************
	GLUE-Math Library: Rounding Off (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_ROUND_LDBL_INTERNAL
#define GML_ROUND_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: rcm2l(), rcm10l(), ldexpl(), ipowl()
#include "../../sys/float/absolute.h"
#include "../../sys/float/signbit.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "../sys/arch/rcm2l.h"
#include "../sys/arch/rcm10l.h"
#include "ldexpl.h"
#include "ur_ipowl.h"

static inline long double
roundl_core(register long double x)
{
	int base_exp = 0, sign = 0;
	register long double ip, frac, eq, s, t;
	
	if (isnan(x) || isinf(x))  return x;

	if (signbit(x))
	{
		if (x > -1)  return x < -0.5 ? -1.L : -0.L;
		x = fabsl(x); sign = 1;
	}
	else
		if (x < 1)  return x < 0.5 ? 0.L : 1.L;
	
	frac = rcm2l_core(x, &base_exp); frac--;
	
	s = 0.0; t = 1.0 / 2;

	for (volatile int i = 0; i < base_exp; i++)
	{
		if (frac >= (s + t))  s += t;
		if (s == frac)  break;
		t /= 2;
	}
	
	eq = ldexpl_core(1.0, base_exp);
	ip = eq + eq * s;
	
	if (sign == 0)
		return (frac - s) * eq < 0.5 ? ip : ++ip;
	/* else if (sign == 1) */
		ip = -ip;
		return (frac - s) * eq <= 0.5 ? ip : --ip;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ROUND_LDBL_INTERNAL */
