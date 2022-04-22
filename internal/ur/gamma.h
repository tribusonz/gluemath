/*******************************************************************************
	GLUE-Math Library: Gamma Function

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_GAMMA_DBL_INTERNAL
#define GML_GAMMA_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: exp(), fmod(), factorial(), lgamma()
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "exp.h"
#include "fmod.h"
#include "factorial.h"
#include "../../tuning/lgamma_approx.h"
#include "../../tuning/constexpr_gamma.h"
#if defined(_USE_LGAMMA_APPROX) && _USE_LGAMMA_APPROX == 1
# include "lgamma_a.h"
#endif
#include "lgamma_b.h"

static inline double
ur_loggamma_r(double x, int *signp)
{
#if defined(_USE_LGAMMA_APPROX) && _USE_LGAMMA_APPROX == 1
	if (x < 0)  return loggamma_a(x, signp); // approx
#endif
	return loggamma_b(x, signp); // bernoulli
}

static inline double
gamma_core(register double x)
{
	static int check = 0;
	int signp;
	register double y;

	if (check == 0) { get_gamma_const(); check = 1; }

	switch (fpclassify(y = fmod_core(x, 1))) {
	case FP_NAN:
	case FP_INFINITE:
		return x > 0 ? HUGE_VAL : NAN;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		if (x < 0.1)
			return (int)fmod_core(x - y, 2) == 1 ? -HUGE_VAL : HUGE_VAL;
		else if (x <= gamma_max)
			return factorial_core((int)(x - y) - 1);
		else
			return HUGE_VAL;
		break;
	default:
		break;
	}
	y = ur_loggamma_r(x, &signp);
	return signp * exp_core(y);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_GAMMA_DBL_INTERNAL */
