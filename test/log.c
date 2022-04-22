/*******************************************************************************
	GLUE-Math test routine: Natural Logarithm
*******************************************************************************/
#if defined(_CMATH_TEST)
# include "../legacy/legacy.h"
# define log_r8 log 
# define log_re logl
# define log_r4 logf
#else
# include "../realmath/realmath.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -D_CMATH_TEST -o bin/log test/log.c legacy/log.c legacy/logl.c legacy/logf.c
$ gcc -Wall -Wextra -O3 -o bin/log test/log.c realmath/log_r8.c realmath/log_re.c realmath/log_r4.c

And Test Result:
GLUE-Math with POSIX standard
Test Suite:
  Natural Logarithm

  (x)   float     double             long double
  0.2  -1.609438 -1.609437912434100 -1.609437912434100319
  0.4  -0.916291 -0.916290731874155 -0.916290731874155010
  0.6  -0.510826 -0.510825623765991 -0.510825623765990720
  0.8  -0.223144 -0.223143551314210 -0.223143551314209700
  1.0   0.000000  0.000000000000000  0.000000000000000000
  1.2   0.182322  0.182321556793955  0.182321556793954589
  1.4   0.336472  0.336472236621213  0.336472236621212867
  1.6   0.470004  0.470003629245736  0.470003629245735609
  1.8   0.587787  0.587786664902119  0.587786664902119033
  2.0   0.693147  0.693147180559945  0.693147180559945309
  2.2   0.788457  0.788457360364270  0.788457360364270250
  2.4   0.875469  0.875468737353900  0.875468737353899898
  2.6   0.955511  0.955511445027436  0.955511445027436395
  2.8   1.029619  1.029619417181158  1.029619417181158176
  3.0   1.098612  1.098612288668110  1.098612288668109691
  3.2   1.163151  1.163150809805681  1.163150809805680918
  3.4   1.223775  1.223775431622116  1.223775431622115679
  3.6   1.280934  1.280933845462064  1.280933845462064342
  3.8   1.335001  1.335001066732340  1.335001066732340038
  4.0   1.386294  1.386294361119891  1.386294361119890619
*******************************************************************************/

int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Natural Logarithm");
	puts("");
	printf("  %3.3s   %-*.*s  %-*.*s  %-*.*s\n", "(x)",
	       FLT_DIG + 2, FLT_DIG + 2, "float",
	       DBL_DIG + 2, DBL_DIG + 2, "double",
	       LDBL_DIG + 2, LDBL_DIG + 2, "long double");
	for (int i = 1; i <= 20; i++) {
		const double x = i / 5.0;  // Iterator Constant
		printf("%5.1f  %*.*f %*.*f %*.*Lf\n",
		    x, FLT_DIG + 3, FLT_DIG, log_r4(x),
		    DBL_DIG + 3, DBL_DIG, log_r8(x),
		    LDBL_DIG + 3, LDBL_DIG, log_re(x));
	}
	return 0;
}
