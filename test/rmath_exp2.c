/*******************************************************************************
	GLUE-Math test suite: Binary Exponent
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int
main(void)
{
	int i;

	rmath_title_print("Binary Exponent");

	puts("++++ Calculation test ++++");
	puts("(x), exp2(x), float/double/long-double");
	for (i = -10; i <= 10; i++)
	{
		const double x = i / 4.0;  // Iterator constant
		printf("%5.2f  %*.*f %*.*f %*.*Lf\n",
		    x, FLT_DIG + 3,  FLT_DIG, exp2_r4((float)x),
		       DBL_DIG + 3,  DBL_DIG, exp2_r8(x),
		      LDBL_DIG + 3, LDBL_DIG, exp2_re((long double)x));
	}
	
	puts("");

	puts("++++ Check handling of Infinity & NaN ++++");
	
	puts("for float");
	printf("exp2(FLT_MAX_EXP) = %f\n", exp2_r4(FLT_MAX_EXP));
	printf("exp2(FLT_MIN_EXP) = %f\n", exp2_r4(FLT_MIN_EXP));
	printf("exp2(Infinity) = %f\n", exp2_r4(1.0/0.0));
	printf("exp2(-Infinity) = %f\n", exp2_r4(-1.0/0.0));
	printf("exp2(NaN) = %f\n", exp2_r4(0.0/0.0));
	for (i = 0; 0.0 != exp2_r4(i); i--);
	printf("Available Calculation Range: %d", i);
	for (i = 0; (1.0/0.0) != exp2_r4(i); i++);
	printf("..%d\n", i);

	puts("");

	puts("for double");
	printf("exp2(DBL_MAX_EXP) = %f\n", exp2_r8(DBL_MAX_EXP));
	printf("exp2(DBL_MIN_EXP) = %f\n", exp2_r8(DBL_MIN_EXP));
	printf("exp2(Infinity) = %f\n", exp2_r8(1.0/0.0));
	printf("exp2(-Infinity) = %f\n", exp2_r8(-1.0/0.0));
	printf("exp2(NaN) = %f\n", exp2_r8(0.0/0.0));
	for (i = 0; 0.0 != exp2_r8(i); i--);
	printf("Available Calculation Range: %d", i);
	for (i = 0; (1.0/0.0) != exp2_r8(i); i++);
	printf("..%d\n", i);

	puts("");

	puts("for long double:");
	printf("exp2(LDBL_MAX_EXP) = %Lf\n", exp2_re(LDBL_MAX_EXP));
	printf("exp2(LDBL_MIN_EXP) = %Lf\n", exp2_re(LDBL_MIN_EXP));
	printf("exp2(Infinity) = %Lf\n", exp2_re(1.0/0.0));
	printf("exp2(-Infinity) = %Lf\n", exp2_re(-1.0/0.0));
	printf("exp2(NaN) = %Lf\n", exp2_re(0.0/0.0));
	for (i = 0; 0.0 != exp2_re(i); i--);
	printf("Available Calculation Range: %d", i);
	for (i = 0; (1.0/0.0) != exp2_re(i); i++);
	printf("..%d\n", i);
	
	return 0;
}
