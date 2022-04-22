/*******************************************************************************
	GLUE-Math Library: Hyperbolic Cosecant (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/cschl.h"

long double
csch_re(long double x)
{
	return cschl_core(x);
}
