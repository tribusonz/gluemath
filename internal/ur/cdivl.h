/*******************************************************************************
	GLUE-Math Library: Complex Division (long double complex)

	Author: 
	  Haruhiko Okumura (Original Algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License:
	  GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_DIV_LDBLCMPLX_INTERNAL
#define GML_DIV_LDBLCMPLX_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/complex/class.h"
#include "../../sys/float/absolute.h"

static inline lcomplex
cdivl_core(lcomplex x, lcomplex y)
{
	long double w, d;
	lcomplex z;

	if (fabsl(y.real) >= fabsl(y.imag))
	{
		w = y.imag / y.real;  d = y.real + y.imag * w;
		z.real = (x.real + x.imag * w) / d;
		z.imag = (x.imag - x.real * w) / d;
	}
	else
	{
		w = y.real / y.imag;  d = y.real * w + y.imag;
		z.real = (x.real * w + x.imag) / d;
		z.imag = (x.imag * w - x.real) / d;
	}
	return z;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_DIV_LDBLCMPLX_INTERNAL */
