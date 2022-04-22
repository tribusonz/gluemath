/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arccotangent
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/acoth.h"

double
acoth_r8(double x)
{
	return acoth_core(x);
}
