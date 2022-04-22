/*******************************************************************************
	GLUE-Math Library: Hyperbolic Sine (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/sinhf.h"

float
legacy_sinhf(float x)
{
	return sinhf_core(x);
}
