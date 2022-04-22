/*******************************************************************************
	GLUE-Math Library: Logarithm of Beta Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/lbeta.h"

double
lbeta_r8(double a, double b)
{
	return lbeta_core(a, b);
}
