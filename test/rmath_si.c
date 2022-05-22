/*******************************************************************************
	GLUE-Math Library: si()
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	double x;

	rmath_title_print("Sine Integral");

	printf(" x     Si(x)\n");
	for (x = 0; x <= 50; x++)
		printf("%2.0f  %.10f\n", x, si_r8(x));
	return 0;
}
