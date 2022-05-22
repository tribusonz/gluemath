/*******************************************************************************
	GLUE-Math test suite: Hypotenuse
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <float.h>
#define PI 3.1415926535897932

// Declare Prototypes
void print_hypot(double, double);

int
main(void)
{
	rmath_title_print("Hypotenuse");

	print_hypot(3, 4);
	puts("");
	print_hypot(1, 1);

	return 0;
}

void
print_hypot(double a, double b)
{
	printf("%g^2 + %g^2 = c^2\n", a, b);
	printf("  hypotenuse: %.*g %.*g %.*Lg\n",
		FLT_DIG, hypot_r4(a, b), DBL_DIG, hypot_r8(a, b), LDBL_DIG, hypot_re(a, b));
	printf("  angle: %.*g\n", DBL_DIG, atan_r8(b / a) * 180 / PI);
}
