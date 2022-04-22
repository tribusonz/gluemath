/*******************************************************************************
	GLUE-Math Library -- Cotangent
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/cot.h"

double
cot_r8(double x)
{
	return cot_core(x);
}
