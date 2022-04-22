/*******************************************************************************
	GLUE-Math Library -- Complementary Error Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Calculation of Error Function
			by Kenta Kobayashi, Hitotsubashi University
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/erfc.h"

double
erfc_r8(double x)
{
	return erfc_core(x);
}
