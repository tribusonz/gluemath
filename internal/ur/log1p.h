/*******************************************************************************
	GLUE-Math Library: log1p() function

	Author:
	  John Burkardt (Original Code)
	  Hironobu Inatsuka aka tribusonz (ABI modify)

	License:
	  John Burkardt's (See below term)
	  GPL + X11(MIT)  (ABI modify)
********************************************************************************

  - Reposts John Burkardt's Copyrights -

  Purpose:
    LOG1P evaluates the function ln ( 1 + A ).

  Licensing:
    This code is distributed under the GNU LGPL license. 

  Modified:

    14 February 2021

  Reference:

    Armido DiDinato, Alfred Morris,
    Algorithm 708:
    Significant Digit Computation of the Incomplete Beta Function Ratios,
    ACM Transactions on Mathematical Software,
    Volume 18, 1993, pages 360-373.

  Input:

    Input, double A, the argument.

  Output:

    Output, double LOG1P, the value of ln ( 1 + A ).

*******************************************************************************/
#ifndef GML_LOG1P_DBL_INTERNAL
#define GML_LOG1P_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: fabs(), log()
#include "../../sys/float/absolute.h"
#include "log.h"

static inline double
log1p_core(double a)
{
	double p1 = -0.129418923021993e+01;
	double p2 =  0.405303492862024e+00;
	double p3 = -0.178874546012214e-01;
	double q1 = -0.162752256355323e+01;
	double q2 =  0.747811014037616e+00;
	double q3 = -0.845104217945565e-01;
	double t, t2, value, w, x;

	if (fabs(a) <= 0.375)
	{
		t = a / (a + 2.0e0);
		t2 = t * t;
		w = (((p3 * t2 + p2) * t2 + p1) * t2 + 1.0)
		  / (((q3 * t2 + q2) * t2 + q1) * t2 + 1.0);
		value = 2.0 * t * w;
	}
	else
	{
		x = 1.0 + a;
		value = log_core(x);
	}

	return value;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_LOG1P_DBL_INTERNAL */
