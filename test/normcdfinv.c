/*******************************************************************************
	GLUE-Math test routine: normcdfinv()

	Following paper:
		Algorithm 955: approximation of the inverse Poisson cumulative
		               distribution function
			by Michael B. Giles, University of Oxford, UK
*******************************************************************************/
#include "../dist/dist.h"
#include <stdio.h>
#include <float.h>
/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -o bin/normcdfinv test/normcdfinv.c dist/normcdfinv.c dist/normcdfcinv.c dist/snormcdfinv.c dist/snormcdfcinv.c

And Test Result:
Inverse Normal CDF test
(q)    phi^-1(q; 0, 1)          phi^-1(q)   phic^-1(q; 0, 1)         phic^-1(q)
0.0              -inf              -inf               inf               inf
0.1  -1.28155156554460  -1.28155156554460   1.28155156554460   1.28155156554460
0.2  -0.84162123357291  -0.84162123357291   0.84162123357291   0.84162123357291
0.3  -0.52440051270804  -0.52440051270804   0.52440051270804   0.52440051270804
0.4  -0.25334710313580  -0.25334710313580   0.25334710313580   0.25334710313580
0.5   0.00000000000000   0.00000000000000   0.00000000000000   0.00000000000000
0.6   0.25334710313580   0.25334710313580  -0.25334710313580  -0.25334710313580
0.7   0.52440051270804   0.52440051270804  -0.52440051270804  -0.52440051270804
0.8   0.84162123357291   0.84162123357291  -0.84162123357291  -0.84162123357291
0.9   1.28155156554460   1.28155156554460  -1.28155156554460  -1.28155156554460
1.0               inf               inf              -inf              -inf
*******************************************************************************/

int
main(void)
{
	puts("Inverse Normal CDF test");
	printf("%3s %*s %*s %*s %*s\n", "(q)",
	       DBL_DIG + 3, "phi^-1(q; 0, 1)", DBL_DIG + 3, "phi^-1(q)",
	       DBL_DIG + 3, "phic^-1(q; 0, 1)", DBL_DIG + 3, "phic^-1(q)");
	for (volatile int i = 0; i < 11; i++)
	{
		const double q = i / 10.0;  // Iterator Constant
		printf("%2.1f  % 16.14f  % 16.14f  % 16.14f  % 16.14f\n",
		       q, normcdfinv(q, 0, 1),  snormcdfinv(q),
		          normcdfcinv(q, 0, 1), snormcdfcinv(q));
	}
}
