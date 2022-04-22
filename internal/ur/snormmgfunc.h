/*******************************************************************************
	GLUE-Math Library: Standard Normal Distribution Moment-Generating Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_SNORMMGFUNC_INTERNAL
#define GML_SNORMMGFUNC_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "exp.h"
#include "../../tuning/constexpr_exp.h"

static inline double
snormmgfunc_core(register double z)
{
	register double z2;

	get_exp_const();
	
	z2 = z * z;
	if (z2 < exp_max)
		return exp_core(0.5 * z2);
	return z != z ? z : HUGE_VAL;  // out of calculation range with NaN Handling
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_SNORMMGFUNC_INTERNAL */
