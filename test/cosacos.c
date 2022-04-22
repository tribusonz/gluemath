/*******************************************************************************
	GLUE-Math test suite: Cosine and Arccosine
*******************************************************************************/
#if defined(_CMATH_TEST)
# include "../legacy/legacy.h"
# define cos_r8 cos
# define cos_re cosl
# define cos_r4 cosf
# define acos_r8 acos
# define acos_re acosl
# define acos_r4 acosf
#else
# include "../realmath/realmath.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -D_CMATH_TEST -o bin/cosacos test/cosacos.c legacy/acos.c legacy/acosl.c legacy/acosf.c legacy/cos.c legacy/cosl.c legacy/cosf.c
$ gcc -Wall -Wextra -O3 -o bin/cosacos test/cosacos.c realmath/acos_r8.c realmath/acos_re.c realmath/acos_r4.c realmath/cos_r8.c realmath/cos_re.c realmath/cos_r4.c

And Test Result:
GLUE-Math with POSIX standard
Test Suite:
  Cosine and Arccosine

for long double
  x    自家製acos         左のcos
-1.00   3.14159265358979324  -1
-0.90   2.69056584179353081  -0.9
-0.80   2.49809154479650885  -0.8
-0.70   2.34619382340564968  -0.7
-0.60   2.21429743558818101  -0.6
-0.50   2.09439510239319549  -0.5
-0.40   1.98231317286238464  -0.4
-0.30   1.87548898081029413  -0.3
-0.20   1.77215424758522741  -0.2
-0.10   1.67096374795645642  -0.1
 0.00   1.57079632679489662   0
 0.10   1.47062890563333682   0.1
 0.20   1.36943840600456583   0.2
 0.30   1.26610367277949911   0.3
 0.40   1.15927948072740860   0.4
 0.50   1.04719755119659775   0.5
 0.60   0.92729521800161223   0.6
 0.70   0.79539883018414356   0.7
 0.80   0.64350110879328439   0.8
 0.90   0.45102681179626243   0.9
 1.00   0.00000000000000000   1

for double
  x    自家製acos      左のcos
-1.00   3.14159265358979  -1
-0.90   2.69056584179353  -0.9
-0.80   2.49809154479651  -0.8
-0.70   2.34619382340565  -0.7
-0.60   2.21429743558818  -0.6
-0.50   2.09439510239320  -0.5
-0.40   1.98231317286238  -0.4
-0.30   1.87548898081029  -0.3
-0.20   1.77215424758523  -0.2
-0.10   1.67096374795646  -0.1
 0.00   1.57079632679490   0
 0.10   1.47062890563334   0.1
 0.20   1.36943840600457   0.2
 0.30   1.26610367277950   0.3
 0.40   1.15927948072741   0.4
 0.50   1.04719755119660   0.5
 0.60   0.92729521800161   0.6
 0.70   0.79539883018414   0.7
 0.80   0.64350110879328   0.8
 0.90   0.45102681179626   0.9
 1.00   0.00000000000000   1

for float
  x    自家製acos  左のcos
-1.00   3.14159  -1
-0.90   2.69057  -0.9
-0.80   2.49809  -0.8
-0.70   2.34619  -0.7
-0.60   2.21430  -0.6
-0.50   2.09440  -0.5
-0.40   1.98231  -0.4
-0.30   1.87549  -0.3
-0.20   1.77215  -0.2
-0.10   1.67096  -0.1
 0.00   1.57080   0
 0.10   1.47063   0.1
 0.20   1.36944   0.2
 0.30   1.26610   0.3
 0.40   1.15928   0.4
 0.50   1.04720   0.5
 0.60   0.92730   0.6
 0.70   0.79540   0.7
 0.80   0.64350   0.8
 0.90   0.45103   0.9
 1.00   0.00000   1
*******************************************************************************/

void acos_re_test(void);
void acos_r8_test(void);
void acos_r4_test(void);

int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Cosine and Arccosine");
	puts("");
	puts("for long double");
	acos_re_test();
	puts("");
	puts("for double");
	acos_r8_test();
	puts("");
	puts("for float");
	acos_r4_test();
	return 0;
}

void
acos_re_test(void)
{
	long double x, y;

	printf("  x    %-*s  左のcos\n", LDBL_DIG + 2, "自家製acos");
	for (volatile int i = -10; i <= 10; i++) {
		x = i / 10.0L;  y = acos_re(x);
		printf("%5.2Lf  %*.*Lf  % Lg\n",
			x, LDBL_DIG + 2, LDBL_DIG - 1, y, cos_re(y));
	}
}

void
acos_r8_test(void)
{
	double x, y;

	printf("  x    %-*s  左のcos\n", DBL_DIG + 2, "自家製acos");
	for (volatile int i = -10; i <= 10; i++) {
		x = i / 10.0;  y = acos_r8(x);
		printf("%5.2f  %*.*f  % g\n",
			x, DBL_DIG + 2, DBL_DIG - 1, y, cos_r8(y));
	}
}

void
acos_r4_test(void)
{
	float x, y;

	printf("  x    %-*s  左のcos\n", FLT_DIG + 2, "自家製acos");
	for (volatile int i = -10; i <= 10; i++) {
		x = i / 10.0;  y = acos_r4(x);
		printf("%5.2f  %*.*f  % g\n",
			x, FLT_DIG + 2, FLT_DIG - 1, y, cos_r4(y));
	}
}
