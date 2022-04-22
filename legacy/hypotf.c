/*******************************************************************************
	GLUE-Math Library: Hypotenuse (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/hypotf.h"

float
legacy_hypotf(float x, float y)
{
	return hypotf_core(x, y);
}
