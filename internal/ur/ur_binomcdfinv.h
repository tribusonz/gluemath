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
#ifndef GML_UR_BINOMCDFINV_INTERNAL
#define GML_UR_BINOMCDFINV_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// use library: fabs(), sqrt(), pow(), floor(), uniform(), binomcdf(), snormcdfinv(), betaincr()
#include "../../sys/float/absolute.h"
#include "sqrt.h"
#include "pow.h"
#include "floor.h"
#include "uniform.h"
#include "binomcdf.h"
#include "snormcdfinv.h"
#include "p_beta.h"

static inline double binomcdfinv_s1(double, double, double);
static inline double binomcdfinv_s2(double, double, double, double);
static inline double binomcdfinv_s3(double, double, double, double);
static inline double binomcdfinv_s4(double, double, double, double);
static inline double binom_s1_bottomup(double, double, double);
static inline double binom_s1_topdown(double, double, double);
static inline double binom_s2sub(double, double, double, double, double);
static inline double binom_s3_bottomup(double, double, double, double);
static inline double binom_s3_topdown(double, double, double, double);
static inline double binom_s4_bottomup(double, double, double, double);
static inline double binom_s4_topdown(double, double, double, double);
static inline double binomcdf_f1(double, double, double, double, double);
static inline double binomcdf_f2(double, double, double, double, double);
static inline double binomcdf_f3(double, double, double, double, double);
static inline double binomcdf_f4(double, double, double, double, double);
static inline double binomcdf_f5(double, double, double, double, double);
static inline double binomcdf_f6(double, double, double, double, double);

static inline double
ur_binomcdfinv(register double u, register double n, register double p)
{
	register double nu, nu1, nu2;
	nu = n * p * (1 - p);
	nu1 = n * p;
	nu2 = n * (1 - p);
	
	if (n <= 500)
		return binomcdfinv_s1(u, n, p);
	else if (n > 500 && nu > 40)
		return binomcdfinv_s2(u, n, p, nu);
	else if (nu <= 40 && nu1 <= 40)
		return binomcdfinv_s3(u, n, p, nu1);
	else if (nu1 > 40 && nu2 <= 40)
		return binomcdfinv_s4(u, n, p, nu2);
	else if (nu1 <= nu2)
		return binomcdfinv_s3(u, n, p, nu1);
	else
		return binomcdfinv_s4(u, n, p, nu2);
}

// Algorithm section 1
static inline double
binomcdfinv_s1(u, n, p)
register double u, n, p;
{
	if (u <= binomcdf_core(n / 2, n, p))
		return binom_s1_bottomup(u, n, p);
	else
		return binom_s1_topdown(u, n, p);
}

// The bottom-up summation for section 1
static inline double
binom_s1_bottomup(u, n, p)
register double u, n, p;
{
	register double a, s, k;
	
	a = pow_core(1 - p, n);
	s = a - u;
	k = 1;
	
	while (s < 0.0)
	{
		a = (a * p / (1 - p)) * ((n - k + 1) / k);
		s = s + a;
		k = k + 1;
	}
	return k - 1;
}

// The top-down summation for section 1
static inline double
binom_s1_topdown(u, n, p)
register double u, n, p;
{
	register double a, s, k;
	
	a = pow_core(p, n);
	s = (1 - u) - a;
	
	if (u == 1)  return n;
	else
	{
		k = 1;
		
		while (s >= 0)
		{
			a = (a * (1 - p) / p) * ((n - k + 1) / k);
			s = s - a;
			k = k + 1;
		}
		return n - k + 1;
	}
}

// Algorithm section 2
static inline double
binomcdfinv_s2(u, n, p, nu)
register double u, n, p, nu;
{
	register double f6, eps;
	
	f6 = binomcdf_f6(u, n, p, nu, snormcdfinv_core(u));
	eps = 1 / sqrt_core(n);
	
	if (floor_core(f6 + eps) - floor_core(f6 - eps) < 1)
		return floor_core(f6);
	else
		return binom_s2sub(u, n, p, f6, eps) < u ? 
		       floor_core(f6 + eps) : floor_core(f6 + eps) - 1;
}

