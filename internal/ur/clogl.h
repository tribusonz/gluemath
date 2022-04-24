/*******************************************************************************
	GLUE-Math Library: Complex Natural Logarithm (long double)

	Author:
	  John Burkardt (Original Source)
	  Hironobu Inatsuka aka tribusonz (Part of modify)
	License:
	  John Burkardt's (Original C Source)
	  GPL + X11(MIT) (ABI part)
	Reference:
	  David Collens,
	  Algorithm 243: Logarithm of a Complex Number,
	  Communications of the Association for Computing Machinery,
	  Volume 7, Number 11, November 1964, page 660.
*******************************************************************************/
#ifndef GML_LOG_LDBLCMPLX_INTERNAL
#define GML_LOG_LDBLCMPLX_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/complex/class.h"
#include "../../sys/float/absolute.h"
#include "../../sys/float/copysign.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "logl.h"
#include "sqrtl.h"
#include "atanl.h"
#include "m_pi.h"

static inline lcomplex
clogl_core(lcomplex z)
{
	long double a, b, c, d, e, f;
	static long double PI = 0;
	lcomplex value;

	if (PI == 0)  PI = m_pi_ld();

	a = z.real;
	b = z.imag;

	if (a != a || b != b)  return z;
	switch (fpclassify(b)) {
	case FP_INFINITE:
		if (b > 0)
			{ value.real = NAN; value.imag = NAN; }
		else
			{ value.real = HUGE_VALL; value.imag = NAN; }
		return value;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		c = logl_core(fabs(a));
		d = a < 0 ? PI : 0;
		break;
	default:
		e = a / 2.0;
		f = b / 2.0;
		if (fabs(e) < 0.5 && fabs(f) < 0.5)
		{
			c = fabs(2.0 * a) + fabs(2.0 * b);
			d = 8.0 * (a / c) * a + 8.0 * (b / c) * b;
			c = 0.5 * (logl_core(c) + logl_core(d)) - logl_core(sqrtl_core(8.0));
		}
		else
		{
			c = fabs(e / 2.0) + fabs(f / 2.0);
			d = 0.5 * (e / c) * e + 0.5 * (f / c) * f;
			c = 0.5 * (logl_core(c) + logl_core(d)) + logl_core(sqrtl_core(8.0));
		}
		
		if ((a != 0.0) && fabs(f) <= fabs(e))
		{
			if (copysignl(1.0, a) != -1.0)
				d = atanl_core(b / a);
			else if (copysignl(1.0, b) != -1.0)
				d = atanl_core(b / a) + PI;
			else
				d = atanl_core(b / a) - PI;
		}
		else
			d = -atanl_core(a / b) + PI / 2.0 * copysignl(1.0, b);
		break;
	}
	
	value.real = c; value.imag = d;
	
	return value;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_LOG_LDBLCMPLX_INTERNAL */
