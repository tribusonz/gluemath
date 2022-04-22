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
#include "../internal/ur/geomcdfinv.h"

double
gml_geomcdfinv(double q, double phi)
{
	return geomcdfinv_core(q, phi);
}
