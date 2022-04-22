/*******************************************************************************
	GLUE-Math Complex Primitive: Conjugate

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_COMPLEX_ABSOLUTE
#define GML_COMPLEX_ABSOLUTE

#if defined(__cplusplus)
extern "C" {
#endif

#include "class.h"

static inline fcomplex
fc_conj(fcomplex z)
{
	z.imag = -z.imag;
	return z;
}

static inline dcomplex
dc_conj(dcomplex z)
{
	z.imag = -z.imag;
	return z;
}

static inline lcomplex
lc_conj(lcomplex z)
{
	z.imag = -z.imag;
	return z;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_COMPLEX_ABSOLUTE */

