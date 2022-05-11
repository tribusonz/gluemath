/*******************************************************************************
	GLUE-Math Library: Quadrant (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/atan2f.h"

float
atan2_r4(float y, float x)
{
	return atan2f_core(y, x);
}
