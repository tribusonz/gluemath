/*******************************************************************************
	GLUE-Math Library: atan2

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ATAN2_DBL_INTERNAL
#define GML_ATAN2_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "quadrant.h"

static inline double
atan2_core(double y, double x)
{
	return quadrant(x, y);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ATAN2_DBL_INTERNAL */
