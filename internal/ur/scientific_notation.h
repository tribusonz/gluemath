/*******************************************************************************
	GLUE-Math Library: Scientific Notation

	Author:
	  Rémy Abergel, Lionel Moisan (Original Algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modified)
	License:
	  Rémy Abergel and Lionel Moisan's (with copyright)
	  GPL + X11(MIT) (ABI modified)
	following paper:
	  Algorithm 1006: Fast and accurate evaluation of a generalized
	                  incomplete gamma function
	                  - Rémy Abergel, Lionel Moisan
*******************************************************************************/
#ifndef GML_SCIENTIFIC_NOTATION_INTERNAL
#define GML_SCIENTIFIC_NOTATION_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: floor(), exp(), log(), log10()
#include "../../exception/matherrstat.h"
#include "floor.h"
#include "exp.h"
#include "log.h"
#include "log10.h"

static inline matherrstatus_t
scientific_notation(double *a, double *b, double rho, double sigma)
{
	double l10, delta;

	l10 = log_core(10);
	delta = log10_core(rho)+sigma/l10;
	*b = floor_core(delta);
	*a = exp_core((delta-(*b))*l10);
	return E_MATHNOERR;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_SCIENTIFIC_NOTATION_INTERNAL */
