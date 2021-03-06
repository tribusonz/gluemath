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
#ifndef GML_ERFC_DBLCMPLX_INTERNAL
#define GML_ERFC_DBLCMPLX_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/complex/class.h"
#include "../../sys/complex/arithmetic.h"
#include "../../sys/complex/unary.h"
#include "../../sys/complex/cast.h"
#include "../../sys/float/absolute.h"
#include "cexp.h"

#if 0
// C99 complex ver.
double _Complex
cerfc(double _Complex x)
{
	static const double
	pv  = 1.27813464856668857e+01,
	ph  = 6.64067324283344283e+00,
	p0  = 2.94608570191793668e-01,
	p1  = 1.81694307871527086e-01,
	p2  = 6.91087778921425355e-02,
	p3  = 1.62114197106901582e-02,
	p4  = 2.34533471539159422e-03,
	p5  = 2.09259199579049675e-04,
	p6  = 1.15149016557480535e-05,
	p7  = 3.90779571296927748e-07,
	p8  = 8.17898509247247602e-09,
	p9  = 1.05575446466983499e-10,
	p10 = 8.40470321453263734e-13,
	p11 = 4.12646136715431977e-15,
	p12 = 1.24947948599560084e-17,
	q0  = 6.04152433382652546e-02,
	q1  = 5.43737190044387291e-01,
	q2  = 1.51038108345663136e+00,
	q3  = 2.96034692357499747e+00,
	q4  = 4.89363471039948562e+00,
	q5  = 7.31024444393009580e+00,
	q6  = 1.02101761241668280e+01,
	q7  = 1.35934297511096823e+01,
	q8  = 1.74600053247586586e+01,
	q9  = 2.18099028451137569e+01,
	q10 = 2.66431223121749773e+01,
	q11 = 3.19596637259423197e+01,
	q12 = 3.77595270864157841e+01,
	r0  = 1.56478036351085356e-01,
	r1  = 2.45771407110492625e-01,
	r2  = 1.19035163906534275e-01,
	r3  = 3.55561834455977740e-02,
	r4  = 6.55014550718381002e-03,
	r5  = 7.44188068433574137e-04,
	r6  = 5.21447276257559040e-05,
	r7  = 2.25337799750608244e-06,
	r8  = 6.00556181041662576e-08,
	r9  = 9.87118243564461826e-10,
	r10 = 1.00064645539515792e-11,
	r11 = 6.25587539334288736e-14,
	r12 = 2.41207864479170276e-16,
	s1  = 2.41660973353061018e-01,
	s2  = 9.66643893412244073e-01,
	s3  = 2.17494876017754917e+00,
	s4  = 3.86657557364897629e+00,
	s5  = 6.04152433382652546e+00,
	s6  = 8.69979504071019666e+00,
	s7  = 1.18413876942999899e+01,
	s8  = 1.54663022945959052e+01,
	s9  = 1.95745388415979425e+01,
	s10 = 2.41660973353061018e+01,
	s11 = 2.92409777757203832e+01,
	s12 = 3.47991801628407866e+01;
	double _Complex y = x * x;

	if (fabs(creal(x)) + fabs(cimag(x)) < ph)
	{
		double _Complex z = cexp(pv * x);
		if (creal(z) > 0)
			y = cexp(-y) * x *
			   (p12 / (y + q12) + p11 / (y + q11) +
			    p10 / (y + q10) + p9  / (y + q9)  +
			    p8  / (y + q8)  + p7  / (y + q7)  +
			    p6  / (y + q6)  + p5  / (y + q5)  +
			    p4  / (y + q4)  + p3  / (y + q3)  +
			    p2  / (y + q2)  + p1  / (y + q1)  +
			    p0  / (y + q0)) + 2 / (1 + z);
		else
			y = cexp(-y) * x *
			   (r12 / (y + s12) + r11 / (y + s11) +
			    r10 / (y + s10) + r9  / (y + s9)  +
			    r8  / (y + s8)  + r7  / (y + s7)  +
			    r6  / (y + s6)  + r5  / (y + s5)  +
			    r4  / (y + s4)  + r3  / (y + s3)  +
			    r2  / (y + s2)  + r1  / (y + s1)  +
			    r0 / y) + 2 / (1 - z);
	}
	else
	{
		y = cexp(-y) * x *
		   (p12 / (y + q12) + p11 / (y + q11) +
		    p10 / (y + q10) + p9  / (y + q9)  +
		    p8  / (y + q8)  + p7  / (y + q7)  +
		    p6  / (y + q6)  + p5  / (y + q5)  +
		    p4  / (y + q4)  + p3  / (y + q3)  +
		    p2  / (y + q2)  + p1  / (y + q1)  +
		    p0  / (y + q0));
		if (creal(x) < 0)  y = y + 2;
	}
	return y;
}
#endif

static inline dcomplex
dc_divadd(double t1, dcomplex z, double t2)
{
	z.real += t2;
	return dc_div(dtodc(t1), z);
}

