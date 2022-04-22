/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arctangent (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/acothl.h"

long double
acoth_re(long double x)
{
	return acothl_core(x);
}
