/*******************************************************************************
	GLUE-Math Library -- Legacy (ANSI C Math Compatibility)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GLUEMATH_LEGACY_H
#define GLUEMATH_LEGACY_H

#if defined(__cplusplus)
extern "C" {
#endif

/*
 *  For CPython, CRuby, ...
 */

/*
 *  C ABI: pow(x, y) -> f64, powl(x, y) -> f80 | f128, powf(x, y) -> f32
 *  
 *  Return Powers of x and y.
 *  If y is an integer, it is automatically calculated by an integer power algorithm.
 *  Although it is an implementation for compatibility with ANSI Math,
 *  gluemath provides it as an operator of primitives, so it is described here in the internal implementation.
 *  However, it also corresponds when x and y are negative real numbers.
 *  
 *  @x: base
 *  @y: power
 *  @retval: powers
 *  
 *  Mathematical Notation:
 *  $x^y$
 *  
 *  Calculation Formula:
 *  $x^{y}=\begin{Bmatrix}e^{y\,\ln(x)}&x<0\\-e^{y\,\ln(\left|x\right|)}&x\neq0,\,y<0\\\end{Bmatrix}$
 *  
 *  Inline implementation as follows:
 *  $x^{y}=\begin{Bmatrix}e_2^{y\,\log_2(x)}&x<0\\-e_2^{y\,\log_2(\left|x\right|)}&x\neq0,\,y<0\\\end{Bmatrix}$
 *  
 *  This is an operator. For builtin function, so uses by include project header <fplib.h>.
 *  
 *  Special behaviors:
 *  Arg y is zero: always result 1 or -1
 *  Arg x is NaN, y is +-Infinity: return NaN (computational NaN handling)
 *  Arg y is +infinity: return +-Infinity (Mean Complex Infinity)
 *  Arg y is -Infinity: return +-0
 *  Arg y is NaN: return NaN (undefined)
 */

/*
 *  C ABI: fmod(x, y) -> f64, fmodl(x, y) -> f80 | f128, fmodf(x, y) -> f32
 *  
 *  Return modulo of x and y.
 *  Although it is an implementation for compatibility with ANSI Math,
 *  gluemath provides it as an operator of primitives, so it is described here in the internal implementation.
 *  However, it also corresponds negative direction.
 *  
 *  Directions:
 *   x %  y : Zero direction
 *   x % -y : Negative direction
 *  -x %  y : Negative direction
 *  -x % -y : Zero direction
 *  
 *  @x: numerator
 *  @y: denominator
 *  @retbal: modulo of x and y
 *  
 *  Note:
 *  Since it corresponds to the negative direction, binary operation is simple.
 *  
 *    value = -1.0;
 *    unsigned char bin = (unsigned char)(fmod(value, 0x100));  // 0xFF
 *  
 *  It's useful in engineering. However, the remainder of the computer operations is
 *  based on the nearest neighbor method, so a machine-dependent.
 *  If your architecture is not confident in the nearest neighbor method, define _USE_NNINT_MACRO
 *  to compile without hesitating.
 *  
 *  Mathematical Notation:
 *  $x \mod y$
 *  
 *  Calculation Formula:
 *  ${x}\mod{y}=x\neg{y}\left\lfloor\frac{x}{y}\right\rfloor$
 *  
 *  This is an operator. For builtin function, so uses by include project header <fplib.h>.
 *  
 *  Special behaviors:
 *  Arg y is 0: return NaN
 *  Any or either of the args +-Infinity: return NaN
 *  Any or either of the args NaN: return NaN (computational NaN handling)
 */

/*
 *  C ABI: fabs(x) -> f64, fabsl(x) -> f80 | f128, fabsf(x) -> f32
 * 
 *  Return absolute number of x.
 *  Although it is an implementation for compatibility with ANSI Math,
 *  gluemath provides it as an fp-library of primitives, so it is described here in the internal implementation.
 *  
 *  @x: Real number
 *  @retval: absoluted number of x.
 *  
 *  This is an fp-library. For builtin function, so uses by include project header <fplib.h>.
 *  
 *  Mathematical Notation:
 *  $|x|$
 *  
 *  Special behaviors:
 *  Arg x is NaN: return NaN (computational NaN handling)
 */

