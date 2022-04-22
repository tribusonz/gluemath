/*******************************************************************************
	GLUE-Math Library: Normal Distribution Complementary Inverse CDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		John Burkardt's Home Page
		 - John Burkardt
******************************************************************************/
#include "dist.h"
#include "../internal/ur/normcdfinv.h"

double
gml_normcdfcinv(double q, double mu, double sigma)
{
	return normcdfinv_core(1-q, mu, sigma);
}
