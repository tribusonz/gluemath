/*******************************************************************************
	GLUE-Math test routine: atan
*******************************************************************************/
#include "../sys/float/huge_val_nan.h"
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

// Declare Prototypes
static void atan_re_test(void);
static void atan_r8_test(void);
static void atan_r4_test(void);

int
main(void)
{
	rmath_title_print("Tangent and Arctangent");

	puts("for long double");
	atan_re_test();
	puts("");
	puts("for double");
	atan_r8_test();
	puts("");
	puts("for float");
	atan_r4_test();

	return 0;
}

static void
atan_re_test(void)
{
	long double x, y;

	printf("  x    %-*s  左のtan\n", LDBL_DIG + 2, "自家製atan");
	x = -HUGE_VALL;  y = atan_re(x);
	printf("%5.2Lf  %*.*Lf  % Lg\n", x, LDBL_DIG + 2, LDBL_DIG - 1, y, tan_re(y));
	for (volatile int i = -10; i <= 10; i++) {
		x = i / 4.0L;  y = atan_re(x);
		printf("%5.2Lf  %*.*Lf  % Lg\n",
			x, LDBL_DIG + 2, LDBL_DIG - 1, y, tan_re(y));
	}
	x = HUGE_VALL;  y = atan_re(x);
	printf("%5.2Lf  %*.*Lf  % Lg\n", x, LDBL_DIG + 2, LDBL_DIG - 1, y, tan_re(y));
}

static void
atan_r8_test(void)
{
	double x, y;

	printf("  x    %-*s  左のtan\n", DBL_DIG + 2, "自家製atan");
	x = -HUGE_VAL;  y = atan_r8(x);
	printf("%5.2f  %*.*f  % g\n", x, DBL_DIG + 2, DBL_DIG - 1, y, tan_r8(y));
	for (volatile int i = -10; i <= 10; i++) {
		x = i / 4.0;  y = atan_r8(x);
		printf("%5.2f  %*.*f  % g\n",
			x, DBL_DIG + 2, DBL_DIG - 1, y, tan_r8(y));
	}
	x = HUGE_VAL;  y = atan_r8(x);
	printf("%5.2f  %*.*f  % g\n", x, DBL_DIG + 2, DBL_DIG - 1, y, tan_r8(y));
}

static void
atan_r4_test(void)
{
	float x, y;

	printf("  x    %-*s  左のtan\n", FLT_DIG + 2, "自家製atan");
	x = -HUGE_VALF;  y = atan_r4(x);
	printf("%5.2f  %*.*f  % g\n", x, FLT_DIG + 2, FLT_DIG - 1, y, tan_r4(y));
	for (volatile int i = -10; i <= 10; i++) {
		x = i / 4.0;  y = atan_r4(x);
		printf("%5.2f  %*.*f  % g\n",
			x, FLT_DIG + 2, FLT_DIG - 1, y, tan_r4(y));
	}
	x = HUGE_VALF;  y = atan_r4(x);
	printf("%5.2f  %*.*f  % g\n", x, FLT_DIG + 2, FLT_DIG - 1, y, tan_r4(y));
}
