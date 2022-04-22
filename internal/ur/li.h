/*******************************************************************************
	GLUE-Math Library: Logarithmic Integral
	
	Author:
	  William H. Press, Saul A. Teukolsky, William T. Vetterling, Brian P. Flannery
	  Hironobu Inatsuka aka tribusonz
	License:
	  GPL + X11(MIT)
	Reference:
	  Numerical Recipes in C; 3rd edition
*******************************************************************************/
#ifndef GML_LI_DBL_INTERNAL
#define GML_LI_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "log.h"
#include "ei.h"

static inline double
li_core(register double x)
{
	return ei_core(log_core(x));
}


#if defined(__cplusplus)
}
#endif

#endif /* GML_LI_DBL_INTERNAL */
