/*******************************************************************************
	GLUE-Math Library: Secant (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/secl.h"

long double
sec_re(long double x)
{
	return secl_core(x);
}
