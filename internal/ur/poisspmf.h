/*******************************************************************************
	GLUE-Math Library: Poisson Distribution PMF

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_POISSPMF_INTERNAL
#define GML_POISSPMF_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: log(), exp(), logfactorial()
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "exp.h"
#include "log.h"
#include "logfactorial.h"

static inline double
poisspmf_core(register int x, register double lambda)
{
	register double loglampowx = 0.0; // log(pow(lambda, x));
	if (x < 0 || lambda < 0)  return 0.0;
	switch (fpclassify(lambda)) {
	case FP_NAN:
	case FP_INFINITE:
	case FP_ZERO:
	case FP_SUBNORMAL:
		// loglampowx = 0.0;
		lambda = 0.0;
		break;
	default:
		loglampowx = x * log_core(lambda);
		break;
	}
	return exp_core(-logfactorial_core(x) - lambda + loglampowx);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_POISSPMF_INTERNAL */
