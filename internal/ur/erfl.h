/*******************************************************************************
	GLUE-Math Library -- Error Function (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Calculation of Error Function
			by Kenta Kobayashi, Hitotsubashi University
*******************************************************************************/
#ifndef GML_ERF_LDBL_INTERNAL
#define GML_ERF_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "ur_erfl.h"

static inline long double
erfl_core(long double x)
{
	return ur_erfl(x);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ERF_LDBL_INTERNAL */
