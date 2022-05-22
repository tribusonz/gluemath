/*******************************************************************************
	GLUE-Math test suite: Inverse of Gaussian Error Function
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include "../sys/float/huge_val_nan.h"
#include <stdio.h>
#include <float.h>

int
main(void)
{
	rmath_title_print("Inverse of Gaussian Error Function");

	puts("Inverse Error Function -1 <= q <= 1");
	for (volatile int i = -11; i <= 11; i++)
	{
		const double x = i / 10.0;  // Iterator Constant
		printf("% 2.1f   % *.*f\n", x, DBL_DIG, DBL_DIG, erfinv_r8(x));
	}
	puts("");
	puts("++++ Check Infinity & NaN ++++");
	printf("erf^-1(-HUGE_VAL) = %f\n", erfinv_r8(-HUGE_VAL)); // -Infinity Check
	printf("erf^-1(HUGE_VAL) = %f\n", erfinv_r8(HUGE_VAL)); // Infinity Check
	printf("erf^-1(NAN) = %f\n", erfinv_r8(NAN)); // NaN Check
	puts("");
	puts("Inverse Complementary Error Function 0 <= q <= 2");
	for (volatile int i = -1; i <= 21; i++)
	{
		const double x = i / 10.0;  // Iterator Constant
		printf("% 2.1f   % *.*f\n", x, DBL_DIG, DBL_DIG, erfcinv_r8(x));
	}
	puts("");
	puts("++++ Check Infinity & NaN ++++");
	printf("erfc^-1(-HUGE_VAL) = %f\n", erfcinv_r8(-HUGE_VAL)); // -Infinity Check
	printf("erfc^-1(HUGE_VAL) = %f\n", erfcinv_r8(HUGE_VAL)); // Infinity Check
	printf("erfc^-1(NAN) = %f\n", erfcinv_r8(NAN)); // NaN Check
	return 0;
}
