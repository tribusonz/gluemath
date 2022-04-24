/*******************************************************************************
	GLUE-Math Library: Bessel Function (the 2nd kind)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/y1.h"

double
y1_r8(double x)
{
	return y1_core(x);
}
