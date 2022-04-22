/*******************************************************************************
	GLUE-Math Library: Hypotenuse
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/hypot.h"

double
hypot_r8(double x, double y)
{
	return hypot_core(x, y);
}
