/*******************************************************************************
	GLUE-Math Library: Square Root (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/sqrtf.h"

float
legacy_sqrtf(float x)
{
	return sqrtf_core(x);
}
