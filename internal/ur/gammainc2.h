/*******************************************************************************
	GLUE-Math Library: Incomplete Gamma Function (the 2nd kind)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_GAMMAINC2_DBL_INTERNAL
#define GML_GAMMAINC2_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "../../tuning/constexpr_gamma.h"
#include "gammaincterm.h"
#include "exp.h"
#include "fmod.h"
#include "trunc.h"
#include "intdeo.h"
#if 0
# include "factorial.h"
#endif

double gammainc2(double, double);
static inline double gammainc2_posa(double);
static inline double gammainc2_nega(double);
static inline double gammainc2_inta(int, double);

static inline double
gammainc2_core(double a, double x)
{
	static int check = 0;

	if (check == 0) { get_gamma_const(); check = 1; }

	switch (fpclassify(a)) {
	case FP_NAN:
		return NAN;
		break;
	case FP_INFINITE:
		return a < 0 ? NAN : HUGE_VAL;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		gammainc_a = 0;
		return gammainc2_nega(x);
		break;
	case FP_NORMAL:
	default:
		switch (fpclassify(fmod_core(a, 1))) {
		case FP_ZERO:
		case FP_SUBNORMAL:
			if (0 < a && a <= gamma_max)
				return gammainc2_inta((int)trunc_core(a), x);
			break;
		}
		gammainc_a = a;
		if (a < 0)
			return gammainc2_nega(x);
		else
			return gammainc2_posa(x);
		break;
	}
}

// positive a routine
static inline double
gammainc2_posa(double x)
{
	double i, err;
	if (x != x)  return x;
	intdeo_core(gammaincterm_core, x, 1, &i, &err);
	return i;
}

// negative a routine
static inline double
gammainc2_nega(double x)
{
	double i, err;
	switch (fpclassify(x)) {
	case FP_NAN:
		return NAN;
		break;
	case FP_INFINITE:
		if (x < 0)  return NAN;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		return HUGE_VAL;
		break;
	case FP_NORMAL:
	default:
		if (x < 0)  return NAN;
		break;
	}
	intdeo_core(gammaincterm_core, x, 1, &i, &err);
	return i;
}

// 2nd kind of integer a
static inline double
gammainc2_inta(int a, double x)
{
	double expmx, xs, s = 0, b = 0, bi = 1;
	
	switch (fpclassify(x)) {
	case FP_NAN:
		return NAN;
		break;
	case FP_INFINITE:
		return x > 0 ? 0.0 : NAN; // Gamma(a, -Infinity) is undefined
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:  // don't use denormalized number
#if 0
		return factorial_core(a - 1);
#else
		for (volatile int i = 0; i < a; i++)
		{
			b = bi;
			for (volatile int j = 0; j < (a-i-1); j++)
				bi = bi + b;
			bi = bi - b;
		}
		return b;
#endif
		break;
	default:
		break;
	}
	
	switch (fpclassify(expmx = exp_core(-x))) {
	case FP_NAN:
	case FP_INFINITE:
		return a % 2 ? HUGE_VAL : -HUGE_VAL;  // Negative direction overflow.
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		return 0.0;  // Positive direction underflow.
		break;
	default:
		break;
	}
	
	switch (a) {
	case 1:
		return expmx;
		break;
	case 2:
		return (expmx * (x * x + x)) / x;
		break;
	case 3:
		return (expmx * (x * x * x +
		                 2 * x * x + 2 * x)) / x;
		break;
	case 4:
		return (expmx * (x * x * x * x +
		                 3 * x * x * x +
		                 6 * x * x + 6 * x)) / x;
		break;
	case 5:
		return (expmx * (x * x * x * x * x +
		                 4 * x * x * x * x +
		                 12 * x * x * x +
		                 24 * x * x + 24 * x)) / x;
		break;
	case 6:
		return (expmx * (x * x * x * x * x * x +
		                 5 * x * x * x * x * x +
		                 20 * x * x * x * x +
		                 60 * x * x * x +
		                 120 * x * x + 120 * x)) / x;
		break;
	case 7:
		return (expmx * (x * x * x * x * x * x * x +
		                 6 * x * x * x * x * x * x +
		                 30 * x * x * x * x * x +
		                 120 * x * x * x * x +
		                 360 * x * x * x +
		                 720 * x * x + 720 * x)) / x;
		break;
	case 8:
		return (expmx * (x * x * x * x * x * x * x * x +
		                 7 * x * x * x * x * x * x * x +
		                 42 * x * x * x * x * x * x +
		                 210 * x * x * x * x * x +
		                 840 * x * x * x * x +
		                 2520 * x * x * x +
		                 5040 * x * x + 5040 * x)) / x;
		break;
	default:
		for (volatile int i = 0; i < a; i++)
		{
			xs = x;  b = bi;
			for (volatile int j = 0; j < (a-i-1); j++)
				{  xs = xs * x; bi = bi + b;  }
			s = s + b * xs;  bi = bi - b;
		}
		return (1 / x) * expmx * s;
		break;
	}
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_GAMMAINC2_DBL_INTERNAL */
