/*******************************************************************************
    GLUE Math Library: Arccosine

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_ACOS_DBL_INTERNAL
#define GML_ACOS_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: sqrt()
#include "../../sys/float/huge_val_nan.h"
#include "ur_atan.h"
#include "sqrt.h"

static inline double
acos_core(register double x)
{
	static const double PI2 = 1.570796326794896619231321;
	if (x >= -1.0 && x <= 1.0)
		return PI2 - ur_atan(x / sqrt_core(1 - x * x));
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ACOS_DBL_INTERNAL */
