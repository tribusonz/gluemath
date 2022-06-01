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

float _Complex
cerff(float _Complex x)
{
	static const float
	p0 =  1.12837917e+00,
	p1 = -3.76126389e-01,
	p2 =  1.12837917e-01,
	p3 = -2.68661706e-02;
	
	if (fabsf(crealf(x)) + fabsf(cimagf(x)) >= 0.125)
		if (crealf(x) >= 0)
			return 1 - cerfcf(x);
		else
			return cerfcf(-x) - 1;
	else
	{
		float _Complex y = x * x;
		return (((p3 * y + p2) * y + p1) * y + p0) * x;
	}
}
