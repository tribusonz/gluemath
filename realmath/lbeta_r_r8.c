/*******************************************************************************
	GLUE-Math Library: Logarithm of Beta Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/lbeta.h"

double
lbeta_r_r8(double a, double b, int *signp)
{
	return ur_logbeta_r(a, b, signp);
}
