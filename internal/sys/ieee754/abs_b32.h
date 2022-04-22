/*******************************************************************************
	GLUE-Math Library: IEEE-754 F.C.B.A.
	                   (Function Collection of Binary Arithmetic)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef IEEE754_ABSOLUTE_B32_INTERNAL
#define IEEE754_ABSOLUTE_B32_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "unionhack.h"

static inline float
abs_b32_core(float x)
{
	uflt_t u;
	static const uint32_t mask = 0x80000000;
	if (x != x)  return x;
	u.f = x;
	u.i = u.i & (~mask);
	return u.f;
}

#if defined(__cplusplus)
}
#endif

#endif /* IEEE754_ABSOLUTE_B32_INTERNAL */
