/*******************************************************************************
	GLUE-Math test suite: Exponential Integral
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <float.h>

int
main(void)
{
	rmath_title_print("Exponential Integral");

	for (volatile int i = -90; i < -10; i += 5)
	{
		const double x = i / 10.0;  // Iterator Constant
		printf("Ei(% 2.1f) = % *.*g\n", x, DBL_DIG, DBL_DIG, ei_r8(x));
	}
	for (volatile int i = -10; i < 10; i++)
	{
		const double x = i / 10.0;  // Iterator Constant
		printf("Ei(% 2.1f) = % *.*g\n", x, DBL_DIG, DBL_DIG, ei_r8(x));
	}
	for (volatile int i = 10; i <= 90; i += 5)
	{
		const double x = i / 10.0;  // Iterator Constant
		printf("Ei(% 2.1f) = % *.*g\n", x, DBL_DIG, DBL_DIG, ei_r8(x));
	}

	return 0;
}
