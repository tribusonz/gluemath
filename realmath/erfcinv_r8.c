/*******************************************************************************
	GLUE-Math Library -- Inverse Complementary Error Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Small CUDA Project
			by Michael B. Giles, University of Oxford, UK
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/erfcinv.h"

double
erfcinv_r8(double q)
{
	return erfcinv_core(q);
}
