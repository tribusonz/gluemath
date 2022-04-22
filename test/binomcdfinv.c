/*******************************************************************************
	Distribution Library -- Binomial Distribution Inverse CDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Efficient evaluation of the inverse Binomial
		cumulative distribution function where the
		number of trials is large
			by Sean Moorhead
*******************************************************************************/
#include "../dist/dist.h"
#include <stdio.h>
/*******************************************************************************
MinGW 64bit gcc build:
$ gcc -Wall -Wextra -O3 -o bin/binomcdfinv test/binomcdfinv.c dist/binomcdfinv.c dist/binomcdfcinv.c

Binomial Distribution Inverse CDF test
number of trials=50, percentile=0.5
(q)  Bi^-1(q;n,p)
0.00   0   50
0.05   19   31
0.10   20   30
0.15   21   29
0.20   22   28
0.25   23   27
0.30   23   27
0.35   24   26
0.40   24   26
0.45   25   25
0.50   25   25
0.55   25   25
0.60   26   24
0.65   26   24
0.70   27   23
0.75   27   23
0.80   28   22
0.85   29   21
0.90   30   20
0.95   31   19
1.00   50   0
number of trials=50, percentile=0.9
(q)  Bi^-1(q;n,p)
0.00   0   50
0.05   41   48
0.10   42   48
0.15   43   47
0.20   43   47
0.25   44   47
0.30   44   46
0.35   44   46
0.40   45   46
0.45   45   45
0.50   45   45
0.55   45   45
0.60   46   45
0.65   46   44
0.70   46   44
0.75   47   44
0.80   47   43
0.85   47   43
0.90   48   42
0.95   48   41
1.00   50   0
number of trials=500, percentile=0.1
(q)  Bi^-1(q;n,p)
0.00   0   107
0.05   39   61
0.10   41   59
0.15   43   57
0.20   44   56
0.25   45   54
0.30   46   53
0.35   47   52
0.40   48   52
0.45   49   51
0.50   50   50
0.55   51   49
0.60   52   48
0.65   52   47
0.70   53   46
0.75   54   45
0.80   56   44
0.85   57   43
0.90   59   41
0.95   61   39
1.00   107   0
*******************************************************************************/
void binomcdfinv_print(int, double);

int
main(void)
{
	int n;
	double p;
	
	puts("Binomial Distribution Inverse CDF test");
	n = 50; p = 0.5;
	binomcdfinv_print(n, p);
	n = 50; p = 0.9;
	binomcdfinv_print(n, p);
	n = 500; p = 0.1;
	binomcdfinv_print(n, p);
	
	return 0;
}

void
binomcdfinv_print(int n, double p)
{
	printf("number of trials=%d, percentile=%g\n", n, p);
	puts("(q)  Bi^-1(q;n,p)");
	for (volatile int i = 0; i <= 20; i++)
	{
		const double q = i / 20.0;  // Iterator Constant.
		printf("%1.2f  % g  % g\n",
		       q, binomcdfinv(q, n, p), binomcdfcinv(q, n, p));
	}
}
