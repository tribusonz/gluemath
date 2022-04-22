/*******************************************************************************
	GLUE-Math Library: Hyperbolic Cotangent (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_COTH_FLT_INTERNAL
#define GML_COTH_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: expf()
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "expf.h"

static inline float
cothf_core(register float x)
{
	register float exppx, expmx;
	switch (fpclassify(exppx = expf_core(x))) {
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

#endif /* GML_COTH_FLT_INTERNAL */
