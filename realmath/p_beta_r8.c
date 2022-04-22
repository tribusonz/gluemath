/*******************************************************************************
	GLUE-Math Library: p-adic Beta Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/p_beta.h"

double
p_beta_r8(double x, double a, double b)
{
	if (x != x || a != a || b != b)
		return NAN;
	return p_beta_core(x, a, b);
}
