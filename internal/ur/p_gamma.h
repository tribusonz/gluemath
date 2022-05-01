/*******************************************************************************
	GLUE-Math Library: Incomplete Gamma Function

	Author:
	  Haruhiko Okumura (Original algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
	Following paper:
	  All about of p-adic special functions (Japanese) - Yasuo Morita
******************************************************************************/
#ifndef GML_PADIC_GAMMA_DBL_INTERNAL
#define GML_PADIC_GAMMA_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: exp(), log(), NAN
#include "../../sys/float/huge_val_nan.h"
#include "exp.h"
#include "log.h"

static inline double q_gamma_core(double, double, double);
	/* 宣言だけ. 実際の定義は後. */

/* p進ガンマ関数, p-adic Gamma Function */
static inline double
p_gamma_core(register double a, register double x, register double loggamma_a)
{
	int k;
	double result, term, previous;

	if (x >= 1 + a) return 1 - q_gamma_core(a, x, loggamma_a);
	if (x == 0)     return 0;
	result = term = exp_core(a * log_core(x) - x - loggamma_a) / a;
	for (k = 1; k < 1000; k++) {
		term *= x / (a + k);
		previous = result;  result += term;
		if (result == previous) return result;
	}
#if 0
	printf("p_gamma(): 収束しません.\n");
	return result;
#else
	return NAN;
#endif
}

/* q-類似性ガンマ関数, q-analog Gamma Function */
static inline double
q_gamma_core(register double a, register double x, register double loggamma_a)
{
	int k;
	double result, w, temp, previous;
	double la = 1, lb = 1 + x - a;  /* Laguerreの多項式 */

	if (x < 1 + a) return 1 - p_gamma_core(a, x, loggamma_a);
	w = exp_core(a * log_core(x) - x - loggamma_a);
	result = w / lb;
	for (k = 2; k < 1000; k++) {
		temp = ((k - 1 - a) * (lb - la) + (k + x) * lb) / k;
		la = lb;  lb = temp;
		w *= (k - 1 - a) / k;
		temp = w / (la * lb);
		previous = result;  result += temp;
		if (result == previous) return result;
	}
#if 0
	printf("q_gamma(): 収束しません.\n");
	return result;
#else
	return NAN;
#endif
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_PADIC_GAMMA_DBL_INTERNAL */
