/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arcsine
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/asinh.h"

double
legacy_asinh(double x)
{
	return asinh_core(x);
}
