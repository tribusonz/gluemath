/*******************************************************************************
	GLUE-Math Library: Standard Normal Distribution PDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "dist.h"
#include "../internal/ur/snormpdf.h"

double
gml_snormpdf(double z)
{
	return snormpdf_core(z);
}
