/*******************************************************************************
	GLUE-Math Library: DE-rule

	Author:
	  Takuya Ooura (Algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License:
	  GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_QUADRATURE_DERULE_INTERNAL
#define GML_QUADRATURE_DERULE_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: atan, log, exp, sqrt, fabs
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/absolute.h"
#include "exp.h"
#include "log.h"
#include "sqrt.h"
#include "atan.h"
#include "../../sys/quadrature/class.h"
#include "../../tuning/lenaw.h"
#ifndef _LENAW
# define _LENAW 1000
#endif

// Initializer
static inline void
__int_de_init(int lenaw, double tiny, double eps, double *aw)
{
	/* ---- adjustable parameter ---- */
	double efs = 0.1, hoff = 8.5;
	/* ------------------------------ */
	int noff, nk, k, j;
	double pi2, tinyln, epsln, h0, ehp, ehm, h, t, ep, em, xw, wg;
	
	pi2 = 2 * atan_core(1.0);
	tinyln = -log_core(tiny);
	epsln = 1 - log_core(efs * eps);
	h0 = hoff / epsln;
	ehp = exp_core(h0);
	ehm = 1 / ehp;
	aw[2] = eps;
	aw[3] = exp_core(-ehm * epsln);
	aw[4] = sqrt_core(efs * eps);
	noff = 5;
	aw[noff] = 0.5;
	aw[noff + 1] = h0;
	aw[noff + 2] = pi2 * h0 * 0.5;
	h = 2;
	nk = 0;
	k = noff + 3;
	do {
		t = h * 0.5;
		do {
			em = exp_core(h0 * t);
			ep = pi2 * em;
			em = pi2 / em;
			j = k;
			do {
				xw = 1 / (1 + exp_core(ep - em));
				wg = xw * (1 - xw) * h0;
				aw[j] = xw;
				aw[j + 1] = wg * 4;
				aw[j + 2] = wg * (ep + em);
				ep *= ehp;
				em *= ehm;
				j += 3;
			} while (ep < tinyln && j <= lenaw - 3);
			t += h;
			k += nk;
		} while (t < 1);
		h *= 0.5;
		if (nk == 0)
		{
			if (j > lenaw - 6)  j -= 3;
			nk = j - noff;
			k += nk;
			aw[1] = nk;
		}
	} while (2 * k - noff - 3 <= lenaw);
	aw[0] = k - 3;
}

// Entity
static inline void
__int_de_entity(integrand f, double a, double b, double *aw, double *i, double *err)
{
	int noff, lenawm, nk, k, j, jtmp, jm, m, klim;
	double epsh, ba, ir, xa, fa, fb, errt, errh, errd, h, iback, irback;
	
	noff = 5;
	lenawm = (int) (aw[0] + 0.5);
	nk = (int) (aw[1] + 0.5);
	epsh = aw[4];
	ba = b - a;
	*i = (*f)((a + b) * aw[noff]);
	ir = *i * aw[noff + 1];
	*i *= aw[noff + 2];
	*err = fabs(*i);
	k = nk + noff;
	j = noff;
	do {
		j += 3;
		xa = ba * aw[j];
		fa = (*f)(a + xa);
		fb = (*f)(b - xa);
		ir += (fa + fb) * aw[j + 1];
		fa *= aw[j + 2];
		fb *= aw[j + 2];
		*i += fa + fb;
		*err += fabs(fa) + fabs(fb);
	} while (aw[j] > epsh && j < k);
	errt = *err * aw[3];
	errh = *err * epsh;
	errd = 1 + 2 * errh;
	jtmp = j;
	while (fabs(fa) > errt && j < k) {
		j += 3;
		fa = (*f)(a + ba * aw[j]);
		ir += fa * aw[j + 1];
		fa *= aw[j + 2];
		*i += fa;
	}
	jm = j;
	j = jtmp;
	while (fabs(fb) > errt && j < k) {
		j += 3;
		fb = (*f)(b - ba * aw[j]);
		ir += fb * aw[j + 1];
		fb *= aw[j + 2];
		*i += fb;
	}
	if (j < jm)  jm = j;
	jm -= noff + 3;
	h = 1;
	m = 1;
	klim = k + nk;
	while (errd > errh && klim <= lenawm) {
		iback = *i;
		irback = ir;
		do {
			jtmp = k + jm;
			for (j = k + 3; j <= jtmp; j += 3)
			{
				xa = ba * aw[j];
				fa = (*f)(a + xa);
				fb = (*f)(b - xa);
				ir += (fa + fb) * aw[j + 1];
				*i += (fa + fb) * aw[j + 2];
			}
			k += nk;
			j = jtmp;
			do {
				j += 3;
				fa = (*f)(a + ba * aw[j]);
				ir += fa * aw[j + 1];
				fa *= aw[j + 2];
				*i += fa;
			} while (fabs(fa) > errt && j < k);
			j = jtmp;
			do {
				j += 3;
				fb = (*f)(b - ba * aw[j]);
				ir += fb * aw[j + 1];
				fb *= aw[j + 2];
				*i += fb;
			} while (fabs(fb) > errt && j < k);
		} while (k < klim);
		errd = h * (fabs(*i - 2 * iback) + fabs(ir - 2 * irback));
		h *= 0.5;
		m *= 2;
		klim = 2 * klim - noff;
	}
	*i *= h * ba;
	if (errd > errh)
		*err = -errd * (m * fabs(ba));
	else
		*err = *err * aw[2] * (m * fabs(ba));
}

static inline void
intde_core(integrand f, double a, double b, double *i, double *err)
{
	static double aw[_LENAW];
	static int check = 0;

	if (check == 0)
	{
		get_dbl_info();
		__int_de_init(_LENAW, dbl_info.min, dbl_info.epsilon, aw);
		check = 1;
	}
	__int_de_entity(f, a, b, aw, i, err);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_QUADRATURE_DERULE_INTERNAL */
