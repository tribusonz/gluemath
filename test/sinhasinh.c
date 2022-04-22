/*******************************************************************************
	GLUE-Math test routine: sinh()/asinh()
*******************************************************************************/
#if defined(_CMATH_TEST)
# include "../legacy/legacy.h"
#else
# include "../realmath/realmath.h"
# define sinh sinh_r8
# define sinhl sinh_re
# define sinhf sinh_r4
# define asinh asinh_r8
# define asinhl asinh_re
# define asinhf asinh_r4
#endif
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -D_CMATH_TEST -o bin/sinhasinh test/sinhasinh.c legacy/asinh.c legacy/asinhl.c legacy/asinhf.c legacy/sinh.c legacy/sinhl.c legacy/sinhf.c
$ gcc -Wall -Wextra -O3 -o bin/sinhasinh test/sinhasinh.c realmath/asinh_r8.c realmath/asinh_re.c realmath/asinh_r4.c realmath/sinh_r8.c realmath/sinh_re.c realmath/sinh_r4.c

And Test Result:
for long double
  x    自家製asinh        左のsinh
-4.00  -2.09471254726110129  -4
-3.50  -1.96572047164965152  -3.5
-3.00  -1.81844645923206682  -3
-2.50  -1.64723114637109571  -2.5
-2.00  -1.44363547517881034  -2
-1.50  -1.19476321728710930  -1.5
-1.00  -0.88137358701954303  -1
-0.50  -0.48121182505960345  -0.5
 0.00   0.00000000000000000   0
 0.50   0.48121182505960345   0.5
 1.00   0.88137358701954303   1
 1.50   1.19476321728710930   1.5
 2.00   1.44363547517881034   2
 2.50   1.64723114637109571   2.5
 3.00   1.81844645923206682   3
 3.50   1.96572047164965152   3.5
 4.00   2.09471254726110129   4

for double
  x    自家製asinh     左のsinh
-4.00  -2.09471254726110  -4
-3.50  -1.96572047164965  -3.5
-3.00  -1.81844645923207  -3
-2.50  -1.64723114637110  -2.5
-2.00  -1.44363547517881  -2
-1.50  -1.19476321728711  -1.5
-1.00  -0.88137358701954  -1
-0.50  -0.48121182505960  -0.5
 0.00   0.00000000000000   0
 0.50   0.48121182505960   0.5
 1.00   0.88137358701954   1
 1.50   1.19476321728711   1.5
 2.00   1.44363547517881   2
 2.50   1.64723114637110   2.5
 3.00   1.81844645923207   3
 3.50   1.96572047164965   3.5
 4.00   2.09471254726110   4

for float
  x    自家製asinh  左のsinh
-4.00  -2.09471  -4
-3.50  -1.96572  -3.5
-3.00  -1.81845  -3
-2.50  -1.64723  -2.5
-2.00  -1.44364  -2
-1.50  -1.19476  -1.5
-1.00  -0.88137  -1
-0.50  -0.48121  -0.5
 0.00   0.00000   0
 0.50   0.48121   0.5
 1.00   0.88137   1
 1.50   1.19476   1.5
 2.00   1.44364   2
 2.50   1.64723   2.5
 3.00   1.81845   3
 3.50   1.96572   3.5
 4.00   2.09471   4
*******************************************************************************/

void asinhl_test(void);
void asinh_test(void);
void asinhf_test(void);

int
main(void)
{
	puts("for long double");
	asinhl_test();
	puts("");
	puts("for double");
	asinh_test();
	puts("");
	puts("for float");
	asinhf_test();
	return 0;
}

void
asinhl_test(void)
{
	long double x, y;

	printf("  x    %-*s  左のsinh\n", LDBL_DIG + 2, "自家製asinh");
	for (volatile int i = -40; i <= 40; i += 5) {
		x = i / 10.0L;  y = asinhl(x);
		printf("%5.2Lf  %*.*Lf  % Lg\n",
			x, LDBL_DIG + 2, LDBL_DIG - 1, y, sinhl(y));
	}
}

void
asinh_test(void)
{
	double x, y;

	printf("  x    %-*s  左のsinh\n", DBL_DIG + 2, "自家製asinh");
	for (volatile int i = -40; i <= 40; i += 5) {
		x = i / 10.0;  y = asinh(x);
		printf("%5.2f  %*.*f  % g\n",
			x, DBL_DIG + 2, DBL_DIG - 1, y, sinh(y));
	}
}

void
asinhf_test(void)
{
	float x, y;

	printf("  x    %-*s  左のsinh\n", FLT_DIG + 2, "自家製asinh");
	for (volatile int i = -40; i <= 40; i += 5) {
		x = i / 10.0;  y = asinhf(x);
		printf("%5.2f  %*.*f  % g\n",
			x, FLT_DIG + 2, FLT_DIG - 1, y, sinhf(y));
	}
}
