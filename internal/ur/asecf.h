/*******************************************************************************
	GLUE-Math Library: Arcsecant (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ASEC_FLT_INTERNAL
#define GML_ASEC_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: acosf()
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "acosf.h"

static inline float
asecf_core(register float x)
{
	register float y;
	switch (fpclassify(x)) {
	case FP_NAN:
		break;
	case FP_INFINITE:
		return acosf_core(0);
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		break;
	default:
		y = 1 / x;
		if (y >= -1.0 && y <= 1.0)
			return acosf_core(y);
		break;
	}
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ASEC_FLT_INTERNAL */
