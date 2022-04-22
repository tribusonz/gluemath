/*******************************************************************************
	GLUE-Math Library: IEEE-754 F.C.B.A.
	                   (Function Collection of Binary Arithmetic)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef IEEE754_SIGNBIT_B64_INTERNAL
#define IEEE754_SIGNBIT_B64_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "unionhack.h"

static inline int
signbit_b64_core(double x)
{
	udbl_t u;
	u.d = x;
	return x == x && (u.l >> 63);
}

#if defined(__cplusplus)
}
#endif

#endif /* IEEE754_SIGNBIT_B64_INTERNAL */
