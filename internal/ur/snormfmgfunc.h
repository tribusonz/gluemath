/*******************************************************************************
	GLUE-Math Library: Standard Normal Distribution Factorial Momental-Generating Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_SNORMFMGFUNC_INTERNAL
#define GML_SNORMFMGFUNC_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "log.h"
#include "exp.h"
#include "../../tuning/constexpr_exp.h"

static inline double
snormfmgfunc(register double x)
{
	double x_2;

	get_exp_const();

	if (isnan(x_2 = log_core(x)))
		return NAN;

	x_2 = x_2 * x_2 * 0.5;

	if (x_2 <= exp_max)
		return exp_core(x_2);
	
	return HUGE_VAL;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_SNORMFMGFUNC_INTERNAL */
