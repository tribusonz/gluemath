/*******************************************************************************
	GLUE-Math Library: Binary Logarithm (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/log2l.h"

long double
legacy_log2l(long double x)
{
	return log2l_core(x);
}
