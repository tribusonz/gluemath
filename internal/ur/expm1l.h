/*******************************************************************************
	GLUE-Math Library: expm1() (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_EXPM1_LDBL_INTERNAL
#define GML_EXPM1_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "expl.h"
#include "sinhl.h"

static inline long double
expm1l_core(long double x)
{
	if (x != x)  return x;
	return 2 * expl_core(x / 2) * sinhl_core(x / 2);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_EXPM1_LDBL_INTERNAL */
