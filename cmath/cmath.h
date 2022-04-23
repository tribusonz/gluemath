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

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.log(z) -> complex (c4/c8/ceX)
 *    (Native Code)
 *      log_c4(z) -> c32, log_c8(z) -> c64, log_ce(z) -> c80|c128
 *  
 *  Computes Complex Natural logarithm of z.
 *  
 *  @z: complex number
 *  @retval: solve of complex natural logarithm
 *  
 *  Mathematical Notation:
 *  $\ln(z)$
 */
extern fcomplex gml_log_c4(fcomplex);
#define log_c4 gml_log_c4
extern dcomplex gml_log_c8(dcomplex);
#define log_c8 gml_log_c8
extern lcomplex gml_log_ce(lcomplex);
#define log_ce gml_log_ce

extern dcomplex gml_gamma_c8(dcomplex);
#define gamma_c8 gml_gamma_c8

#if defined(__cplusplus)
}
#endif

#endif /* GLUEMATH_COMPLEXMATH_H */
