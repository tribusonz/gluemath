/*******************************************************************************
	GLUE-Math Library: Standard Normal Distribution PDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_SNORMPDF_INTERNAL
#define GML_SNORMPDF_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "exp.h"
#include "../../tuning/constexpr_exp.h"

static inline double
snormpdf_core(register double z)
{
	register double z2;
	static const double sqrt2pi = 2.50662827463100050241576; /*$\sqrt{2\pi}$*/

	get_exp_const();
	
	z2 = z * z;
	if (z2 < exp_max)
		return exp_core(-0.5 * z2) / sqrt2pi;
	return z != z ? z : 0;  // out of calculation range with NaN Handling
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_SNORMPDF_INTERNAL */

