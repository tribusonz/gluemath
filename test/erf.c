/*******************************************************************************
	GLUE-Math test suite: Gaussian Error Function
*******************************************************************************/
#include "../sys/float/huge_val_nan.h"
#if defined(_CMATH_TEST)
# include "../legacy/legacy.h"
# define erf_r8 erf
# define erf_re erfl
# define erf_r4 erff
#else
# include "../realmath/realmath.h"
#endif
#include <stdio.h>
#include <float.h>
/*******************************************************************************
MinGW 64bit gcc build:
$ gcc -Wall -Wextra -O3 -D_CMATH_TEST -o bin/erf test/erf.c legacy/erf.c legacy/erfl.c legacy/erff.c
$ gcc -Wall -Wextra -O3 -o bin/erf test/erf.c realmath/erf_r8.c realmath/erf_re.c realmath/erf_r4.c

Result:
GLUE-Math with POSIX standard
Test Suite:
  Gaussian Error Function

 (x)            erf(x)
-6.0 -1.000000 -1.000000000000000 -0.999999999999999978
-5.5 -1.000000 -0.999999999999993 -0.999999999999992642
-5.0 -1.000000 -0.999999999998463 -0.999999999998462540
-4.5 -1.000000 -0.999999999803384 -0.999999999803383956
-4.0 -1.000000 -0.999999984582742 -0.999999984582742100
-3.5 -0.999999 -0.999999256901628 -0.999999256901627659
-3.0 -0.999978 -0.999977909503001 -0.999977909503001415
-2.5 -0.999593 -0.999593047982555 -0.999593047982555041
-2.0 -0.995322 -0.995322265018953 -0.995322265018952734
-1.5 -0.966105 -0.966105146475311 -0.966105146475310727
-1.0 -0.842701 -0.842700792949715 -0.842700792949714869
-0.5 -0.520500 -0.520499877813047 -0.520499877813046538
 0.0  0.000000  0.000000000000000  0.000000000000000000
 0.5  0.520500  0.520499877813047  0.520499877813046538
 1.0  0.842701  0.842700792949715  0.842700792949714869
 1.5  0.966105  0.966105146475311  0.966105146475310727
 2.0  0.995322  0.995322265018953  0.995322265018952734
 2.5  0.999593  0.999593047982555  0.999593047982555041
 3.0  0.999978  0.999977909503001  0.999977909503001415
 3.5  0.999999  0.999999256901628  0.999999256901627659
 4.0  1.000000  0.999999984582742  0.999999984582742100
 4.5  1.000000  0.999999999803384  0.999999999803383956
 5.0  1.000000  0.999999999998463  0.999999999998462540
 5.5  1.000000  0.999999999999993  0.999999999999992642
 6.0  1.000000  1.000000000000000  0.999999999999999978

++++ Check Infinity & NaN ++++
double:
erf(Infinity) = 1
erf(-Infinity) = -1
erf(NaN) = nan
long double:
erf(Infinity) = 1
erf(-Infinity) = -1
erf(NaN) = nan
float:
erf(Infinity) = 1
erf(-Infinity) = -1
erf(NaN) = nan
*******************************************************************************/
int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Gaussian Error Function");
	puts("");
	printf("%4s  %16s\n", "(x)", "erf(x)");
	for (volatile int i = -60; i <= 60; i += 5)
	{
		const double x = i / 10.0; // Iterator Constant
		printf("% 3.1f % *.*f % *.*f % *.*Lf\n", x,
		       FLT_DIG + 3, FLT_DIG, erf_r4(x),
		       DBL_DIG + 3, DBL_DIG, erf_r8(x),
		       LDBL_DIG + 3, LDBL_DIG, erf_re(x));
	}
	puts("");
	puts("++++ Check Infinity & NaN ++++");
	puts("double:");
	printf("erf(Infinity) = %g\n", erf_r8(HUGE_VAL));
	printf("erf(-Infinity) = %g\n", erf_r8(-HUGE_VAL));
	printf("erf(NaN) = %g\n", erf_r8(NAN));
	puts("long double:");
	printf("erf(Infinity) = %Lg\n", erf_re(HUGE_VALL));
	printf("erf(-Infinity) = %Lg\n", erf_re(-HUGE_VALL));
	printf("erf(NaN) = %Lg\n", erf_re(NAN));
	puts("float:");
	printf("erf(Infinity) = %g\n", erf_r4(HUGE_VALF));
	printf("erf(-Infinity) = %g\n", erf_r4(-HUGE_VALF));
	printf("erf(NaN) = %g\n", erf_r4(NAN));
	
	return 0;
}
