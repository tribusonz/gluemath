/*******************************************************************************
	GLUE-Math Complex Primitive: Argument

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_COMPLEX_ARGUMENT
#define GML_COMPLEX_ARGUMENT

#if defined(__cplusplus)
extern "C" {
#endif

#include "class.h"

#include "../../internal/ur/quadrantf.h"
static inline float
fc_arg(fcomplex z)
{
	return quadrantf_core(z.imag, z.real);
}

#include "../../internal/ur/quadrant.h"
static inline double
dc_arg(dcomplex z)
{
	return quadrant_core(z.imag, z.real);
}

#include "../../internal/ur/quadrantl.h"
static inline long double
lc_arg(lcomplex z)
{
	return quadrantl_core(z.imag, z.real);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_COMPLEX_ARGUMENT */

