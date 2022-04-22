/*******************************************************************************
	GLUE-Math Library: Euler Beta Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/beta.h"

double
beta_r8(double a, double b)
{
	return beta_core(a, b);
}
