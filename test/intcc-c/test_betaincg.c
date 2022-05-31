/*******************************************************************************
	Generalized Incomplete Beta Function
*******************************************************************************/
#include <math.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include "fft2f.h"
#include "intcc.h"

double at, bt;

int
main(void)
{
	double betaincgterm(double);
	int lenw = 3200;
	double w[3200 + 1], i, err;
	double x0, x1;
	
	printf("x0 x1 a b ? ");  scanf("%lf%lf%lf%lf", &x0, &x1, &at, &bt);
	fflush(stdout);
	
	intccini(lenw, w);
	intcc(betaincgterm, x0, x1, DBL_EPSILON, lenw, w, &i, &err);
	printf("B_{%g, %g}(%g, %g) = ", x0, x1, at, bt);
	printf("%.15g\n(err = %.15lg)\n", i, err);
}

double
betaincgterm(double t)
{
	return pow(t, at - 1) * pow(1 - t, bt - 1);
}

