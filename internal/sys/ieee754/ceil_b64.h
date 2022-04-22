/*******************************************************************************
	GLUE-Math Library: IEEE-754 F.C.B.A.
	                   (Function Collection of Binary Arithmetic)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef IEEE754_CEILING_B64_INTERNAL
#define IEEE754_CEILING_B64_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "ur_floor_b64.h"
#include "ur_ceil_b64.h"

static inline double
ceil_b64_core(double x)
{
	return x != x ? x : x < 0 ? -ur_floor_b64(-x) : ur_ceil_b64(x);
}

#if defined(__cplusplus)
}
#endif

#endif /* IEEE754_CEILING_B32_INTERNAL */
