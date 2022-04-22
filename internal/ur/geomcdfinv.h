/*******************************************************************************
	GLUE-Math Library: Geometric Distribution Inverse CDF

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Simulation and Statistical Programming Hilary Term 2020
		- Robert Davies
		- Anthony Caterini, Bobby He, Sheheryar Zaidi
		- Alan (Siu Chau)
		(University of Oxford)
*******************************************************************************/
#ifndef GML_GEOMCDFINV_INTERNAL
#define GML_GEOMCDFINV_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "ur_geomcdfinv.h"

static inline double
geomcdfinv_core(register double u, register double q)
{
	return ur_geomcdfinv(u, q);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_GEOMCDFINV_INTERNAL */
