/*******************************************************************************
	GLUE-Math Library: log1p() function (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_LOG1P_FLT_INTERNAL
#define GML_LOG1P_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "logf.h"
#include "atanhf.h"

static inline float
log1pf_core(float x)
{
	if (x < 1)
		return 2 * atanhf_core(x / (2 + x));
	else if (x >= 1)
		return logf_core(1 + x);
	else
		return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_LOG1P_FLT_INTERNAL */
