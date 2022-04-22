/*******************************************************************************
	GLUE-Math Library: Binary Logarithm (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/log2l.h"

long double
log2_re(long double x)
{
	return log2l_core(x);
}
