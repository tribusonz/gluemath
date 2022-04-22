/*******************************************************************************
	GLUE-Math test suite: Hyperbolic Cosecant and Hyperbolic Arccosecant
*******************************************************************************/
#include "../realmath/realmath.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -o bin/cschacsch test/cschacsch.c realmath/acsch_r8.c realmath/acsch_re.c realmath/acsch_r4.c realmath/csch_r8.c realmath/csch_re.c realmath/csch_r4.c

And Test Result:
GLUE-Math with POSIX standard
Test Suite:
  Hyperbolic Cosecant and Hyperbolic Arccosecant

for long double
  x    自家製acsch        左のcsch
-4.00  -0.24746646154726345  -4
-3.50  -0.28196323918998292  -3.5
-3.00  -0.32745015023725844  -3
-2.50  -0.39003531977071528  -2.5
-2.00  -0.48121182505960345  -2
-1.50  -0.62514511725041669  -1.5
-1.00  -0.88137358701954303  -1
-0.50  -1.44363547517881034  -0.5
 0.00                   inf   0
 0.50   1.44363547517881034   0.5
 1.00   0.88137358701954303   1
 1.50   0.62514511725041669   1.5
 2.00   0.48121182505960345   2
 2.50   0.39003531977071528   2.5
 3.00   0.32745015023725844   3
 3.50   0.28196323918998292   3.5
 4.00   0.24746646154726345   4

for double
  x    自家製acsch     左のcsch
-4.00  -0.24746646154726  -4
-3.50  -0.28196323918998  -3.5
-3.00  -0.32745015023726  -3
-2.50  -0.39003531977072  -2.5
-2.00  -0.48121182505960  -2
-1.50  -0.62514511725042  -1.5
-1.00  -0.88137358701954  -1
-0.50  -1.44363547517881  -0.5
 0.00                inf   0
 0.50   1.44363547517881   0.5
 1.00   0.88137358701954   1
 1.50   0.62514511725042   1.5
 2.00   0.48121182505960   2
 2.50   0.39003531977072   2.5
 3.00   0.32745015023726   3
 3.50   0.28196323918998   3.5
 4.00   0.24746646154726   4

for float
  x    自家製acsch  左のcsch
-4.00  -0.24747  -4
-3.50  -0.28196  -3.5
-3.00  -0.32745  -3
-2.50  -0.39004  -2.5
-2.00  -0.48121  -2
-1.50  -0.62515  -1.5
-1.00  -0.88137  -1
-0.50  -1.44364  -0.5
 0.00       inf   0
 0.50   1.44364   0.5
 1.00   0.88137   1
 1.50   0.62515   1.5
 2.00   0.48121   2
 2.50   0.39004   2.5
 3.00   0.32745   3
 3.50   0.28196   3.5
 4.00   0.24747   4
*******************************************************************************/

void acsch_re_test(void);
void acsch_r8_test(void);
void acsch_r4_test(void);

int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Hyperbolic Cosecant and Hyperbolic Arccosecant");
	puts("");
	puts("for long double");
	acsch_re_test();
	puts("");
	puts("for double");
	acsch_r8_test();
	puts("");
	puts("for float");
	acsch_r4_test();
	return 0;
}

void
acsch_re_test(void)
{
	long double x, y;

	printf("  x    %-*s  左のcsch\n", LDBL_DIG + 2, "自家製acsch");
	for (volatile int i = -40; i <= 40; i += 5) {
		x = i / 10.0L;  y = acsch_re(x);
		printf("%5.2Lf  %*.*Lf  % Lg\n",
			x, LDBL_DIG + 2, LDBL_DIG - 1, y, csch_re(y));
	}
}

void
acsch_r8_test(void)
{
	double x, y;

	printf("  x    %-*s  左のcsch\n", DBL_DIG + 2, "自家製acsch");
	for (volatile int i = -40; i <= 40; i += 5) {
		x = i / 10.0;  y = acsch_r8(x);
		printf("%5.2f  %*.*f  % g\n",
			x, DBL_DIG + 2, DBL_DIG - 1, y, csch_r8(y));
	}
}

void
acsch_r4_test(void)
{
	float x, y;

	printf("  x    %-*s  左のcsch\n", FLT_DIG + 2, "自家製acsch");
	for (volatile int i = -40; i <= 40; i += 5) {
		x = i / 10.0;  y = acsch_r4(x);
		printf("%5.2f  %*.*f  % g\n",
			x, FLT_DIG + 2, FLT_DIG - 1, y, csch_r4(y));
	}
}
