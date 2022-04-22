/*******************************************************************************
	GLUE-Math Library: Hyperbolic Cosecant (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/cschf.h"

float
csch_r4(float x)
{
	return cschf_core(x);
}
