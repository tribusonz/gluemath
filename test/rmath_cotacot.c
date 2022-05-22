/*******************************************************************************
	GLUE-Math test suite: Cotangent and Arccotangent
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

// Declare Prototypes
void acot_re_test(void);
void acot_r8_test(void);
void acot_r4_test(void);

int
main(void)
{
	rmath_title_print("Cotangent and Arccotangent");

	puts("for long double"); acot_re_test();

	puts("");

	puts("for double"); acot_r8_test();

	puts("");

	puts("for float"); acot_r4_test();

	return 0;
}

void
acot_re_test(void)
{
	long double x, y;

	printf("  x    %-*s  左のcot\n", LDBL_DIG + 2, "自家製acot");
	for (volatile int i = -20; i <= 20; i++) {
		x = i / 10.0L;  y = acot_re(x);
		printf("%5.2Lf  %*.*Lf  % Lg\n",
			x, LDBL_DIG + 2, LDBL_DIG - 1, y, cot_re(y));
	}
}

void
acot_r8_test(void)
{
	double x, y;

	printf("  x    %-*s  左のcot\n", DBL_DIG + 2, "自家製acot");
	for (volatile int i = -20; i <= 20; i++) {
		x = i / 10.0;  y = acot_r8(x);
		printf("%5.2f  %*.*f  % g\n",
			x, DBL_DIG + 2, DBL_DIG - 1, y, cot_r8(y));
	}
}

void
acot_r4_test(void)
{
	float x, y;

	printf("  x    %-*s  左のcot\n", FLT_DIG + 2, "自家製acot");
	for (volatile int i = -20; i <= 20; i++) {
		x = i / 10.0;  y = acot_r4(x);
		printf("%5.2f  %*.*f  % g\n",
			x, FLT_DIG + 2, FLT_DIG - 1, y, cot_r4(y));
	}
}
