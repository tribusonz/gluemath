/*******************************************************************************
	GLUE-Math test suite: Cosine and Arccosine
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

// Declare Prototypes
void acos_re_test(void);
void acos_r8_test(void);
void acos_r4_test(void);

int
main(void)
{
	rmath_title_print("Cosine and Arccosine");

	puts("for long double");
	acos_re_test();
	puts("");
	puts("for double");
	acos_r8_test();
	puts("");
	puts("for float");
	acos_r4_test();
	return 0;
}

void
acos_re_test(void)
{
	long double x, y;

	printf("  x    %-*s  左のcos\n", LDBL_DIG + 2, "自家製acos");
	for (volatile int i = -10; i <= 10; i++) {
		x = i / 10.0L;  y = acos_re(x);
		printf("%5.2Lf  %*.*Lf  % Lg\n",
			x, LDBL_DIG + 2, LDBL_DIG - 1, y, cos_re(y));
	}
}

void
acos_r8_test(void)
{
	double x, y;

	printf("  x    %-*s  左のcos\n", DBL_DIG + 2, "自家製acos");
	for (volatile int i = -10; i <= 10; i++) {
		x = i / 10.0;  y = acos_r8(x);
		printf("%5.2f  %*.*f  % g\n",
			x, DBL_DIG + 2, DBL_DIG - 1, y, cos_r8(y));
	}
}

void
acos_r4_test(void)
{
	float x, y;

	printf("  x    %-*s  左のcos\n", FLT_DIG + 2, "自家製acos");
	for (volatile int i = -10; i <= 10; i++) {
		x = i / 10.0;  y = acos_r4(x);
		printf("%5.2f  %*.*f  % g\n",
			x, FLT_DIG + 2, FLT_DIG - 1, y, cos_r4(y));
	}
}
