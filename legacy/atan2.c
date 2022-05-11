/*******************************************************************************
	GLUE-Math Library: Quadrant
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/atan2.h"

double
legacy_atan2(double y, double x)
{
	return atan2_core(y, x);
}
