/*******************************************************************************
	GLUE-Math Library -- Tangent (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/tanf.h"

float
legacy_tanf(float x)
{
	return tanf_core(x);
}