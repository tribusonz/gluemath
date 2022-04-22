/*******************************************************************************
	GLUE-Math Library -- Tangent
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/tan.h"

double
legacy_tan(double x)
{
	return tan_core(x);
}
