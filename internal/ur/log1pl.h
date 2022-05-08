/*******************************************************************************
	GLUE-Math Library: log1p() function (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_LOG1P_LDBL_INTERNAL
#define GML_LOG1P_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "logl.h"
#include "atanhl.h"

static inline long double
log1pl_core(long double x)
{
	if (x < 1)
		return 2 * atanhl_core(x / (2 + x));
	else if (x >= 1)
		return logl_core(1 + x);
	else
		return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_LOG1P_LDBL_INTERNAL */
