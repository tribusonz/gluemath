/*******************************************************************************
	GLUE-Math Library: Poisson Distribution Inverse CDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Following paper:
		Algorithm 955: approximation of the inverse Poisson cumulative
		               distribution function
			by Michael B. Giles, University of Oxford, UK
******************************************************************************/
#include "dist.h"
#include "../internal/ur/poisscdfinv.h"

double
gml_poisscdfinv(double q, double lambda)
{
	return poisscdfinv_core(q, lambda);
}
