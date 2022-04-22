/*******************************************************************************
	GLUE-Math Library: Fraction and Exponent (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_FREXP_FLT_INTERNAL
#define GML_FREXP_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: (nothing)
#include "../sys/arch/rcm2f.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"

static inline float
frexpf_core(register float x, register int *k)
{
	register float fra = rcm2f_core(x, k);
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

#endif /* GML_FREXP_FLT_INTERNAL */
