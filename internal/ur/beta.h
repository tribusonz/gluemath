/*******************************************************************************
	GLUE Math Library: Euler Beta Function

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_BETA_DBL_INTERNAL
#define GML_BETA_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "lbeta.h"
#include "exp.h"

static inline double
beta_core(double a, double b)
{
	double y;
	int signp;
	
	y = ur_logbeta_r(a, b, &signp);
	return signp * exp_core(y);
}


#if defined(__cplusplus)
}
#endif

#endif /* GML_BETA_DBL_INTERNAL */
