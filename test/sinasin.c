/*******************************************************************************
	GLUE-Math test routine: asin()
*******************************************************************************/
#if defined(_CMATH_TEST)
# include "../legacy/legacy.h"
#else
# include "../realmath/realmath.h"
# define sin sin_r8
# define sinl sin_re
# define sinf sin_r4
# define asin asin_r8
# define asinl asin_re
# define asinf asin_r4
#endif
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -D_CMATH_TEST -o bin/sinasin test/sinasin.c legacy/asin.c legacy/asinl.c legacy/asinf.c legacy/sinl.c legacy/sin.c legacy/sinf.c
$ gcc -Wall -Wextra -O3 -o bin/sinasin test/sinasin.c realmath/asin_r8.c realmath/asin_re.c realmath/asin_r4.c realmath/sin_r8.c realmath/sin_re.c realmath/sin_r4.c

And Test Result:
for long double
  x    自家製asin         左のsin
-1.00  -1.57079632679489662  -1
-0.90  -1.11976951499863419  -0.9
-0.80  -0.92729521800161223  -0.8
-0.70  -0.77539749661075306  -0.7
-0.60  -0.64350110879328439  -0.6
-0.50  -0.52359877559829887  -0.5
-0.40  -0.41151684606748802  -0.4
-0.30  -0.30469265401539751  -0.3
-0.20  -0.20135792079033079  -0.2
-0.10  -0.10016742116155980  -0.1
 0.00   0.00000000000000000   0
 0.10   0.10016742116155980   0.1
 0.20   0.20135792079033079   0.2
 0.30   0.30469265401539751   0.3
 0.40   0.41151684606748802   0.4
 0.50   0.52359877559829887   0.5
 0.60   0.64350110879328439   0.6
 0.70   0.77539749661075306   0.7
 0.80   0.92729521800161223   0.8
 0.90   1.11976951499863419   0.9
 1.00   1.57079632679489662   1

for double
  x    自家製asin      左のsin
-1.00  -1.57079632679490  -1
-0.90  -1.11976951499863  -0.9
-0.80  -0.92729521800161  -0.8
-0.70  -0.77539749661075  -0.7
-0.60  -0.64350110879328  -0.6
-0.50  -0.52359877559830  -0.5
-0.40  -0.41151684606749  -0.4
-0.30  -0.30469265401540  -0.3
-0.20  -0.20135792079033  -0.2
-0.10  -0.10016742116156  -0.1
 0.00   0.00000000000000   0
 0.10   0.10016742116156   0.1
 0.20   0.20135792079033   0.2
 0.30   0.30469265401540   0.3
 0.40   0.41151684606749   0.4
 0.50   0.52359877559830   0.5
 0.60   0.64350110879328   0.6
 0.70   0.77539749661075   0.7
 0.80   0.92729521800161   0.8
 0.90   1.11976951499863   0.9
 1.00   1.57079632679490   1

for float
  x    自家製asin  左のsin
-1.00  -1.57080  -1
-0.90  -1.11977  -0.9
-0.80  -0.92730  -0.8
-0.70  -0.77540  -0.7
-0.60  -0.64350  -0.6
-0.50  -0.52360  -0.5
-0.40  -0.41152  -0.4
-0.30  -0.30469  -0.3
-0.20  -0.20136  -0.2
-0.10  -0.10017  -0.1
 0.00   0.00000   0
 0.10   0.10017   0.1
 0.20   0.20136   0.2
 0.30   0.30469   0.3
 0.40   0.41152   0.4
 0.50   0.52360   0.5
 0.60   0.64350   0.6
 0.70   0.77540   0.7
 0.80   0.92730   0.8
 0.90   1.11977   0.9
 1.00   1.57080   1
*******************************************************************************/

void asinl_test(void);
void asin_test(void);
void asinf_test(void);

int
main(void)
{
	puts("for long double");
	asinl_test();
	puts("");
	puts("for double");
	asin_test();
	puts("");
	puts("for float");
	asinf_test();
	return 0;
}

void
asinl_test(void)
{
	long double x, y;

	printf("  x    %-*s  左のsin\n", LDBL_DIG + 2, "自家製asin");
	for (volatile int i = -10; i <= 10; i++) {
		x = i / 10.0L;  y = asinl(x);
		printf("%5.2Lf  %*.*Lf  % Lg\n",
			x, LDBL_DIG + 2, LDBL_DIG - 1, y, sinl(y));
	}
}

void
asin_test(void)
{
	double x, y;

	printf("  x    %-*s  左のsin\n", DBL_DIG + 2, "自家製asin");
	for (volatile int i = -10; i <= 10; i++) {
		x = i / 10.0;  y = asin(x);
		printf("%5.2f  %*.*f  % g\n",
			x, DBL_DIG + 2, DBL_DIG - 1, y, sin(y));
	}
}

void
asinf_test(void)
{
	float x, y;

	printf("  x    %-*s  左のsin\n", FLT_DIG + 2, "自家製asin");
	for (volatile int i = -10; i <= 10; i++) {
		x = i / 10.0;  y = asinf(x);
		printf("%5.2f  %*.*f  % g\n",
			x, FLT_DIG + 2, FLT_DIG - 1, y, sinf(y));
	}
}
