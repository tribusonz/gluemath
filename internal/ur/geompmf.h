/*******************************************************************************
	GLUE-Math Library: Geometric Distribution PMF

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_GEOMPMF_INTERNAL
#define GML_GEOMPMF_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "ur_ipow.h"

static inline double
geompmf_core(register int x, register double p)
{
	if (p >= 0 && p <= 1 && x >= 0)
		return p * ur_ipow(1 - p, x);
	return 0;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_GEOMPMF_INTERNAL */
