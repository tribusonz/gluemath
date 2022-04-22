/*******************************************************************************
	GLUE-Math Library: Hyperbolic Tangent (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_TANH_FLT_INTERNAL
#define GML_TANH_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: expf()
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "expf.h"

static inline float
tanhf_core(register float x)
{
	register float exppx, expmx, t;
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
		t = expmx + exppx;
		return exppx / t - expmx / t;
		break;
	}
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_TANH_FLT_INTERNAL */
