/*******************************************************************************
	GLUE-Math Library: expm1() (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_EXPM1_FLT_INTERNAL
#define GML_EXPM1_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "expf.h"
#include "sinhf.h"

static inline float
expm1f_core(float x)
{
	if (x != x)  return x;
	return 2 * expf_core(x / 2) * sinhf_core(x / 2);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_EXPM1_FLT_INTERNAL */

