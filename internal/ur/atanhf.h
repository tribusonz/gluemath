/*******************************************************************************
	GLUE-Math Library: Hyperbolic Argtangent (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ATANH_FLT_INTERNAL
#define GML_ATANH_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: logf()
#include "../../sys/float/huge_val_nan.h"
#include "logf.h"

static inline float
atanhf_core(register float x)
{
	if (x >= -1.0 && x <= 1.0)
	{
		if (x < 0) // -1.0 <= x <  0.0
			return 0.5 * ( logf_core(1 + x) - logf_core(1 - x));
		/* else */ //  0.0 <= x <= 1.0
			return 0.5 * (-logf_core(1 - x) + logf_core(1 + x));
	}
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ATANH_FLT_INTERNAL */
