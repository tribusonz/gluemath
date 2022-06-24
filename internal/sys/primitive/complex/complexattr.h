/*******************************************************************************
	Complex Number Arithmetic -- Macro of complexattr()

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#if !defined(GLUE_PRIMITIVE_COMPLEX_ATTRIBUTE)
# error include sys/complex/complexattr.h at first
#endif

#ifndef GLUEMATH_COMPLEXATTR_INTERNAL
#define GLUEMATH_COMPLEXATTR_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../../../sys/float/fpclassify.h"
#include "../float/fpclassify.h"

static inline int
gml_fltcmplx_attr(fcomplex z)
{
	int attr = 0;
	switch (fpclassify(z.imag)) {
	case FP_NAN:
		break;
	case FP_INFINITE:
		attr |= C_IMAG_INFINITE;
		if (signbit(z.imag))  attr |= C_IMAG_HAS_SIGN;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		attr |= C_IMAG_ZERO;
		if (signbit(z.imag))  attr |= C_IMAG_HAS_SIGN;
		break;
	case FP_NORMAL:
	default:
		switch (fpclassify(fabsf(z.imag)-1)) {
		case FP_ZERO:
		case FP_SUBNORMAL:
			attr |= C_IMAG_ONE;
			break;
		default:
			attr |= C_IMAG_FINITE;
			break;
		}
		if (signbit(z.imag))  attr |= C_IMAG_HAS_SIGN;
		break;
	}
	switch (fpclassify(z.real)) {
	case FP_NAN:
		break;
	case FP_INFINITE:
		attr |= C_REAL_INFINITE;
		if (signbit(z.real))  attr |= C_REAL_HAS_SIGN;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		attr |= C_REAL_ZERO;
		if (signbit(z.real))  attr |= C_REAL_HAS_SIGN;
		break;
	case FP_NORMAL:
	default:
		switch (fpclassify(fabsf(z.real)-1)) {
		case FP_ZERO:
		case FP_SUBNORMAL:
			attr |= C_REAL_ONE;
			break;
		default:
			attr |= C_REAL_FINITE;
			break;
		}
		if (signbit(z.real))  attr |= C_REAL_HAS_SIGN;
		break;
	}
	return attr;
}

static inline int
gml_dblcmplx_attr(dcomplex z)
{
	int attr = 0;
	switch (fpclassify(z.imag)) {
	case FP_NAN:
		break;
	case FP_INFINITE:
		attr |= C_IMAG_INFINITE;
		if (signbit(z.imag))  attr |= C_IMAG_HAS_SIGN;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		attr |= C_IMAG_ZERO;
		if (signbit(z.imag))  attr |= C_IMAG_HAS_SIGN;
		break;
	case FP_NORMAL:
	default:
		switch (fpclassify(fabs(z.imag)-1)) {
		case FP_ZERO:
		case FP_SUBNORMAL:
			attr |= C_IMAG_ONE;
			break;
		default:
			attr |= C_IMAG_FINITE;
			break;
		}
		if (signbit(z.imag))  attr |= C_IMAG_HAS_SIGN;
		break;
	}
	switch (fpclassify(z.real)) {
	case FP_NAN:
		break;
	case FP_INFINITE:
		attr |= C_REAL_INFINITE;
		if (signbit(z.real))  attr |= C_REAL_HAS_SIGN;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		attr |= C_REAL_ZERO;
		if (signbit(z.real))  attr |= C_REAL_HAS_SIGN;
		break;
	case FP_NORMAL:
	default:
		switch (fpclassify(fabs(z.real)-1)) {
		case FP_ZERO:
		case FP_SUBNORMAL:
			attr |= C_REAL_ONE;
			break;
		default:
			attr |= C_REAL_FINITE;
			break;
		}
		if (signbit(z.real))  attr |= C_REAL_HAS_SIGN;
		break;
	}
	return attr;
}

static inline int
gml_ldblcmplx_attr(lcomplex z)
{
	int attr = 0;
	switch (fpclassify(z.imag)) {
	case FP_NAN:
		break;
	case FP_INFINITE:
		attr |= C_IMAG_INFINITE;
		if (signbit(z.imag))  attr |= C_IMAG_HAS_SIGN;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		attr |= C_IMAG_ZERO;
		if (signbit(z.imag))  attr |= C_IMAG_HAS_SIGN;
		break;
	case FP_NORMAL:
	default:
		switch (fpclassify(fabsl(z.imag)-1)) {
		case FP_ZERO:
		case FP_SUBNORMAL:
			attr |= C_IMAG_ONE;
			break;
		default:
			attr |= C_IMAG_FINITE;
			break;
		}
		if (signbit(z.imag))  attr |= C_IMAG_HAS_SIGN;
		break;
	}
	switch (fpclassify(z.real)) {
	case FP_NAN:
		break;
	case FP_INFINITE:
		attr |= C_REAL_INFINITE;
		if (signbit(z.real))  attr |= C_REAL_HAS_SIGN;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		attr |= C_REAL_ZERO;
		if (signbit(z.real))  attr |= C_REAL_HAS_SIGN;
		break;
	case FP_NORMAL:
	default:
		switch (fpclassify(fabsl(z.real)-1)) {
		case FP_ZERO:
		case FP_SUBNORMAL:
			attr |= C_REAL_ONE;
			break;
		default:
			attr |= C_REAL_FINITE;
			break;
		}
		if (signbit(z.real))  attr |= C_REAL_HAS_SIGN;
		break;
	}
	return attr;
}

#if defined(__cplusplus)
}
#endif

#endif /* GLUEMATH_FPCLASSIFY_INTERNAL */
