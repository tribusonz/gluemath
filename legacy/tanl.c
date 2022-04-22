/*******************************************************************************
	GLUE-Math Library -- Tangent (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/tanl.h"

long double
legacy_tanl(long double x)
{
	return tanl_core(x);
}
