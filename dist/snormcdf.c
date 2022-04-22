/*******************************************************************************
	GLUE-Math Library: Standard Normal Distribution CDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		John Burkardt's Home Page
		 - John Burkardt
*******************************************************************************/
#include "dist.h"
#include "../internal/ur/snormcdf.h"

double
gml_snormcdf(double z)
{
	return snormcdf_core(z);
}
