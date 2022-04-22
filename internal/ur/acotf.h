/*******************************************************************************
    GLUE Math Library: Arccotangent (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_ACOT_FLT_INTERNAL
#define GML_ACOT_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "ur_atanf.h"

static inline float
acotf_core(register float x)
{
	return x != x ? x : ur_atanf(1/x);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ACOT_FLT_INTERNAL */
