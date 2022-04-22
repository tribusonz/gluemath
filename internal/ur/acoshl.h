/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arccosine (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ACOSH_LDBL_INTERNAL
#define GML_ACOSH_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: asechl()
#include "asechl.h"

static inline long double
acoshl_core(register long double x)
{
	return asechl_core(1.L/x);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ACOSH_LDBL_INTERNAL */
