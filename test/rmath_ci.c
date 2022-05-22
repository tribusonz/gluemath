/*******************************************************************************
	GLUE-Math test suite: Cosine Integral
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	double x;

	rmath_title_print("Cosine Integral");

	printf(" x     Ci(x)\n");
	for (x = 0; x <= 50; x++)
		printf("%2.0f  % .10f\n", x, ci_r8(x));
	return 0;
}
