/*******************************************************************************
	GLUE-Math test suite: Regularized Incomplete Gamma Function
******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

// Declare Prototypes
static void gammaincr_r8_print(double a);

int
main(void)
{
	rmath_title_print("Regularized Incomplete Gamma Function");
	
	gammaincr_r8_print(1);
	gammaincr_r8_print(2.5);
	gammaincr_r8_print(5);
	
	return 0;
}

static void
gammaincr_r8_print(double a)
{
	printf("  a = %g\n", a);
	printf("%5.5s  %*s  %*s\n", "(x)", DBL_DIG + 2, "P(a,x)", DBL_DIG + 2, "Q(a,x)");
	for (volatile int i = 0; i <= 25; i++)
	{
		const double x = 0.2 * i;  // Iterator Constant
		printf("%5.1f  ", x);
		printf("%.*f  ", DBL_DIG, gammaincr1_r8(a, x));
		printf("%.*f\n", DBL_DIG, gammaincr2_r8(a, x));
	}
	puts("");
}
