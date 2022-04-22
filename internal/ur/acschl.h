/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arccosecant (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ACSCH_LDBL_INTERNAL
#define GML_ACSCH_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: asinhl()
#include "asinhl.h"

static inline long double
acschl_core(register long double x)
{
	return asinhl_core(1 / x);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ACSCH_LDBL_INTERNAL */
