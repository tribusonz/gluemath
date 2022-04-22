/*******************************************************************************
	GLUE-Math Library: Modulo

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_FMOD_DBL_INTERNAL
#define GML_FMOD_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: floor
#include "floor.h"

static inline double
fmod_core(register double x, register double y)
{
	return x - y * floor_core(x / y);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_FMOD_DBL_INTERNAL */
