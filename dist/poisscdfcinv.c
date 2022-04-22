/*******************************************************************************
	GLUE-Math Library: Poissson Distribution Inverse CDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Following paper:
		Algorithm 955: approximation of the inverse Poisson cumulative
		               distribution function
			by Michael B. Giles, University of Oxford, UK
******************************************************************************/
#include "dist.h"
#include "../internal/ur/poisscdfcinv.h"

double
gml_poisscdfcinv(double q, double lambda)
{
	return poisscdfcinv_core(q, lambda);
}
