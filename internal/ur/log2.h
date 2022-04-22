/*******************************************************************************
	GLUE-Math Library -- Binary Logarithm
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Programming in Oberon Tutorial
			- Niklaus Wirth and his team
*******************************************************************************/
#ifndef GML_LOG2_DBL_INTERNAL
#define GML_LOG2_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// Use library: signbit(), fpclassify(), HUGE_VAL, NAN
#include "../../sys/float/signbit.h"
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "../sys/arch/rcm2.h"
#include "logxt.h"

static inline double
log2_core(register double x)
{
	register double fra;
	int exp_val;
	
	if (!signbit(x)) {
		switch (fpclassify(x)) {
		case FP_NAN:
			break;
		case FP_INFINITE:
			return HUGE_VAL;
			break;
		case FP_ZERO:
		case FP_SUBNORMAL:
			return -HUGE_VAL;
			break;
		case FP_NORMAL:
			fra = rcm2_core(x, &exp_val);
			return exp_val + logxt(fra, 2);
			break;
		default:
			break;
		}
	}
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_LOG2_DBL_INTERNAL */
