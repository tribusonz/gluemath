/*******************************************************************************
	GLUE-Math test routine: Riemann Zeta Function
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	double x;

	rmath_title_print("Riemann Zeta Function");

	for (x = -14; x <= 20; x++)
		printf("zeta(% 3.0f) = % 17.15f\n", x, riemann_zeta_r8(x));
	return 0;
}
