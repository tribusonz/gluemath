/*******************************************************************************
	GLUE-Math Library -- Poisson Distribution Inverse CDF

	Author:
	  Mike B. Giles (Original algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License: GPL + X11(MIT)
	Following paper:
		Algorithm 955: approximation of the inverse Poisson cumulative
		               distribution function
			by Michael B. Giles, University of Oxford, UK
*******************************************************************************/
#ifndef GML_POISSCDFINV_CORE_INTERNAL
#define GML_POISSCDFINV_CORE_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: fmin(), fabs(), floor(), sqrt(), log(), exp(), erfc(), snormcdfinv()
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/comparable.h"
#include "../sys/primitive/float/comparable.h"
#include "../../sys/float/absolute.h"
#include "floor.h"
#include "sqrt.h"
#include "log.h"
#include "exp.h"
#include "erfc.h"
#include "snormcdfinv.h"

// Declare prototypes
static inline double ur_poisscdfinv(double, double, double);
static inline double poissinv_approx(double, double, double, double*);
static inline double poissinv_newtiter(double, double, double*);
static inline double poissinv_corrprod(double, double, double, double, double);
static inline double poissinv_sum(double, double, double, double, double);
static inline double poissinv_bottomup(double, double, double, double);
static inline double poissinv_topdown(double, double, double, double);

static inline double
ur_poisscdfinv(register double q, register double v, register double lambda)
{
	register double x=0.0, w, lambda_i=1.0/lambda, s;
	double delta;

	// handle exceptions -- constants defined in <math.h>
	if (q == 0.0)              return 0.0;
	if (v == 0.0)              return HUGE_VAL;
	if (!(q > 0.0 && v > 0.0)) return NAN;   // handles NAN inputs as well

	if (lambda > 4.0)
	{
		w = snormcdfinv_core(fmin(q, v));
		if (q > v) w = -w;

		// use polynomial approximations in central region
 		if (fabs(w) < 3.0)
			s = poissinv_approx(lambda, lambda_i, w, &delta);
		// otherwise use Newton iteration
		else
			s = poissinv_newtiter(lambda, w, &delta);

		// if x>10, round down to nearest integer, and check accuracy
		x = floor_core(s);

		if (s > 10.0 && s < x + 2.0 * delta)
		{
			// correction procedure based on Temme approximation
			if (x > 0.5 * lambda && x < 2.0 * lambda)
				x = poissinv_corrprod(x, q, v, lambda, lambda_i);
			// sum downwards or upwards
			else
				x = poissinv_sum(x, q, v, lambda, lambda_i);
		}
	}

	// bottom-up summation
	if (x < 10.0) x = poissinv_bottomup(q, v, lambda, lambda_i);

	return x;
}

static inline double
poissinv_approx(lambda, lambda_i, w, delta)
register double lambda, lambda_i, w;
double *delta;
{
	register double s, del;
	const double Lam_root = sqrt_core(lambda);

	s = Lam_root * w + (1.0 / 3.0 + (1.0 / 6.0) * w * w) * (1.0 - w / (12.0 * Lam_root));

	del = (1.0 / 160.0);
	del = (1.0 /  80.0) + del * (w * w);
	del = (1.0 /  40.0) + del * (w * w);
	del = del * lambda_i;

	s = lambda + (s + del);
	*delta = del;

	return s;
}

static inline double
poissinv_newtiter(lambda, w, delta)
register double lambda, w;
double *delta;
{
	register double s, s2, r, r2, t;

	s = w / sqrt_core(lambda);
	r = 1.0 + s;
	if (r < 0.1) r = 0.1;

	do {
		t  = log_core(r);
		r2 = r;
		s2 = sqrt_core(2.0 * ((1.0 - r) + r * t));
		if (r < 1.0) s2 = -s2;
		r = r2 - (s2 - s) * s2 / t;
		if (r < 0.1 * r2) r = 0.1 * r2;
	} while (fabs(r - r2) > 1e-8);

	t   = log_core(r);
	s   = lambda * r + log_core(sqrt_core(2.0 * r * ((1.0 - r) + r * t)) / fabs(r - 1.0)) / t;
	s   = s - 0.0218/(s + 0.065 * lambda);
	*delta = 0.01/s;
	s     = s + *delta;

	return s;
}

