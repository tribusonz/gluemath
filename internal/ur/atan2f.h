/*******************************************************************************
	GLUE-Math Library: atan2 (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ATAN2_FLT_INTERNAL
#define GML_ATAN2_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "quadrantf.h"

static inline float
atan2f_core(float y, float x)
{
	return quadrantf(x, y);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ATAN2_FLT_INTERNAL */
