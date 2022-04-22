/*******************************************************************************
	GLUE-Math Library: Exponential function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/exp.h"

double
legacy_exp(double x)
{
	return exp_core(x);
}
