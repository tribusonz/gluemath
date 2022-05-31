/*******************************************************************************
	Clenshaw-Curtis-Quadrature Numerical Automatic Integrator
	  method    : Chebyshev Series Expansion
	  dimension : one
	  table     : use
	function
	  intcc  : integrator of f(x) over [a,b].
	necessary package
	  fft2f.c  : FFT package
*******************************************************************************/
#ifndef INTCC_H
#define INTCC_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "class.h"

/*
intcc
    [description]
        I = integral of f(x) over [a,b]
    [declaration]
        void intccini(int lenw, double *w);
        void intcc(double (*f)(double), double a, double b, double eps, 
            int lenw, double *w, double *i, double *err);
    [usage]
        intccini(lenw, w);  // initialization of w
        ...
        intcc(f, a, b, eps, lenw, w, &i, &err);
    [parameters]
        lenw      : (length of w[]) - 1 (int)
        w         : work area and weights of the quadrature 
                    formula, w[0...lenw] (double *)
        f         : integrand f(x) (double (*f)(double))
        a         : lower limit of integration (double)
        b         : upper limit of integration (double)
        eps       : relative error requested (double)
        i         : approximation to the integral (double *)
        err       : estimate of the absolute error (double *)
    [remarks]
        initial parameters
            lenw >= 14 and 
            lenw > (maximum number of f(x) evaluations) * 3 / 2
            example :
                lenc = 3200;
        function
            f(x) needs to be analytic over [a,b].
        relative error
            eps is relative error requested excluding 
            cancellation of significant digits.
            i.e. eps means : (absolute error) / 
                             (integral_a^b |f(x)| dx).
            eps does not mean : (absolute error) / I.
        error message
            err >= 0 : normal termination.
            err < 0  : abnormal termination (n > nmax).
                       i.e. convergent error is detected :
                           1. f(x) or (d/dx)^n f(x) has 
                              discontinuous points or sharp 
                              peaks over [a,b].
                              you must use other routine.
                           2. relative error of f(x) is 
                              greater than eps.
                           3. f(x) has oscillatory factor 
                              and frequency of the oscillation 
                              is very high.
*/
extern void intccini(int, double*);
extern void intcc(
  integrand, double, double, double,
  int, double*, double*, double*);

#if defined(__cplusplus)
}
#endif

#endif /* INTCC_H */

