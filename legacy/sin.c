/*******************************************************************************
	GLUE-Math Library: Sine
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/sin.h"

double
legacy_sin(double x)
{
	return sin_core(x);
}
