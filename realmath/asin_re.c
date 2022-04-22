/*******************************************************************************
	GLUE-Math Library: Arcsine (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/asinl.h"

long double
asin_re(long double x)
{
	return asinl_core(x);
}
