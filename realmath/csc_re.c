/*******************************************************************************
	GLUE-Math Library: Cosecant (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/cscl.h"

long double
csc_re(long double x)
{
	return cscl_core(x);
}
