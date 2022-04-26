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
 *      RMath.exp(z) -> complex (c4/c8/ceX)
 *    (Native Code)
 *      exp_c4(z) -> c32, exp_c8(z) -> c64, exp_ce(z) -> c80|c128
 *  
 *  Computes Complex Exponential Function of z.
 *  
 *  @z: complex number
 *  @retval: solve of complex exponential function
 *  
 *  Mathematical Notation:
 *  $e^z$
 */
extern fcomplex exp_c4(fcomplex);
extern dcomplex exp_c8(dcomplex);
extern lcomplex exp_ce(lcomplex);

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
extern fcomplex log_c4(fcomplex);
extern dcomplex log_c8(dcomplex);
extern lcomplex log_ce(lcomplex);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.erf(z) -> complex (c4/c8/ceX)
 *    (Native Code)
 *      erf_c4(z) -> c32, erf_c8(z) -> c64, erf_ce(z) -> c80|c128
 *  
 *  Computes complex error function of z.
 *  
 *  @z: complex number
 *  @retval: solve of complex error function
 *  
 */
extern fcomplex erf_c4(fcomplex);
extern dcomplex erf_c8(dcomplex);
extern lcomplex erf_ce(lcomplex);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.erfc(z) -> complex (c4/c8/ceX)
 *    (Native Code)
 *      erfc_c4(z) -> c32, erfc_c8(z) -> c64, erfc_ce(z) -> c80|c128
 *  
 *  Computes complex complementary error function of z.
 *  
 *  @z: complex number
 *  @retval: solve of complex complementary error function
 *  
 */
extern fcomplex erfc_c4(fcomplex);
extern dcomplex erfc_c8(dcomplex);
extern lcomplex erfc_ce(lcomplex);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.gamma(z) -> complex (c4/c8/ceX)
 *    (Native Code)
 *      gamma_c4(z) -> c32, gamma_c8(z) -> c64, gamma_ce(z) -> c80|c128
 *  
 *  Computes complex gamma function of z.
 *  
 *  @z: complex number
 *  @retval: solve of complex gamma function
 *  
 */
extern fcomplex gamma_c4(fcomplex);
extern dcomplex gamma_c8(dcomplex);
extern lcomplex gamma_ce(lcomplex);

#if defined(__cplusplus)
}
#endif

#endif /* GLUEMATH_COMPLEXMATH_H */
