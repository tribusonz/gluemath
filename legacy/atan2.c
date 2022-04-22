/*******************************************************************************
	GLUE-Math Library: Quadrant
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/quadrant.h"

double
legacy_atan2(double y, double x)
{
	return quadrant_core(y, x);
}
