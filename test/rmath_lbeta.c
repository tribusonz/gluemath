/*******************************************************************************
	GLUE-Math test suite: Logarithm of Euler Beta Function
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

// Declare Prototypes
static char *lbeta_print_dbl(double a, double b);

int
main(void)
{
	rmath_title_print("Logarithm of Euler Beta Function");

	puts("Polymorphism Pattern: Real 2 variables -> Real solution");
	rmath_methname_print("lbeta(a, b)");
	printf(" %3.3s  % *.*s  % *.*s  % *.*s  % *.*s\n", "(b)",
	       DBL_DIG + 2, DBL_DIG + 2, "logbeta(1, b)",
	       DBL_DIG + 2, DBL_DIG + 2, "logbeta(3, b)",
	       DBL_DIG + 2, DBL_DIG + 2, "logbeta(5, b)",
	       DBL_DIG + 2, DBL_DIG + 2, "logbeta(8, b)");
	for (volatile int i = -50; i <= 50; i += 2)
	{
		const double b = i / 10.0;
		printf("% 1.1f  ", b);
		printf("%s  ", lbeta_print_dbl(1, b));
		printf("%s  ", lbeta_print_dbl(3, b));
		printf("%s  ", lbeta_print_dbl(5, b));
		printf("%s  ", lbeta_print_dbl(8, b));
		puts("");
	}
	
	return 0;
}

static char *
lbeta_print_dbl(double a, double b)
{
	static char s[0x200];
	
	snprintf(s, 0x200, "% *.*s", DBL_DIG + 2, DBL_DIG + 2, dbl_inspect_g(lbeta_r8(a, b), UNARY_AUTO));

	return s;
}
