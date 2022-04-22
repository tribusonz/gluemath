/*******************************************************************************
	GLUE-Math test suite: Load Exponent
*******************************************************************************/
#include "../legacy/legacy.h"
#include "../sys/random/random.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <time.h>
/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -o bin/ldexp test/ldexp.c legacy/ldexp.c legacy/ldexpl.c legacy/ldexpf.c

And Test Result:
GLUE-Math with POSIX standard
Test Suite:
  Load Exponent

for double:
exp: 3 fra: 1.961601678344525 = 15.6928
exp: 6 fra: 0.123206143069894 = 7.88519
exp: 9 fra: 1.497616045091875 = 766.779
exp: 7 fra: 0.599731313867643 = 76.7656
exp: 6 fra: 0.663422385941421 = 42.459
for long double:
exp: 4 fra: 1.620624753713742372 = 25.93
exp: 8 fra: 1.592182870832076214 = 407.599
exp: 3 fra: 0.673053606702172624 = 5.38443
exp: 1 fra: 0.838679670747252359 = 1.67736
exp: 9 fra: 1.911927748759433499 = 978.907
for float:
exp: 1 fra: 0.999165 = 1.99833
exp: 4 fra: 1.939582 = 31.0333
exp: 6 fra: 1.958557 = 125.348
exp: 9 fra: 0.960332 = 491.69
exp: 3 fra: 0.868781 = 6.95025
*******************************************************************************/

int
main(void)
{
	init_genrand(time(NULL));
	
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Load Exponent");
	puts("");

	puts("for double:");
	for (volatile int i = 0; i < 5; i++)
	{
		const double frav = genrand_res53() * 2;
		const int    expv = genrand_int32() % 10;
		printf("exp:%2d fra: %*.*f = %g\n",
		       expv, DBL_DIG, DBL_DIG, frav, ldexp(frav, expv));
	}
	puts("for long double:");
	for (volatile int i = 0; i < 5; i++)
	{
		const long double frav = (long double)genrand_res53() * 2;
		const int         expv = genrand_int32() % 10;
		printf("exp:%2d fra: %*.*Lf = %Lg\n",
		       expv, LDBL_DIG, LDBL_DIG, frav, ldexpl(frav, expv));
	}
	puts("for float:");
	for (volatile int i = 0; i < 5; i++)
	{
		const float frav = (float)genrand_res53() * 2;
		const int   expv = genrand_int32() % 10;
		printf("exp:%2d fra: %*.*f = %g\n",
		       expv, FLT_DIG, FLT_DIG, frav, ldexpf(frav, expv));
	}
	return 0;
}
