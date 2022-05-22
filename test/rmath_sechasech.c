/*******************************************************************************
	GLUE-Math test routine: sech()/asech()
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

// Declare Prototypes
void asech_re_test(void);
void asech_r8_test(void);
void asech_r4_test(void);

int
main(void)
{
	rmath_title_print("Hyperbolic Secant and Hyperbolic Arcsecant");
	
	puts("for long double");
	asech_re_test();
	puts("");
	puts("for double");
	asech_r8_test();
	puts("");
	puts("for float");
	asech_r4_test();
	return 0;
}

void
asech_re_test(void)
{
	long double x, y;

	printf("  x    %-*s  左のsech\n", LDBL_DIG + 2, "自家製asech");
	for (volatile int i = 0; i <= 10; i++) {
		x = i / 10.0L;  y = asech_re(x);
		printf("%5.2Lf  %*.*Lf  % Lg\n",
			x, LDBL_DIG + 2, LDBL_DIG - 1, y, sech_re(y));
	}
}

void
asech_r8_test(void)
{
	double x, y;

	printf("  x    %-*s  左のsech\n", DBL_DIG + 2, "自家製asech");
	for (volatile int i = 0; i <= 10; i++) {
		x = i / 10.0;  y = asech_r8(x);
		printf("%5.2f  %*.*f  % g\n",
			x, DBL_DIG + 2, DBL_DIG - 1, y, sech_r8(y));
	}
}

void
asech_r4_test(void)
{
	float x, y;

	printf("  x    %-*s  左のsech\n", FLT_DIG + 2, "自家製asech");
	for (volatile int i = 0; i <= 10; i++) {
		x = i / 10.0;  y = asech_r4(x);
		printf("%5.2f  %*.*f  % g\n",
			x, FLT_DIG + 2, FLT_DIG - 1, y, sech_r4(y));
	}
}
