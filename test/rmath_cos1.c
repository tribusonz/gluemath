/*******************************************************************************
	GLUE-Math test suite: 1 - cos()
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#define PI 3.1415926535897932384626433832795L

int
main(void)
{
	float c1f; double c1; long double c1l;
	
	rmath_title_print("Half-angle Formula");

	printf("x(deg) cos1(x)\n");
	for (volatile int i = -720; i <= 720; i += 15) {
		c1f = cos1_r4(i * (PI / 180));
		c1  = cos1_r8(i * (PI / 180));
		c1l = cos1_re(i * (PI / 180));
		printf("%4d %6.6f %17.14f %21.17Lf\n", i, c1f, c1, c1l);
	}
	return 0;
}
