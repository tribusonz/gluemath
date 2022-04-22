/*******************************************************************************
	GLUE-Math Library: Hyperbolic Argtangent

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ATANH_DBL_INTERNAL
#define GML_ATANH_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: log()
#include "../../sys/float/huge_val_nan.h"
#include "log.h"

static inline double
atanh_core(register double x)
{
	if (x >= -1.0 && x <= 1.0)
	{
		if (x < 0) // -1.0 <= x <  0.0
			return 0.5 * ( log_core(1 + x) - log_core(1 - x));
		/* else */ //  0.0 <= x <= 1.0
			return 0.5 * (-log_core(1 - x) + log_core(1 + x));
	}
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ATANH_DBL_INTERNAL */
