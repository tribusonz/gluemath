/*******************************************************************************
	GLUE-Math Library: Incomplete Beta Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_CBETAINCR_RV_CORE_DBL_INTERNAL
#define GML_CBETAINCR_RV_CORE_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/absolute.h"
#include "log.h"
#include "lbeta.h"
#include "../../sys/complex/class.h"
#include "../../sys/complex/build.h"
#include "../../sys/complex/arithmetic.h"
#include "../../sys/complex/cast.h"
#include "cexp.h"

static inline double betainc_cf(double, double, double);
static inline dcomplex betainc_cf_func(double, double, double);
static inline double betainc_cf_term(double, double, double, int);

// Continued fraction for real variable
static inline dcomplex
ur_cbetaincr_rv(double x, double a, double b)
{
	dcomplex bt;

	if (x == 0.0 || x == 1.0)
		bt = cbuild(0, 0);
	else
		bt = betainc_cf_func(x, a, b);
	if (x <= (a + 1) / (a + b + 2))
		return dc_div(dc_mul(bt, cbuild(betainc_cf(x, a, b), 0)), dtodc(a));
	else
		return dc_sub(dtodc(1),
		       dc_div(dc_mul(bt, cbuild(betainc_cf(1-x, b, a),0)), dtodc(b))
		       );
}

static inline dcomplex
betainc_cf_func(double x, double a, double b)
{
	static const double PI = 3.14159265358979323846;
	double ax, bx, lbeta, logreal, logimag;
	int ax_sign = 1, bx_sign = 1, lbeta_sign = 1;

	lbeta = ur_logbeta_r(a, b, &lbeta_sign);
	if ((ax = x) < 0)     { ax = -ax; ax_sign = -1; }
	if ((bx = 1 - x) < 0) { bx = -bx; bx_sign = -1; }
	
	logreal = a * log_core(ax) + b * log_core(bx) - lbeta;
	logimag = 0;
	
	if (ax_sign == 1 && bx_sign == 1 && lbeta_sign == 1)
		return cexp_core(cbuild(logreal, 0));
	else
	{
		logimag += ax_sign == -1 ? a : 0;
		logimag += bx_sign == -1 ? b : 0;
		logimag += lbeta_sign == -1 ? 1 : 0;
		logimag *= PI;
		return cexp_core(cbuild(logreal, logimag));
	}
}

static inline double
betainc_cf(double x, double a, double b)
{
	static const int MAXIT = 10000000;
	static const double FPMIN = 1.0e-30;
	double c = 1.0, d = 0.0, s = 1.0;

	get_dbl_info();

	for (volatile int i = 0; i <= MAXIT; i++)
	{
		const double t = betainc_cf_term(x, a, b, i);

		d = 1.0 + t * d;
		if (fabs(d) < FPMIN)  d = FPMIN;
		d = 1.0 / d;

		c = 1.0 + t / c;
		if (fabs(c) < FPMIN)  c = FPMIN;

		s *= c * d;

		if (fabs(1 - c * d) < dbl_info.epsilon)
			return s - 1.0;
	}

	return NAN;
}

static double
betainc_cf_term(double x, double a, double b, int i)
{
	int m = i / 2;
	if (i == 0) // $d_0$
		return 1.0;
	else if (i == 1) // $d_1$
		return -(a + b) / (a + 1) * x;
	else if (i % 2 == 0) // $d_{2m+0}$
		return +(m * (b - m)) /
		        ((a + 2 * m) * (a + 2 * m - 1)) * x;
	else // $d_{2m+1}$
		return -((a + m) * (a + b + m)) /
		        ((a + 2 * m) * (a + 2 * m + 1)) * x;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_CBETAINCR_RV_CORE_DBL_INTERNAL */
