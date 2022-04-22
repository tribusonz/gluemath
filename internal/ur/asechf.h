/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arcsecant (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ASECH_FLT_INTERNAL
#define GML_ASECH_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: logf(), sqrtf()
#include "logf.h"
#include "sqrtf.h"

static inline float
asechf_core(register float x)
{
	return logf_core(sqrtf_core(1/x-1)*sqrtf_core(1/x+1)+1/x);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ASECH_FLT_INTERNAL */
