/*******************************************************************************
	GLUE-Math Library: Floor Function (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_UR_FLOOR_FLT_INTERNAL
#define GML_UR_FLOOR_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: rcm2f(), rcm10f(), ldexpf(), ipowf()
#include "../sys/arch/rcm2f.h"
#include "../sys/arch/rcm10f.h"
#include "ldexpf.h"
#include "ur_ipowf.h"

static inline float
ur_floorf(register float x)
{
	int base_exp = 0;
	register float frac, eq, s, t;
	
	if (x < 2)
		return (float)(int)x;
	
	frac = rcm2f_core(x, &base_exp); frac--;
	
	s = 0.0; t = 1.0 / 2;

	for (volatile int i = 0; i < base_exp; i++)
	{
		if (frac >= (s + t))  s += t;
		if (s == frac)  break;
		t /= 2;
	}

	eq = ldexpf_core(1.0, base_exp);

	return eq + eq * s;
}


#if defined(__cplusplus)
}
#endif

#endif /* GML_UR_FLOOR_FLT_INTERNAL */

