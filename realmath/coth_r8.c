/*******************************************************************************
	GLUE-Math Library: Hyperbolic Cotangent
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/coth.h"

double
coth_r8(double x)
{
	return coth_core(x);
}
