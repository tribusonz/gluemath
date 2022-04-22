/*******************************************************************************
	GLUE-Math Library -- Complementary Error Function (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Calculation of Error Function
			by Kenta Kobayashi, Hitotsubashi University
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/erfcl.h"

long double
erfc_re(long double x)
{
	return erfcl_core(x);
}
