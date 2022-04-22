/*******************************************************************************
	GLUE-Math Library: Logarithm of Gamma Function (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/lgammal.h"

long double
legacy_lgammal(long double x)
{
	return lgammal_core(x);
}
