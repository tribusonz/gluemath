/*******************************************************************************
	GLUE-Math Library: Hyperbolic Sine
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/sinh.h"

double
legacy_sinh(double x)
{
	return sinh_core(x);
}
