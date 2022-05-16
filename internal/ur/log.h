/*******************************************************************************
	GLUE-Math Library -- Natural Logarithm
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Programming in Oberon Tutorial
			- Niklaus Wirth and his team
*******************************************************************************/
#ifndef GML_LOG_DBL_INTERNAL
#define GML_LOG_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// Use library: fpclassify(), HUGE_VAL, NAN
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "../sys/arch/rcm2.h"
#include "logxt.h"

static inline double
log_core(register double x)
{
	register double fra;
	int exp_val;
	
	switch (fpclassify(x)) {
	case FP_NAN:
		break;
	case FP_INFINITE:
		if (x > 0) return HUGE_VAL;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		return -HUGE_VAL;
		break;
	case FP_NORMAL:
		if (x > 0)
		{
			fra = rcm2_core(x, &exp_val);
			return (exp_val + logxt(fra, 2)) * 0.6931471805599453;
		}
		break;
	default:
		break;
	}
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_LOG_DBL_INTERNAL */
