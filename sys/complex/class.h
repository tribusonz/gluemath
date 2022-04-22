/*******************************************************************************
	GLUE-Math Complex Primitive Setting

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
/*
 *  GLUE-Math unsupports a STDC complex.
 *  This is an original close to C++.
 */

#ifndef GML_COMPLEX_PRIMITIVE_H
#define GML_COMPLEX_PRIMITIVE_H

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct { float real, imag; } fcomplex;
typedef struct { double real, imag; } dcomplex;
typedef struct { long double real, imag; } lcomplex;

#if defined(__cplusplus)
}
#endif

#endif /* GML_COMPLEX_PRIMITIVE */
