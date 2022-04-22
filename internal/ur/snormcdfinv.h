/*******************************************************************************
	GLUE-Math Library -- Standard Normal Distribution Inverse CDF

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Following paper:
		Algorithm 955: approximation of the inverse Poisson cumulative
		               distribution function
			by Michael B. Giles, University of Oxford, UK
*******************************************************************************/
#ifndef GML_SNORMCDFINV_INTERNAL
#define GML_SNORMCDFINV_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: fabs(), sqrt(), log(), HUGE_VAL, NAN
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/absolute.h"
#include "sqrt.h"
#include "log.h"

static inline double normcdfinv_as241(double);

static inline double
snormcdfinv_core(register double q)
{
	if (q >= 0 && q <= 1)
		return q == 0 ? -HUGE_VAL : q == 1 ? HUGE_VAL : normcdfinv_as241(q);
	return NAN;
}

/*
 *  For detail, get and see Prof. Mile Giles' paper.
 * 
 * @p      : quantile,  0 <= q <= 1
 */
static inline double
normcdfinv_as241(register double p)
{
	register double q, r, num, den, res;
	
	q = p - 0.5;
	if (fabs(q) <= 0.425) {
		r = 0.180625 - q * q;

		num =           2.5090809287301226727e+3;
		num = r * num + 3.3430575583588128105e+4;
		num = r * num + 6.7265770927008700853e+4;
		num = r * num + 4.5921953931549871457e+4;
		num = r * num + 1.3731693765509461125e+4;
		num = r * num + 1.9715909503065514427e+3;
		num = r * num + 1.3314166789178437745e+2;
		num = r * num + 3.3871328727963666080e0;

		den =           5.2264952788528545610e+3;
		den = r * den + 2.8729085735721942674e+4;
		den = r * den + 3.9307895800092710610e+4;
		den = r * den + 2.1213794301586595867e+4;
		den = r * den + 5.3941960214247511077e+3;
		den = r * den + 6.8718700749205790830e+2;
		den = r * den + 4.2313330701600911252e+1;
		den = r * den + 1.0000000000e+00;

		res = q * num / den; 

		return res;
	}

	else {

		if (q < 0.0)
			r = p;
		else
			r = 1.0 - p;

		r = sqrt_core(-log_core(r));

		if (r <= 5.0) {
			r = r - 1.6;

			num =           7.74545014278341407640e-4;
			num = r * num + 2.27238449892691845833e-2;
			num = r * num + 2.41780725177450611770e-1;
			num = r * num + 1.27045825245236838258e0;
			num = r * num + 3.64784832476320460504e0;
			num = r * num + 5.76949722146069140550e0;
			num = r * num + 4.63033784615654529590e0;
			num = r * num + 1.42343711074968357734e0;

			den =           1.05075007164441684324e-9;
			den = r * den + 5.47593808499534494600e-4;
			den = r * den + 1.51986665636164571966e-2;
			den = r * den + 1.48103976427480074590e-1;
			den = r * den + 6.89767334985100004550e-1;
			den = r * den + 1.67638483018380384940e0;
			den = r * den + 2.05319162663775882187e0;
			den = r * den + 1.0000000000e+00;

			res = num / den;
		}

		else {
			r = r - 5.0;

			num =           2.01033439929228813265e-7;
			num = r * num + 2.71155556874348757815e-5;
			num = r * num + 1.24266094738807843860e-3;
			num = r * num + 2.65321895265761230930e-2;
			num = r * num + 2.96560571828504891230e-1;
			num = r * num + 1.78482653991729133580e0;
			num = r * num + 5.46378491116411436990e0;
			num = r * num + 6.65790464350110377720e0;

			den =           2.04426310338993978564e-15;
			den = r * den + 1.42151175831644588870e-7;
			den = r * den + 1.84631831751005468180e-5;
			den = r * den + 7.86869131145613259100e-4;
			den = r * den + 1.48753612908506148525e-2;
			den = r * den + 1.36929880922735805310e-1;
			den = r * den + 5.99832206555887937690e-1;
			den = r * den + 1.0000000000e+00;

			res = num / den;
		}

		if (q < 0.0)
			res = - res;

		return res;
	}
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_SNORMCDFINV_INTERNAL */
