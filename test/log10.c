/*******************************************************************************
	GLUE-Math test suite: Common Logarithm
*******************************************************************************/
#if defined(_CMATH_TEST)
# include "../legacy/legacy.h"
# define log10_r8 log10
# define log10_re log10l
# define log10_r4 log10f
#else
# include "../realmath/realmath.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -D_CMATH_TEST -o bin/log10 test/log10.c legacy/log10.c legacy/log10l.c legacy/log10f.c
$ gcc -Wall -Wextra -O3 -o bin/log10 test/log10.c realmath/log10_r8.c realmath/log10_re.c realmath/log10_r4.c

And Test Result:
GLUE-Math with POSIX standard
Test Suite:
  Common Logarithm

  (x)   float     double             long double
  0.2  -0.698970 -0.698970004336019 -0.698970004336018781
  0.4  -0.397940 -0.397940008672038 -0.397940008672037586
  0.6  -0.221849 -0.221848749616357 -0.221848749616356384
  0.8  -0.096910 -0.096910013008056 -0.096910013008056390
  1.0   0.000000  0.000000000000000  0.000000000000000000
  1.2   0.079181  0.079181246047625  0.079181246047624812
  1.4   0.146128  0.146128035678238  0.146128035678237998
  1.6   0.204120  0.204119982655925  0.204119982655924805
  1.8   0.255272  0.255272505103306  0.255272505103306080
  2.0   0.301030  0.301029995663981  0.301029995663981195
  2.2   0.342423  0.342422680822206  0.342422680822206271
  2.4   0.380211  0.380211241711606  0.380211241711606007
  2.6   0.414973  0.414973347970818  0.414973347970817979
  2.8   0.447158  0.447158031342219  0.447158031342219193
  3.0   0.477121  0.477121254719662  0.477121254719662437
  3.2   0.505150  0.505149978319906  0.505149978319906000
  3.4   0.531479  0.531478917042255  0.531478917042255112
  3.6   0.556302  0.556302500767287  0.556302500767287276
  3.8   0.579784  0.579783596616810  0.579783596616810136
  4.0   0.602060  0.602059991327962  0.602059991327962390
*******************************************************************************/

int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Common Logarithm");
	puts("");
	printf("  %3.3s   %-*.*s  %-*.*s  %-*.*s\n", "(x)",
	       FLT_DIG + 2, FLT_DIG + 2, "float",
	       DBL_DIG + 2, DBL_DIG + 2, "double",
	       LDBL_DIG + 2, LDBL_DIG + 2, "long double");
	for (int i = 1; i <= 20; i++) {
		const double x = i / 5.0;  // Iterator Constant
		printf("%5.1f  %*.*f %*.*f %*.*Lf\n",
		    x, FLT_DIG + 3, FLT_DIG, log10_r4(x),
		    DBL_DIG + 3, DBL_DIG, log10_r8(x),
		    LDBL_DIG + 3, LDBL_DIG, log10_re(x));
	}
	return 0;
}
