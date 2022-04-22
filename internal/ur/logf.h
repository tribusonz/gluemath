/*******************************************************************************
	GLUE-Math Library -- Natural Logarithm (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Programming in Oberon Tutorial
			- Niklaus Wirth and his team
*******************************************************************************/
#ifndef GML_LOG_FLT_INTERNAL
#define GML_LOG_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// Use library: signbit(), fpclassify(), HUGE_VALF, NAN
#include "../../sys/float/signbit.h"
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "../sys/arch/rcm2f.h"
#include "logxtf.h"

static inline float
logf_core(register float x)
{
	register float fra;
	int exp_val;
	
	if (!signbit(x)) {
		switch (fpclassify(x)) {
		case FP_NAN:
			break;
		case FP_INFINITE:
			return HUGE_VALF;
			break;
		case FP_ZERO:
		case FP_SUBNORMAL:
			return -HUGE_VALF;
			break;
		case FP_NORMAL:
			fra = rcm2f_core(x, &exp_val);
			return (exp_val + logxtf(fra, 2))  * 0.6931471805599453;
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

#endif /* GML_LOG_FLT_INTERNAL */