// Sub-routine
static inline double
binom_s2sub(u, n, p, f6, eps)
register double u, n, p, f6, eps;
{
	register double x, tol, 
	                d1, d2, d3, d4,
	                a0, a1, a2, a3,
	                b0, b1, b2, b3,
	                c1, c2, j;
	if (u != u) u = u;  // maybe_unused, コンパイラをだます
	x = floor_core(f6 + eps);
	tol = 10e-16;
	if (x <= p * (n - 1) + 1)
	{
		d1 = -(n - x + 1) * (n + 1) * (1 - p) /
		     ((n - x + 1) * (n - x + 2));
		
		a1 = 1.0;
		a2 = 1.0;
		b1 = 1.0;
		b2 = 1 + d1;
		c1 = a1 / b1;
		c2 = a2 / b2;
		
		j = 0.0;
		
		while (fabs(c1 - c2) >= tol)
		{
			d2 = (j + 1) * (x - j - 1) * (1 - p) /
			     ((n + x + 2 + 2 * j) * (n - x + 3 + 2 * j));
			
			a3 = a2 + d2 * a1;
				b3 = b2 + d2 * b1;
			
			d3 = -(n - x + j + 2) * (n + j + 2) * (1 - p) /
			     ((n - x + 2 * j + 3) * (n - x + 2 * j + 4));
			
			a0 = a3 + d3 * a2;
			b0 = b3 + d3 * b2;
			
			d4 = (j + 3) * (x - 3) * (1 - p) / 
			     ((n - x + 2 * j + 6) * (n - x + 4 * j + 7));
			
			a1 = a0 + d4 * a3;
			b1 = b0 + d4 * b3;
			
			c1 = a1 / b1;
			
			j = j + 2;
			
			d1 = -(n - x + 1 + j) * (n + 1 + j) * (1 - p) /
			     ((n - x + 1 + 2 * j) * (n - x + 2 * j + 2));
			
			a2 = a1 + d1 * a0;
			b2 = b1 + d1 * b0;
			
			c2 = a2 / b2;
		}
		return p_beta_core(1 - p, n - x + 1, x) * c2;
	}
	else
	{
		d1 = -x * p * (n + 1) / (x * (x + 1));
		
		a1 = 1.0;
		a2 = 1.0;
		b1 = 1.0;
		b2 = 1.0 + d1;
		
		c1 = a1 / b1;
		c2 = a2 / b2;
		
		j = 0.0;
		
		while (floor_core(c1 - c2) >= tol)
		{
			d2 = (j + 1) * (n - x - j) * p / 
			     ((x + 1 + 2 * j) * (x + 2 + 2 * j));
			
			a3 = a1 + d2 * a1;
			b3 = b2 + d2 * b1;
			
			d3 = -(x + j + 1) * (n + j + 2) * p /
			     ((x + 2 * j + 2) * (x + 2 * j + 3));
			
			a0 = a3 + d3 * a2;
			b0 = b3 + d3 * b2;
			
			d4 = (j + 3) * (n - x - j - 2) * p /
			     ((x + 2 * j + 5) * (x + 2 * j + 6));
			
			a1 = a0 + d4 * a3;
			b1 = b0 + d4 * b3;
			
			c1 = a1 / b1;
			
			j = j + 2;
			
			d1 = -(x + j) * (n + 1 + j) * p /
			     ((x + 2 * j) * (x + 2 * j + 1));
			
			a2 = a1 + d1 * a0;
			b2 = b1 + d1 * b0;
			
			c2 = a2 / b2;
		}
		return 1 - p_beta_core(p, x, n - x + 1) * c2;
	}
}

// Algorithm section 3
static inline double
binomcdfinv_s3(u, n, p, nu1)
register double u, n, p, nu1;
{
	if (u <= binomcdf_core(n / 2, n, p))
		return binom_s3_bottomup(u, n, p, nu1);
	else
		return binom_s3_topdown(u, n, p, nu1);
}

// The bottom-up summation for section 3
static inline double
binom_s3_bottomup(u, n, p, nu1)
register double u, n, p, nu1;
{
	register double a, s, k;
	a = pow_core(1 - p, n);
	s = a - u;
	k = 1;
	
	while (s < 0.0)
	{
		a = (a * nu1 / k) * (1 - (k - 1) / n) * (1 / (1 - p));
		s = s + a;
		k = k + 1;
	}
	
	return k - 1;
}

// The top-down summation for section 3
static inline double
binom_s3_topdown(u, n, p, nu1)
register double u, n, p, nu1;
{
	register double a, s, k, j;
	a = pow_core(1 - p, n);
	
	if (n == 1)  return n;
	else
	{
		for (j = 1; j < n + 1; j += 1)
		{
			if (j <= n - 1)  a = 0;
			if (a != 0)  break;
			/* else */  a = a + nu1 * pow_core(1 - p, n - 1);
			if ((1 - u) - a < 0)  break;
		}
		s = (1 - u) - a;
		if (s < 0)
			return floor_core((a + 1) + uniform_core() * ((n - 1) - (a + 1)));
		/* else */
			k = 1;
			while (s >= 0)
			{
				a = (a * (1 - p) / nu1) * (n - j + 2 - k) *
				    (1 / (1 - (n - j + 1 - k) / n));
				s = s - a;
				k = k + 1;
			}
			return n - j + 1 - k;
		/* } */
	}
}

