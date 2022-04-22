/*******************************************************************************
	GLUE-Math Library: Fraction and Exponent (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_FREXP_LDBL_INTERNAL
#define GML_FREXP_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: (nothing)
#include "../sys/arch/rcm2l.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"

static inline long double
frexpl_core(register long double x, register int *k)
{
	register long double fra = rcm2l_core(x, k);
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

#endif /* GML_FREXP_LDBL_INTERNAL */
