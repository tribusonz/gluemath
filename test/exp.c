/***********************************************************
	GLUE-Math test suite: Exponential Function
***********************************************************/
#if defined(_CMATH_TEST)
# include "../legacy/legacy.h"
# define exp_r4 expf
# define exp_r8 exp
# define exp_re expl
#else
# include "../realmath/realmath.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -D_CMATH_TEST -o bin/exp test/exp.c legacy/exp.c legacy/expl.c legacy/expf.c
$ gcc -Wall -Wextra -O3 -o bin/exp test/exp.c realmath/exp_r8.c realmath/exp_r4.c realmath/exp_re.c

And Test Result (Intel 64bit):
GLUE-Math with POSIX standard
Test Suite:
  Exponential Function

++++ Calculation test ++++
(x), exp(x) float/double/long-double
-2.50   0.082085  0.082084998623899  0.082084998623898795
-2.25   0.105399  0.105399224561864  0.105399224561864337
-2.00   0.135335  0.135335283236613  0.135335283236612692
-1.75   0.173774  0.173773943450445  0.173773943450445127
-1.50   0.223130  0.223130160148430  0.223130160148429829
-1.25   0.286505  0.286504796860190  0.286504796860190100
-1.00   0.367879  0.367879441171442  0.367879441171442322
-0.75   0.472367  0.472366552741015  0.472366552741014707
-0.50   0.606531  0.606530659712633  0.606530659712633424
-0.25   0.778801  0.778800783071405  0.778800783071404868
 0.00   1.000000  1.000000000000000  1.000000000000000000
 0.25   1.284025  1.284025416687742  1.284025416687741484
 0.50   1.648721  1.648721270700128  1.648721270700128147
 0.75   2.117000  2.117000016612675  2.117000016612674668
 1.00   2.718282  2.718281828459045  2.718281828459045235
 1.25   3.490343  3.490342957461841  3.490342957461841376
 1.50   4.481689  4.481689070338064  4.481689070338064823
 1.75   5.754602  5.754602676005731  5.754602676005730436
 2.00   7.389056  7.389056098930650  7.389056098930650227
 2.25   9.487735  9.487735836358526  9.487735836358525719
 2.50  12.182493 12.182493960703470 12.182493960703473439

++++ Check handling of Infinity & NaN ++++
for float
exp(FLT_MAX_EXP) = inf
exp(FLT_MIN_EXP) = 0.000000
exp(Infinity) = inf
exp(-Infinity) = 0.000000
exp(NaN) = nan
Available Calculation Range: -86..88

for double
exp(DBL_MAX_EXP) = inf
exp(DBL_MIN_EXP) = 0.000000
exp(Infinity) = inf
exp(-Infinity) = 0.000000
exp(NaN) = nan
Available Calculation Range: -707..710

for long double:
exp(LDBL_MAX_EXP) = inf
exp(LDBL_MIN_EXP) = 0.000000
exp(Infinity) = inf
exp(-Infinity) = 0.000000
exp(NaN) = nan
Available Calculation Range: -11355..11357
*******************************************************************************/

int
main(void)
{
	int i;
	
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Exponential Function");
	puts("");
	puts("++++ Calculation test ++++");
	puts("(x), exp2(x), float/double/long-double");
	for (i = -10; i <= 10; i++)
	{
		const double x = i / 4.0;  // Iterator constant
		printf("%5.2f  %*.*f %*.*f %*.*Lf\n",
		    x, FLT_DIG + 3,  FLT_DIG, exp_r4((float)x),
		       DBL_DIG + 3,  DBL_DIG, exp_r8(x),
		      LDBL_DIG + 3, LDBL_DIG, exp_re((long double)x));
	}
	
	puts("");

	puts("++++ Check handling of Infinity & NaN ++++");
	
	puts("for float");
	printf("exp(FLT_MAX_EXP) = %f\n", exp_r4(FLT_MAX_EXP));
	printf("exp(FLT_MIN_EXP) = %f\n", exp_r4(FLT_MIN_EXP));
	printf("exp(Infinity) = %f\n", exp_r4(1.0/0.0));
	printf("exp(-Infinity) = %f\n", exp_r4(-1.0/0.0));
	printf("exp(NaN) = %f\n", exp_r4(0.0/0.0));
	for (i = 0; 0.0 != exp_r4(i); i--);
	printf("Available Calculation Range: %d", i);
	for (i = 0; (1.0/0.0) != exp_r4(i); i++);
	printf("..%d\n", i);

	puts("");

	puts("for double");
	printf("exp(DBL_MAX_EXP) = %f\n", exp_r8(DBL_MAX_EXP));
	printf("exp(DBL_MIN_EXP) = %f\n", exp_r8(DBL_MIN_EXP));
	printf("exp(Infinity) = %f\n", exp_r8(1.0/0.0));
	printf("exp(-Infinity) = %f\n", exp_r8(-1.0/0.0));
	printf("exp(NaN) = %f\n", exp_r8(0.0/0.0));
	for (i = 0; 0.0 != exp_r8(i); i--);
	printf("Available Calculation Range: %d", i);
	for (i = 0; (1.0/0.0) != exp_r8(i); i++);
	printf("..%d\n", i);

	puts("");

	puts("for long double:");
	printf("exp(LDBL_MAX_EXP) = %Lf\n", exp_re(LDBL_MAX_EXP));
	printf("exp(LDBL_MIN_EXP) = %Lf\n", exp_re(LDBL_MIN_EXP));
	printf("exp(Infinity) = %Lf\n", exp_re(1.0/0.0));
	printf("exp(-Infinity) = %Lf\n", exp_re(-1.0/0.0));
	printf("exp(NaN) = %Lf\n", exp_re(0.0/0.0));
	for (i = 0; 0.0 != exp_re(i); i--);
	printf("Available Calculation Range: %d", i);
	for (i = 0; (1.0/0.0) != exp_re(i); i++);
	printf("..%d\n", i);
	
	return 0;
}
