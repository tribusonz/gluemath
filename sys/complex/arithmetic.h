/*******************************************************************************
	GLUE-Math Complex Primitive Setting: Arithmetic

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_COMPLEX_PRIMITIVE_ARITHMETIC_H
#define GML_COMPLEX_PRIMITIVE_ARITHMETIC_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "class.h"

/******************************************************************************/

/*
 * - About Architectural Side Effects -
 * 
 * Although the behavior of this arithmetic operation is standardized,
 * it is basically model-dependent.
 * Addition and subtraction depend on the architecture
 * because they internally it operates on the floating-point class.
 * Multiplication and division are an in-partly architecture-dependent
 * because they build a dedicated algorithm at the singularity.
 * 
 * The calculation when the values are singularities is what we call
 * "the calculation of singularities."
 * Special values such as 0, 1, and infinity should be treated as 0 for
 * denormalized numbers, based on the idea that slight errors should be
 * allowed in numerical calculations.
 * Multiplication and division are more likely to manifest this in variables.
 * If we define that only singularity calculations return a specified value,
 * then the dependency is a fallback.
 * 
 * | func | dependency |  denormal  |
 * |:----:|:----------:|:----------:|
 * | add  |    model   |   usable   |
 * | sub  |    model   |   usable   |
 * | mul  |  fallback  | treat as 0 |
 * | div  |  fallback  | treat as 0 |
 */

// compiler inline functions

// Addition
static inline fcomplex fc_add(fcomplex, fcomplex);
static inline dcomplex dc_add(dcomplex, dcomplex);
static inline lcomplex lc_add(lcomplex, lcomplex);

// Subtraction
static inline fcomplex fc_sub(fcomplex, fcomplex);
static inline dcomplex dc_sub(dcomplex, dcomplex);
static inline lcomplex lc_sub(lcomplex, lcomplex);

// Multiplication
static inline fcomplex fc_mul(fcomplex, fcomplex);
static inline dcomplex dc_mul(dcomplex, dcomplex);
static inline lcomplex lc_mul(lcomplex, lcomplex);

// Division
static inline fcomplex fc_div(fcomplex, fcomplex);
static inline dcomplex dc_div(dcomplex, dcomplex);
static inline lcomplex lc_div(lcomplex, lcomplex);

/******************************************************************************/

// Implementation of ABI

#include "../../internal/ur/caddf.h"
#include "../../internal/ur/cadd.h"
#include "../../internal/ur/caddl.h"

#include "../../internal/ur/csubf.h"
#include "../../internal/ur/csub.h"
#include "../../internal/ur/csubl.h"

#include "../../internal/ur/cmulf.h"
#include "../../internal/ur/cmul.h"
#include "../../internal/ur/cmull.h"

#include "../../internal/ur/cdivf.h"
#include "../../internal/ur/cdiv.h"
#include "../../internal/ur/cdivl.h"


/***** 和 $x + y$ *****/
// float complex
static inline fcomplex
fc_add(fcomplex z, fcomplex w)
{
	return caddf_core(z, w);
}

// double complex
static inline dcomplex
dc_add(dcomplex z, dcomplex w)
{
	return cadd_core(z, w);
}

// long double complex
static inline lcomplex
lc_add(lcomplex z, lcomplex w)
{
	return caddl_core(z, w);
}


/***** 差 $x - y$ *****/
// float complex
static inline fcomplex
fc_sub(fcomplex z, fcomplex w)
{
	return csubf_core(z, w);
}

// double complex
static inline dcomplex
dc_sub(dcomplex z, dcomplex w)
{
	return csub_core(z, w);
}

// long double complex
static inline lcomplex
lc_sub(lcomplex z, lcomplex w)
{
	return csubl_core(z, w);
}


/***** 積 $xy$ *****/
// float complex
static inline fcomplex
fc_mul(fcomplex z, fcomplex w)
{
	return cmulf_core(z, w);
}

// double complex
static inline dcomplex
dc_mul(dcomplex z, dcomplex w)
{
	return cmul_core(z, w);
}

// long double complex
static inline lcomplex
lc_mul(lcomplex z, lcomplex w)
{
	return cmull_core(z, w);
}


/***** 商 $x / y$ *****/
// float complex
static inline fcomplex
fc_div(fcomplex z, fcomplex w)
{
	return cdivf_core(z, w);
}

// double complex
static inline dcomplex
dc_div(dcomplex z, dcomplex w)
{
    return cdiv_core(z, w);
}

// long double complex
static inline lcomplex
lc_div(lcomplex z, lcomplex w)
{
	return cdivl_core(z, w);
}

/******************************************************************************/

#if defined(__cplusplus)
}
#endif

#endif /* GML_COMPLEX_PRIMITIVE_ARITHMETIC_H */
