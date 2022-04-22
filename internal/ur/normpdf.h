/*******************************************************************************
	GLUE-Math Library: Normal Distribution PDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_NORMPDF_INTERNAL
#define GML_NORMPDF_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "exp.h"
#include "../../tuning/constexpr_exp.h"
#include "sqrt.h"

static inline double
normpdf_core(register double z, register double mu, register double sigma)
{
	register double z2;
	static const double two_pi = 6.28318530717958647; /*$2\pi$*/
	
	get_exp_const();
	
	z2 = ((z - mu) / sigma) * ((z - mu) / sigma);
	if (z2 < exp_max && sigma > 0)
		return exp_core(-0.5 * z2) / sqrt_core(two_pi * sigma * sigma);
	return z != z ? z : 0;  // out of calculation range with NaN Handling
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_NORMPDF_INTERNAL */


