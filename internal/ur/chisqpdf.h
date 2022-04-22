/*******************************************************************************
	GLUE-Math Library: Chi-Square Distribution PDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		John Burkardt's Home Page
*******************************************************************************/
#ifndef GML_CHISQPDF_INTERNAL
#define GML_CHISQPDF_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "log.h"
#include "exp.h"
#include "lgamma.h"

static inline double
chisqpdf_core(register double x, register int df)
{
	register double temp1, temp2, logx, value;
	static const double LOG2 =  0.693147180559945309; /*$\ln{2}$*/

	if (x < 0 || x != x)
		value = 0;
	else
	{
		if (df % 2)  // df is odd
		{
			temp2 = df * 0.5;
			temp1 = (temp2 - 1.0) * log_core(x) - 0.5 * x
			       - temp2 * LOG2 - lgamma_core(temp2);
			value = exp_core(temp1);
		}
		else         // df is even
		{
			logx = log_core(x);
			if (isinf(logx))  logx = 0.0;
			temp2 = df * 0.5;
			temp1 = (temp2 - 1.0) * logx - 0.5 * x
			       - temp2 * LOG2 - lgamma_core(temp2);
			value = exp_core(temp1);
		}
	}
	return value;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_CHISQCDF_INTERNAL */
