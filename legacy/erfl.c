/*******************************************************************************
	GLUE-Math Library -- Error Function (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Calculation of Error Function
			by Kenta Kobayashi, Hitotsubashi University
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/erfl.h"

long double
legacy_erfl(long double x)
{
	return erfl_core(x);
}
