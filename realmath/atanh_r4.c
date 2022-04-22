/*******************************************************************************
	GLUE-Math Library -- Hyperbolic Arctangent (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/atanhf.h"

float
atanh_r4(float x)
{
	return atanhf_core(x);
}
