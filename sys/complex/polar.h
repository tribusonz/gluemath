/*******************************************************************************
	GLUE-Math Complex Primitive: Polar form

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_COMPLEX_POLAR
#define GML_COMPLEX_POLAR

#if defined(__cplusplus)
extern "C" {
#endif

#include "class.h"
#include "build.h"
#include "absolute.h"
#include "argument.h"

static inline fcomplex
fc_polar(float rho, float theta)
{
	fcomplex z;
	z.real = fc_abs(fcbuild(rho, theta));
	z.imag = fc_arg(fcbuild(rho, theta));
	return z;
}

static inline dcomplex
dc_polar(double rho, double theta)
{
	dcomplex z;
	z.real = dc_abs(cbuild(rho, theta));
	z.imag = dc_arg(cbuild(rho, theta));
	return z;
}

static inline lcomplex
lc_polar(long double rho, long double theta)
{
	lcomplex z;
	z.real = lc_abs(lcbuild(rho, theta));
	z.imag = lc_arg(lcbuild(rho, theta));
	return z;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_COMPLEX_POLAR */
