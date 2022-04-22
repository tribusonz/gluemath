/*******************************************************************************
	GLUE-Math Library: IEEE-754 F.C.B.A.
	                   (Function Collection of Binary Arithmetic)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef IEEE754_FLOOR_B32_INTERNAL
#define IEEE754_FLOOR_B32_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "ur_floor_b32.h"
#include "ur_ceil_b32.h"

static inline float
floor_b32_core(float x)
{
	return x != x ? x : x < 0 ? -ur_ceil_b32(-x) : ur_floor_b32(x);
}


#if defined(__cplusplus)
}
#endif

#endif /* IEEE754_FLOOR_B32_INTERNAL */
