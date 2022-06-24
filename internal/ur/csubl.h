/*******************************************************************************
	GLUE-Math Library: Complex Subtraction (long double complex)

	Author: 
	  Haruhiko Okumura (Original Algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License:
	  GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_SUB_LDBLCMPLX_INTERNAL
#define GML_SUB_LDBLCMPLX_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/complex/class.h"

static inline lcomplex
csubl_core(lcomplex x, lcomplex y)
{
	x.real -= y.real;
	x.imag -= y.imag;
	return x;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_SUB_LDBLCMPLX_INTERNAL */
