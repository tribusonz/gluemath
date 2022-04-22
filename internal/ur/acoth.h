/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arccotangent

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ACOTH_DBL_INTERNAL
#define GML_ACOTH_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: log()
#include "log.h"

static inline double
acoth_core(register double x)
{
	if (x != x)  return NAN;
	return 0.5 * log_core(1/x+1) - 0.5 * log_core(1-1/x);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ACOTH_DBL_INTERNAL */
