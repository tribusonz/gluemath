/*******************************************************************************
	GLUE-Math Library: Complex Exponential Function (long double)

	Author:
	  Hironobu Inatsuka aka tribusonz
	License:
	  GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_EXP_LDBLCMPLX_INTERNAL
#define GML_EXP_LDBLCMPLX_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "expl.h"
#include "sinl.h"
#include "cosl.h"

static inline lcomplex
cexpl_core(lcomplex z)
{
	long double a = expl_core(z.real);
	switch (fpclassify(z.imag)) {
	case FP_NAN:
		z.real = NAN; z.imag = NAN;
		return z;
		break;
	case FP_INFINITE:
		if (z.imag < 0)  z.real = NAN;
		else             z.real = HUGE_VALL;
		return z;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		z.real = a;
		z.imag = 0;
		return z;
		break;
	default:
		z.real = a * cosl_core(z.imag);
		z.imag = a * sinl_core(z.imag);
		return z;
		break;
	}
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_EXP_LDBLCMPLX_INTERNAL */
