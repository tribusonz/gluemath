/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arccosecant

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ACSCH_DBL_INTERNAL
#define GML_ACSCH_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: asinh()
#include "asinh.h"

static inline double
acsch_core(register double x)
{
	return asinh_core(1 / x);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ACSCH_DBL_INTERNAL */
