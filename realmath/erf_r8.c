/*******************************************************************************
	GLUE-Math Library -- Error Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Calculation of Error Function
			by Kenta Kobayashi, Hitotsubashi University
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/erf.h"

double
erf_r8(double x)
{
	return erf_core(x);
}
