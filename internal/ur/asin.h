/*******************************************************************************
    GLUE Math Library: Arcsine

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_ASIN_DBL_INTERNAL
#define GML_ASIN_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "ur_atan.h"
#include "sqrt.h"

static inline double
asin_core(register double x)
{
	if (x >= -1.0 && x <= 1.0)
		return ur_atan(x / sqrt_core(1 - x * x));
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ASIN_DBL_INTERNAL */
