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

	puts(" (b)    logbeta(1, b)    logbeta(3, b)    logbeta(5, b)    logbeta(8, b)");
	for (volatile int i = -50; i <= 50; i += 2)
	{
		const double b = i / 10.0;
		printf("% 1.1f  ", b);
		printf("%*.*s  ", DBL_DIG, DBL_DIG, lbeta_print_dbl(1, b));
		printf("%*.*s  ", DBL_DIG, DBL_DIG, lbeta_print_dbl(3, b));
		printf("%*.*s  ", DBL_DIG, DBL_DIG, lbeta_print_dbl(5, b));
		printf("%*.*s  ", DBL_DIG, DBL_DIG, lbeta_print_dbl(8, b));
		puts("");
	}
	
	return 0;
}

static char *
lbeta_print_dbl(double a, double b)
{
	static char s[0x200];
	
	snprintf(s, 0x200, "% *.*g", DBL_DIG, DBL_DIG, lbeta_r8(a, b));

	return s;
}
