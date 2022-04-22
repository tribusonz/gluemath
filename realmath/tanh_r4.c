/*******************************************************************************
	GLUE-Math Library -- Hyperbolic Tangent (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/tanhf.h"

float
tanh_r4(float x)
{
	return tanhf_core(x);
}
