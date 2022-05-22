/*******************************************************************************
	GLUE-Math test routine: sinh()/asinh()
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

// Declare Prototypes
void asinh_re_test(void);
void asinh_r8_test(void);
void asinh_r4_test(void);

int
main(void)
{
	rmath_title_print("Hyperboline Sine and Hyperbolic Arcsine");

	puts("for long double");
	asinh_re_test();
	puts("");
	puts("for double");
	asinh_r8_test();
	puts("");
	puts("for float");
	asinh_r4_test();
	return 0;
}

void
asinh_re_test(void)
{
	long double x, y;

	printf("  x    %-*s  左のsinh\n", LDBL_DIG + 2, "自家製asinh");
	for (volatile int i = -40; i <= 40; i += 5) {
		x = i / 10.0L;  y = asinh_re(x);
		printf("%5.2Lf  %*.*Lf  % Lg\n",
			x, LDBL_DIG + 2, LDBL_DIG - 1, y, sinh_re(y));
	}
}

void
asinh_r8_test(void)
{
	double x, y;

	printf("  x    %-*s  左のsinh\n", DBL_DIG + 2, "自家製asinh");
	for (volatile int i = -40; i <= 40; i += 5) {
		x = i / 10.0;  y = asinh_r8(x);
		printf("%5.2f  %*.*f  % g\n",
			x, DBL_DIG + 2, DBL_DIG - 1, y, sinh_r8(y));
	}
}

void
asinh_r4_test(void)
{
	float x, y;

	printf("  x    %-*s  左のsinh\n", FLT_DIG + 2, "自家製asinh");
	for (volatile int i = -40; i <= 40; i += 5) {
		x = i / 10.0;  y = asinh_r4(x);
		printf("%5.2f  %*.*f  % g\n",
			x, FLT_DIG + 2, FLT_DIG - 1, y, sinh_r4(y));
	}
}
