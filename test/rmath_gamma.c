/*******************************************************************************
	GLUE-Math test suite: Gamma Function
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <float.h>

// Prototypes
static void gamma_r4_print(void);
static void gamma_r8_print(void);
static void gamma_re_print(void);

int
main(void)
{
	rmath_title_print("Euler Gamma Function");

	gamma_r4_print();
	gamma_r8_print();
	gamma_re_print();
	return 0;
}

void
gamma_r8_print(void)
{
	puts("for double");
	for (volatile int i = -50; i <= 50; i += 2)
	{
		const double x = i / 10.0; // Iterator Constant
		printf("Gamma(% 1.1f) = % *.*f\n", x, DBL_DIG, DBL_DIG, gamma_r8(x));
	}
	puts("");
}

void
gamma_re_print(void)
{
	puts("for long double");
	for (volatile int i = -50; i <= 50; i += 2)
	{
		const long double x = i / 10.0; // Iterator Constant
		printf("Gamma(% 1.1Lf) = % *.*Lf\n", x, LDBL_DIG, LDBL_DIG, gamma_re(x));
	}
	puts("");
}

void
gamma_r4_print(void)
{
	puts("for float");
	for (volatile int i = -50; i <= 50; i += 2)
	{
		const float x = i / 10.0; // Iterator Constant
		printf("Gamma(% 1.1f) = % *.*f\n", x, FLT_DIG, FLT_DIG, gamma_r4(x));
	}
	puts("");
}
