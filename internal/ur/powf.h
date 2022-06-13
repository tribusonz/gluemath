/*******************************************************************************
	GLUE-Math Library -- Powers (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_POW_FLT_INTERNAL
#define GML_POW_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../tuning/pow_bin_calc.h"
#include <limits.h>  /* INT_MAX */
// uses math library: fabsf(), expf(), logf(), ipowf() */
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/absolute.h"
#if _POW_BINARY_CALC == 1
# include "exp2f.h"
# include "log2f.h"
#else
# include "expf.h"
# include "logf.h"
#endif
#include "ur_ipowf.h"

static inline float ur_powf(float, float);

static inline float
powf_core(float x, float y)
{
	int attr = 0;
	
	switch (fpclassify(y)) {
	case FP_NAN:
		break;
	case FP_INFINITE:
		attr |= 0x1;
		if (y < 0)  attr |= 0x100;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		attr |= 0x4;
		if (y < 0)  attr |= 0x100;
		break;
	case FP_NORMAL:
	default:
		switch (fpclassify(fabsf(y) - 1)) {
		case FP_ZERO:
		case FP_SUBNORMAL:
			attr |= 0x2;
			break;
		default:
			attr |= 0x8;
			break;
		}
		if (y < 0)  attr |= 0x100;
		break;
	}
	switch (fpclassify(x)) {
	case FP_NAN:
		break;
	case FP_INFINITE:
		attr |= 0x10;
		if (x < 0)  attr |= 0x1000;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		attr |= 0x40;
		if (x < 0)  attr |= 0x1000;
		break;
	case FP_NORMAL:
	default:
		switch (fpclassify(fabsf(x) - 1)) {
		case FP_ZERO:
		case FP_SUBNORMAL:
			attr |= 0x20;
			break;
		default:
			attr |= 0x80;
			break;
		}
		if (x < 0)  attr |= 0x1000;
		break;
	}
	// Branch the singular point for the power series ring
	switch (attr) {
	case 0x0011: /* +Infinity ** +Infinity */
		return HUGE_VALF;
		break;
	case 0x0012: /* +Infinity ** +1 */
		return HUGE_VALF;
		break;
	case 0x0014: /* +Infinity ** +0 */
		return 1.0;
		break;
	case 0x0018: /* +Infinity ** +Re(y) */
		return HUGE_VALF;
		break;
	case 0x0111: /* +Infinity ** -Infinity */
		return 0.0;
		break;
	case 0x0112: /* +Infinity ** -1 */
		return 0.0;
		break;
	case 0x0114: /* +Infinity ** -0 */
		return 1.0;
		break;
	case 0x0118: /* +Infinity ** -Re(y) */
		return 0.0;
		break;
	case 0x1011: /* -Infinity ** +Infinity */
		return -HUGE_VALF;
		break;
	case 0x1012: /* -Infinity ** +1 */
		return -HUGE_VALF;
		break;
	case 0x1014: /* -Infinity ** +0 */
		return -1.0;
		break;
	case 0x1018: /* -Infinity ** +Re(y) */
		return -HUGE_VALF;
		break;
	case 0x1111: /* -Infinity ** -Infinity */
		return -0.0;
		break;
	case 0x1112: /* -Infinity ** -1 */
		return -0.0;
		break;
	case 0x1114: /* -Infinity ** -0 */
		return -1.0;
		break;
	case 0x1118: /* -Infinity ** -Re(y) */
		return -0.0;
		break;

	case 0x0021: /* +1 ** +Infinity */
		return 1.0;
		break;
	case 0x0022: /* +1 ** +1 */
		return 1.0;
		break;
	case 0x0024: /* +1 ** +0 */
		return 1.0;
		break;
	case 0x0028: /* +1 ** +Re(y) */
		return 1.0;
		break;
	case 0x0121: /* +1 ** -Infinity */
		return 1.0;
		break;
	case 0x0122: /* +1 ** -1 */
		return 1.0;
		break;
	case 0x0124: /* +1 ** -0 */
		return 1.0;
		break;
	case 0x0128: /* +1 ** -Re(y) */
		return 1.0;
		break;
	case 0x1021: /* -1 ** +Infinity */
		return -1.0;
		break;
	case 0x1022: /* -1 ** +1 */
		return -1.0;
		break;
	case 0x1024: /* -1 ** +0 */
		return -1.0;
		break;
	case 0x1028: /* -1 ** +Re(y) */
		return -1.0;
		break;
	case 0x1121: /* -1 ** -Infinity */
		return -1.0;
		break;
	case 0x1122: /* -1 ** -1 */
		return -1.0;
		break;
	case 0x1124: /* -1 ** -0 */
		return -1.0;
		break;
	case 0x1128: /* -1 ** -Re(y) */
		return -1.0;
		break;

	case 0x0041: /* +0 ** +Infinity */
		return 0.0;
		break;
	case 0x0042: /* +0 ** +1 */
		return 0.0;
		break;
	case 0x0044: /* +0 ** +0 */
		return 1.0;
		break;
	case 0x0048: /* +0 ** +Re(y) */
		return 0.0;
		break;
	case 0x0141: /* +0 ** -Infinity */
		return HUGE_VALF;
		break;
	case 0x0142: /* +0 ** -1 */
		return HUGE_VALF;
		break;
	case 0x0144: /* +0 ** -0 */
		return 1.0;
		break;
	case 0x0148: /* +0 ** -Re(y) */
		return HUGE_VALF;
		break;
	case 0x1041: /* -0 ** +Infinity */
		return -0.0;
		break;
	case 0x1042: /* -0 ** +1 */
		return -0.0;
		break;
	case 0x1044: /* -0 ** +0 */
		return -1.0;
		break;
	case 0x1048: /* -0 ** +Re(y) */
		return -0.0;
		break;
	case 0x1141: /* -0 ** -Infinity */
		return -HUGE_VALF;
		break;
	case 0x1142: /* -0 ** -1 */
		return -HUGE_VALF;
		break;
	case 0x1144: /* -0 ** -0 */
		return -1.0;
		break;
	case 0x1148: /* -0 ** -Re(y) */
		return -HUGE_VALF;
		break;

	case 0x0081: /* +Re(x) ** +Infinity */
		return x > 1 ? HUGE_VALF : 0.0;
		break;
	case 0x0082: /* +Re(x) ** +1 */
		return x;
		break;
	case 0x0084: /* +Re(x) ** +0 */
		return 1.0;
		break;
	case 0x0088: /* +Re(x) ** +Re(y) */
		return ur_powf(x, y);
		break;
	case 0x0181: /* +Re(x) ** -Infinity */
		return x > 1 ? 0.0 : HUGE_VALF;
		break;
	case 0x0182: /* +Re(x) ** -1 */
		return 1 / x;
		break;
	case 0x0184: /* +Re(x) ** -0 */
		return 1.0;
		break;
	case 0x0188: /* +Re(x) ** -Re(y) */
		return ur_powf(x, y);
		break;
	case 0x1081: /* -Re(x) ** +Infinity */
		return x < -1 ? -HUGE_VALF : -0.0;
		break;
	case 0x1082: /* -Re(x) ** +1 */
		return x;
		break;
	case 0x1084: /* -Re(x) ** +0 */
		return -1.0;
		break;
	case 0x1088: /* -Re(x) ** +Re(y) */
		return ur_powf(x, y);
		break;
	case 0x1181: /* -Re(x) ** -Infinity */
		return x < -1 ? -0.0 : -HUGE_VALF;
		break;
	case 0x1182: /* -Re(x) ** -1 */
		return 1 / x;
		break;
	case 0x1184: /* -Re(x) ** -0 */
		return -1.0;
		break;
	case 0x1188: /* -Re(x) ** -Re(y) */
		return ur_powf(x, y);
		break;
	default:
		return NAN;
	}
}

static inline float
ur_powf(register float x, register float y)
{
	if (y <= INT_MAX && y >= -INT_MAX && y == (int)y)
		// NOTE: According to the exponential law, if the denominator is 0
		// and even one power calculation is included in the numerator,
		// it is always 1. (-1 if negative)
		return y == 0 ? x < 0 ? -1 : 1 : ur_ipowf(x, y);
	else if (x > 0)
#if _POW_BINARY_CALC == 1
		return exp2f_core(y * log2f_core(x));
#else
		return expf_core(y * logf_core(x));
#endif
	else if (x != 0 || y <= 0)
#if _POW_BINARY_CALC == 1
		return -exp2f_core(y * log2f_core(fabsf(x)));
#else
		return -expf_core(y * logf_core(fabsf(x)));
#endif
	/* else */ return 0;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_POW_FLT_INTERNAL */
