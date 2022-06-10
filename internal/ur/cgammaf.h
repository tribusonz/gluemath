/*******************************************************************************
	GLUE-Math Library: Euler Gamma Function
	
	Author:
	  Takuya Ooura (Original Algorithm)
	  Hironobu Inatsuka aka tribusonz (C ABI modify)
	License:
	  GPL + X11(MIT)
	Reference:
	  Ooura's Mathematical Software Packages
*******************************************************************************/
#ifndef GML_GAMMA_FLTCMPLX_INTERNAL
#define GML_GAMMA_FLTCMPLX_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "../../sys/complex/class.h"
#include "../../sys/complex/arithmetic.h"
#include "../../sys/complex/cast.h"
#include "cexpf.h"
#include "clogf.h"
#include "csinf.h"
#include "gammaf.h"

#if 0
// C99 complex ver.
float _Complex
cgammaf(float _Complex x)
{
	static const float
	pi = 3.14159265e+00,
	pv = 3.18354207e+00,
	pr = 1.03871208e-01,
	p0 = 7.00359329e-01,
	p1 = 9.80795502e-01,
	p2 = 2.06175752e-01,
	q1 = 1.00000099e+00,
	q2 = 1.99987038e+00;
	float _Complex y, w = x;

	if (crealf(x) < 0)  w = 1 - x;
	y = (((p2 / (w + q2) + p1) /
	      (w + q1) + p0) / w + pr) *
	      cexpf((w - 0.5) * clogf(w + pv) - w);
	if (crealf(x) < 0)  y = pi / (y * csinf(pi * x));

	return y;
}
#endif

static inline fcomplex ur_cgammaf(fcomplex x);

static inline fcomplex
cgammaf_core(fcomplex z)
{
	fcomplex y;
	switch (fpclassify(z.imag)) {
	case FP_NAN:
		y.real = NAN; y.imag = NAN;
		break;
	case FP_INFINITE:
		if (z.imag < 0)  y.real = NAN;
		else             y.real = HUGE_VALF;
		y.imag = NAN;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		y.real = gammaf_core(z.real);
		y.imag = 0;
		break;
	default:
		y = ur_cgammaf(z);
		break;
	}
	return y;
}

static inline fcomplex
fc_divadd2(fcomplex t1, fcomplex z, float t2, float t3)
{
	z.real += t2;
	z = fc_div(t1, z);
	z.real += t3;
	return z;
}

static inline fcomplex
ur_cgammaf(fcomplex x)
{
	static const float
	pi = 3.14159265e+00,
	pv = 3.18354207e+00,
	pr = 1.03871208e-01,
	p0 = 7.00359329e-01,
	p1 = 9.80795502e-01,
	p2 = 2.06175752e-01,
	q1 = 1.00000099e+00,
	q2 = 1.99987038e+00;
	fcomplex y, w = fctofc(x);

	if (x.real < 0)  w = fc_sub(ftofc(1), x);
	y =
	fc_mul(
	  fc_add(fc_div(fc_divadd2(fc_divadd2(
	  ftofc(p2), w, q2, p1), w, q1, p0), w), pr), 
	  cexpf_core(
	    fc_sub(
	      fc_mul(
	        fc_sub(w, ftofc(0.5)),
	        clogf_core(fc_add(w, ftofc(pv)))
	      ),
	      w
	    )
	  )
	);
	if (x.real < 0)
		y =
		fc_div(
		  ftofc(pi),
		  fc_mul(y, csinf_core(fc_mul(ftofc(pi), x)))
		);

	return y;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_GAMMA_FLTCMPLX_INTERNAL */
