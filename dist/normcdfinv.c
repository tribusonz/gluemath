/*******************************************************************************
	GLUE-Math Library: Normal Distribution Inverse CDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		John Burkardt's Home Page
		 - John Burkardt
******************************************************************************/
#include "dist.h"
#include "../internal/ur/normcdfinv.h"

double
gml_normcdfinv(double q, double mu, double sigma)
{
	return normcdfinv_core(q, mu, sigma);
}
