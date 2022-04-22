/*******************************************************************************
	GLUE-Math Library: Cosecant (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_CSC_FLT_INTERNAL
#define GML_CSC_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: sinf()
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "sinf.h"

static inline float
cscf_core(register float x)
{
	register float y = 0;
	if (isfinite(y = sinf_core(x)))
		return 1 / y;
	return x;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_CSC_FLT_INTERNAL */
