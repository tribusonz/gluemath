/*******************************************************************************
    GLUE Math Library: Arctangent (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_ATAN_LDBL_INTERNAL
#define GML_ATAN_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "ur_atanl.h"

static inline long double
atanl_core(register long double x)
{
	return x != x ? x : ur_atanl(x);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ATAN_LDBL_INTERNAL */
