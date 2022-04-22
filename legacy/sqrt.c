/*******************************************************************************
	GLUE-Math Library: Square Root (double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/sqrt.h"

double
legacy_sqrt(double x)
{
	return sqrt_core(x);
}
