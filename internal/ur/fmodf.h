/*******************************************************************************
	GLUE-Math Library: Modulo (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_FMOD_FLT_INTERNAL
#define GML_FMOD_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: floorf
#include "floorf.h"

static inline float
fmodf_core(register float x, register float y)
{
	return x - y * floorf_core(x / y);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_FMOD_FLT_INTERNAL */
