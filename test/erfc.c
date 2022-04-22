/*******************************************************************************
	GLUE-Math test suite: Gaussian Complementary Error Function
*******************************************************************************/
#include "../sys/float/huge_val_nan.h"
#if defined(_CMATH_TEST)
# include "../legacy/legacy.h"
# define erfc_r8 erfc
# define erfc_re erfcl
# define erfc_r4 erfcf
#else
# include "../realmath/realmath.h"
#endif
#include <stdio.h>
#include <float.h>
/*******************************************************************************
MinGW 64bit gcc build:
$ gcc -Wall -Wextra -O3 -D_CMATH_TEST -o bin/erfc test/erfc.c legacy/erfc.c legacy/erfcl.c legacy/erfcf.c
$ gcc -Wall -Wextra -O3 -o bin/erfc test/erfc.c realmath/erfc_r8.c realmath/erfc_re.c realmath/erfc_r4.c

And test result:
GLUE-Math with POSIX standard
Test Suite:
  Gaussian Complementary Error Function

 (x)           erfc(x)
-6.0  2.000000  2.000000000000000  1.999999999999999979
-5.5  2.000000  1.999999999999993  1.999999999999992642
-5.0  2.000000  1.999999999998463  1.999999999998462540
-4.5  2.000000  1.999999999803384  1.999999999803383956
-4.0  2.000000  1.999999984582742  1.999999984582742100
-3.5  1.999999  1.999999256901628  1.999999256901627659
-3.0  1.999978  1.999977909503001  1.999977909503001414
-2.5  1.999593  1.999593047982555  1.999593047982555041
-2.0  1.995322  1.995322265018953  1.995322265018952734
-1.5  1.966105  1.966105146475311  1.966105146475310727
-1.0  1.842701  1.842700792949715  1.842700792949714869
-0.5  1.520500  1.520499877813047  1.520499877813046538
 0.0  1.000000  1.000000000000000  1.000000000000000000
 0.5  0.479500  0.479500122186953  0.479500122186953462
 1.0  0.157299  0.157299207050285  0.157299207050285131
 1.5  0.033895  0.033894853524689  0.033894853524689273
 2.0  0.004678  0.004677734981047  0.004677734981047266
 2.5  0.000407  0.000406952017445  0.000406952017444959
 3.0  0.000022  0.000022090496999  0.000022090496998585
 3.5  0.000001  0.000000743098372  0.000000743098372341
 4.0  0.000000  0.000000015417258  0.000000015417257900
 4.5  0.000000  0.000000000196616  0.000000000196616044
 5.0  0.000000  0.000000000001537  0.000000000001537460
 5.5  0.000000  0.000000000000007  0.000000000000007358
 6.0  0.000000  0.000000000000000  0.000000000000000022

++++ Check Infinity & NaN ++++
double:
erfc(Infinity) = 0
erfc(-Infinity) = 2
erfc(NaN) = nan
long double:
erfc(Infinity) = 0
erfc(-Infinity) = 2
erfc(NaN) = nan
float:
erfc(Infinity) = 0
erfc(-Infinity) = 2
erfc(NaN) = nan
*******************************************************************************/
int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Gaussian Complementary Error Function");
	puts("");
	printf("%4s  %16s\n", "(x)", "erfc(x)");
	for (volatile int i = -60; i <= 60; i += 5)
	{
		const double x = i / 10.0; // Iterator Constant
		printf("% 3.1f % *.*f % *.*f % *.*Lf\n", x,
		       FLT_DIG + 3, FLT_DIG, erfc_r4(x),
		       DBL_DIG + 3, DBL_DIG, erfc_r8(x),
		       LDBL_DIG + 3, LDBL_DIG, erfc_re(x));
	}
	puts("");
	puts("++++ Check Infinity & NaN ++++");
	puts("double:");
	printf("erfc(Infinity) = %g\n", erfc_r8(HUGE_VAL));
	printf("erfc(-Infinity) = %g\n", erfc_r8(-HUGE_VAL));
	printf("erfc(NaN) = %g\n", erfc_r8(NAN));
	puts("long double:");
	printf("erfc(Infinity) = %Lg\n", erfc_re(HUGE_VALL));
	printf("erfc(-Infinity) = %Lg\n", erfc_re(-HUGE_VALL));
	printf("erfc(NaN) = %Lg\n", erfc_re(NAN));
	puts("float:");
	printf("erfc(Infinity) = %g\n", erfc_r4(HUGE_VALF));
	printf("erfc(-Infinity) = %g\n", erfc_r4(-HUGE_VALF));
	printf("erfc(NaN) = %g\n", erfc_r4(NAN));
	
	return 0;
}
