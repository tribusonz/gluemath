/*******************************************************************************
	GLUE-Math Library: q-analog Beta Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/p_beta.h"

double
q_beta_r8(double x, double a, double b)
{
	if (x != x || a != a || b != b)
		return NAN;
	return q_beta_core(x, a, b);
}
