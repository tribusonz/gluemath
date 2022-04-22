/*******************************************************************************
	GLUE-Math Library: Normal Distribution complementary CDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "dist.h"
#include "../internal/ur/normcdf.h"

double
gml_normcdfc(double z, double mu, double sigma)
{
	return 1 - normcdf_core(z, mu, sigma);
}
