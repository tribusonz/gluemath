/*******************************************************************************
	GLUE-Math test suite: Hyperbolic Cosecant and Hyperbolic Arccosecant
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

// Declare Prototypes
void acsch_re_test(void);
void acsch_r8_test(void);
void acsch_r4_test(void);

int
main(void)
{
	rmath_title_print("Hyperbolic Cosecant and Hyperbolic Arccosecant");

	puts("for long double"); acsch_re_test();

	puts("");

	puts("for double"); acsch_r8_test();

	puts("");

	puts("for float"); acsch_r4_test();

	return 0;
}

void
acsch_re_test(void)
{
	long double x, y;

	printf("  x    %-*s  左のcsch\n", LDBL_DIG + 2, "自家製acsch");
	for (volatile int i = -40; i <= 40; i += 5) {
		x = i / 10.0L;  y = acsch_re(x);
		printf("%5.2Lf  %*.*Lf  % Lg\n",
			x, LDBL_DIG + 2, LDBL_DIG - 1, y, csch_re(y));
	}
}

void
acsch_r8_test(void)
{
	double x, y;

	printf("  x    %-*s  左のcsch\n", DBL_DIG + 2, "自家製acsch");
	for (volatile int i = -40; i <= 40; i += 5) {
		x = i / 10.0;  y = acsch_r8(x);
		printf("%5.2f  %*.*f  % g\n",
			x, DBL_DIG + 2, DBL_DIG - 1, y, csch_r8(y));
	}
}

void
acsch_r4_test(void)
{
	float x, y;

	printf("  x    %-*s  左のcsch\n", FLT_DIG + 2, "自家製acsch");
	for (volatile int i = -40; i <= 40; i += 5) {
		x = i / 10.0;  y = acsch_r4(x);
		printf("%5.2f  %*.*f  % g\n",
			x, FLT_DIG + 2, FLT_DIG - 1, y, csch_r4(y));
	}
}