static inline dcomplex
cerfc_core(dcomplex x)
{
	static const double
	pv  = 1.27813464856668857e+01,
	ph  = 6.64067324283344283e+00,
	p0  = 2.94608570191793668e-01,
	p1  = 1.81694307871527086e-01,
	p2  = 6.91087778921425355e-02,
	p3  = 1.62114197106901582e-02,
	p4  = 2.34533471539159422e-03,
	p5  = 2.09259199579049675e-04,
	p6  = 1.15149016557480535e-05,
	p7  = 3.90779571296927748e-07,
	p8  = 8.17898509247247602e-09,
	p9  = 1.05575446466983499e-10,
	p10 = 8.40470321453263734e-13,
	p11 = 4.12646136715431977e-15,
	p12 = 1.24947948599560084e-17,
	q0  = 6.04152433382652546e-02,
	q1  = 5.43737190044387291e-01,
	q2  = 1.51038108345663136e+00,
	q3  = 2.96034692357499747e+00,
	q4  = 4.89363471039948562e+00,
	q5  = 7.31024444393009580e+00,
	q6  = 1.02101761241668280e+01,
	q7  = 1.35934297511096823e+01,
	q8  = 1.74600053247586586e+01,
	q9  = 2.18099028451137569e+01,
	q10 = 2.66431223121749773e+01,
	q11 = 3.19596637259423197e+01,
	q12 = 3.77595270864157841e+01,
	r0  = 1.56478036351085356e-01,
	r1  = 2.45771407110492625e-01,
	r2  = 1.19035163906534275e-01,
	r3  = 3.55561834455977740e-02,
	r4  = 6.55014550718381002e-03,
	r5  = 7.44188068433574137e-04,
	r6  = 5.21447276257559040e-05,
	r7  = 2.25337799750608244e-06,
	r8  = 6.00556181041662576e-08,
	r9  = 9.87118243564461826e-10,
	r10 = 1.00064645539515792e-11,
	r11 = 6.25587539334288736e-14,
	r12 = 2.41207864479170276e-16,
	s1  = 2.41660973353061018e-01,
	s2  = 9.66643893412244073e-01,
	s3  = 2.17494876017754917e+00,
	s4  = 3.86657557364897629e+00,
	s5  = 6.04152433382652546e+00,
	s6  = 8.69979504071019666e+00,
	s7  = 1.18413876942999899e+01,
	s8  = 1.54663022945959052e+01,
	s9  = 1.95745388415979425e+01,
	s10 = 2.41660973353061018e+01,
	s11 = 2.92409777757203832e+01,
	s12 = 3.47991801628407866e+01;
	dcomplex y = dc_mul(x, x);

	if (fabs(x.real) + fabs(x.imag) < ph)
	{
		dcomplex z = cexp_core(dc_mul(dtodc(pv), x));
		if (z.real > 0)
			y = dc_add(dc_mul(cexp_core(dc_uminus(y)), dc_mul(x, (
			    dc_add(dc_add(dc_add(dc_add(dc_add(dc_add(
			    dc_add(dc_add(dc_add(dc_add(dc_add(dc_add(
			    dc_divadd(p12, y, q12) , dc_divadd(p11, y, q11)),
			    dc_divadd(p10, y, q10)), dc_divadd(p9,  y, q9)),
			    dc_divadd(p8,  y, q8)),  dc_divadd(p7,  y, q7)),
			    dc_divadd(p6,  y, q6)),  dc_divadd(p5,  y, q5)),
			    dc_divadd(p4,  y, q4)),  dc_divadd(p3,  y, q3)),
			    dc_divadd(p2,  y, q2)),  dc_divadd(p1,  y, q1)),
			    dc_divadd(p0,  y, q0))))),
			    dc_div(dtodc(2), dc_add(dtodc(1), z)));
		else
			y = dc_add(dc_mul(cexp_core(dc_uminus(y)), dc_mul(x, (
			    dc_add(dc_add(dc_add(dc_add(dc_add(dc_add(
			    dc_add(dc_add(dc_add(dc_add(dc_add(dc_add(
			    dc_divadd(r12, y, s12),  dc_divadd(r11, y, s11)),
			    dc_divadd(r10, y, s10)), dc_divadd(r9,  y, s9)),
			    dc_divadd(r8,  y, s8)),  dc_divadd(r7,  y, s7)),
			    dc_divadd(r6,  y, s6)),  dc_divadd(r5,  y, s5)),
			    dc_divadd(r4,  y, s4)),  dc_divadd(r3,  y, s3)),
			    dc_divadd(r2,  y, s2)),  dc_divadd(r1,  y, s1)),
			    dc_div(dtodc(r0), y))))), 
			    dc_div(dtodc(2), dc_sub(dtodc(1), z)));
	}
	else
	{
		y = dc_mul(cexp_core(dc_uminus(y)), dc_mul(x, (
		    dc_add(dc_add(dc_add(dc_add(dc_add(dc_add(
		    dc_add(dc_add(dc_add(dc_add(dc_add(dc_add(
		    dc_divadd(p12, y, q12),  dc_divadd(p11, y, q11)),
		    dc_divadd(p10, y, q10)), dc_divadd(p9,  y, q9)),
		    dc_divadd(p8,  y, q8)),  dc_divadd(p7,  y, q7)),
		    dc_divadd(p6,  y, q6)),  dc_divadd(p5,  y, q5)),
		    dc_divadd(p4,  y, q4)),  dc_divadd(p3,  y, q3)),
		    dc_divadd(p2,  y, q2)),  dc_divadd(p1,  y, q1)),
		    dc_divadd(p0,  y, q0)))));
		if (x.real < 0)  y = dc_add(y, dtodc(2));
	}
	return y;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ERFC_DBLCMPLX_INTERNAL */
