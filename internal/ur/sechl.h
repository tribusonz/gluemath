/*******************************************************************************
	GLUE-Math Library: Hyperbolic Secant (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_SECH_LDBL_INTERNAL
#define GML_SECH_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: expl()
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "expl.h"

static inline long double
sechl_core(register long double x)
{
	register long double exppx, expmx;
	switch (fpclassify(exppx = expl_core(x))) {
	case FP_NAN:
		break;
	case FP_INFINITE:
	case FP_ZERO:
	case FP_SUBNORMAL:
		return 0.L;
		break;
	default:
		expmx = 1 / exppx;
		return 2 / (expmx + exppx);
		break;
	}
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_SECH_LDBL_INTERNAL */