/*
 *  C ABI: floor(x) -> f64, floorl(x) -> f80 | f128, floorf(x) -> f32
 * 
 *  Attempts return {x} of floor function based on the exponential decomposition formula.
 *  Although the algorithm is devised to truncate the decimal point, it is machine-dependent,
 *  and even if you try a large number that cannot be returned to decimal, it can not be expected to be very effective.
 *  Side effects may be -0.0 in results (e.g., Windows).
 *  If you want to fast it up, _USE_NNINT_MACRO define and compile,
 *  then try to type-convertion to int type if it is a smaller number.
 *  
 *  @x: Real number
 *  @retval: floor function of x.
 *  
 *  Note:
 *  The Nearest Neighbor (NN) interpolation is originally a machine-dependent.
 *  If your architecture's unworkable to this, please choose define _USE_NNINT_MACRO to compile without hesitating.
 *  
 *  Mathematical Notation:
 *  $\left\lfloor{x}\right\rfloor$
 *  
 *  Special behaviors:
 *  Arg x is +-Infinity: return +-Infinity
 *  Arg x is NaN: return NaN (computational NaN handling)
 */

/*
 *  C ABI: ceil(x) -> f64, ceill(x) -> f80 | f128, ceilf(x) -> f32
 * 
 *  Attempts return {x} of ceiling function based on the exponential decomposition formula.
 *  Although the algorithm is devised to truncate the decimal point, it is machine-dependent,
 *  and even if you try a large number that cannot be returned to decimal, it can not be expected to be very effective.
 *  Side effects may be -0.0 in results (e.g., Windows).
 *  If you want to fast it up, _USE_NNINT_MACRO define and compile,
 *  then try to type-convertion to int type if it is a smaller number.
 *  
 *  @x: Real number
 *  @retval: ceiling function of x.
 *  
 *  Note:
 *  The Nearest Neighbor (NN) interpolation is originally a machine-dependent.
 *  If your architecture's unworkable to this, please choose define _USE_NNINT_MACRO to compile without hesitating.
 *  
 *  Mathematical Notation:
 *  $\left\lceil{x}\right\rceil$
 *  
 *  Special behaviors:
 *  Arg x is +-Infinity: return +-Infinity
 *  Arg x is NaN: return NaN (computational NaN handling)
 */

/*
 *  C ABI: trunc(x) -> f64, truncl(x) -> f80 | f128, truncf(x) -> f32
 * 
 *  Attempts return {x} of truncate function based on the exponential decomposition formula.
 *  Although the algorithm is devised to truncate the decimal point, it is machine-dependent,
 *  and even if you try a large number that cannot be returned to decimal, it can not be expected to be very effective.
 *  Side effects may be -0.0 in results (e.g., Windows).
 *  If you want to fast it up, _USE_NNINT_MACRO define and compile,
 *  then try to type-convertion to int type if it is a smaller number.
 *  
 *  @x: Real number
 *  @retval: truncate function of x.
 *  
 *  Note:
 *  The Nearest Neighbor (NN) interpolation is originally a machine-dependent.
 *  If your architecture's unworkable to this, please choose define _USE_NNINT_MACRO to compile without hesitating.
 *  
 *  Mathematical Notation:
 *  $\mathrm{IntegerPart}[x]$
 *  
 *  Special behaviors:
 *  Arg x is +-Infinity: return +-Infinity
 *  Arg x is NaN: return NaN (computational NaN handling)
 */

// See realmath.h for calling sequences.
extern double legacy_exp(double);
#define exp legacy_exp
extern long double legacy_expl(long double);
#define expl legacy_expl
extern float legacy_expf(float);
#define expf legacy_expf

// See realmath.h for calling sequences.
extern double legacy_exp2(double);
#define exp2 legacy_exp2
extern long double legacy_exp2l(long double);
#define exp2l legacy_exp2l
extern float legacy_exp2f(float);
#define exp2f legacy_exp2f

// See realmath.h for calling sequences.
extern double legacy_log(double);
#define log legacy_log
extern long double legacy_logl(long double);
#define logl legacy_logl
extern float legacy_logf(float);
#define logf legacy_logf

