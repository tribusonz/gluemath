/*******************************************************************************
	GLUE-Math test routine: atan
*******************************************************************************/
#include "../sys/float/huge_val_nan.h"
#if defined(_CMATH_TEST)
# include "../legacy/legacy.h"
#else
# include "../realmath/realmath.h"
# define tan tan_r8
# define tanl tan_re
# define tanf tan_r4
# define atan atan_r8
# define atanl atan_re
# define atanf atan_r4
#endif
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
/*******************************************************************************
MinGW 64bit gcc build:
$ gcc -Wall -Wextra -O3 -D_CMATH_TEST -o bin/tanatan test/tanatan.c legacy/atanl.c legacy/tanl.c legacy/atan.c legacy/tan.c legacy/atanf.c legacy/tanf.c
$ gcc -Wall -Wextra -O3 -o bin/tanatan test/tanatan.c realmath/atan_re.c realmath/tan_re.c realmath/atan_r8.c realmath/tan_r8.c realmath/atan_r4.c realmath/tan_r4.c

And test result:
for long double
  x    自家製atan         左のtan
 -inf  -1.57079632679489662  -inf
-2.50  -1.19028994968253173  -2.5
-2.25  -1.15257199721566752  -2.25
-2.00  -1.10714871779409050  -2
-1.75  -1.05165021254837367  -1.75
-1.50  -0.98279372324732907  -1.5
-1.25  -0.89605538457134396  -1.25
-1.00  -0.78539816339744831  -1
-0.75  -0.64350110879328439  -0.75
-0.50  -0.46364760900080612  -0.5
-0.25  -0.24497866312686415  -0.25
 0.00   0.00000000000000000   0
 0.25   0.24497866312686415   0.25
 0.50   0.46364760900080612   0.5
 0.75   0.64350110879328439   0.75
 1.00   0.78539816339744831   1
 1.25   0.89605538457134396   1.25
 1.50   0.98279372324732907   1.5
 1.75   1.05165021254837367   1.75
 2.00   1.10714871779409050   2
 2.25   1.15257199721566752   2.25
 2.50   1.19028994968253173   2.5
  inf   1.57079632679489662   inf

for double
  x    自家製atan      左のtan
 -inf  -1.57079632679490  -inf
-2.50  -1.19028994968253  -2.5
-2.25  -1.15257199721567  -2.25
-2.00  -1.10714871779409  -2
-1.75  -1.05165021254837  -1.75
-1.50  -0.98279372324733  -1.5
-1.25  -0.89605538457134  -1.25
-1.00  -0.78539816339745  -1
-0.75  -0.64350110879328  -0.75
-0.50  -0.46364760900081  -0.5
-0.25  -0.24497866312686  -0.25
 0.00   0.00000000000000   0
 0.25   0.24497866312686   0.25
 0.50   0.46364760900081   0.5
 0.75   0.64350110879328   0.75
 1.00   0.78539816339745   1
 1.25   0.89605538457134   1.25
 1.50   0.98279372324733   1.5
 1.75   1.05165021254837   1.75
 2.00   1.10714871779409   2
 2.25   1.15257199721567   2.25
 2.50   1.19028994968253   2.5
  inf   1.57079632679490   inf

for float
  x    自家製atan  左のtan
 -inf  -1.57080  -inf
-2.50  -1.19029  -2.5
-2.25  -1.15257  -2.25
-2.00  -1.10715  -2
-1.75  -1.05165  -1.75
-1.50  -0.98279  -1.5
-1.25  -0.89606  -1.25
-1.00  -0.78540  -1
-0.75  -0.64350  -0.75
-0.50  -0.46365  -0.5
-0.25  -0.24498  -0.25
 0.00   0.00000   0
 0.25   0.24498   0.25
 0.50   0.46365   0.5
 0.75   0.64350   0.75
 1.00   0.78540   1
 1.25   0.89606   1.25
 1.50   0.98279   1.5
 1.75   1.05165   1.75
 2.00   1.10715   2
 2.25   1.15257   2.25
 2.50   1.19029   2.5
  inf   1.57080   inf
*******************************************************************************/

void atanl_test(void);
void atan_test(void);
void atanf_test(void);

int
main(void)
{
	puts("for long double");
	atanl_test();
	puts("");
	puts("for double");
	atan_test();
	puts("");
	puts("for float");
	atanf_test();

	return 0;
}

void
atanl_test(void)
{
	long double x, y;

	printf("  x    %-*s  左のtan\n", LDBL_DIG + 2, "自家製atan");
	x = -HUGE_VALL;  y = atanl(x);
	printf("%5.2Lf  %*.*Lf  % Lg\n", x, LDBL_DIG + 2, LDBL_DIG - 1, y, tanl(y));
	for (volatile int i = -10; i <= 10; i++) {
		x = i / 4.0L;  y = atanl(x);
		printf("%5.2Lf  %*.*Lf  % Lg\n",
			x, LDBL_DIG + 2, LDBL_DIG - 1, y, tanl(y));
	}
	x = HUGE_VALL;  y = atanl(x);
	printf("%5.2Lf  %*.*Lf  % Lg\n", x, LDBL_DIG + 2, LDBL_DIG - 1, y, tanl(y));
}

void
atan_test(void)
{
	double x, y;

	printf("  x    %-*s  左のtan\n", DBL_DIG + 2, "自家製atan");
	x = -HUGE_VAL;  y = atan(x);
	printf("%5.2f  %*.*f  % g\n", x, DBL_DIG + 2, DBL_DIG - 1, y, tan(y));
	for (volatile int i = -10; i <= 10; i++) {
		x = i / 4.0;  y = atan(x);
		printf("%5.2f  %*.*f  % g\n",
			x, DBL_DIG + 2, DBL_DIG - 1, y, tan(y));
	}
	x = HUGE_VAL;  y = atan(x);
	printf("%5.2f  %*.*f  % g\n", x, DBL_DIG + 2, DBL_DIG - 1, y, tan(y));
}

void
atanf_test(void)
{
	float x, y;

	printf("  x    %-*s  左のtan\n", FLT_DIG + 2, "自家製atan");
	x = -HUGE_VALF;  y = atanf(x);
	printf("%5.2f  %*.*f  % g\n", x, FLT_DIG + 2, FLT_DIG - 1, y, tanf(y));
	for (volatile int i = -10; i <= 10; i++) {
		x = i / 4.0;  y = atanf(x);
		printf("%5.2f  %*.*f  % g\n",
			x, FLT_DIG + 2, FLT_DIG - 1, y, tanf(y));
	}
	x = HUGE_VALF;  y = atanf(x);
	printf("%5.2f  %*.*f  % g\n", x, FLT_DIG + 2, FLT_DIG - 1, y, tanf(y));
}
