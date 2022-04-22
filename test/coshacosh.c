/*******************************************************************************
	GLUE-Math test suite: Hyperbolic Cosine and Hyperbolic Arccosine
*******************************************************************************/
#if defined(_CMATH_TEST)
# include "../legacy/legacy.h"
# define cosh_r8 cosh
# define cosh_re coshl
# define cosh_r4 coshf
# define acosh_r8 acosh
# define acosh_re acoshl
# define acosh_r4 acoshf
#else
# include "../realmath/realmath.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -D_CMATH_TEST -o bin/coshacosh test/coshacosh.c legacy/acosh.c legacy/acoshl.c legacy/acoshf.c legacy/cosh.c legacy/coshl.c legacy/coshf.c
$ gcc -Wall -Wextra -O3 -o bin/coshacosh test/coshacosh.c realmath/acosh_r8.c realmath/acosh_re.c realmath/acosh_r4.c realmath/cosh_r8.c realmath/cosh_re.c realmath/cosh_r4.c

And Test Result:
GLUE-Math with POSIX standard
Test Suite:
  Hyperbolic Cosine and Hyperbolic Arccosine

for long double
  x    自家製acosh        左のcosh
 1.00   0.00000000000000000   1
 1.50   0.96242365011920689   1.5
 2.00   1.31695789692481671   2
 2.50   1.56679923697241108   2.5
 3.00   1.76274717403908605   3
 3.50   1.92484730023841379   3.5
 4.00   2.06343706889556055   4
 4.50   2.18464379160510873   4.5
 5.00   2.29243166956117769   5

for double
  x    自家製acosh     左のcosh
 1.00   0.00000000000000   1
 1.50   0.96242365011921   1.5
 2.00   1.31695789692482   2
 2.50   1.56679923697241   2.5
 3.00   1.76274717403909   3
 3.50   1.92484730023841   3.5
 4.00   2.06343706889556   4
 4.50   2.18464379160511   4.5
 5.00   2.29243166956118   5

for float
  x    自家製acosh  左のcosh
 1.00   0.00000   1
 1.50   0.96242   1.5
 2.00   1.31696   2
 2.50   1.56680   2.5
 3.00   1.76275   3
 3.50   1.92485   3.5
 4.00   2.06344   4
 4.50   2.18464   4.5
 5.00   2.29243   5
*******************************************************************************/

void acosh_re_test(void);
void acosh_r8_test(void);
void acosh_r4_test(void);

int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Hyperbolic Cosine and Hyperbolic Arccosine");
	puts("");
	puts("for long double");
	acosh_re_test();
	puts("");
	puts("for double");
	acosh_r8_test();
	puts("");
	puts("for float");
	acosh_r4_test();
	return 0;
}

void
acosh_re_test(void)
{
	long double x, y;

	printf("  x    %-*s  左のcosh\n", LDBL_DIG + 2, "自家製acosh");
	for (volatile int i = 10; i <= 50; i += 5) {
		x = i / 10.0L;  y = acosh_re(x);
		printf("%5.2Lf  %*.*Lf  % Lg\n",
			x, LDBL_DIG + 2, LDBL_DIG - 1, y, cosh_re(y));
	}
}

void
acosh_r8_test(void)
{
	double x, y;

	printf("  x    %-*s  左のcosh\n", DBL_DIG + 2, "自家製acosh");
	for (volatile int i = 10; i <= 50; i += 5) {
		x = i / 10.0;  y = acosh_r8(x);
		printf("%5.2f  %*.*f  % g\n",
			x, DBL_DIG + 2, DBL_DIG - 1, y, cosh_r8(y));
	}
}

void
acosh_r4_test(void)
{
	float x, y;

	printf("  x    %-*s  左のcosh\n", FLT_DIG + 2, "自家製acosh");
	for (volatile int i = 10; i <= 50; i += 5) {
		x = i / 10.0;  y = acosh_r4(x);
		printf("%5.2f  %*.*f  % g\n",
			x, FLT_DIG + 2, FLT_DIG - 1, y, cosh_r4(y));
	}
}
