/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arcsecant (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/asechf.h"

float
asech_r4(float x)
{
	return asechf_core(x);
}
