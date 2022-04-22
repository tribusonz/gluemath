/*******************************************************************************
	GLUE-Math Library: Standard Normal Distribution complementary inverse CDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Following paper:
		Algorithm 955: approximation of the inverse Poisson cumulative
		               distribution function
			by Michael B. Giles, University of Oxford, UK
*******************************************************************************/
#include "dist.h"
#include "../internal/ur/snormcdfinv.h"

double
gml_snormcdfcinv(double q)
{
	return snormcdfinv_core(1-q);
}
