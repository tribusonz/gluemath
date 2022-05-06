/*******************************************************************************
	GLUE-Math Library: Incomplete Gamma Function - Integral term

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_GAMMAINCTERM_DBL_INTERNAL
#define GML_GAMMAINCTERM_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "exp.h"
#include "pow.h"

static double gammainc_a;

static inline double
gammaincterm_core(double t)
{
	return exp_core(-t) * pow_core(t, gammainc_a - 1);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_GAMMAINCTERM_DBL_INTERNAL */
