/*
---- calculation of PI(= 3.14159...) using FFT ----
    by T.Ooura, ver. LG1.1.2-MP1.5a Sep. 2001.

This is a test program to estimate the performance of
the FFT routines: fft*g.c.
*/

/* Please check the following macros before compiling */
#ifndef DBL_ERROR_MARGIN
#define DBL_ERROR_MARGIN 0.3  /* must be < 0.5 */
#endif

#include <math.h>
#include <limits.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mp.h"

int
main(void)
{
	int nfft, log2_nfft, radix, log10_radix, n, npow, nprc;
	double err, d_time, n_op;
	int *a, *b, *c, *e, *i1, *i2, *ip;
	double *d1, *d2, *d3, *w;
	time_t t_1, t_2;
	FILE *f_log, *f_out;
	
	f_log = fopen("pi.log", "w");
	printf("PI calculation to estimate the FFT benchmarks\n");
	fprintf(f_log, "PI calculation to estimate the FFT benchmarks\n");
	printf("length of FFT =?\n");
	scanf("%d", &nfft);
	
	printf("initializing...\n");
	for (log2_nfft = 1; (1 << log2_nfft) < nfft; log2_nfft++);
	nfft = 1 << log2_nfft;
	n = nfft + 2;
	ip = (int *) malloc((3 + (int) sqrt(0.5 * nfft)) * sizeof(int));
	w = (double *) malloc(nfft / 2 * sizeof(double));
	a = (int *) malloc((n + 2) * sizeof(int));
	b = (int *) malloc((n + 2) * sizeof(int));
	c = (int *) malloc((n + 2) * sizeof(int));
	e = (int *) malloc((n + 2) * sizeof(int));
	i1 = (int *) malloc((n + 2) * sizeof(int));
	i2 = (int *) malloc((n + 2) * sizeof(int));
	d1 = (double *) malloc((nfft + 2) * sizeof(double));
	d2 = (double *) malloc((nfft + 2) * sizeof(double));
	d3 = (double *) malloc((nfft + 2) * sizeof(double));
	if (d3 == NULL) {
		printf("Allocation Failure!\n");
		exit(1);
	}
	ip[0] = 0;
	/* ---- radix test ---- */
	log10_radix = 1;
	radix = 10;
	err = mp_mul_radix_test(n, radix, nfft, d1, ip, w);
	err += DBL_EPSILON * (n * radix * radix / 4);
	while (100 * err < DBL_ERROR_MARGIN && radix <= INT_MAX / 20) {
		err *= 100;
		log10_radix++;
		radix *= 10;
	}
	printf("nfft= %d\nradix= %d\nerror_margin= %g\n", nfft, radix, err);
	fprintf(f_log, "nfft= %d\nradix= %d\nerror_margin= %g\n", nfft, radix, err);
	printf("calculating %d digits of PI...\n", log10_radix * (n - 2));
	fprintf(f_log, "calculating %d digits of PI...\n", log10_radix * (n - 2));
	/* ---- time check ---- */
	time(&t_1);
	/*
	 * ---- a formula based on the AGM (Arithmetic-Geometric Mean) ----
	 *   c = sqrt(0.125);
	 *   a = 1 + 3 * c;
	 *   b = sqrt(a);
	 *   e = b - 0.625;
	 *   b = 2 * b;
	 *   c = e - c;
	 *   a = a + e;
	 *   npow = 4;
	 *   do {
	 *       npow = 2 * npow;
	 *       e = (a + b) / 2;
	 *       b = sqrt(a * b);
	 *       e = e - b;
	 *       b = 2 * b;
	 *       c = c - e;
	 *       a = e + b;
	 *   } while (e > SQRT_SQRT_EPSILON);
	 *   e = e * e / 4;
	 *   a = a + b;
	 *   pi = (a * a - e - e / 2) / (a * c - e) / npow;
	 * ---- modification ----
	 *   This is a modified version of Gauss-Legendre formula
	 *   (by T.Ooura). It is faster than original version.
	 * ---- reference ----
	 *   1. E.Salamin, 
	 *      Computation of PI Using Arithmetic-Geometric Mean, 
	 *      Mathematics of Computation, Vol.30 1976.
	 *   2. R.P.Brent, 
	 *      Fast Multiple-Precision Evaluation of Elementary Functions, 
	 *      J. ACM 23 1976.
	 *   3. D.Takahasi, Y.Kanada, 
	 *      Calculation of PI to 51.5 Billion Decimal Digits on 
	 *      Distributed Memoriy Parallel Processors, 
	 *      Transactions of Information Processing Society of Japan, 
	 *      Vol.39 No.7 1998.
	 *   4. T.Ooura, 
	 *      Improvement of the PI Calculation Algorithm and 
	 *      Implementation of Fast Multiple-Precision Computation, 
	 *      Information Processing Society of Japan SIG Notes, 
	 *      98-HPC-74, 1998.
	 */
	/* ---- c = sqrt(0.125) ---- */
	mp_sscanf(n, log10_radix, "0.125", a);
	mp_sqrt(n, radix, a, c, i1, i2, nfft, d1, d2, ip, w);
	/* ---- a = 1 + 3 * c ---- */
	mp_imul(n, radix, c, 3, e);
	mp_sscanf(n, log10_radix, "1", a);
	mp_add(n, radix, a, e, a);
	/* ---- b = sqrt(a) ---- */
	mp_sqrt(n, radix, a, b, i1, i2, nfft, d1, d2, ip, w);
	/* ---- e = b - 0.625 ---- */
	mp_sscanf(n, log10_radix, "0.625", e);
	mp_sub(n, radix, b, e, e);
	/* ---- b = 2 * b ---- */
	mp_add(n, radix, b, b, b);
	/* ---- c = e - c ---- */
	mp_sub(n, radix, e, c, c);
	/* ---- a = a + e ---- */
	mp_add(n, radix, a, e, a);
	printf("AGM iteration\n");
	fprintf(f_log, "AGM iteration\n");
	npow = 4;
	do {
		npow *= 2;
		/* ---- e = (a + b) / 2 ---- */
		mp_add(n, radix, a, b, e);
		mp_idiv_2(n, radix, e, e);
		/* ---- b = sqrt(a * b) ---- */
		mp_mul(n, radix, a, b, a, i1, nfft, d1, d2, d3, ip, w);
		mp_sqrt(n, radix, a, b, i1, i2, nfft, d1, d2, ip, w);
		/* ---- e = e - b ---- */
		mp_sub(n, radix, e, b, e);
		/* ---- b = 2 * b ---- */
		mp_add(n, radix, b, b, b);
		/* ---- c = c - e ---- */
		mp_sub(n, radix, c, e, c);
		/* ---- a = e + b ---- */
		mp_add(n, radix, e, b, a);
		/* ---- convergence check ---- */
		nprc = -e[1];
		if (e[0] == 0) {
			nprc = n;
		}
		printf("precision= %d\n", 4 * nprc * log10_radix);
		fprintf(f_log, "precision= %d\n", 4 * nprc * log10_radix);
	} while (4 * nprc <= n);
	/* ---- e = e * e / 4 (half precision) ---- */
	mp_idiv_2(n, radix, e, e);
	mp_squh(n, radix, e, e, nfft, d1, ip, w);
	/* ---- a = a + b ---- */
	mp_add(n, radix, a, b, a);
	/* ---- a = (a * a - e - e / 2) / (a * c - e) / npow ---- */
	mp_mul(n, radix, a, c, c, i1, nfft, d1, d2, d3, ip, w);
	mp_sub(n, radix, c, e, c);
	mp_inv(n, radix, c, b, i1, i2, nfft, d1, d2, ip, w);
	mp_squ(n, radix, a, a, i1, nfft, d1, d2, ip, w);
	mp_sub(n, radix, a, e, a);
	mp_idiv_2(n, radix, e, e);
	mp_sub(n, radix, a, e, a);
	mp_mul(n, radix, a, b, a, i1, nfft, d1, d2, d3, ip, w);
	mp_idiv(n, radix, a, npow, a);
	/* ---- time check ---- */
	time(&t_2);
	/* ---- output ---- */
	f_out = fopen("pi.dat", "w");
	printf("writing pi.dat...\n");
	mp_fprintf(n - 1, log10_radix, a, f_out);
	fclose(f_out);
	free(d3);
	free(d2);
	free(d1);
	free(i2);
	free(i1);
	free(e);
	free(c);
	free(b);
	free(a);
	free(w);
	free(ip);
	/* ---- benchmark ---- */
	n_op = 50.0 * nfft * log2_nfft * log2_nfft;
	printf("floating point operation: %g op.\n", n_op);
	fprintf(f_log, "floating point operation: %g op.\n", n_op);
	/* ---- difftime ---- */
	d_time = difftime(t_2, t_1);
	printf("execution time: %g sec. (real time)\n", d_time);
	fprintf(f_log, "execution time: %g sec. (real time)\n", d_time);
	fclose(f_log);
	return 0;
}
