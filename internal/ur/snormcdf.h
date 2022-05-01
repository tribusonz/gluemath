/*******************************************************************************
	GLUE-Math Library: Standard Normal Distribution CDF
	
	Author:
	  Haruhiko Okumura (Original algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_SNORMCDF_INTERNAL
#define GML_SNORMCDF_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "exp.h"
#include "../../tuning/constexpr_exp.h"

static inline double
snormcdf_core(register double z)
{
	register double z2, prev, p, t;
	static const double sqrt2pi = 2.50662827463100050241576; /*$\sqrt{2\pi}$*/

	get_exp_const();
	
	z2 = z * z;
	if (z2 < exp_max)
	{
		t = p = z * exp_core(-0.5 * z2) / sqrt2pi;
		for (volatile int i = 3; i < 200; i += 2)
		{
			prev = p;  t *= z2 / i;  p += t;
			if (p == prev) return 0.5 + p;
		}
	}
	return z != z ? z : (z > 0);  // out of calculation range with NaN Handling
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_SNORMCDF_INTERNAL */

