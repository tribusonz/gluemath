/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arccotangent (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/acothf.h"

float
acoth_r4(float x)
{
	return acothf_core(x);
}
