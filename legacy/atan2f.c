/*******************************************************************************
	GLUE-Math Library: Quadrant (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/atan2f.h"

float
legacy_atan2f(float y, float x)
{
	return atan2f_core(x, y);
}
