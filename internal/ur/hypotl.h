/*******************************************************************************
	GLUE-Math Library: Hypotenuse (long double)

	Author:
	  Haruhiko Okumura (Algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_HYPOT_LDBL_INTERNAL
#define GML_HYPOT_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: fabsl()
#include "../../sys/float/absolute.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"

static inline long double ur_hypotl(long double, long double);

static inline long double
hypotl_core(register long double x, register long double y)
{
	int attr = 0;
	switch (fpclassify(y)) {
	case FP_NAN:
		break;
	case FP_INFINITE:
		attr |= 0x01;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		attr |= 0x02;
		break;
	case FP_NORMAL:
	default:
		attr |= 0x04;
	}
	switch (fpclassify(x)) {
	case FP_NAN:
		break;
	case FP_INFINITE:
		attr |= 0x10;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		attr |= 0x20;
		break;
	case FP_NORMAL:
	default:
		attr |= 0x40;
	}
	switch (attr) {
	case 0x11: // $\sqrt{\pm\infty^2+\pm\infty^2}$
		return HUGE_VALL;
		break;
	case 0x12: // $\sqrt{\pm\infty^2+\pm0^2}$
		return HUGE_VALL;
		break;
	case 0x14: // $\sqrt{\pm\infty^2+y^2}$
		return HUGE_VALL;
		break;
	case 0x21: // $\sqrt{\pm0^2+\pm\infty^2}$
		return HUGE_VALL;
		break;
	case 0x22: // $\sqrt{\pm0^2+\pm0^2}$
		return 0.0;
		break;
	case 0x24: // $\sqrt{\pm0^2+y^2}$
		return y < 0 ? -y : y;
		break;
	case 0x41: // $\sqrt{x^2+\pm\infty^2}$
		return HUGE_VALL;
		break;
	case 0x42: // $\sqrt{x^2+0^2}$
		return x < 0 ? -x : x;
		break;
	case 0x44:
		return ur_hypotl(x, y);
		break;
	default:
		return NAN;
		break;
	}
}

/* Moler-Morrison method */
static inline long double
ur_hypotl(register long double x, register long double y)
{
	register long double t;
	static const int N = 5; /* float: 2, double: 3 */
	x = fabsl(x);  y = fabsl(y);
	if (x < y) {  t = x;  x = y;  y = t;  }
	if (y == 0) return x;
	for (volatile int i = 0; i < N; i++)
	{
		t = y / x;  t *= t;  t /= 4 + t;
		x += 2 * x * t;  y *= t;
	}
	return x;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_HYPOT_LDBL_INTERNAL */
