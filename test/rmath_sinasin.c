/*******************************************************************************
	GLUE-Math test routine: asin()
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

// Declare Prototypes
void asin_re_test(void);
void asin_r8_test(void);
void asin_r4_test(void);

int
main(void)
{
	rmath_title_print("Sine and Arcsine");

	puts("for long double");
	asin_re_test();
	puts("");
	puts("for double");
	asin_r8_test();
	puts("");
	puts("for float");
	asin_r4_test();
	return 0;
}

void
asin_re_test(void)
{
	long double x, y;

	printf("  x    %-*s  左のsin\n", LDBL_DIG + 2, "自家製asin");
	for (volatile int i = -10; i <= 10; i++) {
		x = i / 10.0L;  y = asin_re(x);
		printf("%5.2Lf  %*.*Lf  % Lg\n",
			x, LDBL_DIG + 2, LDBL_DIG - 1, y, sin_re(y));
	}
}

void
asin_r8_test(void)
{
	double x, y;

	printf("  x    %-*s  左のsin\n", DBL_DIG + 2, "自家製asin");
	for (volatile int i = -10; i <= 10; i++) {
		x = i / 10.0;  y = asin_r8(x);
		printf("%5.2f  %*.*f  % g\n",
			x, DBL_DIG + 2, DBL_DIG - 1, y, sin_r8(y));
	}
}

void
asin_r4_test(void)
{
	float x, y;

	printf("  x    %-*s  左のsin\n", FLT_DIG + 2, "自家製asin");
	for (volatile int i = -10; i <= 10; i++) {
		x = i / 10.0;  y = asin_r4(x);
		printf("%5.2f  %*.*f  % g\n",
			x, FLT_DIG + 2, FLT_DIG - 1, y, sin_r4(y));
	}
}