static inline double
poissinv_corrprod(x, q, v, lambda, lambda_i)
register double x, q, v, lambda, lambda_i;
{
	register double s, b0, b1, xi = 1.0 / x, eta = x * lambda_i;
	
	eta = sqrt_core(2.0 * (1.0 - eta + eta * log_core(eta)) / eta);
	if (x > lambda) eta = -eta;

	b1 =  8.0995211567045583e-16;                  s = b1;
	b0 = -1.9752288294349411e-15;                  s = b0 + s * eta;
	b1 = -5.1391118342426808e-16 + 25.0 * b1 * xi; s = b1 + s * eta;
	b0 =  2.8534893807047458e-14 + 24.0 * b0 * xi; s = b0 + s * eta;
	b1 = -1.3923887224181616e-13 + 23.0 * b1 * xi; s = b1 + s * eta;
	b0 =  3.3717632624009806e-13 + 22.0 * b0 * xi; s = b0 + s * eta;
	b1 =  1.1004392031956284e-13 + 21.0 * b1 * xi; s = b1 + s * eta;
	b0 = -5.0276692801141763e-12 + 20.0 * b0 * xi; s = b0 + s * eta;
	b1 =  2.4361948020667402e-11 + 19.0 * b1 * xi; s = b1 + s * eta;
	b0 = -5.8307721325504166e-11 + 18.0 * b0 * xi; s = b0 + s * eta;
	b1 = -2.5514193994946487e-11 + 17.0 * b1 * xi; s = b1 + s * eta;
	b0 =  9.1476995822367933e-10 + 16.0 * b0 * xi; s = b0 + s * eta;
	b1 = -4.3820360184533521e-09 + 15.0 * b1 * xi; s = b1 + s * eta;
	b0 =  1.0261809784240299e-08 + 14.0 * b0 * xi; s = b0 + s * eta;
	b1 =  6.7078535434015332e-09 + 13.0 * b1 * xi; s = b1 + s * eta;
	b0 = -1.7665952736826086e-07 + 12.0 * b0 * xi; s = b0 + s * eta;
	b1 =  8.2967113409530833e-07 + 11.0 * b1 * xi; s = b1 + s * eta;
	b0 = -1.8540622107151585e-06 + 10.0 * b0 * xi; s = b0 + s * eta;
	b1 = -2.1854485106799979e-06 +  9.0 * b1 * xi; s = b1 + s * eta;
	b0 =  3.9192631785224383e-05 +  8.0 * b0 * xi; s = b0 + s * eta;
	b1 = -0.00017875514403292177 +  7.0 * b1 * xi; s = b1 + s * eta;
	b0 =  0.00035273368606701921 +  6.0 * b0 * xi; s = b0 + s * eta;
	b1 =   0.0011574074074074078 +  5.0 * b1 * xi; s = b1 + s * eta;
	b0 =   -0.014814814814814815 +  4.0 * b0 * xi; s = b0 + s * eta;
	b1 =    0.083333333333333329 +  3.0 * b1 * xi; s = b1 + s * eta;
	b0 =    -0.33333333333333331 +  2.0 * b0 * xi; s = b0 + s * eta;
	s  = s / (1.0 + b1 * xi);

	s = s * exp_core(-0.5 * x * eta * eta) / sqrt_core(2.0 * 3.141592653589793 * x);
	if (x < lambda)
	{
		s += 0.5 * erfc_core(eta * sqrt_core(0.5 * x));
		if (s > q) x -= 1.0;
	}
	else
	{
		s -= 0.5 * erfc_core(-eta * sqrt_core(0.5 * x));
		if (s > -v) x -= 1.0;
	}
	return x;
}

static inline double
poissinv_sum(x, q, v, lambda, lambda_i)
register double x, q, v, lambda, lambda_i;
{
	volatile int i;
	register double s, t, xi = 1.0 / x;
	
	s = - (691.0/360360.0);
	s =   (1.0/1188.0) + s * xi * xi;
	s = - (1.0/1680.0) + s * xi * xi;
	s =   (1.0/1260.0) + s * xi * xi;
	s = - (1.0/360.0)  + s * xi * xi;
	s =   (1.0/12.0)   + s * xi * xi;
	s =                  s * xi;
	s = (x - lambda) - x * log_core(x * lambda_i) - s;

	if (x < lambda)
	{
		t  = exp_core(-0.5 * s);
		s  = 1.0 - t * (q * t) * sqrt_core(2.0 * 3.141592653589793 * xi) * lambda;
		t  = 1.0;
		xi = x;
		for (i = 1; i < 50; i++)
		{
			xi -= 1.0;
			t  *= xi * lambda_i;
			s  += t;
		}
		if (s > 0.0) x -= 1.0;
	}
	else
	{
		t  = exp_core(-0.5 * s);
		s  = 1.0 - t * (v * t) * sqrt_core(2.0 * 3.141592653589793 * x);
		xi = x;
		for (i = 0; i < 50; i++) {
			xi += 1.0;
			s   = s * xi * lambda_i + 1.0;
		}
		if (s < 0.0) x -= 1.0;
	}
	return x;
}

static inline double
poissinv_bottomup(q, v, lambda, lambda_i)
register double q, v, lambda, lambda_i;
{
	register double x, t, delta, s;
	
	x     = 0.0;
	t     = exp_core(0.5 * lambda);
	delta = 0.0;
	if (q > 0.5) delta = t * (1e-13 * t);
	s   = 1.0 - t * (q * t) + delta;

	while (s < 0.0)
	{
		x    += 1.0;
		t     = x * lambda_i;
		delta = t * delta;
		s     = t * s + 1.0;
	}

	// top-down summation if needed
	if (s < 2.0 * delta)  x = poissinv_topdown(x, v, delta, lambda_i);
	
	return x;
}


static inline double
poissinv_topdown(x, v, delta, lambda_i)
register double x, v, delta, lambda_i;
{
	register double s, t;
	
	delta = 1e13 * delta;
	t     = 1e17 * delta;
	delta = v * delta;
	while (delta < t) {
		x     += 1.0;
		delta *= x * lambda_i;
	}
	s = delta;
	t = 1.0;
	while (s > 0.0) {
		t *= x * lambda_i;
		s -= t;
		x -= 1.0;
	}
	return x;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_POISSCDFINV_CORE_INTERNAL */
