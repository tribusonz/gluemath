/*******************************************************************************
	GLUE-Math Library: Exponential Integral
	
	Author:
	  William H. Press, Saul A. Teukolsky, William T. Vetterling, Brian P. Flannery
	  Hironobu Inatsuka aka tribusonz
	License:
	  GPL + X11(MIT)
	Reference:
	  Numerical Recipes in C; 3rd edition
*******************************************************************************/
#ifndef GML_EI_DBL_INTERNAL
#define GML_EI_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "expint_pos.h"
#include "ei_pos.h"

static inline double
ei_core(register double x)
{
	register double y;
	switch (fpclassify(x)) {
	case FP_NAN:
		return NAN;
		break;
	case FP_INFINITE:
		return x < 0 ? 0.0 : HUGE_VAL;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		return -HUGE_VAL;
		break;
	default:
		break;
	}

	if (x > 0)  y = ei_pos(x);
	else        y = -expint_pos(1, -x);

	if (isnan(y))
		return x < 0 ? 0.0 : HUGE_VAL;
	else
		return y;
}


#if defined(__cplusplus)
}
#endif

#endif /* GML_EI_DBL_INTERNAL */
