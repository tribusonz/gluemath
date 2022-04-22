/*******************************************************************************
	GLUE-Math Library: Exponential Integral

	Author:
	  William H. Press, Saul A. Teukolsky, William T. Vetterling, Brian P. Flannery
	  Hironobu Inatsuka aka tribusonz
	License:
	  GPL + X11(MIT)
	Reference:
	  Numerical Recipes in C; 3rd edition
*******************************************************************************/
#ifndef GML_EXPINT_POS_INTERNAL
#define GML_EXPINT_POS_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/absolute.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "exp.h"
#include "log.h"

// En(x), 0 < x < Infinity.
static inline double
expint_pos(register int n, register double x)
{
	static const int MAXIT = 100;
	static const double EULER = 0.577215664901533;
	volatile int i, ii;
	register int nm1 = n - 1;
	register double a, b, c, d, del, fact, h, psi, ans;

	get_dbl_info();

	if (x != x || n < 0 || x < 0.0 || (x == 0.0 && (n == 0 || n == 1)))
		return NAN;
	if (n == 0)  ans = exp_core(-x) / x;
	else
	{
		if (x == 0.0)  ans = 1.0 / nm1;
		else {
			if (x > 1.0)
			{
				b = x + n;
				c = dbl_info.max * dbl_info.epsilon;

				d = 1.0 / b;
				h = d;
				for (i = 1; i <= MAXIT; i++)
				{
					a = -i * (nm1 + i);
					b += 2.0;
					d = 1.0 / (a * d + b);
					c = b + a / c;
					del = c * d;
					h *= del;
					if (fabs(del - 1.0) <= dbl_info.epsilon)
					{
						ans = h * exp_core(-x);
						return ans;
					}
				}
				return NAN;  // Continued Fraction Failed
			}
			else
			{
				ans = (nm1 != 0 ? 1.0 / nm1 : -log_core(x) - EULER);
				fact = 1.0;
				for (i = 1; i <= MAXIT; i++)
				{
					fact *= -x / i;
					if (i != nm1)  del = -fact / (i - nm1);
					else
					{
						psi = -EULER;
						for (ii = 1; ii <= nm1; ii++)  psi += 1.0 / ii;
						del = fact * (-log_core(x) + psi);
					}
					ans += del;
					if (fabs(del) < fabs(ans) * dbl_info.epsilon)  return ans;
				}
				return NAN;  // Series expansion failed
			}
		}
	}
	return ans;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_EXPINT_INTERNAL */
