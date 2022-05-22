/*******************************************************************************
	GLUE-Math Library: Modf function (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/modfl.h"

long double
modf_re(long double x, long double *ip)
{
	return modfl_core(x, ip);
}
