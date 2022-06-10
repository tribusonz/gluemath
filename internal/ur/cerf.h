/*******************************************************************************
	GLUE-Math Library: Gaussian Error Function
	
	Author:
	  Takuya Ooura (Original Algorithm)
	  Hironobu Inatsuka aka tribusonz (C ABI modify)
	License:
	  GPL + X11(MIT)
	Reference:
	  Ooura's Mathematical Software Packages
*******************************************************************************/
#ifndef GML_ERF_DBLCMPLX_INTERNAL
#define GML_ERF_DBLCMPLX_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/complex/class.h"
#include "../../sys/complex/arithmetic.h"
#include "../../sys/complex/unary.h"
#include "../../sys/complex/cast.h"
#include "../../sys/float/absolute.h"
#include "cerfc.h"

#if 0
// C99 complex ver.
double _Complex
cerf(double _Complex x)
{
	static const double
	p0 =  1.12837916709551257e+00,
	p1 = -3.76126389031837525e-01,
	p2 =  1.12837916709551257e-01,
	p3 = -2.68661706451312518e-02,
	p4 =  5.22397762544218784e-03,
	p5 = -8.54832702345085283e-04,
	p6 =  1.20553329817896643e-04;

	if (fabs(creal(x)) + fabs(cimag(x)) > 0.125)
		if (creal(x) > 0)
			return 1 - cerfc(x);
		else
			return cerfc(-x) - 1;
	else
	{
		double _Complex y = x * x;
		return ((((((p6 * y + p5)
		                * y + p4)
		                * y + p3)
		                * y + p2)
		                * y + p1)
		                * y + p0) * x;
	}
}
#endif

static inline dcomplex
cerf_core(dcomplex x)
{
	static const double
	p0 =  1.12837916709551257e+00,
	p1 = -3.76126389031837525e-01,
	p2 =  1.12837916709551257e-01,
	p3 = -2.68661706451312518e-02,
	p4 =  5.22397762544218784e-03,
	p5 = -8.54832702345085283e-04,
	p6 =  1.20553329817896643e-04;

	if (fabs(x.real) + fabs(x.imag) > 0.125)
		if (x.real > 0)
			return dc_sub(dtodc(1), cerfc_core(x));
		else
			return dc_sub(cerfc_core(dc_uminus(x)), dtodc(1));
	else
	{
		dcomplex y = dc_mul(x, x);
		return
		dc_mul(dc_add(
		  dc_mul(dc_add(
		    dc_mul(dc_add(
		      dc_mul(dc_add(
		        dc_mul(dc_add(
		          dc_mul(dc_add(
		            dc_mul(dtodc(p6), y),
		            dtodc(p5)), y),
		          dtodc(p4)), y),
		        dtodc(p3)), y),
		     dtodc(p2)), y),
		   dtodc(p1)), y),
		dtodc(p0)), x);
	}
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ERF_DBLCMPLX_INTERNAL */
