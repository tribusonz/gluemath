/*******************************************************************************
	GLUE-Math Complex Primitive: Absolute

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_COMPLEX_ABSOLUTE
#define GML_COMPLEX_ABSOLUTE

#if defined(__cplusplus)
extern "C" {
#endif

#include "class.h"

#include "../internal/ur/hypotf.h"
static inline float
fc_abs(fcomplex z)
{
	return hypotf_core(z.real, z.imag);
}

#include "../internal/ur/hypot.h"
static inline double
dc_abs(dcomplex z)
{
	return hypot_core(z.real, z.imag);
}

#include "../internal/ur/hypotl.h"
static inline long double
lc_abs(lcomplex z)
{
	return hypotl_core(z.real, z.imag);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_COMPLEX_ABSOLUTE */

