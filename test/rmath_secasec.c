/*******************************************************************************
	GLUE-Math test routine: sec()/asec()
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

// Declare Prototypes
void asec_re_test(void);
void asec_r8_test(void);
void asec_r4_test(void);

int
main(void)
{
	rmath_title_print("Secant and Arcsecant");
	
	puts("for long double");
	asec_re_test();
	puts("");
	puts("for double");
	asec_r8_test();
	puts("");
	puts("for float");
	asec_r4_test();
	return 0;
}

void
asec_re_test(void)
{
	long double x, y;

	printf("  x    %-*s  左のsec\n", LDBL_DIG + 2, "自家製asec");
	for (volatile int i = -20; i <= 20; i++) {
		if (i > -10 && i < 10)  continue;
		x = i / 10.0L;  y = asec_re(x);
		printf("%5.2Lf  %*.*Lf  % Lg\n",
			x, LDBL_DIG + 2, LDBL_DIG - 1, y, sec_re(y));
	}
}

void
asec_r8_test(void)
{
	double x, y;

	printf("  x    %-*s  左のsec\n", DBL_DIG + 2, "自家製asec");
	for (volatile int i = -20; i <= 20; i++) {
		if (i > -10 && i < 10)  continue;
		x = i / 10.0;  y = asec_r8(x);
		printf("%5.2f  %*.*f  % g\n",
			x, DBL_DIG + 2, DBL_DIG - 1, y, sec_r8(y));
	}
}

void
asec_r4_test(void)
{
	float x, y;

	printf("  x    %-*s  左のsec\n", FLT_DIG + 2, "自家製asec");
	for (volatile int i = -20; i <= 20; i++) {
		if (i > -10 && i < 10)  continue;
		x = i / 10.0;  y = asec_r4(x);
		printf("%5.2f  %*.*f  % g\n",
			x, FLT_DIG + 2, FLT_DIG - 1, y, sec_r4(y));
	}
}
