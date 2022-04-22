/*******************************************************************************
    GLUE Math Library: Arctangent

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_ATAN_DBL_INTERNAL
#define GML_ATAN_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "ur_atan.h"

static inline double
atan_core(register double x)
{
	return x != x ? x : ur_atan(x);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ATAN_DBL_INTERNAL */
