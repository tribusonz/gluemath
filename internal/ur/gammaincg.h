/*******************************************************************************
	GLUE-Math Library: Generalized Incomplete Gamma Function

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_GAMMAINCG_DBL_INTERNAL
#define GML_GAMMAINCG_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "gammaincterm.h"
#include "intde.h"

static inline double
gammaincg_core(double a, double x0, double x1)
{
	double i, err;
	gammainc_a = a;
	intde_core(gammaincterm_core, x0, x1, &i, &err);
	return i;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_GAMMAINCG_DBL_INTERNAL */
