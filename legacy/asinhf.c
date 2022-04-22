/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arcsine (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/asinhf.h"

float
legacy_asinhf(float x)
{
	return asinhf_core(x);
}
