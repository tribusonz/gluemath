/*******************************************************************************
	GLUE-Math Library: Hyperbolic Cosine
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/cosh.h"

double
cosh_r8(double x)
{
	return cosh_core(x);
}
