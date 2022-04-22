/*******************************************************************************
	GLUE-Math Library: Secant (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_SEC_LDBL_INTERNAL
#define GML_SEC_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: cosl()
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "cosl.h"

static inline long double
secl_core(register long double x)
{
	register long double y = 0;
	if (isfinite(y = cosl_core(x)))
		return 1.L / y;
	return x;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_SEC_LDBL_INTERNAL */
