/*******************************************************************************
	GLUE-Math test suite: Logarithm of Gamma Function
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

// Prototypes
static void lgamma_r4_print(void);
static void lgamma_r8_print(void);
static void lgamma_re_print(void);

int
main(void)
{
	rmath_title_print("Logarithm of Euler Gamma Function");

	lgamma_r4_print();
	lgamma_r8_print();
	lgamma_re_print();
	return 0;
}

static void
lgamma_r8_print(void)
{
	puts("for double:");
	printf("  x    LogGamma(x)\n");
	for (volatile int i = -50; i <= 50; i += 2)
	{
		const double x = i / 10.0; // Iterator Constant
		printf("%4.1f  % .*g\n", x, DBL_DIG, lgamma_r8(x));
	}
	puts("");
}

static void
lgamma_re_print(void)
{
	puts("for long double:");
	printf("  x    LogGamma(x)\n");
	for (volatile int i = -50; i <= 50; i += 2)
	{
		const long double x = i / 10.0; // Iterator Constant
		printf("%4.1Lf  % .*Lg\n", x, LDBL_DIG, lgamma_re(x));
	}
	puts("");
}

static void
lgamma_r4_print(void)
{
	puts("for float:");
	printf("  x    LogGamma(x)\n");
	for (volatile int i = -50; i <= 50; i += 2)
	{
		const float x = i / 10.0; // Iterator Constant
		printf("%4.1f  % .*g\n", x, FLT_DIG, lgamma_r4(x));
	}
	puts("");
}
