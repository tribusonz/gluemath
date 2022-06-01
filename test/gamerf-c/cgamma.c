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

double _Complex
cgamma(double _Complex x)
{
	static const double
	pi = 3.14159265358979324e+00,
	pv = 7.31790632447016203e+00,
	pr = 1.66327323256597418e-03,
	p0 = 5.07600435957593046e-02,
	p1 = 5.35012283109043333e-01,
	p2 = 2.40511969085241713e+00,
	p3 = 4.62624880633891119e+00,
	p4 = 3.36415438064135324e+00,
	p5 = 6.71454520397933746e-01,
	p6 = 1.49097237136722798e-02,
	q1 = 9.99999999999975753e-01,
	q2 = 2.00000000000603851e+00,
	q3 = 2.99999999944915534e+00,
	q4 = 4.00000003016801681e+00,
	q5 = 4.99999857982434025e+00,
	q6 = 6.00009857740312429e+00;
	
	double _Complex y, w = x;
	
	if (creal(x) < 0)  w = 1 - x;
	y = (((((((p6 /
	    (w + q6) + p5) / (w + q5) + p4) /
	    (w + q4) + p3) / (w + q3) + p2) /
	    (w + q2) + p1) / (w + q1) + p0) /
	     w + pr) * cexp((w - 0.5) * clog(w + pv) - w);
	
	if (creal(x) < 0)  y = pi / (y * csin(pi * x));
	return y;
}
