/*******************************************************************************
	GLUE-Math Library: Hypotenuse (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/hypotl.h"

long double
hypot_re(long double x, long double y)
{
	return hypotl_core(x, y);
}
