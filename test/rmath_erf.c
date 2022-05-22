/*******************************************************************************
	GLUE-Math test suite: Gaussian Error Function
*******************************************************************************/
#include "../sys/float/huge_val_nan.h"
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <float.h>

int
main(void)
{
	rmath_title_print("Gaussian Error Function");

	printf("%4s  %16s\n", "(x)", "erf(x)");
	for (volatile int i = -60; i <= 60; i += 5)
	{
		const double x = i / 10.0; // Iterator Constant
		printf("% 3.1f % *.*f % *.*f % *.*Lf\n", x,
		       FLT_DIG + 3, FLT_DIG, erf_r4(x),
		       DBL_DIG + 3, DBL_DIG, erf_r8(x),
		       LDBL_DIG + 3, LDBL_DIG, erf_re(x));
	}
	puts("");
	puts("++++ Check Infinity & NaN ++++");
	puts("double:");
	printf("erf(Infinity) = %g\n", erf_r8(HUGE_VAL));
	printf("erf(-Infinity) = %g\n", erf_r8(-HUGE_VAL));
	printf("erf(NaN) = %g\n", erf_r8(NAN));
	puts("long double:");
	printf("erf(Infinity) = %Lg\n", erf_re(HUGE_VALL));
	printf("erf(-Infinity) = %Lg\n", erf_re(-HUGE_VALL));
	printf("erf(NaN) = %Lg\n", erf_re(NAN));
	puts("float:");
	printf("erf(Infinity) = %g\n", erf_r4(HUGE_VALF));
	printf("erf(-Infinity) = %g\n", erf_r4(-HUGE_VALF));
	printf("erf(NaN) = %g\n", erf_r4(NAN));
	
	return 0;
}
