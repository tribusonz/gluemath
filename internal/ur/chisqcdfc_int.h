/*******************************************************************************
	GLUE-Math Library -- Chi-Square Distribution CDF

	Author:
	  Haruhiko Okumura (Original algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_CHISQCDF_INT_INTERNAL
#define GML_CHISQCDF_INT_INTERNAL


#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: sqrt(), exp(), snormcdf()
#include "../../sys/float/huge_val_nan.h"
#include "exp.h"
#include "sqrt.h"
#include "snormcdf.h"

/* Ur. Integer DF. */
static inline double
chisqcdfc_int_core(register double chi2, register int df)
{
	register double s, t, chi;
	static const double sqrt2pi = 2.50662827463100050241576; /*$\sqrt{2\pi}$*/
	if (isinf(chi2))  return 0.0;
	if (df & 1) {  /* Degree of Freedom is odd */
		chi = sqrt_core(chi2);
		if (df == 1) return 2 * (1 - snormcdf_core(chi));
		s = t = chi * exp_core(-0.5 * chi2) / sqrt2pi;
		for (volatile int k = 3; k < df; k += 2) {
			t *= chi2 / k;  s += t;
		}
		return 2 * ((1 - snormcdf_core(chi)) + s);
	} else {      /* Degree of Freedom is even */
		s = t = exp_core(-0.5 * chi2);
		for (volatile int k = 2; k < df; k += 2) {
			t *= chi2 / k;  s += t;
		}
		return s;
	}
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_CHISQCDF_INT_INTERNAL */
