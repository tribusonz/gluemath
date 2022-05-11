/*******************************************************************************
	GLUE-Math Library: Quadrant (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/quadrantf.h"

float
legacy_atan2f(float y, float x)
{
	return quadrantf_core(x, y);
}
