/*******************************************************************************
	GLUE-Math Library: Arccotangent
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/acot.h"

double
acot_r8(double x)
{
	return acot_core(x);
}
