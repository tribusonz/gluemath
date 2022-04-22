/*******************************************************************************
	GLUE-Math Library: Arcsine
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/asin.h"

double
legacy_asin(double x)
{
	return asin_core(x);
}
