/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arccotangent (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ACOTH_LDBL_INTERNAL
#define GML_ACOTH_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: logl()
#include "logl.h"

static inline long double
acothl_core(register long double x)
{
	if (x != x)  return NAN;
	return 0.5L * logl_core(1.L/x+1) - 0.5L * logl_core(1.L-1/x);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ACOTH_LDBL_INTERNAL */
