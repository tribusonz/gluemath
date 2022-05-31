/* test of intcc2.c */

#include <math.h>
#include <float.h>
#include <stdio.h>

#include "fft2f.h"
#include "intcc.h"

int nf = 0;

int
main(void)
{
    double f(double);
    int lenw = 3200;
    double w[3200 + 1], i, err;
    
    intccini(lenw, w);
    intcc(f, 0.0, 1.0, DBL_EPSILON, lenw, w, &i, &err);
    printf("I= integral_0^1 4/(1+x^2) dx\n");
    printf("I= %.15lg\t err= %.15lg\t N= %d\n", i, err, nf);
}

double
f(double x)
{
    nf++;
    return 4 / (1 + x * x);
}

