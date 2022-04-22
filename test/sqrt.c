/*******************************************************************************
	GLUE-Math test suite: Square Root
*******************************************************************************/
#if defined(_CMATH_TEST)
# include "../legacy/legacy.h"
# define sqrt_r8 sqrt
# define sqrt_re sqrtl
# define sqrt_r4 sqrtf
#else
# include "../realmath/realmath.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -D_CMATH_TEST -o bin/sqrt test/sqrt.c legacy/sqrt.c legacy/sqrtl.c legacy/sqrtf.c
$ gcc -Wall -Wextra -O3 -o bin/sqrt test/sqrt.c realmath/sqrt_r8.c realmath/sqrt_re.c realmath/sqrt_r4.c

And Test Result:
GLUE-Math with POSIX standard
Test Suite:
  Square Root

  (x)   float     double             long double
    0   0.000000  0.000000000000000  0.000000000000000000
    1   1.000000  1.000000000000000  1.000000000000000000
    2   1.414214  1.414213562373095  1.414213562373095049
    3   1.732051  1.732050807568877  1.732050807568877294
    4   2.000000  2.000000000000000  2.000000000000000000
    5   2.236068  2.236067977499790  2.236067977499789696
    6   2.449490  2.449489742783178  2.449489742783178098
    7   2.645751  2.645751311064591  2.645751311064590590
    8   2.828427  2.828427124746190  2.828427124746190098
    9   3.000000  3.000000000000000  3.000000000000000000
   10   3.162278  3.162277660168379  3.162277660168379332
   11   3.316625  3.316624790355400  3.316624790355399849
   12   3.464102  3.464101615137754  3.464101615137754587
   13   3.605551  3.605551275463990  3.605551275463989293
   14   3.741657  3.741657386773941  3.741657386773941385
   15   3.872983  3.872983346207417  3.872983346207416885
   16   4.000000  4.000000000000000  4.000000000000000000
   17   4.123106  4.123105625617661  4.123105625617660550
   18   4.242640  4.242640687119286  4.242640687119285147
   19   4.358899  4.358898943540673  4.358898943540673552
   20   4.472136  4.472135954999580  4.472135954999579393
*******************************************************************************/

int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Square Root");
	puts("");
	printf("  %3.3s   %-*.*s  %-*.*s  %-*.*s\n", "(x)",
	       FLT_DIG + 2, FLT_DIG + 2, "float",
	       DBL_DIG + 2, DBL_DIG + 2, "double",
	       LDBL_DIG + 2, LDBL_DIG + 2, "long double");
	for (volatile int i = 0; i <= 20; i++)
		printf("  % 3d  % *.*f % *.*f % *.*Lf\n", i,
			FLT_DIG, FLT_DIG, sqrt_r4(i), 
		    DBL_DIG, DBL_DIG, sqrt_r8(i),
		    LDBL_DIG, LDBL_DIG, sqrt_re(i));
	return 0;
}