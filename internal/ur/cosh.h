/*******************************************************************************
	GLUE-Math Library: Hyperbolic Cosine

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_COSH_DBL_INTERNAL
#define GML_COSH_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: exp()
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "exp.h"

static inline double
cosh_core(register double x)
{
	register double exppx, expmx;
	switch (fpclassify(exppx = exp_core(x))) {
	case FP_NAN:
		break;
	case FP_INFINITE:
	case FP_ZERO:
	case FP_SUBNORMAL:
		return HUGE_VAL;
		break;
	default:
		expmx = 1 / exppx;
		return (expmx + exppx) / 2;
		break;
	}
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_COSH_DBL_INTERNAL */
