/*******************************************************************************
	GLUE-Math Library: Poisson Distribution CDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_POISSCDFC_INTERNAL
#define GML_POISSCDFC_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "floor.h"
#include "gammaincr.h"

static inline double
poisscdfc_core(register double x, register double lambda)
{
	register double y, floorx;
	if (x < 0)  return 1.0;
	if (x == x && lambda >= 0)
	{
		floorx = floor_core(x); floorx++;
		if (isinf(floorx))  return 0.0;
		y = gammaincr1_core(floorx, lambda);
		return y;
	}
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_POISSCDFC_INTERNAL */

