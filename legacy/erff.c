/*******************************************************************************
	GLUE-Math Library -- Error Function (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Calculation of Error Function
			by Kenta Kobayashi, Hitotsubashi University
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/erff.h"

float
legacy_erff(float x)
{
	return erff_core(x);
}
