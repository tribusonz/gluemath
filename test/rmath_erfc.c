/*******************************************************************************
	GLUE-Math test suite: Gaussian Complementary Error Function
*******************************************************************************/
#include "../sys/float/huge_val_nan.h"
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <float.h>

int
main(void)
{
	rmath_title_print("Gaussian Complementary Error Function");

	printf("%4s  %16s\n", "(x)", "erfc(x)");
	for (volatile int i = -60; i <= 60; i += 5)
	{
		const double x = i / 10.0; // Iterator Constant
		printf("% 3.1f % *.*f % *.*f % *.*Lf\n", x,
		       FLT_DIG + 3, FLT_DIG, erfc_r4(x),
		       DBL_DIG + 3, DBL_DIG, erfc_r8(x),
		       LDBL_DIG + 3, LDBL_DIG, erfc_re(x));
	}
	puts("");
	puts("++++ Check Infinity & NaN ++++");
	puts("double:");
	printf("erfc(Infinity) = %g\n", erfc_r8(HUGE_VAL));
	printf("erfc(-Infinity) = %g\n", erfc_r8(-HUGE_VAL));
	printf("erfc(NaN) = %g\n", erfc_r8(NAN));
	puts("long double:");
	printf("erfc(Infinity) = %Lg\n", erfc_re(HUGE_VALL));
	printf("erfc(-Infinity) = %Lg\n", erfc_re(-HUGE_VALL));
	printf("erfc(NaN) = %Lg\n", erfc_re(NAN));
	puts("float:");
	printf("erfc(Infinity) = %g\n", erfc_r4(HUGE_VALF));
	printf("erfc(-Infinity) = %g\n", erfc_r4(-HUGE_VALF));
	printf("erfc(NaN) = %g\n", erfc_r4(NAN));
	
	return 0;
}
