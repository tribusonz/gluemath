/*******************************************************************************
	GLUE-Math Library: atan2 (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ATAN2_LDBL_INTERNAL
#define GML_ATAN2_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "quadrantl.h"

static inline long double
atan2l_core(long double y, long double x)
{
	return quadrantl(x, y);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ATAN2_LDBL_INTERNAL */
