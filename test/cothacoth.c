/*******************************************************************************
	GLUE-Math test suite: Hyperbolic Cotangent and Hyperbolic Arccotangent
*******************************************************************************/
#include "../realmath/realmath.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -o bin/cothacoth test/cothacoth.c realmath/acoth_r8.c realmath/acoth_re.c realmath/acoth_r4.c realmath/coth_r8.c realmath/coth_re.c realmath/coth_r4.c

And Test Result:
GLUE-Math with POSIX standard
Test Suite:
  Hyperbolic Cotangent and Hyperbolic Arccotangent

for long double
  x    自家製acoth        左のcoth
-4.00  -0.25541281188299534  -4
-3.50  -0.29389333245105950  -3.5
-3.00  -0.34657359027997265  -3
-2.50  -0.42364893019360181  -2.5
-2.00  -0.54930614433405485  -2
-1.50  -0.80471895621705019  -1.5
-1.00                  -inf  -1
 1.00                   inf   1
 1.50   0.80471895621705019   1.5
 2.00   0.54930614433405485   2
 2.50   0.42364893019360181   2.5
 3.00   0.34657359027997265   3
 3.50   0.29389333245105950   3.5
 4.00   0.25541281188299534   4

for double
  x    自家製acoth     左のcoth
-4.00  -0.25541281188300  -4
-3.50  -0.29389333245106  -3.5
-3.00  -0.34657359027997  -3
-2.50  -0.42364893019360  -2.5
-2.00  -0.54930614433405  -2
-1.50  -0.80471895621705  -1.5
-1.00               -inf  -1
 1.00                inf   1
 1.50   0.80471895621705   1.5
 2.00   0.54930614433405   2
 2.50   0.42364893019360   2.5
 3.00   0.34657359027997   3
 3.50   0.29389333245106   3.5
 4.00   0.25541281188300   4

for float
  x    自家製acoth  左のcoth
-4.00  -0.25541  -4
-3.50  -0.29389  -3.5
-3.00  -0.34657  -3
-2.50  -0.42365  -2.5
-2.00  -0.54931  -2
-1.50  -0.80472  -1.5
-1.00      -inf  -1
 1.00       inf   1
 1.50   0.80472   1.5
 2.00   0.54931   2
 2.50   0.42365   2.5
 3.00   0.34657   3
 3.50   0.29389   3.5
 4.00   0.25541   4
*******************************************************************************/

void acoth_re_test(void);
void acoth_r8_test(void);
void acoth_r4_test(void);

int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Hyperbolic Cotangent and Hyperbolic Arccotangent");
	puts("");
	puts("for long double");
	acoth_re_test();
	puts("");
	puts("for double");
	acoth_r8_test();
	puts("");
	puts("for float");
	acoth_r4_test();
	return 0;
}

void
acoth_re_test(void)
{
	long double x, y;

	printf("  x    %-*s  左のcoth\n", LDBL_DIG + 2, "自家製acoth");
	for (volatile int i = -40; i <= 40; i += 5) {
		if (i > -10 && i < 10)  continue;
		x = i / 10.0L;  y = acoth_re(x);
		printf("%5.2Lf  %*.*Lf  % Lg\n",
			x, LDBL_DIG + 2, LDBL_DIG - 1, y, coth_re(y));
	}
}

void
acoth_r8_test(void)
{
	double x, y;

	printf("  x    %-*s  左のcoth\n", DBL_DIG + 2, "自家製acoth");
	for (volatile int i = -40; i <= 40; i += 5) {
		if (i > -10 && i < 10)  continue;
		x = i / 10.0;  y = acoth_r8(x);
		printf("%5.2f  %*.*f  % g\n",
			x, DBL_DIG + 2, DBL_DIG - 1, y, coth_r8(y));
	}
}

void
acoth_r4_test(void)
{
	float x, y;

	printf("  x    %-*s  左のcoth\n", FLT_DIG + 2, "自家製acoth");
	for (volatile int i = -40; i <= 40; i += 5) {
		if (i > -10 && i < 10)  continue;
		x = i / 10.0;  y = acoth_r4(x);
		printf("%5.2f  %*.*f  % g\n",
			x, FLT_DIG + 2, FLT_DIG - 1, y, coth_r4(y));
	}
}
