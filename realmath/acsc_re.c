/*******************************************************************************
	GLUE-Math Library: Arccosecant (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/acscl.h"

long double
acsc_re(long double x)
{
	return acscl_core(x);
}
