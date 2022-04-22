/*******************************************************************************
	GLUE-Math Library: Hyperbolic Cosecant (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_CSCH_FLT_INTERNAL
#define GML_CSCH_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: expf()
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "expf.h"

static inline float
cschf_core(register float x)
{
	register float exppx, expmx;
	switch (fpclassify(exppx = expf_core(x))) {
	case FP_NAN:
		break;
	case FP_INFINITE:
		return 0.0;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		return -0.0;
		break;
	default:
		expmx = 1 / exppx;
		return 2 / (exppx - expmx);
		break;
	}
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_CSCH_FLT_INTERNAL */
