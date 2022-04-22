/*******************************************************************************
	GLUE-Math Library: Arcsecant (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ASEC_LDBL_INTERNAL
#define GML_ASEC_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: acos()
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "acosl.h"

static inline long double
asecl_core(register long double x)
{
	register long double y;
	switch (fpclassify(x)) {
	case FP_NAN:
		break;
	case FP_INFINITE:
		return acosl_core(0);
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		break;
	default:
		y = 1 / x;
		if (y >= -1.0 && y <= 1.0)
			return acosl_core(y);
		break;
	}
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ASEC_LDBL_INTERNAL */
