/*******************************************************************************
	GLUE-Math test suite: Hyperbolic Cosine and Hyperbolic Arccosine
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

// Declare Prototypes
void acosh_re_test(void);
void acosh_r8_test(void);
void acosh_r4_test(void);

int
main(void)
{
	rmath_title_print("Hyperbolic Cosine and Hyperbolic Arccosine");

	puts("for long double");
	acosh_re_test();
	puts("");
	puts("for double");
	acosh_r8_test();
	puts("");
	puts("for float");
	acosh_r4_test();
	return 0;
}

void
acosh_re_test(void)
{
	long double x, y;

	printf("  x    %-*s  左のcosh\n", LDBL_DIG + 2, "自家製acosh");
	for (volatile int i = 10; i <= 50; i += 5) {
		x = i / 10.0L;  y = acosh_re(x);
		printf("%5.2Lf  %*.*Lf  % Lg\n",
			x, LDBL_DIG + 2, LDBL_DIG - 1, y, cosh_re(y));
	}
}

void
acosh_r8_test(void)
{
	double x, y;

	printf("  x    %-*s  左のcosh\n", DBL_DIG + 2, "自家製acosh");
	for (volatile int i = 10; i <= 50; i += 5) {
		x = i / 10.0;  y = acosh_r8(x);
		printf("%5.2f  %*.*f  % g\n",
			x, DBL_DIG + 2, DBL_DIG - 1, y, cosh_r8(y));
	}
}

void
acosh_r4_test(void)
{
	float x, y;

	printf("  x    %-*s  左のcosh\n", FLT_DIG + 2, "自家製acosh");
	for (volatile int i = 10; i <= 50; i += 5) {
		x = i / 10.0;  y = acosh_r4(x);
		printf("%5.2f  %*.*f  % g\n",
			x, FLT_DIG + 2, FLT_DIG - 1, y, cosh_r4(y));
	}
}
