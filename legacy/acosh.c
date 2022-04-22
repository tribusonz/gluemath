/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arccosine
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/acosh.h"

double
legacy_acosh(double x)
{
	return acosh_core(x);
}
