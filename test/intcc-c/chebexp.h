/*******************************************************************************
	Chebyshev Series Expansion and Interpolation routine functions
	  chebexp  : function f(x) -> Chebyshev series
	  chebeval : Chebyshev series -> evaluation of the f(x)
	necessary package
	  fft2f.c  : FFT package
*******************************************************************************/
#ifndef CHEBEXP_H
#define CHEBEXP_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "class.h"

/*
chebexp, chebeval
    [description]
        evaluation of f(x) from Chebyshev series of f(x)
    [declaration]
        void chebexp(double (*f)(double), double a, double b, 
            double eps, int lenc, double *c, double *err);
        double chebeval(double x, double *c);
    [usage]
        chebexp(f, a, b, eps, lenc, c, &err);  // f(x) -> c[]
        ...
        y = chebeval(x, c);  // evaluation of the f(x) from c[]
    [parameters]
        f         : function f(x) (double (*f)(double))
        a         : lower limit of interpolation (double)
        b         : upper limit of interpolation (double)
        eps       : relative error of interpolation (double)
        lenc      : (length of c[]) - 1 (int)
        c         : data of Chebyshev expansion, 
                    c[0...lenc] (double *)
        err       : estimate of the maximum absolute error 
                    of the interpolation over [a,b] (double *)
    [remarks]
        initial parameters
            lenc >= 12
            example :
                lenc = 1024 + 4;
        function
            f(x) needs to be analytic over [a,b].
        relative error
            eps is relative error requested excluding 
            cancellation of significant digits.
            i.e. eps means : (maximum absolute error) / 
                             (integral_a^b |f(x)| dx).
            eps does not mean : (maximum absolute error) / I.
        error message
            err >= 0 : normal termination.
            err < 0  : abnormal termination (n > lenc-4).
                       i.e. convergent error is detected :
                           1. f(x) or (d/dx)^n f(x) has 
                              discontinuous points or sharp 
                              peaks over [a,b].
                           2. relative error of f(x) is 
                              greater than eps.
                           3. f(x) has oscillatory factor 
                              and frequency of the oscillation 
                              is very high.
        array of c[]
            lenc           : (int) c[0]
            n              : (int) c[1]
            (b+a)/2        : c[2]
            2/(b-a)        : c[3]
            f(c[2]-t/c[3]) : c[lenc]*T_0(t) + c[lenc-1]*T_1(t) 
                             + ... + c[lenc-n]*T_n(t)
*/
extern void chebexp(integrand, double, double, double, int, double*, double*);
extern double chebeval(double, double*);

#if defined(__cplusplus)
}
#endif

#endif /* CHEBEXP_H */
