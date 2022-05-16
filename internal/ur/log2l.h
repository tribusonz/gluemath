/*******************************************************************************
	GLUE-Math Library -- Binary Logarithm (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Programming in Oberon Tutorial
			- Niklaus Wirth and his team
*******************************************************************************/
#ifndef GML_LOG2_LDBL_INTERNAL
#define GML_LOG2_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// Use library: fpclassify(), HUGE_VALL, NAN
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "../sys/arch/rcm2l.h"
#include "logxtl.h"

static inline long double
log2l_core(register long double x)
{
	register long double fra;
	int exp_val;
	
	switch (fpclassify(x)) {
	case FP_NAN:
		break;
	case FP_INFINITE:
		if (x > 0)  return HUGE_VALL;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		return -HUGE_VALL;
		break;
	case FP_NORMAL:
		if (x > 0)
		{
			fra = rcm2l_core(x, &exp_val);
			return exp_val + logxtl(fra, 2);
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

#endif /* GML_LOG2_LDBL_INTERNAL */
