/*******************************************************************************
	GLUE-Math Library: Arccosecant (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ACSC_LDBL_INTERNAL
#define GML_ACSC_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: asinl()
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "asinl.h"

static inline long double
acscl_core(register long double x)
{
	register long double y;
	switch (fpclassify(x)) {
	case FP_NAN:
		break;
	case FP_INFINITE:
		return 0.L;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		break;
	default:
		y = 1 / x;
		if (y >= -1.L && y <= 1.L)
			return asinl_core(y);
		break;
	}
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ACSC_DBL_INTERNAL */
