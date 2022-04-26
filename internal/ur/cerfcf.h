/*******************************************************************************
	GLUE-Math Library: Gaussian Complementary Error Function
	
	Author:
	  Takuya Ooura (Original Algorithm)
	  Hironobu Inatsuka aka tribusonz (C ABI modify)
	License:
	  GPL + X11(MIT)
	Reference:
	  Ooura's Mathematical Software Packages
*******************************************************************************/
#ifndef GML_ERFC_FLTCMPLX_INTERNAL
#define GML_ERFC_FLTCMPLX_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/complex/class.h"
#include "../../sys/complex/arithmetic.h"
#include "../../sys/complex/unary.h"
#include "../../sys/complex/cast.h"
#include "../../sys/float/absolute.h"
#include "cexpf.h"

static inline fcomplex
fc_divadd(float t1, fcomplex z, float t2)
{
	z.real += t2;
	return fc_div(ftofc(t1), z);
}

static inline fcomplex
cerfcf_core(fcomplex x)
{
	static const float
	pv = 9.03777677e+00,
	ph = 4.76888839e+00,
	p0 = 3.92213346e-01,
	p1 = 1.49181256e-01,
	p2 = 2.15823157e-02,
	p3 = 1.18760964e-03,
	p4 = 2.48565745e-05,
	p5 = 1.97879468e-07,
	q0 = 1.20830487e-01,
	q1 = 1.08747438e+00,
	q2 = 3.02076217e+00,
	q3 = 5.92069385e+00,
	q4 = 9.78726942e+00,
	q5 = 1.46204889e+01,
	r0 = 2.21293361e-01,
	r1 = 2.72957057e-01,
	r2 = 6.40298026e-02,
	r3 = 5.71296931e-03,
	r4 = 1.93880223e-04,
	r5 = 2.50263215e-06,
	r6 = 1.22871857e-08,
	s1 = 4.83321947e-01,
	s2 = 1.93328779e+00,
	s3 = 4.34989752e+00,
	s4 = 7.73315115e+00,
	s5 = 1.20830487e+01,
	s6 = 1.73995901e+01;

	fcomplex y = fc_mul(x, x);

	if (fabsf(x.real) + fabsf(x.imag) < ph)
	{
		fcomplex z = cexpf_core(fc_mul(ftofc(pv), x));
		if (z.real >= 0)
			y =
			fc_add(fc_mul(cexpf_core(fc_uminus(y)), fc_mul(x, (
			fc_add(fc_add(fc_add(fc_add(fc_add(
			fc_divadd(p5, y,  q5),
			fc_divadd(p4, y,  q4)),
			fc_divadd(p3, y,  q3)),
			fc_divadd(p2, y,  q2)),
			fc_divadd(p1, y,  q1)),
			fc_divadd(p0, y,  q0))))),
			fc_div(ftofc(2), fc_add(ftofc(1), z)));
		else
			y =
			fc_add(fc_mul(cexpf_core(fc_uminus(y)), fc_mul(x, (
			fc_add(fc_add(fc_add(fc_add(fc_add(fc_add(
			fc_divadd(r6, y, s6),
			fc_divadd(r5, y, s5)),
			fc_divadd(r4, y, s4)),
			fc_divadd(r3, y, s3)),
			fc_divadd(r2, y, s2)),
			fc_divadd(r1, y, s1)),
			fc_div(ftofc(r0), y))))),
			fc_div(ftofc(2), fc_sub(ftofc(1), z)));
	}
	else
	{
		y =
		fc_mul(cexpf_core(fc_uminus(y)), fc_mul(x, (
		fc_add(fc_add(fc_add(fc_add(fc_add(
		fc_divadd(p5, y, q5),
		fc_divadd(p4, y, q4)),
		fc_divadd(p3, y, q3)),
		fc_divadd(p2, y, q2)),
		fc_divadd(p1, y, q1)),
		fc_divadd(p0, y, q0)))));
		if (x.real < 0)  y = fc_add(y, ftofc(2));
	}
	return y;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ERFC_FLTCMPLX_INTERNAL */
