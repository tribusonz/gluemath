/*******************************************************************************
	GLUE-Math Test Routine: modf()

*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include "../sys/random/random.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare Prototypes
static void modf_dbl_test(void);
static void modf_ldbl_test(void);
static void modf_flt_test(void);

int
main(void)
{
	init_genrand(time(NULL));

	rmath_title_print("modf() function");

	puts("for double:");
	modf_dbl_test();
	puts("");
	puts("for long double");
	modf_ldbl_test();
	puts("");
	puts("for float");
	modf_flt_test();

	return 0;
}

static void
modf_dbl_test(void)
{
	double x, ip, frac;

	for (volatile int i = 0; i < 5; i++)
	{
		x = (genrand_res53() -0.5) * 16;
		frac = modf_r8(x, &ip);
		printf("modf(% 15.15f) = [% g, % 15.15f]\n", x, ip, frac);
	}
	for (volatile int i = 0; i < 5; i++)
	{
		x = (genrand_res53() -0.5) * 32;
		frac = modf_r8(x, &ip);
		printf("modf(% 15.15f) = [% g, % 15.15f]\n", x, ip, frac);
	}
	for (volatile int i = 0; i < 5; i++)
	{
		x = (genrand_res53() -0.5) * 64;
		frac = modf_r8(x, &ip);
		printf("modf(% 15.15f) = [% g, % 15.15f]\n", x, ip, frac);
	}
}

static void
modf_ldbl_test(void)
{
	long double x, ip, frac;

	for (volatile int i = 0; i < 5; i++)
	{
		x = (long double)(genrand_res53() - 0.5) * 16;
		frac = modf_re(x, &ip);
		printf("modf(% 18.18Lf) = [% Lg, % 18.18Lf]\n", x, ip, frac);
	}
	for (volatile int i = 0; i < 5; i++)
	{
		x = (long double)(genrand_res53() - 0.5) * 32;
		frac = modf_re(x, &ip);
		printf("modf(% 18.18Lf) = [% Lg, % 18.18Lf]\n", x, ip, frac);
	}
	for (volatile int i = 0; i < 5; i++)
	{
		x = (long double)(genrand_res53() - 0.5) * 64;
		frac = modf_re(x, &ip);
		printf("modf(% 18.18Lf) = [% Lg, % 18.18Lf]\n", x, ip, frac);
	}
}

static void
modf_flt_test(void)
{
	float x, ip, frac;

	for (volatile int i = 0; i < 5; i++)
	{
		x = (float)(genrand_res53() -0.5) * 16;
		frac = modf_r4(x, &ip);
		printf("modf(% 6.6f) = [% g, % 6.6f]\n", x, ip, frac);
	}
	for (volatile int i = 0; i < 5; i++)
	{
		x = (float)(genrand_res53() -0.5) * 32;
		frac = modf_r4(x, &ip);
		printf("modf(% 6.6f) = [% g, % 6.6f]\n", x, ip, frac);
	}
	for (volatile int i = 0; i < 5; i++)
	{
		x = (float)(genrand_res53() -0.5) * 64;
		frac = modf_r4(x, &ip);
		printf("modf(% 6.6f) = [% g, % 6.6f]\n", x, ip, frac);
	}
}
