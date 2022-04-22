/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arcsine (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/asinhf.h"

float
asinh_r4(float x)
{
	return asinhf_core(x);
}
