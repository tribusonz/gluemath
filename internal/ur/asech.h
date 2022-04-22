/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arcsecant

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ASECH_DBL_INTERNAL
#define GML_ASECH_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: log(), sqrt()
#include "log.h"
#include "sqrt.h"

static inline double
asech_core(register double x)
{
	return log_core(sqrt_core(1/x-1)*sqrt_core(1/x+1)+1/x);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ASECH_DBL_INTERNAL */
