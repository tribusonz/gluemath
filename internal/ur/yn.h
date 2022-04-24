/*******************************************************************************
	GLUE Math Library: Bessel Function (the 2nd kind)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_YN_DBL_INTERNAL
#define GML_YN_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: log()
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "log.h"

/* $Y_n(x)$ */
static inline double
yn_core(int n, double x)
{
#define EPS      1e-10                /* 許容相対誤差 */
#define odd(x)   ((x) & 1)            /* 奇数? */
#define PI       3.14159265358979324  /* $\pi$ */
#define EULER    0.577215664901532861 /* Eulerの定数 $\gamma$ */
	int k;
	double a, b, s, t, u;
	const double x_2 = x / 2;
	const double log_x_2 = log_core(x_2);

	if (x < 0)
		return NAN;
	if (n < 0)
	{
		if (odd(n)) return -yn_core(-n, x);
		/* else */  return  yn_core(-n, x);
	}
	if (x == 0)  return n == 0 ? -HUGE_VAL : HUGE_VAL; // n != 0 == 無限複素量
	else if (isnan(x))  return NAN;
	else if (isinf(x))  return 0;
	k = x;  b = 1;
	do {  k++;  } while ((b *= x_2 / k) > EPS);
	if (odd(k)) k++;   /* 奇数なら偶数にする */
	a = 0;  /* $a = J_{k+1}(x) = 0$, $b = J_k(x)$, $k$ 偶数 */
	s = 0;  /* 規格化の因子 */
	t = 0;  /* $Y_0(x)$ */
	u = 0;  /* $Y_1(x)$ */
	while (k > 0) {
		s += b;  t = b / (k / 2) - t;
		a = 2 * k * b / x - a;  k--;  /* $a = J_k(x)$, $k$ 奇数 */
		if (k > 2) u = (k * a) / ((k / 2) * (k / 2 + 1)) - u;
		b = 2 * k * a / x - b;  k--;  /* $b = J_k(x)$, $k$ 偶数 */
	}
	s = 2 * s + b;
	a /= s;  b /= s;  t /= s;  u /= s;  /* $a = J_1(x)$, $b = J_0(x)$ */
	t = (2 / PI) * (2 * t + (log_x_2 + EULER) * b);  /* $Y_0(x)$ */
	if (n == 0) return t;
	u = (2 / PI) * (u + ((EULER - 1) + log_x_2) * a - b / x);  /* $Y_1(x)$ */
	for (k = 1; k < n; k++) {
		s = (2 * k) * u / x - t;  t = u;  u = s;
	}
	return u;
#undef EPS
#undef odd
#undef PI
#undef EULER
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_YN_DBL_INTERNAL */
