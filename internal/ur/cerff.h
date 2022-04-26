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
#ifndef GML_ERF_FLTCMPLX_INTERNAL
#define GML_ERF_FLTCMPLX_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/complex/class.h"
#include "../../sys/complex/arithmetic.h"
#include "../../sys/complex/unary.h"
#include "../../sys/complex/cast.h"
#include "../../sys/float/absolute.h"
#include "cerfcf.h"

static inline fcomplex
cerff_core(fcomplex x)
{
	static const float
	p0 =  1.12837917e+00,
	p1 = -3.76126389e-01,
	p2 =  1.12837917e-01,
	p3 = -2.68661706e-02;
	
	if (fabsf(x.real) + fabsf(x.imag) > 0.125)
		if (x.real >= 0)
			return fc_sub(ftofc(1), cerfcf_core(x));
		else
			return fc_sub(cerfcf_core(fc_uminus(x)), ftofc(1));
	else
	{
		fcomplex y = fc_mul(x, x);
		return
		fc_mul(fc_add(
		  fc_mul(fc_add(
		    fc_mul(fc_add(
		      fc_mul(ftofc(p3), y),
		    ftofc(p2)), y),
		  ftofc(p1)), y),
		ftofc(p0)), x);
	}
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ERF_FLTCMPLX_INTERNAL */
