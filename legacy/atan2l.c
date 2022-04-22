/*******************************************************************************
	GLUE-Math Library: Quadrant (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/quadrantl.h"

long double
legacy_atan2l(long double y, long double x)
{
	return quadrantl_core(y, x);
}
