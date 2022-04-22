/*******************************************************************************
	GLUE-Math Library -- Inverse Error Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Small CUDA Project
			by Michael B. Giles, University of Oxford, UK
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/erfinv.h"

double
erfinv_r8(double q)
{
	return erfinv_core(q);
}
