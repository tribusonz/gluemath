/*******************************************************************************
	GLUE-Math Library: Secant (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_SEC_FLT_INTERNAL
#define GML_SEC_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: cosf()
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "cosf.h"

static inline float
secf_core(register float x)
{
	register float y = 0;
	if (isfinite(y = cosf_core(x)))
		return 1 / y;
	return x;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_SEC_FLT_INTERNAL */
