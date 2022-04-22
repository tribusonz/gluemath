/*******************************************************************************
	GLUE-Math Library: Hypotenuse
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/hypot.h"

double
legacy_hypot(double x, double y)
{
	return hypot_core(x, y);
}
