/*******************************************************************************
	GLUE-Math Library: expm1()

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_EXPM1_DBL_INTERNAL
#define GML_EXPM1_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "exp.h"
#include "sinh.h"

static inline double
expm1_core(double x)
{
	if (x != x)  return x;
	return 2 * exp_core(x / 2) * sinh_core(x / 2);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_EXPM1_DBL_INTERNAL */

