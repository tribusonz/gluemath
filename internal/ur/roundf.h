/*******************************************************************************
	GLUE-Math Library: Rounding Off (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_ROUND_FLT_INTERNAL
#define GML_ROUND_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: rcm2f(), rcm10f(), ldexpf(), ipowf()
#include "../../sys/float/absolute.h"
#include "../../sys/float/signbit.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "../sys/arch/rcm2f.h"
#include "../sys/arch/rcm10f.h"
#include "ldexpf.h"
#include "ur_ipowf.h"

static inline float
roundf_core(register float x)
{
	int base_exp = 0, sign = 0;
	register float ip, frac, eq, s, t;
	
	if (isnan(x) || isinf(x))  return x;

	if (signbit(x))
	{
		if (x > -1)  return x < -0.5 ? -1.0 : -0.0;
		x = fabsf(x); sign = 1;
	}
	else
		if (x < 1)  return x < 0.5 ? 0.0 : 1.0;
	
	frac = rcm2f_core(x, &base_exp); frac--;
	
	s = 0.0; t = 1.0 / 2;

	for (volatile int i = 0; i < base_exp; i++)
	{
		if (frac >= (s + t))  s += t;
		if (s == frac)  break;
		t /= 2;
	}
	
	eq = ldexpf_core(1.0, base_exp);
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

#endif /* GML_ROUND_FLT_INTERNAL */
