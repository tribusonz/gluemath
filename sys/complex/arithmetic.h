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
#include "../../sys/float/absolute.h"

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
fc_add(fcomplex x, fcomplex y)
{
    x.real += y.real;
    x.imag += y.imag;
    return x;
}

/* 差 $x - y$ */
static inline fcomplex
fc_sub(fcomplex x, fcomplex y)
{
    x.real -= y.real;
    x.imag -= y.imag;
    return x;
}

/* 積 $xy$ */
static inline fcomplex
fc_mul(fcomplex x, fcomplex y)
{
    fcomplex z;

    z.real = x.real * y.real - x.imag * y.imag;
    z.imag = x.real * y.imag + x.imag * y.real;
    return z;
}

/* 商 $x / y$ (上位桁あふれ対策版) */
static inline fcomplex
fc_div(fcomplex x, fcomplex y)
{
    float w, d;
    fcomplex z;

    if (fabs(y.real) >= fabs(y.imag)) {
        w = y.imag / y.real;  d = y.real + y.imag * w;
        z.real = (x.real + x.imag * w) / d;
        z.imag = (x.imag - x.real * w) / d;
    } else {
        w = y.real / y.imag;  d = y.real * w + y.imag;
        z.real = (x.real * w + x.imag) / d;
        z.imag = (x.imag * w - x.real) / d;
    }
    return z;
}

// double complex
/* 和 $x + y$ */
static inline dcomplex
dc_add(dcomplex x, dcomplex y)
{
    x.real += y.real;
    x.imag += y.imag;
    return x;
}

/* 差 $x - y$ */
static inline dcomplex
dc_sub(dcomplex x, dcomplex y)
{
    x.real -= y.real;
    x.imag -= y.imag;
    return x;
}

/* 積 $xy$ */
static inline dcomplex
dc_mul(dcomplex x, dcomplex y)
{
    dcomplex z;

    z.real = x.real * y.real - x.imag * y.imag;
    z.imag = x.real * y.imag + x.imag * y.real;
    return z;
}

/* 商 $x / y$ (上位桁あふれ対策版) */
static inline dcomplex
dc_div(dcomplex x, dcomplex y)
{
    double w, d;
    dcomplex z;

    if (fabs(y.real) >= fabs(y.imag)) {
        w = y.imag / y.real;  d = y.real + y.imag * w;
        z.real = (x.real + x.imag * w) / d;
        z.imag = (x.imag - x.real * w) / d;
    } else {
        w = y.real / y.imag;  d = y.real * w + y.imag;
        z.real = (x.real * w + x.imag) / d;
        z.imag = (x.imag * w - x.real) / d;
    }
    return z;
}

// double complex
/* 和 $x + y$ */
static inline lcomplex
lc_add(lcomplex x, lcomplex y)
{
    x.real += y.real;
    x.imag += y.imag;
    return x;
}

/* 差 $x - y$ */
static inline lcomplex
lc_sub(lcomplex x, lcomplex y)
{
    x.real -= y.real;
    x.imag -= y.imag;
    return x;
}

/* 積 $xy$ */
static inline lcomplex
lc_mul(lcomplex x, lcomplex y)
{
    lcomplex z;

    z.real = x.real * y.real - x.imag * y.imag;
    z.imag = x.real * y.imag + x.imag * y.real;
    return z;
}

/* 商 $x / y$ (上位桁あふれ対策版) */
static inline lcomplex
lc_div(lcomplex x, lcomplex y)
{
    long double w, d;
    lcomplex z;

    if (fabs(y.real) >= fabs(y.imag)) {
        w = y.imag / y.real;  d = y.real + y.imag * w;
        z.real = (x.real + x.imag * w) / d;
        z.imag = (x.imag - x.real * w) / d;
    } else {
        w = y.real / y.imag;  d = y.real * w + y.imag;
        z.real = (x.real * w + x.imag) / d;
        z.imag = (x.imag * w - x.real) / d;
    }
    return z;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_COMPLEX_PRIMITIVE_ARITHMETIC_H */
