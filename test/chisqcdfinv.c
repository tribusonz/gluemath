/*******************************************************************************
	GLUE-Math test routine: chisqcdfinv()

*******************************************************************************/
#include "../dist/dist.h"
#include <stdio.h>
#include <math.h> /* sqrt(), exp(), log(), pow() */

/*******************************************************************************
$ gcc -Wall -Wextra -O3 -o bin/chisqcdfinv test/chisqcdfinv.c dist/snormcdfinv.c dist/chisqcdfc.c

***** chi2^-1{q}(chi2, 1) *****
chi2   inverseCDF       CDF
0.00              inf 0.00000000000000
0.05 3.84145882069413 0.05000000000000
0.10 2.70554345409541 0.10000000000000
0.15 2.07225085582223 0.15000000000000
0.20 1.64237441514982 0.20000000000000
0.25 1.32330369693147 0.25000000000000
0.30 1.07419417085758 0.30000000000000
0.35 0.87345714298923 0.35000000000000
0.40 0.70832630080079 0.40000000000000
0.45 0.57065186205119 0.45000000000000
0.50 0.45493642311957 0.50000000000000
0.55 0.35731716828632 0.55000000000000
0.60 0.27499589772846 0.60000000000000
0.65 0.20590012522777 0.65000000000000
0.70 0.14847186183255 0.70000000000000
0.75 0.10153104426762 0.75000000000000
0.80 0.06418475466730 0.80000000000000
0.85 0.03576577915590 0.85000000000000
0.90 0.01579077409343 0.90000000000000
0.95 0.00393214000002 0.95000000000000
***** chi2^-1{q}(chi2, 2) *****
chi2   inverseCDF       CDF
0.00              inf 0.00000000000000
0.05 5.99146454710798 0.05000000000000
0.10 4.60517018598809 0.10000000000000
0.15 3.79423996977176 0.15000000000000
0.20 3.21887582486820 0.20000000000000
0.25 2.77258872223978 0.25000000000000
0.30 2.40794560865187 0.30000000000000
0.35 2.09964424899736 0.35000000000000
0.40 1.83258146374831 0.40000000000000
0.45 1.59701539243554 0.45000000000000
0.50 1.38629436111989 0.50000000000000
0.55 1.19567400151124 0.55000000000000
0.60 1.02165124753198 0.60000000000000
0.65 0.86156583218491 0.65000000000000
0.70 0.71334988787746 0.70000000000000
0.75 0.57536414490356 0.75000000000000
0.80 0.44628710262842 0.80000000000000
0.85 0.32503785899555 0.85000000000000
0.90 0.21072103131565 0.90000000000000
0.95 0.10258658877510 0.95000000000000
***** chi2^-1{q}(chi2, 5) *****
chi2   inverseCDF       CDF
0.00              inf 0.00000000000000
0.05 11.07036969856359 0.05000247351458
0.10 9.23621960731048 0.10000505879683
0.15 8.11511208006880 0.15000464225208
0.20 7.28923136149970 0.20000306134385
0.25 6.62566194193195 0.25000147177489
0.30 6.06442574471117 0.30000040589029
0.35 5.57306994623378 0.35000000604234
0.40 5.13186554987280 0.40000018112020
0.45 4.72775107411269 0.45000070874637
0.50 4.35145064566483 0.50000130806586
0.55 3.99593266069705 0.55000169897112
0.60 3.65548852671394 0.60000165809981
0.65 3.32510034095201 0.65000107896215
0.70 2.99990786924961 0.70000004062811
0.75 2.67461013764902 0.74999888083648
0.80 2.34254625548094 0.79999823397003
0.85 1.99382479450278 0.84999883286325
0.90 1.61030804781001 0.89999999260867
0.95 1.14560011289470 0.94998860858024
***** chi2^-1{q}(chi2, 20) *****
chi2   inverseCDF       CDF
0.00              inf 0.00000000000000
0.05 31.40975141915889 0.05000824827567
0.10 28.41198264327007 0.09999995476067
0.15 26.49778361435195 0.14999378677450
0.20 25.03775832825796 0.19999038367230
0.25 23.82792678345898 0.24998952536519
0.30 22.77472731400690 0.29999083367615
0.35 21.82659218086760 0.34999389689451
0.40 20.95139726049465 0.39999829409626
0.45 20.12711714235173 0.45000359421733
0.50 19.33728395061728 0.50000934672811
0.55 18.56845016954357 0.55001506792899
0.60 17.80852233716996 0.60002022309418
0.65 17.04539230912439 0.65002420301340
0.70 16.26543914740121 0.70002629216043
0.75 15.45134377753548 0.75002562429072
0.80 14.57805280735257 0.80002112061812
0.85 13.60362044627490 0.85001141364595
0.90 12.44274432899652 0.89999483603347
0.95 10.85201086515369 0.94997035518613
*******************************************************************************/

