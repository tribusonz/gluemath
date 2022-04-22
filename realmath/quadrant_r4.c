/*******************************************************************************
	GLUE-Math Library: Quadrant (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/quadrantf.h"

float
quadrant_r4(float x, float y)
{
	return quadrantf_core(x, y);
}
