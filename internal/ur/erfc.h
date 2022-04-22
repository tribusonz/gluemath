/*******************************************************************************
	GLUE-Math Library -- Complementary Error Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Calculation of Error Function
			by Kenta Kobayashi, Hitotsubashi University
*******************************************************************************/
#ifndef GML_ERFC_DBL_INTERNAL
#define GML_ERFC_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "ur_erf.h"

static inline double
erfc_core(double x)
{
	return 1 - ur_erf(x);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ERFC_DBL_INTERNAL */
