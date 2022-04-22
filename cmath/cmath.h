/*******************************************************************************
	GLUE-Math Library -- ComplexMath C Compiler ABI

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GLUEMATH_COMPLEXMATH_H
#define GLUEMATH_COMPLEXMATH_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "../sys/complex/class.h"

extern dcomplex gml_log_c8(dcomplex);
#define log_c8 gml_log_c8

extern dcomplex gml_gamma_c8(dcomplex);
#define gamma_c8 gml_gamma_c8

#if defined(__cplusplus)
}
#endif

#endif /* GLUEMATH_COMPLEXMATH_H */
