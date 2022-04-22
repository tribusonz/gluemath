/*******************************************************************************
	GLUE-Math Library -- Complementary Error Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Calculation of Error Function
			by Kenta Kobayashi, Hitotsubashi University
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/erfc.h"

double
legacy_erfc(double x)
{
	return erfc_core(x);
}
