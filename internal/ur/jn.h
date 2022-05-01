/*******************************************************************************
	GLUE Math Library: Bessel Function (the 1st kind)

	Author:
	  Haruhiko Okumura (Original algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_JN_DBL_INTERNAL
#define GML_JN_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library:
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"

/* $J_n(x)$ */
static inline double
jn_core(int n, double x)
{
#define odd(x)   ((x) & 1)            /* 奇数? */
#define EPS      1e-10                /* 許容相対誤差 */
	int k;
	double a, b, r = 0, s;
	const double x_2 = x / 2;

	if (x < 0) {
		if (odd(n)) return -jn_core(n, -x);
		/* else */  return  jn_core(n, -x);
	}
	if (n < 0) {
		if (odd(n)) return -jn_core(-n, x);
		/* else */  return  jn_core(-n, x);
	}
	if (x == 0) return (n == 0);
	else if (isnan(x))  return x;
	else if (isinf(x))  return 0;
	a = s = 0;  b = 1;
	k = n;  if (k < x) k = x;
	do {  k++;  } while ((b *= x_2 / k) > EPS);
	if (odd(k)) k++;  /* 奇数なら偶数にする */
	while (k > 0) {
		s += b;
		a = 2 * k * b / x - a;  k--;  /* $a = J_k(x)$ */
		if (n == k) r = a;            /* $k$ 奇数 */
		b = 2 * k * a / x - b;  k--;  /* $b = J_k(x)$ */
		if (n == k) r = b;            /* $k$ 偶数 */
	}
	return r / (2 * s + b);
		/* $J_0 + 2(J_2 + J_4 + \cdots) = 1$ となるように規格化 */
#undef odd
#undef EPS
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_JN_DBL_INTERNAL */
