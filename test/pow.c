/*******************************************************************************
    GLUE-Math test suite: Powers
*******************************************************************************/
#include "../sys/float/powers.h"
#include "../sys/float/huge_val_nan.h"
#include <stdio.h>
#include <stdlib.h>
/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -o bin/pow test/pow.c

And Test Result:
GLUE-Math with POSIX standard
Test Suite:
  Powers

for double:
2 ** 2 = 4
2 ** 1 = 2
2 ** 0.5 = 1.4142135623731
2 ** 0 = 1
2 ** -0.5 = 0.707106781186548
2 ** -1 = 0.5
2 ** -2 = 0.25
1 ** 0 = 1
-1 ** 0 = -1
nan ** 0 = nan
nan ** inf = nan
nan ** -inf = nan
1 ** inf = 1
-1 ** inf = -1
1 ** -inf = 1
-1 ** -inf = -1
inf ** 1 = inf
inf ** -1 = 0
-inf ** 1 = -inf
-inf ** -1 = -0
0 ** nan = nan
nan ** 0 = nan
nan ** nan = nan

for long double:
2 ** 2 = 4
2 ** 1 = 2
2 ** 0.5 = 1.41421356237309505
2 ** 0 = 1
2 ** -0.5 = 0.707106781186547524
2 ** -1 = 0.5
2 ** -2 = 0.25
1 ** 0 = 1
-1 ** 0 = -1
nan ** 0 = nan
nan ** inf = nan
nan ** -inf = nan
1 ** inf = 1
-1 ** inf = -1
1 ** -inf = 1
-1 ** -inf = -1
inf ** 1 = inf
inf ** -1 = 0
-inf ** 1 = -inf
-inf ** -1 = -0
0 ** nan = nan
nan ** 0 = nan
nan ** nan = nan

for float:
2 ** 2 = 4
2 ** 1 = 2
2 ** 0.5 = 1.41421
2 ** 0 = 1
2 ** -0.5 = 0.707107
2 ** -1 = 0.5
2 ** -2 = 0.25
1 ** 0 = 1
-1 ** 0 = -1
nan ** 0 = nan
nan ** inf = nan
nan ** -inf = nan
1 ** inf = 1
-1 ** inf = -1
1 ** -inf = 1
-1 ** -inf = -1
inf ** 1 = inf
inf ** -1 = 0
-inf ** 1 = -inf
-inf ** -1 = -0
0 ** nan = nan
nan ** 0 = nan
nan ** nan = nan
*******************************************************************************/

int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Powers");
	puts("");
	puts("for double:");
#define print_pow(x,y) (printf("%g ** %g = %.15g\n", (double)(x), (double)(y), pow(x,y)))
	print_pow(2.0, 2.0);
	print_pow(2.0, 1.0);
	print_pow(2.0, 0.5);
	print_pow(2.0, 0.0);
	print_pow(2.0, -0.5);
	print_pow(2.0, -1.0);
	print_pow(2.0, -2.0);
	print_pow(1, 0);
	print_pow(-1, 0);
	print_pow(NAN, 0);
	print_pow(NAN, HUGE_VAL);
	print_pow(NAN, -HUGE_VAL);
	print_pow(1, HUGE_VAL);
	print_pow(-1, HUGE_VAL);
	print_pow(1, -HUGE_VAL);
	print_pow(-1, -HUGE_VAL);
	print_pow(HUGE_VAL, 1);
	print_pow(HUGE_VAL, -1);
	print_pow(-HUGE_VAL, 1);
	print_pow(-HUGE_VAL, -1);
	print_pow(0, NAN);
	print_pow(NAN, 0);
	print_pow(NAN, NAN);
	puts("");
	puts("for long double:");
#define print_powl(x,y) (printf("%Lg ** %Lg = %.18Lg\n", (long double)(x), (long double)(y), powl(x,y)))
	print_powl(2.0, 2.0);
	print_powl(2.0, 1.0);
	print_powl(2.0, 0.5);
	print_powl(2.0, 0.0);
	print_powl(2.0, -0.5);
	print_powl(2.0, -1.0);
	print_powl(2.0, -2.0);
	print_powl(1, 0);
	print_powl(-1, 0);
	print_powl(NAN, 0);
	print_powl(NAN, HUGE_VALL);
	print_powl(NAN, -HUGE_VALL);
	print_powl(1, HUGE_VALL);
	print_powl(-1, HUGE_VALL);
	print_powl(1, -HUGE_VALL);
	print_powl(-1, -HUGE_VALL);
	print_powl(HUGE_VALL, 1);
	print_powl(HUGE_VALL, -1);
	print_powl(-HUGE_VALL, 1);
	print_powl(-HUGE_VALL, -1);
	print_powl(0, NAN);
	print_powl(NAN, 0);
	print_powl(NAN, NAN);
	puts("");
	puts("for float:");
#define print_powf(x,y) (printf("%g ** %g = %.6g\n", (float)(x), (float)(y), powf(x,y)))
	print_powf(2.0, 2.0);
	print_powf(2.0, 1.0);
	print_powf(2.0, 0.5);
	print_powf(2.0, 0.0);
	print_powf(2.0, -0.5);
	print_powf(2.0, -1.0);
	print_powf(2.0, -2.0);
	print_powf(1, 0);
	print_powf(-1, 0);
	print_powf(NAN, 0);
	print_powf(NAN, HUGE_VALF);
	print_powf(NAN, -HUGE_VALF);
	print_powf(1, HUGE_VALF);
	print_powf(-1, HUGE_VALF);
	print_powf(1, -HUGE_VALF);
	print_powf(-1, -HUGE_VALF);
	print_powf(HUGE_VALF, 1);
	print_powf(HUGE_VALF, -1);
	print_powf(-HUGE_VALF, 1);
	print_powf(-HUGE_VALF, -1);
	print_powf(0, NAN);
	print_powf(NAN, 0);
	print_powf(NAN, NAN);
	
	return 0;
}