/* 多項式アルゴリズム。名もなき数学者による版 */
double
chisqcdfcinv(double q, int n)
{
	double c1, c2, gam, x, w, wx;
	static const double SQRT_PI = 1.772453850905516;
	int j;
	
	     if (q == 0)  return HUGE_VAL;
	else if (q != q)  return NAN;
	
	if (n == 1)
	{
		if (!isnan(w = snormcdfinv(0.5 * q)))
			return w * w;
		return NAN;
	}
	if (n == 2)
	{
		if (q >= 0 && q <= 1)
			return -2.0 * log(q);
		return NAN;
	}
	x = -snormcdfinv(q);
	if (n > 10)
	{
		w = x * x;
		wx = sqrt(2.0 * n);
		c1 = (w - 7.0) * x / 9.0 / wx;
		c2 = ((3.0 * w + 7.0) * w - 16.0) * 2.0 / 405.0 / n;
		wx = n + wx * x + 2.0 * (w - 1.0) / 3.0 + c1 - c2;
		if (wx < 0.0) return 0.0;
		return wx;
	}
	/* else */
	w = 2.0 / 9.0 / n;
	w = 1.0 - w + x * sqrt(w);
	wx = n * w * w * w;
	if (n % 2) gam = SQRT_PI;
	else       gam = 1.0;
	j = (n + 1) / 2 - 1;
	w = n / 2.0;
	for (volatile int i = 1; i <= j; i++) gam *= (w - i);
	x = wx / 2.0;
	c1 = pow(x, w - 1.0);
	c2 = exp(-x) / 2.0;
	return wx + (chisqcdfc(wx, n) - q) * gam / c1 / c2;
}

int
main(void)
{
	int i;
	double chi2, v;

	printf("***** chi2^-1{q}(chi2, 1) *****\n");
	printf("chi2   %-16s %-16s\n", "inverseCDF", "CDF");
	for (i = 0; i < 20; i++) {
		chi2 = i / 20.0;
		printf("%4.2f ", chi2);
		v = chisqcdfcinv(chi2, 1);
		printf("%16.14f %16.14f\n",
		    v, chisqcdfc(v, 1));
	}
	printf("***** chi2^-1{q}(chi2, 2) *****\n");
	printf("chi2   %-16s %-16s\n", "inverseCDF", "CDF");
	for (i = 0; i < 20; i++) {
		chi2 = i / 20.0;
		printf("%4.2f ", chi2);
		v = chisqcdfcinv(chi2, 2);
		printf("%16.14f %16.14f\n",
		    v, chisqcdfc(v, 2));
	}
	printf("***** chi2^-1{q}(chi2, 5) *****\n");
	printf("chi2   %-16s %-16s\n", "inverseCDF", "CDF");
	for (i = 0; i < 20; i++) {
		chi2 = i / 20.0;
		printf("%4.2f ", chi2);
		v = chisqcdfcinv(chi2, 5);
		printf("%16.14f %16.14f\n",
		    v, chisqcdfc(v, 5));
	}
	printf("***** chi2^-1{q}(chi2, 20) *****\n");
	printf("chi2   %-16s %-16s\n", "inverseCDF", "CDF");
	for (i = 0; i < 20; i++) {
		chi2 = i / 20.0;
		printf("%4.2f ", chi2);
		v = chisqcdfcinv(chi2, 20);
		printf("%16.14f %16.14f\n",
		    v, chisqcdfc(v, 20));
	}
	return 0;
}
