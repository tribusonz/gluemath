/*******************************************************************************
	GLUE-Math Library: Hyperbolic Cosecant
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/csch.h"

double
csch_r8(double x)
{
	return csch_core(x);
}
