/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arccosecant (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/acschl.h"

long double
acsch_re(long double x)
{
	return acschl_core(x);
}
