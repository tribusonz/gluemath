/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arccosecant
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/acsch.h"

double
acsch_r8(double x)
{
	return acsch_core(x);
}
