/*******************************************************************************
	GLUE-Math test suite: Cubic Root
*******************************************************************************/
#if defined(_CMATH_TEST)
# include "../legacy/legacy.h"
# define cbrt_r8 cbrt
# define cbrt_re cbrtl
# define cbrt_r4 cbrtf
#else
# include "../realmath/realmath.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -D_CMATH_TEST -o bin/cbrt test/cbrt.c legacy/cbrt.c legacy/cbrtl.c legacy/cbrtf.c
$ gcc -Wall -Wextra -O3 -o bin/cbrt test/cbrt.c realmath/cbrt_r8.c realmath/cbrt_re.c realmath/cbrt_r4.c

And Test Result:
GLUE-Math with POSIX standard
Test Suite:
  Cubic Root

  (x)   float     double             long double
  -20  -2.714418 -2.714417616594906 -2.714417616594906571
  -19  -2.668402 -2.668401648721945 -2.668401648721944868
  -18  -2.620741 -2.620741394208897 -2.620741394208896607
  -17  -2.571282 -2.571281590658236 -2.571281590658235355
  -16  -2.519842 -2.519842099789746 -2.519842099789746330
  -15  -2.466212 -2.466212074330470 -2.466212074330470102
  -14  -2.410142 -2.410142264175230 -2.410142264175229986
  -13  -2.351335 -2.351334687720758 -2.351334687720757490
  -12  -2.289428 -2.289428485106664 -2.289428485106663735
  -11  -2.223980 -2.223980090569315 -2.223980090569315521
  -10  -2.154435 -2.154434690031884 -2.154434690031883722
   -9  -2.080084 -2.080083823051904 -2.080083823051904115
   -8  -2.000000 -2.000000000000000 -2.000000000000000000
   -7  -1.912931 -1.912931182772389 -1.912931182772389101
   -6  -1.817121 -1.817120592832140 -1.817120592832139659
   -5  -1.709976 -1.709975946676697 -1.709975946676696989
   -4  -1.587401 -1.587401051968199 -1.587401051968199475
   -3  -1.442250 -1.442249570307409 -1.442249570307408382
   -2  -1.259921 -1.259921049894873 -1.259921049894873165
   -1  -1.000000 -1.000000000000000 -1.000000000000000000
    0   0.000000  0.000000000000000  0.000000000000000000
    1   1.000000  1.000000000000000  1.000000000000000000
    2   1.259921  1.259921049894873  1.259921049894873165
    3   1.442250  1.442249570307409  1.442249570307408382
    4   1.587401  1.587401051968199  1.587401051968199475
    5   1.709976  1.709975946676697  1.709975946676696989
    6   1.817121  1.817120592832140  1.817120592832139659
    7   1.912931  1.912931182772389  1.912931182772389101
    8   2.000000  2.000000000000000  2.000000000000000000
    9   2.080084  2.080083823051904  2.080083823051904115
   10   2.154435  2.154434690031884  2.154434690031883722
   11   2.223980  2.223980090569315  2.223980090569315521
   12   2.289428  2.289428485106664  2.289428485106663735
   13   2.351335  2.351334687720758  2.351334687720757490
   14   2.410142  2.410142264175230  2.410142264175229986
   15   2.466212  2.466212074330470  2.466212074330470102
   16   2.519842  2.519842099789746  2.519842099789746330
   17   2.571282  2.571281590658236  2.571281590658235355
   18   2.620741  2.620741394208897  2.620741394208896607
   19   2.668402  2.668401648721945  2.668401648721944868
   20   2.714418  2.714417616594906  2.714417616594906571
*******************************************************************************/

int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Cubic Root");
	puts("");
	printf("  %3.3s   %-*.*s  %-*.*s  %-*.*s\n", "(x)",
	       FLT_DIG + 2, FLT_DIG + 2, "float",
	       DBL_DIG + 2, DBL_DIG + 2, "double",
	       LDBL_DIG + 2, LDBL_DIG + 2, "long double");
	for (volatile int i = -20; i <= 20; i++)
		printf("  % 3d  % *.*f % *.*f % *.*Lf\n", i,
		    FLT_DIG, FLT_DIG, cbrt_r4(i),
		    DBL_DIG, DBL_DIG, cbrt_r8(i),
		    LDBL_DIG, LDBL_DIG, cbrt_re(i));

	return 0;
}