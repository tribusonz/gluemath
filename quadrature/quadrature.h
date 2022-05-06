/*******************************************************************************
	GLUE-Math Library: Quadrature ABI

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_QUADRATURE_H
#define GML_QUADRATURE_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "../sys/quadrature/class.h"

// Reference of DE-rule algorithm:
//   Ooura's Mathematical Software Packages
//   https://www.kurims.kyoto-u.ac.jp/~ooura/index-j.html

/*
 *  call-seq:
 *    (UserLevel Code)
 *      Quadrature.de(integrand, a, b) -> [real (r8), real (r8)]
 *    (Native Code)
 *      intde(integrand, a, b, *i, *err) -> void
 *  
 *  Evaluates DE-rule for integral. Limits of integration {a} and {b} must be finite.
 *  The result is returned in a two-pair array.
 *  The first item is the result, and the last item is an error.
 *  If it can be terminated normally, the absolute error is returned as a real number,
 *  but if it is abnormal, a negative value is sent out.
 *  The tiny value (minimum value) and eps value (machine epsilon value)
 *  use the environment constant internally.
 *
 *  @integrand .. integrand. on ABI: double (*f)(double)
 *  @a .. lower limits of integral
 *  @b .. upper limits of integral
 *  @*i .. stack an integral solve (scalar)
 *  @*err .. stack an absolute error or error message (scalar)
 *  @retval .. (void)
 * 
 */
extern void intde(integrand, double, double, double*, double*);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      Quadrature.dei(integrand, a) -> [real (r8), real (r8)]
 *    (Native Code)
 *      intdei(integrand, a, *i, *err) -> void
 *  
 *  Evaluates DE-rule for integral. Infinite limits of integration starts by {a}.
 *  This is called a vibratory type. Attempts to converge to infinity.
 *  The result is returned in a two-pair array.
 *  The first item is the result, and the last item is an error.
 *  If it can be terminated normally, the absolute error is returned as a real number,
 *  but if it is abnormal, a negative value is sent out.
 *  The tiny value (minimum value) and eps value (machine epsilon value)
 *  use the environment constant internally.
 *
 *  @integrand .. integrand. on ABI: double (*f)(double)
 *  @a .. lower limits of integral
 *  @*i .. stack an integral solve (scalar)
 *  @*err .. stack an absolute error or error message (scalar)
 *  @retval .. (void)
 * 
 */
extern void intdei(integrand, double, double*, double*);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      Quadrature.deo(integrand, a, omega) -> [real (r8), real (r8)]
 *    (Native Code)
 *      intdei(integrand, a, omega, *i, *err) -> void
 *  
 *  Evaluates DE-rule for integral. Infinite limits of integration starts by {a}.
 *  This is called a non-vibratory type. calculates f(x) = sin(omega * x + theta) as x -> infinity.
 *  The result is returned in a two-pair array.
 *  The first item is the result, and the last item is an error.
 *  If it can be terminated normally, the absolute error is returned as a real number,
 *  but if it is abnormal, a negative value is sent out.
 *  The tiny value (minimum value) and eps value (machine epsilon value)
 *  use the environment constant internally.
 *
 *  @integrand .. integrand. on ABI: double (*f)(double)
 *  @a .. lower limits of integral
 *  @omega .. frequency of oscillation
 *  @*i .. stack an integral solve (scalar)
 *  @*err .. stack an absolute error or error message (scalar)
 *  @retval .. (void)
 * 
 */
extern void intdeo(integrand, double, double, double*, double*);

#if defined(__cplusplus)
}
#endif

#endif /* GML_QUADRATURE_INTERNAL */
