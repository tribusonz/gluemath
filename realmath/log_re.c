/*******************************************************************************
	GLUE-Math Library: Natural Logarithm (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/logl.h"

long double
log_re(long double x)
{
	return logl_core(x);
}
