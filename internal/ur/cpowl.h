/*******************************************************************************
	GLUE-Math Library: Complex Power (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_POW_LDBLCMPLX_INTERNAL
#define GML_POW_LDBLCMPLX_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "powl.h"
#include "../../sys/complex/class.h"
#include "../../sys/complex/arithmetic.h"
#include "cexpl.h"
#include "clogl.h"

static inline lcomplex
cpowl_core(lcomplex c1, lcomplex c2)
{
	int attr = 0;
	lcomplex c3 = { 0.0, 0.0 };

	switch (fpclassify(c2.imag)) {
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
		break;
	}
	switch (fpclassify(c1.imag)) {
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
		break;
	}
	switch (fpclassify(c2.real)) {
	case FP_NAN:
		break;
	case FP_INFINITE:
		attr |= 0x100;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		attr |= 0x200;
		break;
	case FP_NORMAL:
	default:
		attr |= 0x400;
		break;
	}
	switch (fpclassify(c1.real)) {
	case FP_NAN:
		break;
	case FP_INFINITE:
		attr |= 0x1000;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		attr |= 0x2000;
		break;
	case FP_NORMAL:
	default:
		attr |= 0x4000;
		break;
	}

	if (attr & 0x11) // singular point
	{
		c3.real = 0;
		c3.imag = HUGE_VALL;
	}
	else if (attr & 0x22) // real solution
	{
		c3.real = powl_core(c1.real, c2.real);
		c3.imag = 0;
	}
	else // complex solution
	{
		switch (attr) {
		// appears the variable
		case 0x2242: case 0x2244: case 0x2424: case 0x2444:
		case 0x4242: case 0x4244: case 0x4424: case 0x4444:
			c3 = cexpl_core(lc_mul(c2, clogl_core(c1)));
			break;
		// not appear
		default:
			c3.real = NAN;
			c3.imag = NAN;
			break;
		}
	}
	return c3;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_POW_LDBLCMPLX_INTERNAL */