// See realmath.h for calling sequences.
extern double legacy_log2(double);
#define log2 legacy_log2
extern long double legacy_log2l(long double);
#define log2l legacy_log2l
extern float legacy_log2f(float);
#define log2f legacy_log2f

// See realmath.h for calling sequences.
extern double legacy_log10(double);
#define log10 legacy_log10
extern long double legacy_log10l(long double);
#define log10l legacy_log10l
extern float legacy_log10f(float);
#define log10f legacy_log10f

// See realmath.h for calling sequences.
extern double legacy_sqrt(double);
#define sqrt legacy_sqrt
extern long double legacy_sqrtl(long double);
#define sqrtl legacy_sqrtl
extern float legacy_sqrtf(float);
#define sqrtf legacy_sqrtf

// See realmath.h for calling sequences.
extern double legacy_cbrt(double);
#define cbrt legacy_cbrt
extern long double legacy_cbrtl(long double);
#define cbrtl legacy_cbrtl
extern float legacy_cbrtf(float);
#define cbrtf legacy_cbrtf

// See realmath.h for calling sequences.
extern double legacy_sin(double);
#define sin legacy_sin
extern long double legacy_sinl(long double);
#define sinl legacy_sinl
extern float legacy_sinf(float);
#define sinf legacy_sinf

// See realmath.h for calling sequences.
extern double legacy_cos(double);
#define cos legacy_cos
extern long double legacy_cosl(long double);
#define cosl legacy_cosl
extern float legacy_cosf(float);
#define cosf legacy_cosf

// See realmath.h for calling sequences.
extern double legacy_tan(double);
#define tan legacy_tan
extern long double legacy_tanl(long double);
#define tanl legacy_tanl
extern float legacy_tanf(float);
#define tanf legacy_tanf

// See realmath.h for calling sequences.
extern double legacy_asin(double);
#define asin legacy_asin
extern long double legacy_asinl(long double);
#define asinl legacy_asinl
extern float legacy_asinf(float);
#define asinf legacy_asinf

// See realmath.h for calling sequences.
extern double legacy_acos(double);
#define acos legacy_acos
extern long double legacy_acosl(long double);
#define acosl legacy_acosl
extern float legacy_acosf(float);
#define acosf legacy_acosf

// See realmath.h for calling sequences.
extern double legacy_atan(double);
#define atan legacy_atan
extern long double legacy_atanl(long double);
#define atanl legacy_atanl
extern float legacy_atanf(float);
#define atanf legacy_atanf

// See realmath.h of rmath.quadrant() for calling sequences.
extern double legacy_atan2(double, double);
#define atan2 legacy_atan2
extern long double legacy_atan2l(long double, long double);
#define atan2l legacy_atan2l
extern float legacy_atan2f(float, float);
#define atan2f legacy_atan2f

// See realmath.h for calling sequences.
extern double legacy_sinh(double);
#define sinh legacy_sinh
extern long double legacy_sinhl(long double);
#define sinhl legacy_sinhl
extern float legacy_sinhf(float);
#define sinhf legacy_sinhf

// See realmath.h for calling sequences.
extern double legacy_cosh(double);
#define cosh legacy_cosh
extern long double legacy_coshl(long double);
#define coshl legacy_coshl
extern float legacy_coshf(float);
#define coshf legacy_coshf

// See realmath.h for calling sequences.
extern double legacy_tanh(double);
#define tanh legacy_tanh
extern long double legacy_tanhl(long double);
#define tanhl legacy_tanhl
extern float legacy_tanhf(float);
#define tanhf legacy_tanhf

// See realmath.h for calling sequences.
extern double legacy_asinh(double);
#define asinh legacy_asinh
extern long double legacy_asinhl(long double);
#define asinhl legacy_asinhl
extern float legacy_asinhf(float);
#define asinhf legacy_asinhf

// See realmath.h for calling sequences.
extern double legacy_acosh(double);
#define acosh legacy_acosh
extern long double legacy_acoshl(long double);
#define acoshl legacy_acoshl
extern float legacy_acoshf(float);
#define acoshf legacy_acoshf

// See realmath.h for calling sequences.
extern double legacy_atanh(double);
#define atanh legacy_atanh
extern long double legacy_atanhl(long double);
#define atanhl legacy_atanhl
extern float legacy_atanhf(float);
#define atanhf legacy_atanhf

