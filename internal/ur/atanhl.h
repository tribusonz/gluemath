/*******************************************************************************
	GLUE-Math Library: Hyperbolic Argtangent (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ATANH_LDBL_INTERNAL
#define GML_ATANH_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: logl()
#include "../../sys/float/huge_val_nan.h"
#include "logl.h"

static inline long double
atanhl_core(register long double x)
{
	if (x >= -1.L && x <= 1.L)
	{
		if (x < 0) // -1.0 <= x <  0.0
			return 0.5L * ( logl_core(1 + x) - logl_core(1 - x));
		/* else */ //  0.0 <= x <= 1.0
			return 0.5L * (-logl_core(1 - x) + logl_core(1 + x));
	}
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ATANH_LDBL_INTERNAL */
