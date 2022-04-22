/*******************************************************************************
	GLUE-Math Library: Quadrant (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/quadrantl.h"

long double
quadrant_re(long double x, long double y)
{
	return quadrantl_core(x, y);
}
