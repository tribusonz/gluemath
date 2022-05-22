/*******************************************************************************
	GLUE-Math test routine: sinc()
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#define PI 3.1415926535897932

int
main(void)
{
	rmath_title_print("Sinc Function");

	printf("%5s   %12s\n", "(x)", "sinc(x * PI)");
	for (volatile int i = -30; i <= 30; i++)
	{
		const double x = i / 10.0;
		printf("%5.1f  % 15.15f\n", x, sinc_r8(x * PI));
	}
	return 0;
}
