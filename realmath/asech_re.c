/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arcsecant (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/asechl.h"

long double
asech_re(long double x)
{
	return asechl_core(x);
}
