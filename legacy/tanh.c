/*******************************************************************************
	GLUE-Math Library -- Hyperbolic Tangent
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/tanh.h"

double
legacy_tanh(double x)
{
	return tanh_core(x);
}
