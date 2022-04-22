/*******************************************************************************
    GLUE Math Library: Arccosine (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_ACOS_FLT_INTERNAL
#define GML_ACOS_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: sqrtf()
#include "../../sys/float/huge_val_nan.h"
#include "ur_atanf.h"
#include "sqrtf.h"

static inline float
acosf_core(register float x)
{
	static const float PI2 = 1.570796326794896619231321;
	if (x >= -1.0 && x <= 1.0)
		return PI2 - ur_atanf(x / sqrtf_core(1 - x * x));
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ACOS_FLT_INTERNAL */
