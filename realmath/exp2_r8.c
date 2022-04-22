/*******************************************************************************
	GLUE-Math Library: Exponential function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/exp2.h"

double
exp2_r8(double x)
{
	return exp2_core(x);
}
