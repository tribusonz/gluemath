/*******************************************************************************
	GLUE-Math Library: Arccosecant

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ACSC_DBL_INTERNAL
#define GML_ACSC_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: asin()
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "asin.h"

static inline double
acsc_core(register double x)
{
	register double y;
	switch (fpclassify(x)) {
	case FP_NAN:
		break;
	case FP_INFINITE:
		return 0.0;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		break;
	default:
		y = 1 / x;
		if (y >= -1.0 && y <= 1.0)
			return asin_core(y);
		break;
	}
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ACSC_DBL_INTERNAL */
