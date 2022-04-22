/*******************************************************************************
	GLUE-Math Library: Sine (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/sinf.h"

float
legacy_sinf(float x)
{
	return sinf_core(x);
}
