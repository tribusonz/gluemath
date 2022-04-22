/*******************************************************************************
	GLUE-Math Library -- Hyperbolic Tangent
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/tanh.h"

double
tanh_r8(double x)
{
	return tanh_core(x);
}
