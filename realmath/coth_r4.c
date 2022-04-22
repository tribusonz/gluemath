/*******************************************************************************
	GLUE-Math Library: Hyperbolic Cotangent (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/cothf.h"

float
coth_r4(float x)
{
	return cothf_core(x);
}
