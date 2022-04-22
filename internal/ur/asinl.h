/*******************************************************************************
    GLUE Math Library: Arcsine (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_ASIN_LDBL_INTERNAL
#define GML_ASIN_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "ur_atanl.h"
#include "sqrtl.h"

static inline long double
asinl_core(register long double x)
{
	if (x >= -1.L && x <= 1.L)
		return ur_atanl(x / sqrtl_core(1.L - x * x));
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ASIN_LDBL_INTERNAL */
