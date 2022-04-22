/*******************************************************************************
	GLUE-Math Library: Secant

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_SEC_DBL_INTERNAL
#define GML_SEC_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: cos()
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "cos.h"

static inline double
sec_core(register double x)
{
	register double y = 0;
	if (isfinite(y = cos_core(x)))
		return 1 / y;
	return x;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_SEC_DBL_INTERNAL */
