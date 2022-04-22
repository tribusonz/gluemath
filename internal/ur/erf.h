/*******************************************************************************
	GLUE-Math Library -- Error Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Calculation of Error Function
			by Kenta Kobayashi, Hitotsubashi University
*******************************************************************************/
#ifndef GML_ERF_DBL_INTERNAL
#define GML_ERF_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "ur_erf.h"

static inline double
erf_core(double x)
{
	return ur_erf(x);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ERF_DBL_INTERNAL */
