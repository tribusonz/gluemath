/*******************************************************************************
	GLUE-Math Library -- Error Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Calculation of Error Function
			by Kenta Kobayashi, Hitotsubashi University
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/erf.h"

double
legacy_erf(double x)
{
	return erf_core(x);
}
