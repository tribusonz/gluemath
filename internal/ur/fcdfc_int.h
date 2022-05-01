/*******************************************************************************
	GLUE-Math Library -- F Distribution CDF

	Author:
	  Haruhiko Okumura (Original algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_FCDF_INT_INTERNAL
#define GML_FCDF_INT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: pow(), atan(), sqrt()
#include "pow.h"
#include "atan.h"
#include "sqrt.h"

/* 元 */
static inline double
fcdfc_int_core(register double f, register int df1, register int df2)
{
	register int i;
	register double cos2, sin2, prob, temp;
	static const double PI = 3.14159265358979323846264;

	if (df1 % 2 != 0 && df2 % 2 == 0)
		return 1 - fcdfc_int_core(1 / f, df2, df1);
	cos2 = 1 / (1 + df1 * f / df2);  sin2 = 1 - cos2;
	if (df1 % 2 == 0) {
		prob = pow_core(cos2, df2 / 2.0);  temp = prob;
		for (i = 2; i < df1; i += 2) {
			temp *= (df2 + i - 2) * sin2 / i;
			prob += temp;
		}
		return prob;
	}
	prob = atan_core(sqrt_core(df2 / (df1 * f)));
	temp = sqrt_core(sin2 * cos2);
	for (i = 3; i <= df1; i += 2) {
		prob += temp;  temp *= (i - 1) * sin2 / i;
	}
	temp *= df1;
	for (i = 3; i <= df2; i += 2) {
		prob -= temp;
		temp *= (df1 + i - 2) * cos2 / i;
	}
	return prob * 2 / PI;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_FCDF_INT_INTERNAL */
