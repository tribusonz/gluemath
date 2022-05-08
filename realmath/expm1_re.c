/*******************************************************************************
	GLUE-Math Library: expm1() (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/expm1l.h"

long double
expm1_re(long double x)
{
	return expm1l_core(x);
}
