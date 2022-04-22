/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arccosine

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ACOSH_DBL_INTERNAL
#define GML_ACOSH_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: asech()
#include "asech.h"

static inline double
acosh_core(register double x)
{
	return asech_core(1.0/x);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ACOSH_DBL_INTERNAL */
