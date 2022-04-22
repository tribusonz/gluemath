/*******************************************************************************
	GLUE-Math Library: Hyperbolic Cotangent

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_COTH_DBL_INTERNAL
#define GML_COTH_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: exp()
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "exp.h"

static inline double
coth_core(register double x)
{
	register double exppx, expmx;
	switch (fpclassify(exppx = exp_core(x))) {
	case FP_NAN:
		break;
	case FP_INFINITE:
		return 1.0;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		return -1.0;
		break;
	default:
		expmx = 1 / exppx;
		return (expmx + exppx) / (exppx - expmx);
		break;
	}
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_COTH_DBL_INTERNAL */
