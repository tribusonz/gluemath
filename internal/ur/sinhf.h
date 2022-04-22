/*******************************************************************************
	GLUE-Math Library: Hyperbolic Sine (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_SINH_FLT_INTERNAL
#define GML_SINH_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: expf()
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "expf.h"

static inline float
sinhf_core(register float x)
{
	register float exppx, expmx;
	switch (fpclassify(exppx = expf_core(x))) {
	case FP_NAN:
		break;
	case FP_INFINITE:
		return HUGE_VALF;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		return -HUGE_VALF;
		break;
	default:
		expmx = 1 / exppx;
		return (exppx - expmx) / 2;
		break;
	}
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_SINH_FLT_INTERNAL */
