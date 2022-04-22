/*******************************************************************************
	GLUE-Math Library: Gamma Function (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_GAMMA_LDBL_INTERNAL
#define GML_GAMMA_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: exp(), fmod(), factorial(), lgamma()
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "expl.h"
#include "fmodl.h"
#include "factoriall.h"
#include "../../tuning/lgamma_approx.h"
#include "../../tuning/constexpr_gamma.h"
#if defined(_USE_LGAMMA_APPROX) && _USE_LGAMMA_APPROX == 1
# include "lgammal_a.h"
#endif
#include "lgammal_b.h"

static inline long double
ur_loggammal_r(long double x, int *signp)
{
#if defined(_USE_LGAMMA_APPROX) && _USE_LGAMMA_APPROX == 1
	if (x < 0)  return loggammal_a(x, signp); // approx
#endif
	return loggammal_b(x, signp); // bernoulli
}

static inline long double
gammal_core(register long double x)
{
	static int check = 0;
	int signp = 1;
	register long double y;

	if (check == 0) { get_gammal_const(); check = 1; }

	switch (fpclassify(y = fmodl_core(x, 1))) {
	case FP_NAN:
		return NAN;
		break;
	case FP_INFINITE:
		return x > 0 ? HUGE_VALL : NAN;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		if (x < 0.1)
			return (int)fmodl_core(x - y, 2) == 1 ? -HUGE_VALL : HUGE_VALL;
		else if (x <= gammal_max)
			return factoriall_core((int)(x - y) - 1);
		else
			return HUGE_VALL;
		break;
	default:
		break;
	}
	y = ur_loggammal_r(x, &signp);
	return signp * expl_core(y);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_GAMMA_LDBL_INTERNAL */
