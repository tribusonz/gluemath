/*******************************************************************************
	GLUE-Math test suite: Euler Beta Function
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

// Declare Prototype
static char *beta_print_dbl(double a, double b);

int
main(void)
{
	rmath_title_print("Euler Beta Function");

	rmath_calctest_title_print();

	rmath_polympatt_print("Real 2 variables", "Real solution");
	rmath_methname_print("beta(a, b)");
	printf(" %3.3s  % *.*s  % *.*s  % *.*s  % *.*s\n", "(b)",
	       DBL_DIG + 2, DBL_DIG + 2, "beta(1, b)",
	       DBL_DIG + 2, DBL_DIG + 2, "beta(3, b)",
	       DBL_DIG + 2, DBL_DIG + 2, "beta(5, b)",
	       DBL_DIG + 2, DBL_DIG + 2, "beta(8, b)");
	for (volatile int i = -50; i <= 50; i += 2)
	{
		const double b = i / 10.0;
		printf("% 1.1f  ", b);
		printf("%s  ", beta_print_dbl(1, b));
		printf("%s  ", beta_print_dbl(3, b));
		printf("%s  ", beta_print_dbl(5, b));
		printf("%s  ", beta_print_dbl(8, b));
		puts("");
	}
	
	return 0;
}

static char *
beta_print_dbl(double a, double b)
{
	static char s[0x200];
	
	snprintf(s, 0x200, "% *.*s", DBL_DIG + 2, DBL_DIG + 2, dbl_inspect_g(beta_r8(a, b), UNARY_AUTO));

	return s;
}
