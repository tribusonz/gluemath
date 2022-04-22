/*******************************************************************************
	GLUE-Math Library: Cosecant

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_CSC_DBL_INTERNAL
#define GML_CSC_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: sin()
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "sin.h"

static inline double
csc_core(register double x)
{
	register double y = 0;
	if (isfinite(y = sin_core(x)))
		return 1 / y;
	return x;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_CSC_DBL_INTERNAL */
