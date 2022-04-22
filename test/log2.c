/*******************************************************************************
	GLUE-Math test suite: Binary Logarithm
*******************************************************************************/
#if defined(_CMATH_TEST)
# include "../legacy/legacy.h"
# define log2_r8 log2
# define log2_re log2l
# define log2_r4 log2f
#else
# include "../realmath/realmath.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -D_CMATH_TEST -o bin/log2 test/log2.c legacy/log2.c legacy/log2l.c legacy/log2f.c
$ gcc -Wall -Wextra -O3 -o bin/log2 test/log2.c realmath/log2_r8.c realmath/log2_re.c realmath/log2_r4.c

And Test Result:
GLUE-Math with POSIX standard
Test Suite:
  Binary Logarithm

  (x)   float     double             long double
  0.2  -2.321928 -2.321928094887363 -2.321928094887362268
  0.4  -1.321928 -1.321928094887362 -1.321928094887362268
  0.6  -0.736966 -0.736965594166206 -0.736965594166206220
  0.8  -0.321928 -0.321928094887362 -0.321928094887362268
  1.0   0.000000  0.000000000000000  0.000000000000000000
  1.2   0.263034  0.263034405833794  0.263034405833793780
  1.4   0.485427  0.485426827170242  0.485426827170241668
  1.6   0.678072  0.678071905112638  0.678071905112637732
  1.8   0.847997  0.847996906554950  0.847996906554950051
  2.0   1.000000  1.000000000000000  1.000000000000000000
  2.2   1.137504  1.137503523749935  1.137503523749935025
  2.4   1.263034  1.263034405833794  1.263034405833793780
  2.6   1.378512  1.378511623253730  1.378511623253729862
  2.8   1.485427  1.485426827170242  1.485426827170241668
  3.0   1.584962  1.584962500721156  1.584962500721156181
  3.2   1.678072  1.678071905112638  1.678071905112637732
  3.4   1.765535  1.765534746362977  1.765534746362977023
  3.6   1.847997  1.847996906554950  1.847996906554950051
  3.8   1.925999  1.925999418556223  1.925999418556223078
  4.0   2.000000  2.000000000000000  2.000000000000000000
*******************************************************************************/

int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Binary Logarithm");
	puts("");
	printf("  %3.3s   %-*.*s  %-*.*s  %-*.*s\n", "(x)",
	       FLT_DIG + 2, FLT_DIG + 2, "float",
	       DBL_DIG + 2, DBL_DIG + 2, "double",
	       LDBL_DIG + 2, LDBL_DIG + 2, "long double");
	for (int i = 1; i <= 20; i++) {
		const double x = i / 5.0;  // Iterator Constant
		printf("%5.1f  %*.*f %*.*f %*.*Lf\n",
		    x, FLT_DIG + 3, FLT_DIG, log2_r4(x),
		    DBL_DIG + 3, DBL_DIG, log2_r8(x),
		    LDBL_DIG + 3, LDBL_DIG, log2_re(x));
	}
	return 0;
}
