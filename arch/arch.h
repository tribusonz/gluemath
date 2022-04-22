/*******************************************************************************
	Architecture Set
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ARCH_SET
#define GML_ARCH_SET

#if defined(__cplusplus)
extern "C" {
#endif

/*
 *  C ABI: rcm2(x, *exp) -> f64, rcm2l(x, *exp) -> f80 | f128, rcm2f(x, *exp) -> f32
 *  C ABI: rcm10(x, *exp) -> f64, rcm10l(x, *exp) -> f80 | f128, rcm10f(x, *exp) -> f32
 *  
 *  Floating point x is decomposed into normalized mant number and power based on the exponential decomposition formula,
 *  then return each - the mantissa part as a returning-value - write the exponent to *exp.
 *  rcm2() decomposes the radix as 2, and rcm10() decomposes the radix as 10.
 *  This function is an equation. The nth simultaneous equations. Its name is "Radix Complementation Method".
 *  As an exponential decomposition, rcm of radix 2 is the true value.
 *  There is also a reciprocal, which is the solution of 0 <= x < 1 of rcm10.
 *  In order to make it an interface, the frexp() function and that behavior are the same as possible,
 *  negative numbers and zero should not be solved with RCM. Because it does not exist in the equation.
 *  Moreover, even the use example in the numerical calculation cannot be considered.
 *  It is conceivable to use rcm10() for exponential notation -
 *  printf("%f%+d", fraction, exponent)
 *  - but, The unary sign is independent as an operator in the compiler.
 *  
 *  @x .. Value, real number
 *  @exp .. scalar(int type), Contain as exponent. rcm2: radix = 2, rcm10: radix = 10
 *  @retval .. Fraction Part. rcm2: normalized 1 <= x < 2, rcm10: normalized 1 <= x < 10
 *  
 *  Special behaviors:
 *  {x} is negative number: (unspecified behavior)
 *  {x} is zero: Return 0.0 and *exp is 0
 *  {x} is NaN, +-Infinity: return x and *exp is 0
 *  
 */
extern float gml_rcm2f(float, int*);
#define rcm2f gml_rcm2f
extern double gml_rcm2(double, int*);
#define rcm2 gml_rcm2
extern long double gml_rcm2l(long double, int*);
#define rcm2l gml_rcm2l
extern float gml_rcm10f(float, int*);
#define rcm10f gml_rcm10f
extern double gml_rcm10(double, int*);
#define rcm10 gml_rcm10
extern long double gml_rcm10l(long double, int*);
#define rcm10l gml_rcm10l

#if defined(__cplusplus)
}
#endif

#endif /* GML_ARCH_SET */
