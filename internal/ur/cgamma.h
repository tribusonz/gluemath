/*******************************************************************************
	GLUE-Math Library: Complex Gamma Function

	Author:
	  Takuya Ooura (Original Source)
	  Hironobu Inatsuka aka tribusonz (Part of modify)
	License:
	  Takuya Ooura's (Original C Source)
	  GPL + X11(MIT) (ABI part)
	Reference:
	  Ooura's Mathematical Software Packages
*******************************************************************************/
#ifndef GML_GAMMA_DBLCMPLX_INTERNAL
#define GML_GAMMA_DBLCMPLX_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "../../sys/complex/class.h"
#include "exp.h"
#include "log.h"
#include "quadrant.h"  // atan2
#include "sin.h"
#include "cos.h"
#include "gamma.h"

static inline dcomplex ur_cgamma(dcomplex x);

static inline dcomplex
cgamma_core(dcomplex z)
{
	dcomplex y;
	switch (fpclassify(z.imag)) {
	case FP_NAN:
		y.real = NAN; y.imag = NAN;
		break;
	case FP_INFINITE:
		if (z.imag < 0)  y.real = NAN;
		else             y.real = HUGE_VAL;
		y.imag = NAN;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		y.real = gamma_core(z.real);
		y.imag = 0;
		break;
	default:
		y = ur_cgamma(z);
		break;
	}
	return y;
}

/* complex Gamma function in double precision */
static inline dcomplex
ur_cgamma(dcomplex x)
{
	dcomplex w, u, v, y;
	double t;

	if (x.real < 0)
	{
		w.real = 1 - x.real;
		w.imag = -x.imag;
	}
	else
	{
		w.real = x.real;
		w.imag = x.imag;
	}
	u.real = w.real + 6.00009857740312429;
	v.real = u.real * (w.real + 4.99999857982434025) - w.imag * w.imag;
	v.imag = w.imag * (w.real + 4.99999857982434025) + u.real * w.imag;
	y.real = u.real * 13.2280130755055088 +
	         v.real * 66.2756400966213521 + 0.293729529320536228;
	y.imag = w.imag * 13.2280130755055088 + v.imag * 66.2756400966213521;
	u.real = v.real * (w.real + 4.00000003016801681) - v.imag * w.imag;
	u.imag = v.imag * (w.real + 4.00000003016801681) + v.real * w.imag;
	v.real = u.real * (w.real + 2.99999999944915534) - u.imag * w.imag;
	v.imag = u.imag * (w.real + 2.99999999944915534) + u.real * w.imag;
	y.real += u.real * 91.1395751189899762 + v.real * 47.3821439163096063;
	y.imag += u.imag * 91.1395751189899762 + v.imag * 47.3821439163096063;
	u.real = v.real * (w.real + 2.00000000000603851) - v.imag * w.imag;
	u.imag = v.imag * (w.real + 2.00000000000603851) + v.real * w.imag;
	v.real = u.real * (w.real + 0.999999999999975753) - u.imag * w.imag;
	v.imag = u.imag * (w.real + 0.999999999999975753) + u.real * w.imag;
	y.real += u.real * 10.5400280458730808 + v.real;
	y.imag += u.imag * 10.5400280458730808 + v.imag;
	u.real = v.real * w.real - v.imag * w.imag;
	u.imag = v.imag * w.real + v.real * w.imag;
	t = u.real * u.real + u.imag * u.imag;
	v.real = y.real * u.real + y.imag * u.imag + t * 0.0327673720261526849;
	v.imag = y.imag * u.real - y.real * u.imag;
	y.real = w.real + 7.31790632447016203;
	u.real = log_core(y.real * y.real + w.imag * w.imag) * 0.5 - 1;
	u.imag = quadrant_core(w.imag, y.real);  // Im(u) = Arg(Im(w), Re(y))
	y.real = exp_core(u.real * (w.real - 0.5) - u.imag * w.imag - 3.48064577727581257) / t;
	y.imag = u.imag * (w.real - 0.5) + u.real * w.imag;
	u.real = y.real * cos_core(y.imag);
	u.imag = y.real * sin_core(y.imag);
	y.real = u.real * v.real - u.imag * v.imag;
	y.imag = u.imag * v.real + u.real * v.imag;
	if (x.real < 0)
	{
		w.real = x.real * 3.14159265358979324;
		w.imag = exp_core(x.imag * 3.14159265358979324);
		v.imag = 1 / w.imag;
		u.real = (v.imag + w.imag) * sin_core(w.real);
		u.imag = (v.imag - w.imag) * cos_core(w.real);
		v.real = u.real * y.real + u.imag * y.imag;
		v.imag = u.imag * y.real - u.real * y.imag;
		u.real = 6.2831853071795862 / (v.real * v.real + v.imag * v.imag);
		y.real = u.real * v.real;
		y.imag = u.real * v.imag;
	}
    return y;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_GAMMA_DBLCMPLX_INTERNAL */
