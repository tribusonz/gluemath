/*******************************************************************************
	GLUE-Math Library: Complex Exponential Function (float)

	Author:
	  Hironobu Inatsuka aka tribusonz
	License:
	  GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_EXP_FLTCMPLX_INTERNAL
#define GML_EXP_FLTCMPLX_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "expf.h"
#include "sinf.h"
#include "cosf.h"

static inline fcomplex
cexpf_core(fcomplex z)
{
	double a = expf_core(z.real);
	switch (fpclassify(z.imag)) {
	case FP_NAN:
		z.real = NAN; z.imag = NAN;
		return z;
		break;
	case FP_INFINITE:
		if (z.imag < 0)  z.real = NAN;
		else             z.real = HUGE_VALF;
		return z;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		z.real = a;
		z.imag = 0;
		return z;
		break;
	default:
		z.real = a * cosf_core(z.imag);
		z.imag = a * sinf_core(z.imag);
		return z;
		break;
	}
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_EXP_FLTCMPLX_INTERNAL */
