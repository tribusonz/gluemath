/*******************************************************************************
	GLUE-Math Library: DE-rule

	Author:
	  Takuya Ooura (Algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License:
	  GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_QUADRATURE_DERULE_TYPEI_INTERNAL
#define GML_QUADRATURE_DERULE_TYPEI_INTERNAL

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

static inline void
__int_dei_init(int lenaw, double tiny, double eps, double *aw)
{
	/* ---- adjustable parameter ---- */
	double efs = 0.1, hoff = 11.0;
	/* ------------------------------ */
	int noff, nk, k, j;
	double pi4, tinyln, epsln, h0, ehp, ehm, h, t, ep, em, xp, xm, 
		wp, wm;
	
	pi4 = atan_core(1.0);
	tinyln = -log_core(tiny);
	epsln = 1 - log_core(efs * eps);
	h0 = hoff / epsln;
	ehp = exp_core(h0);
	ehm = 1 / ehp;
	aw[2] = eps;
	aw[3] = exp_core(-ehm * epsln);
	aw[4] = sqrt_core(efs * eps);
	noff = 5;
	aw[noff] = 1;
	aw[noff + 1] = 4 * h0;
	aw[noff + 2] = 2 * pi4 * h0;
	h = 2;
	nk = 0;
	k = noff + 6;
	do {
		t = h * 0.5;
		do {
			em = exp_core(h0 * t);
			ep = pi4 * em;
			em = pi4 / em;
			j = k;
			do {
				xp = exp_core(ep - em);
				xm = 1 / xp;
				wp = xp * ((ep + em) * h0);
				wm = xm * ((ep + em) * h0);
				aw[j] = xm;
				aw[j + 1] = xp;
				aw[j + 2] = xm * (4 * h0);
				aw[j + 3] = xp * (4 * h0);
				aw[j + 4] = wm;
				aw[j + 5] = wp;
				ep *= ehp;
				em *= ehm;
				j += 6;
			} while (ep < tinyln && j <= lenaw - 6);
			t += h;
			k += nk;
		} while (t < 1);
		h *= 0.5;
		if (nk == 0)
		{
			if (j > lenaw - 12) j -= 6;
			nk = j - noff;
			k += nk;
			aw[1] = nk;
		}
	} while (2 * k - noff - 6 <= lenaw);
	aw[0] = k - 6;
}

static inline void
__int_dei_entity(integrand f, double a, double *aw, double *i, double *err)
{
	int noff, lenawm, nk, k, j, jtmp, jm, m, klim;
	double epsh, ir, fp, fm, errt, errh, errd, h, iback, irback;
	
	noff = 5;
	lenawm = (int) (aw[0] + 0.5);
	nk = (int) (aw[1] + 0.5);
	epsh = aw[4];
	*i = (*f)(a + aw[noff]);
	ir = *i * aw[noff + 1];
	*i *= aw[noff + 2];
	*err = fabs(*i);
	k = nk + noff;
	j = noff;
	do {
		j += 6;
		fm = (*f)(a + aw[j]);
		fp = (*f)(a + aw[j + 1]);
		ir += fm * aw[j + 2] + fp * aw[j + 3];
		fm *= aw[j + 4];
		fp *= aw[j + 5];
		*i += fm + fp;
		*err += fabs(fm) + fabs(fp);
	} while (aw[j] > epsh && j < k);
	errt = *err * aw[3];
	errh = *err * epsh;
	errd = 1 + 2 * errh;
	jtmp = j;
	while (fabs(fm) > errt && j < k) {
		j += 6;
		fm = (*f)(a + aw[j]);
		ir += fm * aw[j + 2];
		fm *= aw[j + 4];
		*i += fm;
	}
	jm = j;
	j = jtmp;
	while (fabs(fp) > errt && j < k) {
		j += 6;
		fp = (*f)(a + aw[j + 1]);
		ir += fp * aw[j + 3];
		fp *= aw[j + 5];
		*i += fp;
	}
	if (j < jm)  jm = j;
	jm -= noff + 6;
	h = 1;
	m = 1;
	klim = k + nk;
	while (errd > errh && klim <= lenawm) {
		iback = *i;
		irback = ir;
		do {
			jtmp = k + jm;
			for (j = k + 6; j <= jtmp; j += 6)
			{
				fm = (*f)(a + aw[j]);
				fp = (*f)(a + aw[j + 1]);
				ir += fm * aw[j + 2] + fp * aw[j + 3];
				*i += fm * aw[j + 4] + fp * aw[j + 5];
			}
			k += nk;
			j = jtmp;
			do {
				j += 6;
				fm = (*f)(a + aw[j]);
				ir += fm * aw[j + 2];
				fm *= aw[j + 4];
				*i += fm;
			} while (fabs(fm) > errt && j < k);
			j = jtmp;
			do {
				j += 6;
				fp = (*f)(a + aw[j + 1]);
				ir += fp * aw[j + 3];
				fp *= aw[j + 5];
				*i += fp;
			} while (fabs(fp) > errt && j < k);
		} while (k < klim);
		errd = h * (fabs(*i - 2 * iback) + fabs(ir - 2 * irback));
		h *= 0.5;
		m *= 2;
		klim = 2 * klim - noff;
	}
	*i *= h;
	if (errd > errh)
		*err = -errd * m;
	else
		*err *= aw[2] * m;
}

static inline void
intdei_core(integrand f, double a, double *i, double *err)
{
	static double aw[_LENAW];
	static int check = 0;

	if (check == 0)
	{
		get_dbl_info();
		__int_dei_init(_LENAW, dbl_info.min, dbl_info.epsilon, aw);
		check = 1;
	}
	__int_dei_entity(f, a, aw, i, err);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_QUADRATURE_DERULE_TYPEI_INTERNAL */
