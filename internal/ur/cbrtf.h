/*******************************************************************************
	GLUE-Math Library: Cube Root (float)
	
	Author:
	  Haruhiko Okumura (Original algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_CUBEROOT_FLT_INTERNAL
#define GML_CUBEROOT_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: (nothing)
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"

/* Prof. Okumura's $\sqrt[3]{x}$ */
static inline float
cbrtf_core(register float x)
{
	register float s, prev;
	int positive;

	if (x == 0) return 0;
	if (isinf(x) || isnan(x)) return x;
	if (x > 0) positive = 1;  else {  positive = 0;  x = -x;  }
	if (x > 1) s = x;  else s = 1;
	do {
		prev = s;  s = (x / (s * s) + 2 * s) / 3;
	} while (s < prev);
	if (positive) return prev;  else return -prev;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_CUBEROOT_FLT_INTERNAL */
