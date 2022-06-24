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
#include "../../internal/ur/caddf.h"
#include "../../internal/ur/csubf.h"
#include "../../internal/ur/cmulf.h"
#include "../../internal/ur/cdivf.h"
#include "../../internal/ur/cadd.h"
#include "../../internal/ur/csub.h"
#include "../../internal/ur/cmul.h"
#include "../../internal/ur/cdiv.h"
#include "../../internal/ur/caddl.h"
#include "../../internal/ur/csubl.h"
#include "../../internal/ur/cmull.h"
#include "../../internal/ur/cdivl.h"

// compiler inline function
static inline fcomplex fc_add(fcomplex, fcomplex);
static inline fcomplex fc_sub(fcomplex, fcomplex);
static inline fcomplex fc_mul(fcomplex, fcomplex);
static inline fcomplex fc_div(fcomplex, fcomplex);
static inline dcomplex dc_add(dcomplex, dcomplex);
static inline dcomplex dc_sub(dcomplex, dcomplex);
static inline dcomplex dc_mul(dcomplex, dcomplex);
static inline dcomplex dc_div(dcomplex, dcomplex);
static inline lcomplex lc_add(lcomplex, lcomplex);
static inline lcomplex lc_sub(lcomplex, lcomplex);
static inline lcomplex lc_mul(lcomplex, lcomplex);
static inline lcomplex lc_div(lcomplex, lcomplex);

// float complex
/* 和 $x + y$ */
static inline fcomplex
fc_add(fcomplex z, fcomplex w)
{
	return caddf_core(z, w);
}

/* 差 $x - y$ */
static inline fcomplex
fc_sub(fcomplex z, fcomplex w)
{
	return csubf_core(z, w);
}

/* 積 $xy$ */
static inline fcomplex
fc_mul(fcomplex z, fcomplex w)
{
	return cmulf_core(z, w);
}

/* 商 $x / y$ */
static inline fcomplex
fc_div(fcomplex z, fcomplex w)
{
	return cdivf_core(z, w);
}

// double complex
/* 和 $x + y$ */
static inline dcomplex
dc_add(dcomplex z, dcomplex w)
{
	return cadd_core(z, w);
}

/* 差 $x - y$ */
static inline dcomplex
dc_sub(dcomplex z, dcomplex w)
{
	return csub_core(z, w);
}

/* 積 $xy$ */
static inline dcomplex
dc_mul(dcomplex z, dcomplex w)
{
	return cmul_core(z, w);
}

/* 商 $x / y$ */
static inline dcomplex
dc_div(dcomplex z, dcomplex w)
{
    return cdiv_core(z, w);
}

// long double complex
/* 和 $x + y$ */
static inline lcomplex
lc_add(lcomplex z, lcomplex w)
{
	return caddl_core(z, w);
}

/* 差 $x - y$ */
static inline lcomplex
lc_sub(lcomplex z, lcomplex w)
{
	return csubl_core(z, w);
}

/* 積 $xy$ */
static inline lcomplex
lc_mul(lcomplex z, lcomplex w)
{
	return cmull_core(z, w);
}

/* 商 $x / y$ */
static inline lcomplex
lc_div(lcomplex z, lcomplex w)
{
	return cdivl_core(z, w);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_COMPLEX_PRIMITIVE_ARITHMETIC_H */
