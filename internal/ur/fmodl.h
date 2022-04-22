/*******************************************************************************
	GLUE-Math Library: Modulo (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_FMOD_LDBL_INTERNAL
#define GML_FMOD_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: floorl
#include "floorl.h"

static inline long double
fmodl_core(register long double x, register long double y)
{
	return x - y * floorl_core(x / y);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_FMOD_LDBL_INTERNAL */
