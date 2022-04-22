/*******************************************************************************
	GLUE-Math Library: Natural Logarithm (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/logl.h"

long double
legacy_logl(long double x)
{
	return logl_core(x);
}
