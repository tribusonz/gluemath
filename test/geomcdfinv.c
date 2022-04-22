/*******************************************************************************
	GLUE-Math Library: Geometric Distribution CDF / Inverse CDF

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Simulation and Statistical Programming Hilary Term 2020
		- Robert Davies
		- Anthony Caterini, Bobby He, Sheheryar Zaidi
		- Alan (Siu Chau)
		(University of Oxford)
*******************************************************************************/
#include <stdio.h>
#include "../dist/dist.h"
/*******************************************************************************
MinGW 64bit gcc build:
$ gcc -Wall -Wextra -O3 -o bin/geomcdfinv test/geomcdfinv.c dist/geomcdfinv.c dist/geomcdfcinv.c dist/geomcdf.c dist/geomcdfc.c

And test result:
Geometric Distribution CDF / Inverse CDF test

quantile=(50/100)
 (u)    F^-1(u, q) | Diff:(lower:upper)
0.00      0    inf | -0.50   0.00
0.05      0      4 | -0.45   0.02
0.10      0      3 | -0.40   0.04
0.15      0      3 | -0.35   0.09
0.20      0      2 | -0.30   0.08
0.25      0      2 | -0.25   0.12
0.30      1      2 | -0.45   0.17
0.35      1      2 | -0.40   0.22
0.40      1      1 | -0.35   0.15
0.45      1      1 | -0.30   0.20
0.50      1      1 | -0.25   0.25
0.55      1      1 | -0.20   0.30
0.60      1      1 | -0.15   0.35
0.65      2      1 | -0.22   0.40
0.70      2      1 | -0.18   0.45
0.75      2      0 | -0.12   0.25
0.80      2      0 | -0.07   0.30
0.85      3      0 | -0.09   0.35
0.90      3      0 | -0.04   0.40
0.95      4      0 | -0.02   0.45
1.00    inf      0 |  0.00   0.50

quantile=(10/100)
 (u)    F^-1(u, q) | Diff:(lower:upper)
0.00      0    inf | -0.10   0.00
0.05      0     28 | -0.05   0.00
0.10      1     22 | -0.09   0.01
0.15      2     18 | -0.12   0.01
0.20      2     15 | -0.07   0.01
0.25      3     13 | -0.09   0.02
0.30      3     11 | -0.04   0.02
0.35      4     10 | -0.06   0.04
0.40      5      9 | -0.07   0.05
0.45      6      8 | -0.07   0.06
0.50      7      7 | -0.07   0.07
0.55      8      6 | -0.06   0.07
0.60      9      5 | -0.05   0.07
0.65     10      4 | -0.04   0.06
0.70     11      3 | -0.02   0.04
0.75     13      3 | -0.02   0.09
0.80     15      2 | -0.01   0.07
0.85     18      2 | -0.01   0.12
0.90     22      1 | -0.01   0.09
0.95     28      0 | -0.00   0.05
1.00    inf      0 |  0.00   0.10

quantile=(5/100)
 (u)    F^-1(u, q) | Diff:(lower:upper)
0.00      0    inf | -0.05   0.00
0.05      1     58 | -0.05   0.00
0.10      2     45 | -0.04   0.01
0.15      3     37 | -0.04   0.01
0.20      4     31 | -0.03   0.01
0.25      6     27 | -0.05   0.01
0.30      7     23 | -0.04   0.01
0.35      8     20 | -0.02   0.01
0.40     10     18 | -0.03   0.02
0.45     12     16 | -0.04   0.03
0.50     14     14 | -0.04   0.04
0.55     16     12 | -0.03   0.04
0.60     18     10 | -0.02   0.03
0.65     20      8 | -0.01   0.02
0.70     23      7 | -0.01   0.04
0.75     27      6 | -0.01   0.05
0.80     31      4 | -0.01   0.03
0.85     37      3 | -0.01   0.04
0.90     45      2 | -0.01   0.04
0.95     58      1 | -0.00   0.05
1.00    inf      0 |  0.00   0.05
*******************************************************************************/

static void geomcdfinv_test(double);

int
main(void)
{
	puts("Geometric Distribution CDF / Inverse CDF test");
	puts("");
	geomcdfinv_test(0.5);  // 50percent
	puts("");
	geomcdfinv_test(0.1);  // 10percent
	puts("");
	geomcdfinv_test(0.05);  // 5percent
	return 0;
}

static void
geomcdfinv_test(double q)
{
	printf("quantile=(%g/100)\n", q*100);
	printf("%4s    %.16s | %.20s\n", "(u)", "F^-1(u, q)", "Diff:(lower:upper)");
	for (volatile int i = 0; i <= 20; i++)
	{
		const double u    = i / 20.0,
		             pval = geomcdfinv(u, q),
		             qval = geomcdfcinv(u, q);
		printf("%1.2f  %5g  %5g | % 1.2f  % 1.2f\n",
		       u, pval, qval, u-geomcdf(pval, q), u-geomcdfc(qval, q));
	}
}
