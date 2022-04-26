/*******************************************************************************
	GLUE-Math Complex Primitive Setting: Unary operator

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_COMPLEX_PRIMITIVE_UNARY_OPERATOR_H
#define GML_COMPLEX_PRIMITIVE_UNARY_OPERATOR_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "class.h"

// compiler inline function
static inline fcomplex fc_uplus(fcomplex);
static inline fcomplex fc_uminus(fcomplex);
static inline dcomplex dc_uplus(dcomplex);
static inline dcomplex dc_uminus(dcomplex);
static inline lcomplex lc_uplus(lcomplex);
static inline lcomplex lc_uminus(lcomplex);

static inline fcomplex
fc_uplus(fcomplex z)
{
	return z;
}

static inline fcomplex
fc_uminus(fcomplex z)
{
	z.real = -z.real;
	z.imag = -z.imag;
	return z;
}

static inline dcomplex
dc_uplus(dcomplex z)
{
	return z;
}

static inline dcomplex
dc_uminus(dcomplex z)
{
	z.real = -z.real;
	z.imag = -z.imag;
	return z;
}

static inline lcomplex
lc_uplus(lcomplex z)
{
	return z;
}

static inline lcomplex
lc_uminus(lcomplex z)
{
	z.real = -z.real;
	z.imag = -z.imag;
	return z;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_COMPLEX_PRIMITIVE_UNARY_OPERATOR_H */
