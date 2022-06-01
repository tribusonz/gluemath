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
#include "gamerf.h"
#include <math.h>

float _Complex
cerfcf(float _Complex x)
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

	float _Complex y = x * x;

	if (fabsf(crealf(x)) + fabsf(cimagf(x)) < ph)
	{
		float _Complex z = cexpf(pv * x);
		if (crealf(z) >= 0)
			y = cexpf(-y) * x *
			   (p5 / (y + q5)  +
			    p4 / (y + q4)  +
			    p3 / (y + q3)  +
			    p2 / (y + q2)  +
			    p1 / (y + q1)  +
			    p0 / (y + q0)) + 2 / (1 + z);
		else
			y = cexpf(-y) * x *
			   (r6 / (y + s6)  +
			    r5 / (y + s5)  +
			    r4 / (y + s4)  +
			    r3 / (y + s3)  +
			    r2 / (y + s2)  +
			    r1 / (y + s1)  +
			    r0 / y) + 2 / (1 - z);
	}
	else
	{
		y = cexpf(-y) * x *
		   (p5 / (y + q5) +
		    p4 / (y + q4) +
		    p3 / (y + q3) +
		    p2 / (y + q2) +
		    p1 / (y + q1) +
		    p0 / (y + q0));
		if (crealf(x) < 0)  y = y + 2;
	}
	return y;
}
