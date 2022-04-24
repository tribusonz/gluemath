/*******************************************************************************
	GLUE-Math Library: Bessel Function (the 2nd kind)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/y0.h"

double
y0_r8(double x)
{
	return y0_core(x);
}
