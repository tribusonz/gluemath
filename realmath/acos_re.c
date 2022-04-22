/*******************************************************************************
	GLUE-Math Library: Arccosine (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/acosl.h"

long double
acos_re(long double x)
{
	return acosl_core(x);
}
