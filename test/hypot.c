/*******************************************************************************
	GLUE-Math test suite: Hypotenuse
*******************************************************************************/
#if defined(_CMATH_TEST)
# include "../legacy/legacy.h"
# define hypot_r8 hypot
# define hypot_re hypotl
# define hypot_r4 hypotf
# define atan_r8 atan
#else
# include "../realmath/realmath.h"
#endif
#include <stdio.h>
#include <float.h>
#define PI 3.1415926535897932
/*******************************************************************************
MinGW 64bit gcc build:
$ gcc -Wall -Wextra -O3 -D_CMATH_TEST -o bin/hypot test/hypot.c legacy/hypot.c legacy/hypotl.c legacy/hypotf.c legacy/atan.c
$ gcc -Wall -Wextra -O3 -o bin/hypot test/hypot.c realmath/hypot_r8.c realmath/hypot_re.c realmath/hypot_r4.c realmath/atan_r8.c

And test result:
GLUE-Math with POSIX standard
Test Suite:
  Hypotenuse

3^2 + 4^2 = c^2
  hypotenuse: 5 5 5
  angle: 53.130102354156

1^2 + 1^2 = c^2
  hypotenuse: 1.41421 1.4142135623731 1.41421356237309505
  angle: 45
*******************************************************************************/
void print_hypot(double, double);

int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Hypotenuse");
	puts("");

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
