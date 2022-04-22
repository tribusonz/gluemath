/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arcsine
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/asinh.h"

double
asinh_r8(double x)
{
	return asinh_core(x);
}