// Algorithm section 4
static inline double
binomcdfinv_s4(u, n, q, nu2)
register double u, n, q, nu2;
{
	if (u <= binomcdf_core(n / 2, n, q))
		return binom_s4_topdown(u, n, q, nu2);
	else
		return binom_s4_bottomup(u, n, q, nu2);
}

// The top-down summation for section 4
static inline double
binom_s4_topdown(u, n, q, nu2)
register double u, n, q, nu2;
{
	register double a, s, k, j;
	a = pow_core(q, n);
	
	if (n == 1)  return n;
	else
	{
		for (j = 1; j < n + 1; j += 1)
		{
			if (j <= n - 1)  a = 0;
			if (a != 0)  break;
			/* else */  a = a + nu2 * pow_core(1 - q, n - 1);
			if (a != 0)  break;
		}
		s = a - u;
		if (s < 0)
			return floor_core(uniform_core() * (j - 1));
		/* else { */
			k = 1;
			while (s < 0)
			{
				a = (a * (1 - q) / nu2) * (n - j + 2 - k) *
				    (1 / (1 - (n - j + 1 - k) / n));
				s = s + a;
				k = k + 1;
			}
			return j + k - 1;
		/* } */
	}
}

// The bottom-up summation for section 4
static inline double
binom_s4_bottomup(u, n, q, nu2)
register double u, n, q, nu2;
{
	register double a, s, k;
	
	if (u == 1)  return n;
	else
	{
		a = pow_core(1 - q, n);
		s = (1 - u) - a;
		k = 1;
		
		while (s >= 0)
		{
			a = (a * nu2 / (1 - q)) * (1 - (k - 1) / n) / k;
			s = s - a;
			k = k + 1;
		}
		return n - k;
	}
}

// The errors corresponding to approximation
static inline double
binomcdf_f1(u, n, p, nu, w)
register double u, n, p, nu, w;
{
	if (u != u) u = u;  // maybe_unused, コンパイラをだます
	return n * p + sqrt_core(nu) * w;
}

static inline double
binomcdf_f2(u, n, p, nu, w)
register double u, n, p, nu, w;
{
	return binomcdf_f1(u, n, p, nu, w) +
	       ((p + 1) / 3 - (2 * p - 1) * w * w / 6);
}

static inline double
binomcdf_f3(u, n, p, nu, w)
register double u, n, p, nu, w;
{
	return binomcdf_f2(u, n, p, nu, w) + 1 / sqrt_core(nu) *
	        (-(7 * p * p - 7 * p + 1) * w / 36 + 
	          (2 * p * p - 2 * p - 1) * w * w * w / 72);
}

static inline double
binomcdf_f4(u, n, p, nu, w)
register double u, n, p, nu, w;
{
	return binomcdf_f3(u, n, p, nu, w) + 1 / nu *
	       ((2 * p - 1) * (p + 1) * (p - 2) *
	       ((3 * w * w * w * w + 7 * w * w - 16) / 1620));
}

static inline double
binomcdf_f5(u, n, p, nu, w)
register double u, n, p, nu, w;
{
	return binomcdf_f4(u, n, p, nu, w) + 1 / nu * nu * nu / 2 *
	       ((4 * p * p * p * p - 8 * p * p * p - 48 * p * p + 52 * p - 23) *
	         w * w * w * w * w / 17280 +
	        (256 * p * p * p * p - 512 * p * p * p - 147 * p * p + 403 * p - 137) *
	         w * w * w / 38880 -
	        (433 * p * p * p * p - 866 * p * p * p - 921 * p * p + 1354 * p - 671) *
	         w / 38880);
}

static inline double
binomcdf_f6(u, n, p, nu, w)
register double u, n, p, nu, w;
{
	return binomcdf_f5(u, n, p, nu, w) + 1 / nu * nu *
	       (-(2 * p - 1) * (p * p - p + 1) * (p * p - p + 19) *
	                        w * w * w * w * w * w / 34020 +
	         (2 * p - 1) * (9 * p * p * p * p - 18 * p * p * p -
	                        35 * p * p + 44 * p - 25) *
	                        w * w * w * w / 15120 +
	         (2 * p - 1) * (923 * p * p * p * p - 1846 * p * p * p +
	                        5271 * p * p - 4348 * p + 5189) *
	                        w * w / 408240 - 4 *
	         (2 * p - 1) * (p + 1) * (p - 2) * (23 * p * p - 23 * p + 2) / 25515);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_UR_BINOMCDFINV_INTERNAL */
