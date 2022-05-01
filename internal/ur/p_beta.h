/*******************************************************************************
	GLUE-Math Library: Incomplete Beta Function

	Author:
	  Haruhiko Okumura (Original algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
	Following paper:
	  All about of p-adic special functions (Japanese) - Yasuo Morita
*******************************************************************************/
#ifndef GML_PADIC_BETA_DBL_INTERNAL
#define GML_PADIC_BETA_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// exp(), log(), lgamma(), HUGE_VAL, NAN
#include "../../sys/float/huge_val_nan.h"
#include "exp.h"
#include "log.h"
#include "lgamma.h"

static inline double
ur_p_beta(double x, double a, double b)
{
	int k;
	double p1, q1, p2, q2, d, previous;

	if (a <= 0) return HUGE_VAL;
	if (b <= 0) {
		if (x <  1) return 0;
		if (x == 1) return 1;
		/* else */  return HUGE_VAL;
	}
	if (x > (a + 1) / (a + b + 2))
		return 1 - ur_p_beta(1 - x, b, a);
	if (x <= 0)  return 0;
	p1 = 0;  q1 = 1;
	p2 = exp_core(a * log_core(x) + b * log_core(1 - x)
	    + lgamma_core(a + b) - lgamma_core(a) - lgamma_core(b)) / a;
	q2 = 1;
	for (k = 0; k < 200; ) {
		previous = p2;
		d = - (a + k) * (a + b + k) * x
		    / ((a + 2 * k) * (a + 2 * k + 1));
		p1 = p1 * d + p2;  q1 = q1 * d + q2;
		k++;
		d = k * (b - k) * x / ((a + 2 * k - 1) * (a + 2 * k));
		p2 = p2 * d + p1;  q2 = q2 * d + q1;
		if (q2 == 0) {
			p2 = HUGE_VAL;  continue;
		}
		p1 /= q2;  q1 /= q2;  p2 /= q2;  q2 = 1;
		if (p2 == previous) return p2;
	}
	return NAN;
}

/* p進ベータ関数 p-adic Beta Function */
static inline double
p_beta_core(double x, double a, double b)
{
#if 0
	double y = ur_p_beta(x, a, b);
	if (isnan(y))
		printf("p_beta: 収束しません.\n");
	return y;
#else
	return ur_p_beta(x, a, b);
#endif
}

/* q-類似性ベータ関数 q-analog Beta Function */
static inline double
q_beta_core(double x, double a, double b)
{
#if 0
	double y = 1 - ur_p_beta(x, a, b);
	if (isnan(y))
		printf("q_beta: 収束しません.\n");
	return y;
#else
	return 1 - ur_p_beta(x, a, b);
#endif
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_PADIC_BETA_DBL_INTERNAL */
