/*******************************************************************************
	GLUE-Math Library: Normal Distribution CDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "dist.h"
#include "../internal/ur/normcdf.h"

double
gml_normcdf(double z, double mu, double sigma)
{
	return normcdf_core(z, mu, sigma);
}
