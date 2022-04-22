/*******************************************************************************
	GLUE-Math Library: Common Logarithm (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/log10l.h"

long double
log10_re(long double x)
{
	return log10l_core(x);
}
