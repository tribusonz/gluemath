/*******************************************************************************
	GLUE-Math Library: q-analog Gamma Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/p_gamma.h"
#include "../internal/ur/lgamma.h"

double
q_gamma_r8(double a, double x)
{
	if (a != a || x != x)
		return NAN;
	return q_gamma_core(a, x, lgamma_core(a));
}
