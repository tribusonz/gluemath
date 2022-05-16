/*******************************************************************************
	GLUE-Math Library -- Common Logarithm (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Programming in Oberon Tutorial
			- Niklaus Wirth and his team
*******************************************************************************/
#ifndef GML_LOG10_FLT_INTERNAL
#define GML_LOG10_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// Use library: fpclassify(), HUGE_VALF, NAN
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "../sys/arch/rcm10f.h"
#include "logxtf.h"

static inline float
log10f_core(register float x)
{
	register float fra;
	int exp_val = 0;
	
	switch (fpclassify(x)) {
	case FP_NAN:
		break;
	case FP_INFINITE:
		if (x > 0)  return HUGE_VALF;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		return -HUGE_VALF;
		break;
	case FP_NORMAL:
		if (x > 0)
		{
			fra = rcm10f_core(x, &exp_val);
			return exp_val + logxtf(fra, 10);
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

#endif /* GML_LOG10_FLT_INTERNAL */
