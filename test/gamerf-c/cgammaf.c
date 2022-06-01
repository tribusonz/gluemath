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
#include "gamerf.h"

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
