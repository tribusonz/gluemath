/*******************************************************************************
	GLUE-Math Library: Normal Distribution PDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "dist.h"
#include "../internal/ur/normpdf.h"

double
gml_normpdf(double z, double mu, double sigma)
{
	return normpdf_core(z, mu, sigma);
}
