/*******************************************************************************
	GLUE-Math Library: Quadrant
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/atan2.h"

double
atan2_r8(double y, double x)
{
	return atan2_core(y, x);
}
