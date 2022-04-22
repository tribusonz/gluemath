/*******************************************************************************
	GLUE-Math Library: Standard Normal Distribution Characteristic Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_SNORMCHARFUNC_INTERNAL
#define GML_SNORMCHARFUNC_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "exp.h"
#include "../../tuning/constexpr_exp.h"

// N(0,1) of charfunc imaginary is zero.
static inline double
snormcharfunc_core(register double z)
{
	register double z2;

	get_exp_const();
	
	z2 = z * z;
	if (z2 < exp_max)
		return exp_core(-0.5 * z2);
	return z != z ? z : 0;  // out of calculation range with NaN Handling
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_SNORMCHARFUNC_INTERNAL */

