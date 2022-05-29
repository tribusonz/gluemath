/*******************************************************************************
	GLUE-Math Library: Gamma Function (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_GAMMA_FLT_INTERNAL
#define GML_GAMMA_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: expf(), fmodf(), factorial(), lgamma()
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "expf.h"
#include "fmodf.h"
#include "factorial.h"
#include "../../tuning/lgamma_approx.h"
#include "../../tuning/constexpr_gamma.h"
#if defined(_USE_LGAMMA_APPROX) && _USE_LGAMMA_APPROX == 1
# include "lgamma_a.h"
#endif
#include "lgamma_b.h"

static inline float
ur_loggammaf_r(float x, int *signp)
{
#if defined(_USE_LGAMMA_APPROX) && _USE_LGAMMA_APPROX == 1
	if (x < 0)  return (float)loggamma_a((double)x, signp); // approx
#endif
	return (float)loggamma_b((double)x, signp); // bernoulli
}

static inline float
gammaf_core(register float x)
{
	static int check = 0;
	int signp;
	register float y;

	if (check == 0) { get_gammaf_const(); check = 1; }

	switch (fpclassify(y = fmodf_core(x, 1))) {
	case FP_NAN:
	case FP_INFINITE:
		return x > 0 ? HUGE_VALF : NAN;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		if (x < 0.1)
			return (int)fmodf_core(x - y, 2) == 1 ? -HUGE_VALF : HUGE_VALF;
		else if (x <= gammaf_max)
			return (float)factorial_core((int)(x - y) - 1);
		else
			return HUGE_VALF;
		break;
	default:
		break;
	}
	y = ur_loggammaf_r(x, &signp);
	y = expf_core(y);
	return signp == 1 ? y : -y;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_GAMMA_FLT_INTERNAL */
