/*******************************************************************************
	GLUE-Math Library: IEEE-754 F.C.B.A.
	                   (Function Collection of Binary Arithmetic)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef IEEE754_ABSOLUTE_B64_INTERNAL
#define IEEE754_ABSOLUTE_B64_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "unionhack.h"

static inline double
abs_b64_core(double x)
{
	udbl_t u;
	static const uint64_t mask = 0x8000000000000000ULL;
	if (x != x)  return x;
	u.d = x;
	u.l = u.l & (~mask);
	return u.d;
}

#if defined(__cplusplus)
}
#endif

#endif /* IEEE754_ABSOLUTE_B64_INTERNAL */
