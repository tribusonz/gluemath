/*******************************************************************************
	GLUE-Math Library: Gaussian Error Function
	
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

double _Complex
cerf(double _Complex x)
{
	static const double p0 =  1.12837916709551257e+00,
	                    p1 = -3.76126389031837525e-01,
	                    p2 =  1.12837916709551257e-01,
	                    p3 = -2.68661706451312518e-02,
	                    p4 =  5.22397762544218784e-03,
	                    p5 = -8.54832702345085283e-04,
	                    p6 =  1.20553329817896643e-04;

	if (fabs(creal(x)) + fabs(cimag(x)) > 0.125)
		if (creal(x) > 0)
			return 1 - cerfc(x);
		else
			return cerfc(-x) - 1;
	else
	{
		double _Complex y = x * x;
		return ((((((p6 * y + p5)
		                * y + p4)
		                * y + p3)
		                * y + p2)
		                * y + p1)
		                * y + p0) * x;
	}
}
