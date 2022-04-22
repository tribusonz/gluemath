/*******************************************************************************
	GLUE-Math Library: Fraction and Exponent

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_FREXP_DBL_INTERNAL
#define GML_FREXP_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: (nothing)
#include "../sys/arch/rcm2.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"

static inline double
frexp_core(register double x, register int *k)
{
	register double fra = rcm2_core(x, k);
	switch (fpclassify(fra)) {
	case FP_NAN:
	case FP_INFINITE:
	case FP_ZERO:
		*k = 0;
		return fra;
		break;
	default:
		(*k) = (*k) + 1;
		return fra / 2;
		break;
	}
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_FREXP_DBL_INTERNAL */
