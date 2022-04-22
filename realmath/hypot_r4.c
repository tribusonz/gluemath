/*******************************************************************************
	GLUE-Math Library: Hypotenuse (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/hypotf.h"

float
hypot_r4(float x, float y)
{
	return hypotf_core(x, y);
}
