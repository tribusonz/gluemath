/*******************************************************************************
	GLUE-Math Library: Standard Normal Distribution complementary CDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		John Burkardt's Home Page
		 - John Burkardt
*******************************************************************************/
#include "dist.h"
#include "../internal/ur/snormcdf.h"

double
gml_snormcdfc(double z)
{
	return 1 - snormcdf_core(z);
}
