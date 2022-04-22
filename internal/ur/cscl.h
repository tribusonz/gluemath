/*******************************************************************************
	GLUE-Math Library: Cosecant (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_CSC_LDBL_INTERNAL
#define GML_CSC_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: sinl()
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "sinl.h"

static inline long double
cscl_core(register long double x)
{
	register long double y = 0;
	if (isfinite(y = sinl_core(x)))
		return 1 / y;
	return x;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_CSC_LDBL_INTERNAL */
