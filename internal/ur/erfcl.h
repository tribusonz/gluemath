/*******************************************************************************
	GLUE-Math Library -- Complementary Error Function (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Calculation of Error Function
			by Kenta Kobayashi, Hitotsubashi University
*******************************************************************************/
#ifndef GML_ERFC_LDBL_INTERNAL
#define GML_ERFC_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "ur_erfl.h"

static inline long double
erfcl_core(long double x)
{
	return 1 - ur_erfl(x);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ERFC_LDBL_INTERNAL */
