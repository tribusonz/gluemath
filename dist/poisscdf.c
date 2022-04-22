/*******************************************************************************
	GLUE-Math Library: Poisson Distribution CDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
******************************************************************************/
#include "dist.h"
#include "../internal/ur/poisscdf.h"

double
gml_poisscdf(double x, double lambda)
{
	return poisscdf_core(x, lambda);
}
