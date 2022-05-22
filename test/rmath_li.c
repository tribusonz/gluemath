/*******************************************************************************
	GLUE-Math test suite: Logarithmic Integral
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <float.h>

int
main(void)
{
	rmath_title_print("Logarithmic Integral");

	for (volatile int i = 0; i < 20; i++)
	{
		const double x = i / 10.0;  // Iterator Constant
		printf("Li(% 2.1f) = % *.*f\n", x, DBL_DIG, DBL_DIG, li_r8(x));
	}
	for (volatile int i = 20; i <= 40; i++)
	{
		const double x = i / 10.0;  // Iterator Constant
		printf("Li(% 2.1f) = % *.*f\n", x, DBL_DIG, DBL_DIG, li_r8(x));
	}

	return 0;
}
