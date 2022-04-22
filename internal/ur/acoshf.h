/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arccosine (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ACOSH_FLT_INTERNAL
#define GML_ACOSH_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: asechf()
#include "asechf.h"

static inline float
acoshf_core(register float x)
{
	return asechf_core(1.0/x);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ACOSH_FLT_INTERNAL */
