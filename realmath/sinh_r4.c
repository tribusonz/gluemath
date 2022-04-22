/*******************************************************************************
	GLUE-Math Library: Hyperbolic Sine (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/sinhf.h"

float
sinh_r4(float x)
{
	return sinhf_core(x);
}
