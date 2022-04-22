/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arccosecant (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ACSCH_FLT_INTERNAL
#define GML_ACSCH_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: asinhf()
#include "asinhf.h"

static inline float
acschf_core(register float x)
{
	return asinhf_core(1 / x);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ACSCH_FLT_INTERNAL */
