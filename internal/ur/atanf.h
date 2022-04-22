/*******************************************************************************
    GLUE Math Library: Arctangent (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_ATAN_FLT_INTERNAL
#define GML_ATAN_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "ur_atanf.h"

static inline float
atanf_core(register float x)
{
	return x != x ? x : ur_atanf(x);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ATAN_FLT_INTERNAL */
