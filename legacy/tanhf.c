/*******************************************************************************
	GLUE-Math Library -- Hyperbolic Tangent (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/tanhf.h"

float
legacy_tanhf(float x)
{
	return tanhf_core(x);
}
