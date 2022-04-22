/*******************************************************************************
	GLUE-Math Library: Cube Root (double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/cbrt.h"

double
legacy_cbrt(double x)
{
	return cbrt_core(x);
}
