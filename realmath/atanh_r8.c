/*******************************************************************************
	GLUE-Math Library -- Hyperbolic Arctangent
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/atanh.h"

double
atanh_r8(double x)
{
	return atanh_core(x);
}
