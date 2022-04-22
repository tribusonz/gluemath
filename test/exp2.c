/*******************************************************************************
	GLUE-Math test suite: Binary Exponent
*******************************************************************************/
#if defined(_CMATH_TEST)
# include "../legacy/legacy.h"
# define exp2_r8 exp2
# define exp2_re exp2l
# define exp2_r4 exp2f
#else
# include "../realmath/realmath.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -D_CMATH_TEST -o bin/exp2 test/exp2.c legacy/exp2.c legacy/exp2l.c legacy/exp2f.c 
$ gcc -Wall -Wextra -O3 -o bin/exp2 test/exp2.c realmath/exp2_r8.c realmath/exp2_re.c realmath/exp2_r4.c 

And Test Result (Intel 64bit):
GLUE-Math with POSIX standard
Test Suite:
  Binary Exponent

++++ Calculation test ++++
(x), exp2(x), float/double/long-double
-2.50   0.176777  0.176776695296637  0.176776695296636881
-2.25   0.210224  0.210224103813429  0.210224103813428636
-2.00   0.250000  0.250000000000000  0.250000000000000000
-1.75   0.297302  0.297301778750680  0.297301778750680267
-1.50   0.353553  0.353553390593274  0.353553390593273762
-1.25   0.420448  0.420448207626857  0.420448207626857271
-1.00   0.500000  0.500000000000000  0.500000000000000000
-0.75   0.594604  0.594603557501361  0.594603557501360533
-0.50   0.707107  0.707106781186548  0.707106781186547524
-0.25   0.840896  0.840896415253714  0.840896415253714543
 0.00   1.000000  1.000000000000000  1.000000000000000000
 0.25   1.189207  1.189207115002721  1.189207115002721067
 0.50   1.414214  1.414213562373095  1.414213562373095049
 0.75   1.681793  1.681792830507429  1.681792830507429086
 1.00   2.000000  2.000000000000000  2.000000000000000000
 1.25   2.378414  2.378414230005442  2.378414230005442134
 1.50   2.828427  2.828427124746190  2.828427124746190098
 1.75   3.363586  3.363585661014858  3.363585661014858172
 2.00   4.000000  4.000000000000000  4.000000000000000000
 2.25   4.756828  4.756828460010885  4.756828460010884268
 2.50   5.656854  5.656854249492381  5.656854249492380195

++++ Check handling of Infinity & NaN ++++
for float
exp2(FLT_MAX_EXP) = inf
exp2(FLT_MIN_EXP) = 0.000000
exp2(Infinity) = inf
exp2(-Infinity) = 0.000000
exp2(NaN) = nan
Available Calculation Range: -123..127

for double
exp2(DBL_MAX_EXP) = inf
exp2(DBL_MIN_EXP) = 0.000000
exp2(Infinity) = inf
exp2(-Infinity) = 0.000000
exp2(NaN) = nan
Available Calculation Range: -1020..1024

for long double:
exp2(LDBL_MAX_EXP) = inf
exp2(LDBL_MIN_EXP) = 0.000000
exp2(Infinity) = inf
exp2(-Infinity) = 0.000000
exp2(NaN) = nan
Available Calculation Range: -16381..16384
*******************************************************************************/

int
main(void)
{
	int i;

	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Binary Exponent");
	puts("");

	puts("++++ Calculation test ++++");
	puts("(x), exp2(x), float/double/long-double");
	for (i = -10; i <= 10; i++)
	{
		const double x = i / 4.0;  // Iterator constant
		printf("%5.2f  %*.*f %*.*f %*.*Lf\n",
		    x, FLT_DIG + 3,  FLT_DIG, exp2_r4((float)x),
		       DBL_DIG + 3,  DBL_DIG, exp2_r8(x),
		      LDBL_DIG + 3, LDBL_DIG, exp2_re((long double)x));
	}
	
	puts("");

	puts("++++ Check handling of Infinity & NaN ++++");
	
	puts("for float");
	printf("exp2(FLT_MAX_EXP) = %f\n", exp2_r4(FLT_MAX_EXP));
	printf("exp2(FLT_MIN_EXP) = %f\n", exp2_r4(FLT_MIN_EXP));
	printf("exp2(Infinity) = %f\n", exp2_r4(1.0/0.0));
	printf("exp2(-Infinity) = %f\n", exp2_r4(-1.0/0.0));
	printf("exp2(NaN) = %f\n", exp2_r4(0.0/0.0));
	for (i = 0; 0.0 != exp2_r4(i); i--);
	printf("Available Calculation Range: %d", i);
	for (i = 0; (1.0/0.0) != exp2_r4(i); i++);
	printf("..%d\n", i);

	puts("");

	puts("for double");
	printf("exp2(DBL_MAX_EXP) = %f\n", exp2_r8(DBL_MAX_EXP));
	printf("exp2(DBL_MIN_EXP) = %f\n", exp2_r8(DBL_MIN_EXP));
	printf("exp2(Infinity) = %f\n", exp2_r8(1.0/0.0));
	printf("exp2(-Infinity) = %f\n", exp2_r8(-1.0/0.0));
	printf("exp2(NaN) = %f\n", exp2_r8(0.0/0.0));
	for (i = 0; 0.0 != exp2_r8(i); i--);
	printf("Available Calculation Range: %d", i);
	for (i = 0; (1.0/0.0) != exp2_r8(i); i++);
	printf("..%d\n", i);

	puts("");

	puts("for long double:");
	printf("exp2(LDBL_MAX_EXP) = %Lf\n", exp2_re(LDBL_MAX_EXP));
	printf("exp2(LDBL_MIN_EXP) = %Lf\n", exp2_re(LDBL_MIN_EXP));
	printf("exp2(Infinity) = %Lf\n", exp2_re(1.0/0.0));
	printf("exp2(-Infinity) = %Lf\n", exp2_re(-1.0/0.0));
	printf("exp2(NaN) = %Lf\n", exp2_re(0.0/0.0));
	for (i = 0; 0.0 != exp2_re(i); i--);
	printf("Available Calculation Range: %d", i);
	for (i = 0; (1.0/0.0) != exp2_re(i); i++);
	printf("..%d\n", i);
	
	return 0;
}
