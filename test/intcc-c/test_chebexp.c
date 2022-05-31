/* test of chebexp.c */

#include <math.h>
#include <float.h>
#include <stdio.h>

#include "fft2f.h"
#include "chebexp.h"

int nf = 0;

int
main(void)
{
	double f(double);
	int lenc = 1024 + 4, nn, j;
	double a, b, eps, c[1024 + 5], err, e, emax, x;
	
	a = 1.0;
	b = 2.0;
	eps = DBL_EPSILON;
	chebexp(f, a, b, eps, lenc, c, &err);
	nn = nf;
	emax = 0;
	for (j = 0; j <= nn; j++)
	{
		x = a + (b - a) * j / nn;
		e = chebeval(x, c) - f(x);
		if (emax < fabs(e)) emax = fabs(e);
	}
	printf("interpolation of sin(log(x)) over [%lg,%lg]\n", a, b);
	printf("N_eval= %d  n= %d  err= %.15lg  max_err= %.15lg\n", 
	       nn, (int) c[1], err, emax);
}


double
f(double x)
{
	nf++;
	return sin(log(x));
}

