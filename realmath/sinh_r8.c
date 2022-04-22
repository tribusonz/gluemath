/*******************************************************************************
	GLUE-Math Library: Hyperbolic Sine
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/sinh.h"

double
sinh_r8(double x)
{
	return sinh_core(x);
}
