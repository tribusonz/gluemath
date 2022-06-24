/*******************************************************************************
	GLUE-Math Library: Complex Multiplication (long double complex)

	Author: 
	  Haruhiko Okumura (Original Algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License:
	  GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_MUL_LDBLCMPLX_INTERNAL
#define GML_MUL_LDBLCMPLX_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/complex/class.h"

static inline lcomplex
cmull_core(lcomplex x, lcomplex y)
{
	lcomplex z;

	z.real = x.real * y.real - x.imag * y.imag;
	z.imag = x.real * y.imag + x.imag * y.real;
	return z;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_MUL_LDBLCMPLX_INTERNAL */
