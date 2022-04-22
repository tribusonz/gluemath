/*******************************************************************************
	GLUE-Math Library -- Hyperbolic Arctangent
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/atanh.h"

double
legacy_atanh(double x)
{
	return atanh_core(x);
}
