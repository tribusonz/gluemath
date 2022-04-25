/*******************************************************************************
	GLUE-Math Library: Complex Exponential Function

	Author:
	  Hironobu Inatsuka aka tribusonz
	License:
	  GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_EXP_DBLCMPLX_INTERNAL
#define GML_EXP_DBLCMPLX_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "exp.h"
#include "sin.h"
#include "cos.h"

static inline dcomplex
cexp_core(dcomplex z)
{
	double a = exp_core(z.real);
	switch (fpclassify(z.imag)) {
	case FP_NAN:
		z.real = NAN; z.imag = NAN;
		return z;
		break;
	case FP_INFINITE:
		if (z.imag < 0)  z.real = NAN;
		else             z.real = HUGE_VAL;
		return z;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		z.real = a;
		z.imag = 0;
		return z;
		break;
	default:
		z.real = a * cos_core(z.imag);
		z.imag = a * sin_core(z.imag);
		return z;
		break;
	}
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_EXP_DBLCMPLX_INTERNAL */
