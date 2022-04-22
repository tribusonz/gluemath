/*******************************************************************************
	GLUE-Math Library -- Common Logarithm (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Programming in Oberon Tutorial
			- Niklaus Wirth and his team
*******************************************************************************/
#ifndef GML_LOG10_LDBL_INTERNAL
#define GML_LOG10_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// Use library: signbit(), fpclassify(), HUGE_VALL, NAN
#include "../../sys/float/signbit.h"
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "../sys/arch/rcm10l.h"
#include "logxtl.h"

static inline long double
log10l_core(register long double x)
{
	register long double fra;
	int exp_val = 0;
	
	if (!signbit(x)) {
		switch (fpclassify(x)) {
		case FP_NAN:
			break;
		case FP_INFINITE:
			return HUGE_VALL;
			break;
		case FP_ZERO:
		case FP_SUBNORMAL:
			return -HUGE_VALL;
			break;
		case FP_NORMAL:
			fra = rcm10l_core(x, &exp_val);
			return exp_val + logxtl(fra, 10);
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

#endif /* GML_LOG10_LDBL_INTERNAL */
