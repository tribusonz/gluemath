/*******************************************************************************
	GLUE-Math Library: IEEE-754 F.C.B.A.
	                   (Function Collection of Binary Arithmetic)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef IEEE754_UR_CEILING_B32_INTERNAL
#define IEEE754_UR_CEILING_B32_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "unionhack.h"

static inline float
ur_ceil_b32_core(float x)
{
	uflt_t u;
	int8_t bias;
	u.f = x;
	bias = (int8_t)(u.i >> 23) - 127;
	if (bias < 0)  return x == 0.0 ? 0 : 1;
	else if (bias >= 23)  return x;
	u.i = (u.i >> (23-bias) << (23-bias));
	return x == u.f ? x : ++u.f;
}

#if defined(__cplusplus)
}
#endif

#endif /* IEEE754_UR_CEILING_B32_INTERNAL */
