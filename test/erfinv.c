/*******************************************************************************
	GLUE-Math test suite: Inverse of Gaussian Error Function
*******************************************************************************/
#include "../realmath/realmath.h"
#include "../sys/float/huge_val_nan.h"
#include <stdio.h>
#include <float.h>
/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -o bin/erfinv test/erfinv.c realmath/erfinv_r8.c realmath/erfcinv_r8.c

And Test Result:
GLUE-Math with POSIX standard
Test Suite:
  Inverse of Gaussian Error Function

Inverse Error Function -1 <= q <= 1
-1.1               nan
-1.0              -inf
-0.9   -1.163087153676674
-0.8   -0.906193802436823
-0.7   -0.732869077959217
-0.6   -0.595116081449995
-0.5   -0.476936276204470
-0.4   -0.370807158593558
-0.3   -0.272462714726754
-0.2   -0.179143454621292
-0.1   -0.088855990494258
 0.0    0.000000000000000
 0.1    0.088855990494258
 0.2    0.179143454621292
 0.3    0.272462714726754
 0.4    0.370807158593558
 0.5    0.476936276204470
 0.6    0.595116081449995
 0.7    0.732869077959217
 0.8    0.906193802436823
 0.9    1.163087153676674
 1.0               inf
 1.1               nan

++++ Check Infinity & NaN ++++
erf^-1(-HUGE_VAL) = nan
erf^-1(HUGE_VAL) = nan
erf^-1(NAN) = nan

Inverse Complementary Error Function 0 <= q <= 2
-0.1               nan
 0.0               inf
 0.1    1.163087153676674
 0.2    0.906193802436823
 0.3    0.732869077959217
 0.4    0.595116081449995
 0.5    0.476936276204470
 0.6    0.370807158593558
 0.7    0.272462714726754
 0.8    0.179143454621292
 0.9    0.088855990494258
 1.0    0.000000000000000
 1.1   -0.088855990494258
 1.2   -0.179143454621292
 1.3   -0.272462714726754
 1.4   -0.370807158593558
 1.5   -0.476936276204470
 1.6   -0.595116081449995
 1.7   -0.732869077959217
 1.8   -0.906193802436823
 1.9   -1.163087153676674
 2.0              -inf
 2.1               nan

++++ Check Infinity & NaN ++++
erfc^-1(-HUGE_VAL) = nan
erfc^-1(HUGE_VAL) = nan
erfc^-1(NAN) = nan
*******************************************************************************/
int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Inverse of Gaussian Error Function");
	puts("");
	puts("Inverse Error Function -1 <= q <= 1");
	for (volatile int i = -11; i <= 11; i++)
	{
		const double x = i / 10.0;  // Iterator Constant
		printf("% 2.1f   % *.*f\n", x, DBL_DIG, DBL_DIG, erfinv_r8(x));
	}
	puts("");
	puts("++++ Check Infinity & NaN ++++");
	printf("erf^-1(-HUGE_VAL) = %f\n", erfinv_r8(-HUGE_VAL)); // -Infinity Check
	printf("erf^-1(HUGE_VAL) = %f\n", erfinv_r8(HUGE_VAL)); // Infinity Check
	printf("erf^-1(NAN) = %f\n", erfinv_r8(NAN)); // NaN Check
	puts("");
	puts("Inverse Complementary Error Function 0 <= q <= 2");
	for (volatile int i = -1; i <= 21; i++)
	{
		const double x = i / 10.0;  // Iterator Constant
		printf("% 2.1f   % *.*f\n", x, DBL_DIG, DBL_DIG, erfcinv_r8(x));
	}
	puts("");
	puts("++++ Check Infinity & NaN ++++");
	printf("erfc^-1(-HUGE_VAL) = %f\n", erfcinv_r8(-HUGE_VAL)); // -Infinity Check
	printf("erfc^-1(HUGE_VAL) = %f\n", erfcinv_r8(HUGE_VAL)); // Infinity Check
	printf("erfc^-1(NAN) = %f\n", erfcinv_r8(NAN)); // NaN Check
	return 0;
}
