/*******************************************************************************
	GLUE-Math test suite: Binary Logarithm
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int
main(void)
{
	rmath_title_print("Binary Logarithm");

	printf("  %3.3s   %-*.*s  %-*.*s  %-*.*s\n", "(x)",
	       FLT_DIG + 2, FLT_DIG + 2, "float",
	       DBL_DIG + 2, DBL_DIG + 2, "double",
	       LDBL_DIG + 2, LDBL_DIG + 2, "long double");
	for (int i = 1; i <= 20; i++) {
		const double x = i / 5.0;  // Iterator Constant
		printf("%5.1f  %*.*f %*.*f %*.*Lf\n",
		    x, FLT_DIG + 3, FLT_DIG, log2_r4(x),
		    DBL_DIG + 3, DBL_DIG, log2_r8(x),
		    LDBL_DIG + 3, LDBL_DIG, log2_re(x));
	}
	return 0;
}
