/*******************************************************************************
	GLUE-Math Complex Primitive Setting: Build (Cartesian)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_COMPLEX_PRIMITIVE_BUILD_H
#define GML_COMPLEX_PRIMITIVE_BUILD_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "class.h"

// compiler inline function
static inline fcomplex fcbuild(float, float);
static inline dcomplex cbuild(double, double);
static inline lcomplex lcbuild(long double, long double);

static inline fcomplex
fcbuild(float real, float imag)
{
	fcomplex z = { real, imag };
	return z;
}

static inline dcomplex
cbuild(double real, double imag)
{
	dcomplex z = { real, imag };
	return z;
}

static inline lcomplex
lcbuild(long double real, long double imag)
{
	lcomplex z = { real, imag };
	return z;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_COMPLEX_PRIMITIVE_BUILD_H */
