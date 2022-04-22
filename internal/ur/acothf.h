/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arccotangent (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ACOTH_FLT_INTERNAL
#define GML_ACOTH_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: log()
#include "logf.h"

static inline float
acothf_core(register float x)
{
	if (x != x)  return NAN;
	return 0.5 * logf_core(1/x+1) - 0.5 * logf_core(1-1/x);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ACOTH_FLT_INTERNAL */
