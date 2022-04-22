/*******************************************************************************
	GLUE-Math Library: Hyperbolic Secant (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/sechf.h"

float
sech_r4(float x)
{
	return sechf_core(x);
}
