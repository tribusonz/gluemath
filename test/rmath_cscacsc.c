/*******************************************************************************
	GLUE-Math test suite: Cosecant and Arccosecant
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

// Declare Prototypes
void acsc_re_test(void);
void acsc_r8_test(void);
void acsc_r4_test(void);

int
main(void)
{
	rmath_title_print("Cosecant and Arccosecant");

	puts("for long double"); acsc_re_test();

	puts("");

	puts("for double"); acsc_r8_test();

	puts("");

	puts("for float"); acsc_r4_test();

	return 0;
}

void
acsc_re_test(void)
{
	long double x, y;

	printf("  x    %-*s  左のcsc\n", LDBL_DIG + 2, "自家製acsc");
	for (volatile int i = -90; i <= 90; i += 5) {
		if (i > -10 && i < 10)  continue;
		x = i / 10.0L;  y = acsc_re(x);
		printf("%5.2Lf  %*.*Lf  % Lg\n",
			x, LDBL_DIG + 2, LDBL_DIG - 1, y, csc_re(y));
	}
}

void
acsc_r8_test(void)
{
	double x, y;

	printf("  x    %-*s  左のcsc\n", DBL_DIG + 2, "自家製acsc");
	for (volatile int i = -90; i <= 90; i += 5) {
		if (i > -10 && i < 10)  continue;
		x = i / 10.0;  y = acsc_r8(x);
		printf("%5.2f  %*.*f  % g\n",
			x, DBL_DIG + 2, DBL_DIG - 1, y, csc_r8(y));
	}
}

void
acsc_r4_test(void)
{
	float x, y;

	printf("  x    %-*s  左のcsc\n", FLT_DIG + 2, "自家製acsc");
	for (volatile int i = -90; i <= 90; i += 5) {
		if (i > -10 && i < 10)  continue;
		x = i / 10.0;  y = acsc_r4(x);
		printf("%5.2f  %*.*f  % g\n",
			x, FLT_DIG + 2, FLT_DIG - 1, y, csc_r4(y));
	}
}
