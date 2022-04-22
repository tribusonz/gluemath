/*******************************************************************************
	GLUE-Math Library: Hyperbolic Cosine (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/coshl.h"

long double
legacy_coshl(long double x)
{
	return coshl_core(x);
}