// See realmath.h for calling sequences.
extern double legacy_hypot(double, double);
#define hypot legacy_hypot
extern long double legacy_hypotl(long double, long double);
#define hypotl legacy_hypotl
extern float legacy_hypotf(float, float);
#define hypotf legacy_hypotf

// See realmath.h for calling sequences.
extern double legacy_tgamma(double);
#define tgamma legacy_tgamma
extern long double legacy_tgammal(long double);
#define tgammal legacy_tgammal
extern float legacy_tgammaf(float);
#define tgammaf legacy_tgammaf

// See realmath.h for calling sequences.
extern double legacy_lgamma(double);
#define lgamma legacy_lgamma
extern long double legacy_lgammal(long double);
#define lgammal legacy_lgammal
extern float legacy_lgammaf(float);
#define lgammaf legacy_lgammaf

// See realmath.h for calling sequences.
extern double legacy_erf(double);
#define erf legacy_erf
extern long double legacy_erfl(long double);
#define erfl legacy_erfl
extern float legacy_erff(float);
#define erff legacy_erff

// See realmath.h for calling sequences.
extern double legacy_erfc(double);
#define erfc legacy_erfc
extern long double legacy_erfcl(long double);
#define erfcl legacy_erfcl
extern float legacy_erfcf(float);
#define erfcf legacy_erfcf

/*
 *  C ABI: frexp(x, *exp) -> f64, frexpl(x, *exp) -> f80 | f128, frexpf(x, *exp) -> f32
 *  
 *  Decomposes the exponent and fraction of {x}, writes the exponent as the second argument,
 *  and returns the fraction.
 *  From the idea of the exponential decomposition formula, the exponent is incremented and
 *  fraction is normalized by 1/2.
 *  This is an implementation for compatible and is actually simulated in RCM.
 *  
 *  @x: original value
 *  @exp: scalar (int), written the exponent
 *  @retval: fraction of {x}
 *  
 *  Special behaviors:
 *  The decomposition formula is original.
 *   e.g. 15.0:
 *   -> exponential decompisition: exp=3, frac=1.875
 *   -> fraction and exponent:     exp=4, frac=0.9375
 *  {x} is zero: exp=0 frac=0.0  (unspecified behavior)
 *  {x} is +-Infinity: exp=0 frac=+-Infinity  (unspecified behavior)
 *  {x} is NaN: exp=0 frac=NaN  (unspecified behavior)
 *  {x} is negative: frac has sign  (unspecified behavior)
 */
extern double legacy_frexp(double, int*);
#define frexp legacy_frexp
extern long double legacy_frexpl(long double, int*);
#define frexpl legacy_frexpl
extern float legacy_frexpf(float, int*);
#define frexpf legacy_frexpf

/*
 *  C ABI: ldexp(x, exp) -> f64, ldexpl(x, exp) -> f80 | f128, ldexpf(x, exp) -> f32
 *  
 *  Returns the {exp}-power of {x} by 2.
 *  The calculation is expressed by the following formula:
 *  $x\,2^{\mathrm{exp}}$
 *  Like frexp(), it is a floating-point operation function, but it is also useful as
 *  a function that returns the integer power of 2.
 *  
 *  @x: number to multiply (real)
 *  @exp: integer power number
 *  @retval: solve of load exponent
 *  
 *  Special behaviors:
 *  Implemented Algorithm type: Fully converged convolution
 *  {x} is +-Infinity:  (machine-dependent)
 *  {x} is NaN: (machine-dependent)
 */
extern double legacy_ldexp(double, int);
#define ldexp legacy_ldexp
extern long double legacy_ldexpl(long double, int);
#define ldexpl legacy_ldexpl
extern float legacy_ldexpf(float, int);
#define ldexpf legacy_ldexpf


extern double legacy_modf(double, double*);
#define modf legacy_modf
extern long double legacy_modfl(long double, long double*);
#define modfl legacy_modfl
extern float legacy_modff(float, float*);
#define modff legacy_modff


#if defined(__cplusplus)
}
#endif

#endif /* GLUEMATH_LEGACY_H */
