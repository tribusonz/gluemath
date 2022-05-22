/*******************************************************************************
	GLUE-Math test suite: Hyperbolic Cotangent and Hyperbolic Arccotangent
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

// Declare Prototypes
void acoth_re_test(void);
void acoth_r8_test(void);
void acoth_r4_test(void);

int
main(void)
{
	rmath_title_print("Hyperbolic Cotangent and Hyperbolic Arccotangent");

	puts("for long double"); acoth_re_test();

	puts("");

	puts("for double"); acoth_r8_test();

	puts("");

	puts("for float"); acoth_r4_test();

	return 0;
}

void
acoth_re_test(void)
{
	long double x, y;

	printf("  x    %-*s  左のcoth\n", LDBL_DIG + 2, "自家製acoth");
	for (volatile int i = -40; i <= 40; i += 5) {
		if (i > -10 && i < 10)  continue;
		x = i / 10.0L;  y = acoth_re(x);
		printf("%5.2Lf  %*.*Lf  % Lg\n",
			x, LDBL_DIG + 2, LDBL_DIG - 1, y, coth_re(y));
	}
}

void
acoth_r8_test(void)
{
	double x, y;

	printf("  x    %-*s  左のcoth\n", DBL_DIG + 2, "自家製acoth");
	for (volatile int i = -40; i <= 40; i += 5) {
		if (i > -10 && i < 10)  continue;
		x = i / 10.0;  y = acoth_r8(x);
		printf("%5.2f  %*.*f  % g\n",
			x, DBL_DIG + 2, DBL_DIG - 1, y, coth_r8(y));
	}
}

void
acoth_r4_test(void)
{
	float x, y;

	printf("  x    %-*s  左のcoth\n", FLT_DIG + 2, "自家製acoth");
	for (volatile int i = -40; i <= 40; i += 5) {
		if (i > -10 && i < 10)  continue;
		x = i / 10.0;  y = acoth_r4(x);
		printf("%5.2f  %*.*f  % g\n",
			x, FLT_DIG + 2, FLT_DIG - 1, y, coth_r4(y));
	}
}
