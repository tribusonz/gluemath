/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arcsecant (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ASECH_LDBL_INTERNAL
#define GML_ASECH_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: logl(), sqrtl()
#include "logl.h"
#include "sqrtl.h"

static inline long double
asechl_core(register long double x)
{
	return logl_core(sqrtl_core(1/x-1)*sqrtl_core(1/x+1)+1/x);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ASECH_LDBL_INTERNAL */
