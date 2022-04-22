/*******************************************************************************
	GLUE-Math Library -- Complementary Error Function (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Calculation of Error Function
			by Kenta Kobayashi, Hitotsubashi University
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/erfcf.h"

float
legacy_erfcf(float x)
{
	return erfcf_core(x);
}
