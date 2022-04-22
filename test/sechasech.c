/*******************************************************************************
	GLUE-Math test routine: sech()/asech()
*******************************************************************************/
#include "../realmath/realmath.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -o bin/sechasech test/sechasech.c realmath/asech_r8.c realmath/asech_re.c realmath/asech_r4.c realmath/sech_r8.c realmath/sech_re.c realmath/sech_r4.c

And Test Result:
for long double
  x    自家製asech        左のsech
 0.00                   inf   0
 0.10   2.99322284612638090   0.1
 0.20   2.29243166956117769   0.2
 0.30   1.87382024252741442   0.3
 0.40   1.56679923697241108   0.4
 0.50   1.31695789692481671   0.5
 0.60   1.09861228866810969   0.6
 0.70   0.89558809952997582   0.7
 0.80   0.69314718055994531   0.8
 0.90   0.46714530810326202   0.9
 1.00   0.00000000000000000   1

for double
  x    自家製asech     左のsech
 0.00                inf   0
 0.10   2.99322284612638   0.1
 0.20   2.29243166956118   0.2
 0.30   1.87382024252741   0.3
 0.40   1.56679923697241   0.4
 0.50   1.31695789692482   0.5
 0.60   1.09861228866811   0.6
 0.70   0.89558809952998   0.7
 0.80   0.69314718055995   0.8
 0.90   0.46714530810326   0.9
 1.00   0.00000000000000   1

for float
  x    自家製asech  左のsech
 0.00       inf   0
 0.10   2.99322   0.1
 0.20   2.29243   0.2
 0.30   1.87382   0.3
 0.40   1.56680   0.4
 0.50   1.31696   0.5
 0.60   1.09861   0.6
 0.70   0.89559   0.7
 0.80   0.69315   0.8
 0.90   0.46715   0.9
 1.00   0.00000   1
*******************************************************************************/

void asech_re_test(void);
void asech_r8_test(void);
void asech_r4_test(void);

int
main(void)
{
	puts("for long double");
	asech_re_test();
	puts("");
	puts("for double");
	asech_r8_test();
	puts("");
	puts("for float");
	asech_r4_test();
	return 0;
}

void
asech_re_test(void)
{
	long double x, y;

	printf("  x    %-*s  左のsech\n", LDBL_DIG + 2, "自家製asech");
	for (volatile int i = 0; i <= 10; i++) {
		x = i / 10.0L;  y = asech_re(x);
		printf("%5.2Lf  %*.*Lf  % Lg\n",
			x, LDBL_DIG + 2, LDBL_DIG - 1, y, sech_re(y));
	}
}

void
asech_r8_test(void)
{
	double x, y;

	printf("  x    %-*s  左のsech\n", DBL_DIG + 2, "自家製asech");
	for (volatile int i = 0; i <= 10; i++) {
		x = i / 10.0;  y = asech_r8(x);
		printf("%5.2f  %*.*f  % g\n",
			x, DBL_DIG + 2, DBL_DIG - 1, y, sech_r8(y));
	}
}

void
asech_r4_test(void)
{
	float x, y;

	printf("  x    %-*s  左のsech\n", FLT_DIG + 2, "自家製asech");
	for (volatile int i = 0; i <= 10; i++) {
		x = i / 10.0;  y = asech_r4(x);
		printf("%5.2f  %*.*f  % g\n",
			x, FLT_DIG + 2, FLT_DIG - 1, y, sech_r4(y));
	}
}
