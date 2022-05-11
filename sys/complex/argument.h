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
//	return atan2f_core(z.imag, z.real);
	return quadrantf_core(z.real, z.imag);
}

#include "../../internal/ur/quadrant.h"
static inline double
dc_arg(dcomplex z)
{
//	return atan2_core(z.imag, z.real);
	return quadrant_core(z.real, z.imag);
}

#include "../../internal/ur/quadrantl.h"
static inline long double
lc_arg(lcomplex z)
{
//	return atan2l_core(z.imag, z.real);
	return quadrantl_core(z.real, z.imag);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_COMPLEX_ARGUMENT */

