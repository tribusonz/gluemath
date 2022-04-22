/*******************************************************************************
	GLUE-Math test routine: poisscdfinv()

	Following paper:
		Algorithm 955: approximation of the inverse Poisson cumulative
		               distribution function
			by Michael B. Giles, University of Oxford, UK
*******************************************************************************/
#include "../dist/dist.h"
#include <stdio.h>
/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -o bin/poisscdfinv test/poisscdfinv.c dist/poisscdfinv.c dist/poisscdfcinv.c dist/poisscdf.c dist/poisscdfc.c

And Test Result:
Poisson Distribution CDF with its inverse test
CDF, lambda = 2
 (q) F^-1(q)   (Diff)
0.0 :     0    (-0.135335)
0.1 :     0    (-0.0353353)
0.2 :     1    (-0.206006)
0.3 :     1    (-0.106006)
0.4 :     1    (-0.00600585)
0.5 :     2    (-0.176676)
0.6 :     2    (-0.0766764)
0.7 :     3    (-0.157123)
0.8 :     3    (-0.0571235)
0.9 :     4    (-0.047347)
1.0 :   inf    (0)
CDFC, lambda = 2
 (q) F^-1(q)   (Diff)
0.0 :   inf    (0)
0.1 :     4    (0.047347)
0.2 :     3    (0.0571235)
0.3 :     3    (0.157123)
0.4 :     2    (0.0766764)
0.5 :     2    (0.176676)
0.6 :     1    (0.00600585)
0.7 :     1    (0.106006)
0.8 :     1    (0.206006)
0.9 :     0    (0.0353353)
1.0 :     0    (0.135335)
CDF, lambda = 7
 (q) F^-1(q)   (Diff)
0.0 :     0    (-0.000911882)
0.1 :     4    (-0.0729916)
0.2 :     5    (-0.100708)
0.3 :     5    (-0.000708276)
0.4 :     6    (-0.0497111)
0.5 :     7    (-0.0987138)
0.6 :     8    (-0.129091)
0.7 :     8    (-0.0290913)
0.8 :     9    (-0.0304959)
0.9 :    10    (-0.00147921)
1.0 :   inf    (0)
CDFC, lambda = 7
 (q) F^-1(q)   (Diff)
0.0 :   inf    (0)
0.1 :    10    (0.00147921)
0.2 :     9    (0.0304959)
0.3 :     8    (0.0290913)
0.4 :     8    (0.129091)
0.5 :     7    (0.0987138)
0.6 :     6    (0.0497111)
0.7 :     5    (0.000708276)
0.8 :     5    (0.100708)
0.9 :     4    (0.0729916)
1.0 :     0    (0.000911882)
CDF, lambda = 12
 (q) F^-1(q)   (Diff)
0.0 :     0    (-6.14421e-06)
0.1 :     8    (-0.0550278)
0.2 :     9    (-0.0423922)
0.3 :    10    (-0.0472294)
0.4 :    11    (-0.0615973)
0.5 :    12    (-0.0759652)
0.6 :    13    (-0.0815356)
0.7 :    14    (-0.0720245)
0.8 :    15    (-0.0444157)
0.9 :    17    (-0.0370337)
1.0 :   inf    (0)
CDFC, lambda = 12
 (q) F^-1(q)   (Diff)
0.0 :   inf    (0)
0.1 :    17    (0.0370337)
0.2 :    15    (0.0444157)
0.3 :    14    (0.0720245)
0.4 :    13    (0.0815356)
0.5 :    12    (0.0759652)
0.6 :    11    (0.0615973)
0.7 :    10    (0.0472294)
0.8 :     9    (0.0423922)
0.9 :     8    (0.0550278)
1.0 :     0    (6.14421e-06)
*******************************************************************************/

static void poisscdf_test(double);
static void poisscdfc_test(double);

int
main(void)
{
	puts("Poisson Distribution CDF with its inverse test");
	poisscdf_test(2);
	poisscdfc_test(2);
	poisscdf_test(7);
	poisscdfc_test(7);
	poisscdf_test(12);
	poisscdfc_test(12);
	return 0;
}

static void
poisscdf_test(double lambda)
{
	double y;
	printf("CDF, lambda = %g\n", lambda);
	puts(" (q) F^-1(q)   (Diff)");
	for (volatile int x = 0; x <= 10; x++) {
		const double q = x / 10.0; // Iterator Constant
		printf("%1.1f : ", q);
		y = poisscdfinv(q, lambda);
		printf("%5.0f    ", y);
		y = poisscdf(y, lambda);
		printf("(%g)\n", q-y);
	}
}

static void
poisscdfc_test(double lambda)
{
	double y;
	printf("CDFC, lambda = %g\n", lambda);
	puts(" (q) F^-1(q)   (Diff)");
	for (volatile int x = 0; x <= 10; x++) {
		const double q = x / 10.0; // Iterator Constant
		printf("%1.1f : ", q);
		y = poisscdfcinv(q, lambda);
		printf("%5.0f    ", y);
		y = poisscdfc(y, lambda);
		printf("(%g)\n", q-y);
	}
}
