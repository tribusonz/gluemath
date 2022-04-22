/*******************************************************************************
	GLUE-Math test suite: Gamma Function
*******************************************************************************/
#if defined(_CMATH_TEST)
# include "../legacy/legacy.h"
# define gamma_r8 tgamma
# define gamma_r4 tgammaf
# define gamma_re tgammal
#else
# include "../realmath/realmath.h"
#endif
#include <stdio.h>
#include <float.h>
/*******************************************************************************
MinGW 64bit gcc build:
$ gcc -Wall -Wextra -O3 -D_CMATH_TEST -o bin/gamma test/gamma.c legacy/tgamma.c legacy/tgammaf.c legacy/tgammal.c
$ gcc -Wall -Wextra -O3 -o bin/gamma test/gamma.c realmath/gamma_r8.c realmath/gamma_r4.c realmath/gamma_re.c

And test result (Intel 64bit):
GLUE-Math with POSIX standard
Test Suite:
  Euler Gamma Function

for float
Gamma(-5.0) =   -inf
Gamma(-4.8) = -0.062423
Gamma(-4.6) = -0.053665
Gamma(-4.4) = -0.074066
Gamma(-4.2) = -0.164061
Gamma(-4.0) =    inf
Gamma(-3.8) =  0.299632
Gamma(-3.6) =  0.246857
Gamma(-3.4) =  0.325891
Gamma(-3.2) =  0.689056
Gamma(-3.0) =   -inf
Gamma(-2.8) = -1.138602
Gamma(-2.6) = -0.888686
Gamma(-2.4) = -1.108030
Gamma(-2.2) = -2.204980
Gamma(-2.0) =    inf
Gamma(-1.8) =  3.188085
Gamma(-1.6) =  2.310583
Gamma(-1.4) =  2.659272
Gamma(-1.2) =  4.850956
Gamma(-1.0) =   -inf
Gamma(-0.8) = -5.738555
Gamma(-0.6) = -3.696933
Gamma(-0.4) = -3.722980
Gamma(-0.2) = -5.821149
Gamma( 0.0) =    inf
Gamma( 0.2) =  4.590843
Gamma( 0.4) =  2.218159
Gamma( 0.6) =  1.489192
Gamma( 0.8) =  1.164230
Gamma( 1.0) =  1.000000
Gamma( 1.2) =  0.918169
Gamma( 1.4) =  0.887264
Gamma( 1.6) =  0.893515
Gamma( 1.8) =  0.931384
Gamma( 2.0) =  1.000000
Gamma( 2.2) =  1.101802
Gamma( 2.4) =  1.242169
Gamma( 2.6) =  1.429625
Gamma( 2.8) =  1.676491
Gamma( 3.0) =  2.000000
Gamma( 3.2) =  2.423965
Gamma( 3.4) =  2.981206
Gamma( 3.6) =  3.717023
Gamma( 3.8) =  4.694174
Gamma( 4.0) =  6.000000
Gamma( 4.2) =  7.756688
Gamma( 4.4) =  10.136104
Gamma( 4.6) =  13.381283
Gamma( 4.8) =  17.837866
Gamma( 5.0) =  24.000000

for double
Gamma(-5.0) =            -inf
Gamma(-4.8) = -0.062423361354760
Gamma(-4.6) = -0.053664596295079
Gamma(-4.4) = -0.074066172930036
Gamma(-4.2) = -0.164061050477614
Gamma(-4.0) =             inf
Gamma(-3.8) =  0.299632134502846
Gamma(-3.6) =  0.246857142957364
Gamma(-3.4) =  0.325891160892161
Gamma(-3.2) =  0.689056412005979
Gamma(-3.0) =            -inf
Gamma(-2.8) = -1.138602111110815
Gamma(-2.6) = -0.888685714646509
Gamma(-2.4) = -1.108029947033346
Gamma(-2.2) = -2.204980518419132
Gamma(-2.0) =             inf
Gamma(-1.8) =  3.188085911110278
Gamma(-1.6) =  2.310582858080924
Gamma(-1.4) =  2.659271872880030
Gamma(-1.2) =  4.850957140522095
Gamma(-1.0) =            -inf
Gamma(-0.8) = -5.738554639998502
Gamma(-0.6) = -3.696932572929480
Gamma(-0.4) = -3.722980622032041
Gamma(-0.2) = -5.821148568626512
Gamma( 0.0) =             inf
Gamma( 0.2) =  4.590843711998804
Gamma( 0.4) =  2.218159543757689
Gamma( 0.6) =  1.489192248812814
Gamma( 0.8) =  1.164229713725303
Gamma( 1.0) =  1.000000000000000
Gamma( 1.2) =  0.918168742399760
Gamma( 1.4) =  0.887263817503078
Gamma( 1.6) =  0.893515349287687
Gamma( 1.8) =  0.931383770980240
Gamma( 2.0) =  1.000000000000000
Gamma( 2.2) =  1.101802490879712
Gamma( 2.4) =  1.242169344504308
Gamma( 2.6) =  1.429624558860303
Gamma( 2.8) =  1.676490787764431
Gamma( 3.0) =  2.000000000000000
Gamma( 3.2) =  2.423965479935368
Gamma( 3.4) =  2.981206426810335
Gamma( 3.6) =  3.717023853036776
Gamma( 3.8) =  4.694174205740411
Gamma( 4.0) =  6.000000000000000
Gamma( 4.2) =  7.756689535793175
Gamma( 4.4) =  10.136101851155139
Gamma( 4.6) =  13.381285870932411
Gamma( 4.8) =  17.837861981813543
Gamma( 5.0) =  24.000000000000000

for long double
Gamma(-5.0) =               -inf
Gamma(-4.8) = -0.062423361354759484
Gamma(-4.6) = -0.053664596295079099
Gamma(-4.4) = -0.074066172930036458
Gamma(-4.2) = -0.164061050477614196
Gamma(-4.0) =                inf
Gamma(-3.8) =  0.299632134502845555
Gamma(-3.6) =  0.246857142957363798
Gamma(-3.4) =  0.325891160892160763
Gamma(-3.2) =  0.689056412005979516
Gamma(-3.0) =               -inf
Gamma(-2.8) = -1.138602111110813215
Gamma(-2.6) = -0.888685714646509704
Gamma(-2.4) = -1.108029947033346487
Gamma(-2.2) = -2.204980518419134130
Gamma(-2.0) =                inf
Gamma(-1.8) =  3.188085911110279694
Gamma(-1.6) =  2.310582858080925320
Gamma(-1.4) =  2.659271872880031271
Gamma(-1.2) =  4.850957140522099724
Gamma(-1.0) =               -inf
Gamma(-0.8) = -5.738554639998504338
Gamma(-0.6) = -3.696932572929480352
Gamma(-0.4) = -3.722980622032042847
Gamma(-0.2) = -5.821148568626516927
Gamma( 0.0) =                inf
Gamma( 0.2) =  4.590843711998802563
Gamma( 0.4) =  2.218159543757688027
Gamma( 0.6) =  1.489192248812817122
Gamma( 0.8) =  1.164229713725303307
Gamma( 1.0) =  1.000000000000000000
Gamma( 1.2) =  0.918168742399760578
Gamma( 1.4) =  0.887263817503075266
Gamma( 1.6) =  0.893515349287690251
Gamma( 1.8) =  0.931383770980242697
Gamma( 2.0) =  1.000000000000000000
Gamma( 2.2) =  1.101802490879712786
Gamma( 2.4) =  1.242169344504305294
Gamma( 2.6) =  1.429624558860304482
Gamma( 2.8) =  1.676490787764436581
Gamma( 3.0) =  2.000000000000000000
Gamma( 3.2) =  2.423965479935368326
Gamma( 3.4) =  2.981206426810332591
Gamma( 3.6) =  3.717023853036791782
Gamma( 3.8) =  4.694174205740422134
Gamma( 4.0) =  6.000000000000000000
Gamma( 4.2) =  7.756689535793179074
Gamma( 4.4) =  10.136101851155136701
Gamma( 4.6) =  13.381285870932442352
Gamma( 4.8) =  17.837861981813603265
Gamma( 5.0) =  24.000000000000000000
*******************************************************************************/

