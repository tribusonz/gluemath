/*******************************************************************************
	GLUE-Math test routine: Riemann Zeta Function
*******************************************************************************/
#include "../realmath/realmath.h"
#include <stdio.h>
#include <stdlib.h>
/*******************************************************************************
MinGW 64bit gcc build:
$ gcc -Wall -Wextra -O3 -o bin/riemann_zeta test/riemann_zeta.c realmath/riemann_zeta_r8.c

And test result:
GLUE-Math with POSIX standard
Test Suite:
  Riemann Zeta Function

zeta(-14) =  0.000000000000000
zeta(-13) = -0.083333333333333
zeta(-12) =  0.000000000000000
zeta(-11) =  0.021092796092796
zeta(-10) =  0.000000000000000
zeta( -9) = -0.007575757575758
zeta( -8) =  0.000000000000000
zeta( -7) =  0.004166666666667
zeta( -6) =  0.000000000000000
zeta( -5) = -0.003968253968254
zeta( -4) =  0.000000000000000
zeta( -3) =  0.008333333333333
zeta( -2) =  0.000000000000000
zeta( -1) = -0.083333333333332
zeta(  0) = -0.500000000000000
zeta(  1) =               inf
zeta(  2) =  1.644934066848226
zeta(  3) =  1.202056903159594
zeta(  4) =  1.082323233711138
zeta(  5) =  1.036927755143370
zeta(  6) =  1.017343061984449
zeta(  7) =  1.008349277381923
zeta(  8) =  1.004077356197944
zeta(  9) =  1.002008392826082
zeta( 10) =  1.000994575127818
zeta( 11) =  1.000494188604120
zeta( 12) =  1.000246086553308
zeta( 13) =  1.000122713347579
zeta( 14) =  1.000061248135059
zeta( 15) =  1.000030588236307
zeta( 16) =  1.000015282259409
zeta( 17) =  1.000007637197638
zeta( 18) =  1.000003817293265
zeta( 19) =  1.000001908212716
zeta( 20) =  1.000000953962034
*******************************************************************************/
int
main(void)
{
	double x;

	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Riemann Zeta Function");
	puts("");
#if 0
	puts("  It's supported a negative argument.");
	puts("  But, the series expansion algorithm");
	puts("  gives accurate is until -2 at best.");
	puts("");
#endif

	for (x = -14; x <= 20; x++)
		printf("zeta(% 3.0f) = % 17.15f\n", x, riemann_zeta_r8(x));
	return 0;
}
