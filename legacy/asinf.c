/*******************************************************************************
	GLUE-Math Library: Arcsine (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/asinf.h"

float
legacy_asinf(float x)
{
	return asinf_core(x);
}
