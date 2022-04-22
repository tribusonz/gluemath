/*******************************************************************************
	GLUE-Math Library: p-adic Gamma Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/p_gamma.h"

double
p_gamma_r8(double a, double x, double loggamma_a)
{
	if (a != a || x != x || loggamma_a != loggamma_a)
		return NAN;
	return p_gamma_core(a, x, loggamma_a);
}
