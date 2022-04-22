/*******************************************************************************
	GLUE-Math Library: Geometric Distribution Inverse CDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Following paper:
		Algorithm 955: approximation of the inverse Poisson cumulative
		               distribution function
			by Michael B. Giles, University of Oxford, UK
******************************************************************************/
#include "dist.h"
#include "../internal/ur/geomcdfcinv.h"

double
gml_geomcdfcinv(double q, double phi)
{
	return geomcdfcinv_core(q, phi);
}
