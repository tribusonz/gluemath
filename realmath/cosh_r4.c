/*******************************************************************************
	GLUE-Math Library: Hyperbolic Cosine (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/coshf.h"

float
cosh_r4(float x)
{
	return coshf_core(x);
}
