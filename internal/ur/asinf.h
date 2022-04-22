/*******************************************************************************
    GLUE Math Library: Arcsine (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_ASIN_FLT_INTERNAL
#define GML_ASIN_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "ur_atanf.h"
#include "sqrtf.h"

static inline float
asinf_core(register float x)
{
	if (x >= -1.0 && x <= 1.0)
		return ur_atanf(x / sqrtf_core(1 - x * x));
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ASIN_FLT_INTERNAL */
