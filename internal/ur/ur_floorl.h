/*******************************************************************************
	GLUE-Math Library: Floor Function (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_UR_FLOOR_LDBL_INTERNAL
#define GML_UR_FLOOR_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: rcm2l(), rcm10l(), ldexpl(), ipowl()
#include "../sys/arch/rcm2l.h"
#include "../sys/arch/rcm10l.h"
#include "ldexpl.h"
#include "ur_ipowl.h"

static inline long double
ur_floorl(register long double x)
{
	int base_exp = 0;
	register long double frac, eq, s, t;
	
	if (x < 2)
		return (long double)(int)x;
	
	frac = rcm2l_core(x, &base_exp); frac--;
	
	s = 0.0; t = 1.L / 2;

	for (volatile int i = 0; i < base_exp; i++)
	{
		if (frac >= (s + t))  s += t;
		if (s == frac)  break;
		t /= 2;
	}

	eq = ldexpl_core(1.0, base_exp);

	return eq + eq * s;
}


#if defined(__cplusplus)
}
#endif

#endif /* GML_UR_FLOOR_LDBL_INTERNAL */

