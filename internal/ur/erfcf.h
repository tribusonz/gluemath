/*******************************************************************************
	GLUE-Math Library -- Complementary Error Function (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Calculation of Error Function
			by Kenta Kobayashi, Hitotsubashi University
*******************************************************************************/
#ifndef GML_ERFC_FLT_INTERNAL
#define GML_ERFC_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "ur_erff.h"

static inline float
erfcf_core(float x)
{
	return 1 - ur_erff(x);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ERFC_FLT_INTERNAL */
