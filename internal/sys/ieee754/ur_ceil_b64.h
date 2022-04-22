/*******************************************************************************
	GLUE-Math Library: IEEE-754 F.C.B.A.
	                   (Function Collection of Binary Arithmetic)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef IEEE754_UR_CEILING_B64_INTERNAL
#define IEEE754_UR_CEILING_B64_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "unionhack.h"

static inline double
ur_ceil_b64_core(double x)
{
	udbl_t u;
	int16_t bias;
	u.d = x;
	u.l = ((u.l << 1) >> 1);
	bias = (int16_t)(u.l >> 52) - 1023;
	if (bias < 0)  return x == 0.0 ? 0 : 1;
	else if (bias >= 52)  return x;
	u.l = (u.l >> (52-bias) << (52-bias));
	return x == u.d ? x : ++u.d;
}

#if defined(__cplusplus)
}
#endif

#endif /* IEEE754_UR_CEILING_B64_INTERNAL */
