/*******************************************************************************
    GLUE Math Library: Quadrant (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_QUADRANT_LDBL_INTERNAL
#define GML_QUADRANT_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: atanl()
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/absolute.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "ur_atanl.h"
#include "m_pi.h"

static inline long double
quadrantl_core(register long double x, register long double y)
{
	static long double pi = 0.L;
	register long double atanxy = 0.L;
	register int kind = 0;  // 0:= arg, 1:= quadrant, 2:= radian
	register int quadrant = 0;
	if (pi == 0.L)  pi = m_pi_ld();

	switch (fpclassify(y)) {
	case FP_NAN:
		return NAN;
		break;
	case FP_INFINITE:
		// switch radian
		kind = 2;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		// switch argument of complex
		kind = 0;
		break;
	default:
		// switch quadrant
		kind = 1;
		break;
	}
	switch (fpclassify(x)) {
	case FP_NAN:
		return NAN;
		break;
	case FP_INFINITE:
		switch (kind) {
		case 0:
			kind = 2;  // re-correction to kind is radian
			quadrant = -1;  // mark zero
			break;
		case 1:
			kind = 2;  // re-correction to kind is radian
			quadrant = x < 0 ? 8 : 6;
			break;
		case 2:
			quadrant = y >= 0 ? x >= 0 ? 1 : 2 : x < 0 ? 3 : 4;
			break;
		default:
			break;
		}
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		switch (kind) {
		case 0:
			quadrant = -3;
			break;
		case 1:
		case 2:
			kind = 0;  // re-correction to kind is arg
			quadrant = -1;  // calculate complex-absolute
			break;
		default:
			break;
		}
		break;
	default:
		switch (kind) {
		case 0:
			quadrant = -2;  // calculate complex-arg
			break;
		case 1:
			quadrant = y >= 0 ? x >= 0 ? 1 : 2 : x < 0 ? 3 : 4;
			x = fabs(x); y = fabs(y);
			break;
		case 2: // y is infinite and x is finite
				quadrant = y < 0 ? 7 : 5;
			break;
		default:
			break;
		}
		break;
	}
	switch (kind) {
	case 0:  // arg
		switch (quadrant) {
		case -1:  // Absolute
			return y < 0 ? pi : 0.L;  // $\pi$
			break;
		case -2:  // Arg
			return x < 0 ? -0.5L * pi : 0.5L * pi;  // $\frac{1}{2}\pi$
			break;
		case -3:
			return 0.L; // arg(0+0i) is originally the undefined but returns 0.0
			break;
		default:
			break;
		}
		break;
	case 1:  // quadrant
		atanxy = ur_atanl(x / y);
		switch (quadrant) {
		case 1:
			return atanxy;
			break;
		case 2:
			return -atanxy;
			break;
		case 3:
			return atanxy - pi;
			break;
		case 4:
			return pi - atanxy;
			break;
		default:
			break;
		}
		break;
	case 2:  // radian
		switch (quadrant) {
		case 1: // 1st: $45^{\circ}$
			return 0.25L * pi;
			break;
		case 2: // 2nd: $-45^{\circ}$
			return -0.25L * pi;
			break;
		case 3: // 3rd: $-135^{\circ}$
			return -3.L/4.L * pi;
			break;
		case 4: // 4th: $135^{\circ}$
			return 3.L/4.L * pi;
			break;
		case 5: // $\rm{just} 0^{\circ}$
			return x < 0 ? -0.L : 0.L; // 0-deg is originally the undefined but return 0
			break;
		case 6: // $\rm{just} 90^{\circ}$
			return 0.5L * pi; // $\frac{1}{2}\pi$
			break;
		case 7: // $\rm{just} 180^{\circ}$
			return x < 0 ? -pi : pi; // $\frac{1}{2}\pi$
			break;
		case 8: // $\rm{just} 270^{\circ}$
			return -0.5L * pi; // $\neg\frac{1}{2}\pi$
			break;
		default:
			break;
		}
		break;
	default:
		return NAN;
		break;
	}
	return NAN;
}


#if defined(__cplusplus)
}
#endif

#endif /* GML_QUADRANT_LDBL_INTERNAL */
