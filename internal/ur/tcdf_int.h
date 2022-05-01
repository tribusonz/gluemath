/*******************************************************************************
	GLUE-Math Library: Student's t-Distribution CDF

	Author:
	  Haruhiko Okumura (Original algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_TCDF_INT_INTERNAL
#define GML_TCDF_INT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: sqrt(), atan()
#include "sqrt.h"
#include "atan.h"

/* 元 */
static inline double
tcdf_int_core(register double t, register int df)
{
	register int i;
	register double c2, p, s;
	static const double PI = 3.14159265358979323846264;

	c2 = df / (df + t * t);  /* cos^2 */
	s = sqrt_core(1 - c2);  if (t < 0) s = -s;  /* sin */
	p = 0;
	for (i = df % 2 + 2; i <= df; i += 2) {
		p += s;  s *= (i - 1) * c2 / i;
	}
	if (df & 1)     /* 自由度が奇数 */
		return 0.5+(p*sqrt_core(c2)+atan_core(t/sqrt_core(df)))/PI;
	else            /* 自由度が偶数 */
		return (1 + p) / 2;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_TCDF_INT_INTERNAL */