// Prototypes
static void gamma_r4_print(void);
static void gamma_r8_print(void);
static void gamma_re_print(void);

int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Euler Gamma Function");
	puts("");
	gamma_r4_print();
	gamma_r8_print();
	gamma_re_print();
	return 0;
}

void
gamma_r8_print(void)
{
	puts("for double");
	for (volatile int i = -50; i <= 50; i += 2)
	{
		const double x = i / 10.0; // Iterator Constant
		printf("Gamma(% 1.1f) = % *.*f\n", x, DBL_DIG, DBL_DIG, gamma_r8(x));
	}
	puts("");
}

void
gamma_re_print(void)
{
	puts("for long double");
	for (volatile int i = -50; i <= 50; i += 2)
	{
		const long double x = i / 10.0; // Iterator Constant
		printf("Gamma(% 1.1Lf) = % *.*Lf\n", x, LDBL_DIG, LDBL_DIG, gamma_re(x));
	}
	puts("");
}

void
gamma_r4_print(void)
{
	puts("for float");
	for (volatile int i = -50; i <= 50; i += 2)
	{
		const float x = i / 10.0; // Iterator Constant
		printf("Gamma(% 1.1f) = % *.*f\n", x, FLT_DIG, FLT_DIG, gamma_r4(x));
	}
	puts("");
}
