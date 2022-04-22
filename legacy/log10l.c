/*******************************************************************************
	GLUE-Math Library: Common Logarithm (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/log10l.h"

long double
legacy_log10l(long double x)
{
	return log10l_core(x);
}
