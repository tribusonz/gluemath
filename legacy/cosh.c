/*******************************************************************************
	GLUE-Math Library: Hyperbolic Cosine
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/cosh.h"

double
legacy_cosh(double x)
{
	return cosh_core(x);
}
