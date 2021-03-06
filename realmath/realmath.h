/*******************************************************************************
	GLUE-Math Library -- RealMath C Compiler ABI

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GLUEMATH_REALMATH_H
#define GLUEMATH_REALMATH_H

#if defined(__cplusplus)
extern "C" {
#endif

/*
 *  Real-Math part of RMath (RefinedMath)
 */

/***** Exponent & Logarithm & Power-root *****/
/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.exp(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      exp_r4(x) -> f32, exp_r8(x) -> f64, exp_re(x) -> f80|f128
 *  
 *  Computes Exponential function of x.
 *  The algorithm is based on the exponential decomposition formula, so its accurate, safe and fast.
 *  As an out-of-domain application, the value of arguments that may be sufficient to
 *  trigger automatically returns Infinity for overflow and 0.0 for underflow.
 *  By not using denormalized numbers, all algorithms that use 0.0 instead of underflows
 *  by expansion expressions are designed to be handled intuitively and appropriately.
 *  
 *  @x: X-axis
 *  @retval: solve of exponential function
 *  
 *  Mathematical Notation:
 *  $e^x$
 *  
 *  Special behaviors:
 *  adopting algorithm: Decomposition Formula, RCM x Oberon
 *  Domain: $\mathbb{R}$
 *  Pole: $\left\{y\in\mathbb{R}:y>0\right\}$
 *  Co Domain: MIN_10_EXP*log10(E)..MAX_10_EXP*log10(E), otherwise minus: 0.0, plus: Infinity
 *  Arg is -Infinity: return 0.0
 *  Arg is Infinity: return Infinity
 *  Arg is NaN: return NaN (context-switching NaN handling)
 */
extern float exp_r4(float);
extern double exp_r8(double);
extern long double exp_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.expm1(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      expm1_r4(x) -> f32, expm1_r8(x) -> f64, expm1_re(x) -> f80|f128
 *  
 *  Computes exp(x)-1. The neighborhood of 0 is more accurate than the direct calculation.
 *  
 *  @x: X-axis
 *  @retval: solve of expm1()
 */
extern float expm1_r4(float);
extern double expm1_r8(double);
extern long double expm1_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.exp2(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      exp2_r4(x) -> f32, exp2_r8(x) -> f64, exp2_re(x) -> f80|f128
 *  
 *  Computes Binary exponent of x.
 *  The algorithm is based on the exponential decomposition formula, so its accurate, safe and fast.
 *  As an out-of-domain application, the value of arguments that may be sufficient to
 *  trigger automatically returns Infinity for overflow and 0.0 for underflow.
 *  By not using denormalized numbers, all algorithms that use 0.0 instead of underflows
 *  by expansion expressions are designed to be handled intuitively and appropriately.
 *  
 *  @x: X-axis
 *  @retval: solve of binary exponent
 *  
 *  Mathematical Notation:
 *  $2^x$
 *  
 *  Special behaviors:
 *  adopting algorithm: Decomposition Formula, RCM x Oberon
 *  Domain: $\mathbb{R}$
 *  Pole: $\left\{y\in\mathbb{R}:y>0\right\}$
 *  Co Domain: MIN_10_EXP*log10(2)..MAX_10_EXP*log10(2), otherwise minus: 0.0, plus: Infinity
 *  Arg is -Infinity: return 0.0
 *  Arg is Infinity: return Infinity
 *  Arg is NaN: return NaN (context-switching NaN handling)
 */
extern float exp2_r4(float);
extern double exp2_r8(double);
extern long double exp2_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.log(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      log_r4(x) -> f32, log_r8(x) -> f64, log_re(x) -> f80|f128
 *  
 *  Computes Natural logarithm of x.
 *  In the routine, based on the exponential decomposition formula, then decompose x at the base 2
 *  and solve it in the base conversion formula.
 *  By not using denormalized numbers, all algorithms that use -Infinity instead of underflows
 *  by expansion expressions are designed to be handled intuitively and appropriately.
 *  
 *  @x: X-axis
 *  @retval: solve of natural logarithm
 *  
 *  Mathematical Notation:
 *  $\ln(x)$
 *  
 *  Special behaviors:
 *  adopting algorithm: Decomposition Formula, RCM x Oberon
 *  Domain: $\left\{x\in \mathbb{R};x>0 \right\}$
 *  Pole: $\mathbb{R}$
 *  Arg is negative: return NaN
 *  Arg is -Infinity: return NaN
 *  Arg is 0 or denormalized: return -Infinity
 *  Arg is Infinity: return Infinity
 *  Arg is NaN: return NaN (context-switching NaN handling)
 */
extern float log_r4(float);
extern double log_r8(double);
extern long double log_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.log1p(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      log1p_r4(x) -> f32, log1p_r8(x) -> f64, log1p_re(x) -> f80|f128
 *  
 *  Computes log(1 + x). The neighborhood of 0 is more accurate than the direct calculation.
 *  
 *  @x: X-axis
 *  @retval: solve of log1p()
 */
extern float log1p_r4(float);
extern double log1p_r8(double);
extern long double log1p_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.log2(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      log2_r4(x) -> f32, log2_r8(x) -> f64, log2_re(x) -> f80|f128
 *  
 *  Computes Binary logarithm of x.
 *  In the routine, based on the exponential decomposition formula, then decompose x at the base 2
 *  and solve it.
 *  By not using denormalized numbers, all algorithms that use -Infinity instead of underflows
 *  by expansion expressions are designed to be handled intuitively and appropriately.
 *  
 *  @x: X-axis
 *  @retval: solve of binary logarithm
 *  
 *  Mathematical Notation:
 *  $\log_2(x)$
 *  
 *  Special behaviors:
 *  adopting algorithm: Decomposition Formula, RCM x Oberon
 *  Domain: $\left\{x\in \mathbb{R};x>0 \right\}$
 *  Pole: $\mathbb{R}$
 *  Arg is negative: return NaN
 *  Arg is -Infinity: return NaN
 *  Arg is 0 or denormalized: return -Infinity
 *  Arg is Infinity: return Infinity
 *  Arg is NaN: return NaN (context-switching NaN handling)
 */
extern float log2_r4(float);
extern double log2_r8(double);
extern long double log2_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.log10(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      log10_r4(x) -> f32, log10_r8(x) -> f64, log10_re(x) -> f80|f128
 *  
 *  Computes Common logarithm of x.
 *  In the routine, based on the exponential decomposition formula, then decompose x at the base 10
 *  and solve it.
 *  By not using denormalized numbers, all algorithms that use -Infinity instead of underflows
 *  by expansion expressions are designed to be handled intuitively and appropriately.
 *  
 *  @x: X-axis
 *  @retval: solve of common logarithm
 *  
 *  Mathematical Notation:
 *  $\log_{10}(x)$
 *  
 *  Special behaviors:
 *  adopting algorithm: Decomposition Formula, RCM x Oberon
 *  Domain: $\left\{x\in \mathbb{R};x>0 \right\}$
 *  Pole: $\mathbb{R}$
 *  Arg is negative: return NaN
 *  Arg is -Infinity: return NaN
 *  Arg is 0 or denormalized: return -Infinity
 *  Arg is Infinity: return Infinity
 *  Arg is NaN: return NaN (context-switching NaN handling)
 */
extern float log10_r4(float);
extern double log10_r8(double);
extern long double log10_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.sqrt(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      sqrt_r4(x) -> f32, sqrt_r8(x) -> f64, sqrt_re(x) -> f80|f128
 *  
 *  Computes Square root of x.
 *  Nan returns if x is negative, and infinity if x is infinity.
 *  
 *  @x: X-axis
 *  @retval: solve of square root
 *  
 *  Mathematical Notation:
 *  $\sqrt{x}$
 *  
 *  Special behaviors:
 *  adopting algorithm: Okumura System
 *  Domain: $\left\{x\in\mathbb{R}:x\geq{0}\right\}$
 *  Pole: $\left\{y\in\mathbb{R}:y\geq{0}\right\}$
 *  Co Domain: 0 <= x <= Infinity, otherwise NaN
 *  Arg is -Infinity: return NaN
 *  Arg is Infinity: return Infinity
 *  Arg is NaN: return NaN (context-switching NaN handling)
 * 
 *  Note:
 *  In the numerical calculation rule, \sqrt{-1} may be defined as a domain error,
 *  but in the glue language, \imath is returned.
 *  This behavior cannot be achieved in ABI internal calculations.
 *  If \sqrt{-x} is called, it should fall-back in a numeric class or attempt an-
 *  implicit type conversion and return it as a complex number.
 *  
 *    Definition example for Python:
 *    rmath.sqrt(-1) -> 0+1j
 *
 *    Definition example for Ruby:
 *    Numeric.sqrt(-1) #=> (0.0i+1.0)
 *  
 *  Where, \jmath is the imaginary-number's notation on electrical mathematics.
 */
extern float sqrt_r4(float);
extern double sqrt_r8(double);
extern long double sqrt_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.cbrt(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      cbrt_r4(x) -> f32, cbrt_r8(x) -> f64, cbrt_re(x) -> f80|f128
 *  
 *  Computes Cube root of x.
 *  
 *  @x: X-axis
 *  @retval: solve of cube root (sum of the power root of x by $\frac{1}{3}$)
 *  
 *  Mathematical Notation:
 *  $x^{\frac{1}{3}}\therefore\sqrt[3]{x}$
 *  
 *  Special behaviors:
 *  adopting algorithm: Okumura System
 *  Domain: $\mathbb{R}$
 *  Pole: $\mathbb{R}$
 *  Co Domain: -Infinity < x < Infinity
 *  Arg is +-Infinity: return +-Infinity
 *  Arg is NaN: return NaN (computational NaN handling)
 */
extern float cbrt_r4(float);
extern double cbrt_r8(double);
extern long double cbrt_re(long double);

/***** Trigonometric Function with its Reciprocal, Related Function *****/
/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.sin(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      sin_r4(x) -> f32, sin_r8(x) -> f64, sin_re(x) -> f80|f128
 *  
 *  Computes Sine of {x}.
 *  
 *  @x: angle given radian
 *  @retval: sine of {x}
 *  
 *  Mathematical Notation:
 *  $\mathrm{sin}(x)$
 *  
 *  Special behaviors:
 *  adopting algorithm: Okumura System, Decomposition Formula
 *  Domain: $\mathbb{R}$
 *  Pole: $\left\{y\in\mathbb{R}:-1\leq{y}\leq{1}\right\}$
 *  Arg is +Infinity: return  1.0
 *  Arg is -Infinity: return -1.0
 *  Arg is NaN: return NaN (context-switching NaN handling)
 */
extern float sin_r4(float);
extern double sin_r8(double);
extern long double sin_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.sinc(x) -> real (r8)
 *    (Native Code)
 *      sinc_r8(x) -> f64
 *  
 *  Computes Sinc function of {x}.
 *  
 *  @x: X-axis
 *  @retval: sinc function of {x}
 *  
 *  Formula:
 *  $\mathit{F}(x)=\frac{\mathrm{sin}(x)}{x}$
 *  
 *  Special behaviors:
 *  Arg is +-Infinity: return 0.0
 *  Arg is NaN: return NaN (context-switching NaN handling)
 */
extern double sinc_r8(double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.cos(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      cos_r4(x) -> f32, cos_r8(x) -> f64, cos_re(x) -> f80|f128
 *  
 *  Computes Cosine of {x}.
 *  
 *  @x: angle given radian
 *  @retval: cosine of {x}
 *  
 *  Mathematical Notation:
 *  $\mathrm{cos}(x)$
 *  
 *  Special behaviors:
 *  adopting algorithm: Okumura System, Decomposition Formula
 *  Domain: $\mathbb{R}$
 *  Pole: $\left\{y\in\mathbb{R}:-1\leq{y}\leq{1}\right\}$
 *  Arg is +Infinity: return  1.0
 *  Arg is -Infinity: return -1.0
 *  Arg is NaN: return NaN (context-switching NaN handling)
 */
extern float cos_r4(float);
extern double cos_r8(double);
extern long double cos_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.cos1(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      cos1_r4(x) -> f32, cos1_r8(x) -> f64, cos1_re(x) -> f80|f128
 *  
 *  Computes 1 - Cosine of {x}. (half-angle formula)
 *  
 *  @x: angle given radian
 *  @retval: 1-cosine of {x}
 *  
 *  Special behaviors:
 *  supports pole: $\mathbb{R}$
 *  pole of primary value: ${0}\leq{x}<{\pi}}$
 *  Arg is +Infinity: return  0.0
 *  Arg is -Infinity: return  2.0
 *  Arg is NaN: return NaN (context-switching NaN handling)
 */
extern float cos1_r4(float);
extern double cos1_r8(double);
extern long double cos1_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.tan(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      tan_r4(x) -> f32, tan_r8(x) -> f64, tan_re(x) -> f80|f128
 *  
 *  Computes Tangent of {x} as angle.
 *  
 *  @x: angle given radian
 *  @retval: tangent of {x}
 *  
 *  Mathematical Notation:
 *  $\mathrm{tan}(x)$
 *  
 *  Special behaviors:
 *  adopting algorithm: Okumura System, Decomposition Formula
 *  Domain: $\left\{x\in\mathbb{R}:\frac{x}{\pi}+\frac{1}{2}\notin\mathbb{Z}\right\}$
 *  Pole: $\mathbb{R}$
 *  If arg is $\pm\frac{pi}{2}$: returning switch sign of {x}, minus is -Infinity, plus is Infinity
 *  Arg is +-Infinity: return Infinity
 *  Arg is NaN: return NaN (context-switching NaN handling)
 */
extern float tan_r4(float);
extern double tan_r8(double);
extern long double tan_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.sec(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      sec_r4(x) -> f32, sec_r8(x) -> f64, sec_re(x) -> f80|f128
 *  
 *  Computes Secant of {x}.
 *  
 *  @x: angle given radian
 *  @retval: secant of {x}
 *  
 *  Mathematical Notation:
 *  $\mathrm{sec}(x)$
 *  
 *  Special behaviors:
 *  adopting algorithm: Okumura System, Decomposition Formula
 *  Domain: $\left\{ x\in\mathbb{R}:\frac{x}{\pi}+\frac{1}{2}\notin\mathbb{Z}\right\}$
 *  Pole: $\left\{ y\in\mathbb{R}:y\le{-1}\vee{y}\ge{1}\right\}$
 *  Arg is +-Infinity: return Infinity
 *  Arg is NaN: return NaN (context-switching NaN handling)
 */
extern float sec_r4(float);
extern double sec_r8(double);
extern long double sec_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.csc(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      csc_r4(x) -> f32, csc_r8(x) -> f64, csc_re(x) -> f80|f128
 *  
 *  Computes Cosecant of {x}.
 *  
 *  @x: angle given radian
 *  @retval: cosecant of {x}
 *  
 *  Mathematical Notation:
 *  $\mathrm{csc}(x)$
 *  
 *  Special behaviors:
 *  adopting algorithm: Okumura System, Decomposition Formula
 *  Domain: $\left\{ x\in\mathbb{R}:\frac{x}{\pi}\notin\mathbb{Z}\right\}$
 *  Pole: $\left\{ y\in\mathbb{R}:y\le{-1}\vee{y}\ge{1}\right\}$
 *  Arg is +-Infinity: return Infinity
 *  Arg is NaN: return NaN (context-switching NaN handling)
 */
extern float csc_r4(float);
extern double csc_r8(double);
extern long double csc_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.cot(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      cot_r4(x) -> f32, cot_r8(x) -> f64, cot_re(x) -> f80|f128
 *  
 *  Computes Cotangent of {x}.
 *  
 *  @x: angle given radian
 *  @retval: cotangent of {x}
 *  
 *  Mathematical Notation:
 *  $\mathrm{cot}(x)$
 *  
 *  Special behaviors:
 *  adopting algorithm: Okumura System, Decomposition Formula
 *  Domain: $\left\{ x\in\mathbb{R}:\frac{x}{\pi}\notin\mathbb{Z}\right\}$
 *  Pole: $\mathbb{R}$
 *  Arg is +-Infinity: return Infinity
 *  Arg is NaN: return NaN (context-switching NaN handling)
 */
extern float cot_r4(float);
extern double cot_r8(double);
extern long double cot_re(long double);

/***** Inverse Trigonometric Function with its Reciprocal, Related Function *****/
/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.asin(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      asin_r4(x) -> f32, asin_r8(x) -> f64, asin_re(x) -> f80|f128
 *  
 *  Computes Arcsine of {x}.
 *  
 *  @x: sine value
 *  @retval: arcsine of {x} in radian, ${\neg\frac{\pi}{2}}\leq{x}\leq{\frac{\pi}{2}}$
 *  
 *  Mathematical Notation:
 *  $\mathrm{sin}^{-1}(x)$
 *  
 *  NOTE:
 *  Inverse circular is complex function. Therefore, the solution is not necessarily a triangular ratio.
 *  
 *  Special behaviors:
 *  adopting algorithm: Okumura System, Decomposition Formula
 *  Domain: $\left\{x\in\mathbb{R}:-1<x<1\right\}$
 *  Pole: $\mathbb{R}$
 *  pole of primary value: ${-1}\leq{a}\leq{1}$, otherwise {x} is in complex plane therefore undefined
 *  Arg is +-Infinity: return NaN
 *  Arg is NaN: return NaN (computational NaN handling)
 */
extern float asin_r4(float);
extern double asin_r8(double);
extern long double asin_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.acos(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      acos_r4(x) -> f32, acos_r8(x) -> f64, acos_re(x) -> f80|f128
 *  
 *  Computes Arccosine of {x}.
 *  
 *  @x: cosine value
 *  @retval: arccosine of {x} in radian, ${{0}\leq{x}\leq{\pi}}$
 *  
 *  Mathematical Notation:
 *  $\mathrm{cos}^{-1}(x)$
 *  
 *  NOTE:
 *  Inverse circular is complex function. Therefore, the solution is not necessarily a triangular ratio.
 *  
 *  Special behaviors:
 *  adopting algorithm: Okumura System, Decomposition Formula
 *  Domain: $\left\{x\in\mathbb{R}:-1\leq{x}\leq{1}\right\}$
 *  Pole: $\left\{y\in\mathbb{R}:0\leq{y}\leq{\pi}\right\}$
 *  Arg is +-Infinity: return NaN
 *  Arg is NaN: return NaN (computational NaN handling)
 */
extern float acos_r4(float);
extern double acos_r8(double);
extern long double acos_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.atan(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      atan_r4(x) -> f32, atan_r8(x) -> f64, atan_re(x) -> f80|f128
 *  
 *  Computes Arctangent of {x}.
 *  
 *  @x: tangent value
 *  @retval: arctangent of {x} in radian
 *  
 *  Mathematical Notation:
 *  $\mathrm{tan}^{-1}(x)$
 *  
 *  Special behaviors:
 *  adopting algorithm: Okumura System, Decomposition Formula
 *  Domain: $\mathbb{R}$
 *  Pole: $\left\{y\in\mathbb{R}:-\frac{\pi}{2}\lt{y}\lt\frac{\pi}{2}\right\}$
 *  Arg is +Infinity: return $\frac{pi}{2}$
 *  Arg is -Infinity: return $\neg\frac{pi}{2}$
 *  Arg is NaN: return NaN (computational NaN handling)
 */
extern float atan_r4(float);
extern double atan_r8(double);
extern long double atan_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.atan2(y, x) -> real (r4/r8/reX)
 *    (Native Code)
 *      atan2_r4(y, x) -> f32, atan2_r8(y, x) -> f64, atan2_re(y, x) -> f80|f128
 *  
 *  Computes Arctangent of {y} and {x}.
 *  This function is a two-variable arctan, but it is often used to solve quadrant.
 *  Because of the behavior targeting quadrants, it may differ from existing regulation.
 *  
 *  @y: tangent value
 *  @x: tangent value
 *  @retval: arctangent of {y} and {x} in radian
 */
extern float atan2_r4(float, float);
extern double atan2_r8(double, double);
extern long double atan2_re(long double, long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.asec(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      asec_r4(x) -> f32, asec_r8(x) -> f64, asec_re(x) -> f80|f128
 *  
 *  Computes Arcsecant of {x}.
 *  
 *  @x: cosecant value
 *  @retval: arcsecant of {x} in radian
 *  
 *  Mathematical Notation:
 *  $\mathrm{sec}^{-1}(x)$
 *  
 *  NOTE:
 *  Inverse circular is complex function. Therefore, the solution is not necessarily a triangular ratio.
 *  
 *  Special behaviors:
 *  adopting algorithm: Okumura System, Decomposition Formula
 *  Domain: $\left\{x\in\mathbb{R}:x\le{-1}\vee{x}\ge{1}\right\}$
 *  Pole: $\left\{ y\in\mathbb{R}:0\le{y}\lt\frac{\pi}{2}\vee\frac{\pi}{2}\lt{y}\le\pi\right\}$
 *  Arg is +-Infinity: return $\frac{\pi}{2}$
 *  Arg is NaN: return NaN (computational NaN handling)
 */
extern float asec_r4(float);
extern double asec_r8(double);
extern long double asec_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.acsc(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      acsc_r4(x) -> f32, acsc_r8(x) -> f64, acsc_re(x) -> f80|f128
 *  
 *  Computes Arccosecant of {x}.
 *  
 *  @x: secant value
 *  @retval: arccosecant of {x} in radian
 *  
 *  Mathematical Notation:
 *  $\mathrm{csc}^{-1}(x)$
 *  
 *  NOTE:
 *  Inverse circular is complex function. Therefore, the solution is not necessarily a triangular ratio.
 *  
 *  Special behaviors:
 *  adopting algorithm: Okumura System, Decomposition Formula
 *  Domain: $\left\{x\in\mathbb{R}:x\le{-1}\vee{x}\ge{1}\right\}$
 *  Pole: $\left\{ y\in\mathbb{R}:-\frac{\pi}{2}\le{y}\lt{0}\vee{0}\lt{y}\le\frac{\pi}{2}\right\}$
 *  Arg is +-Infinity: return 0
 *  Arg is NaN: return NaN (computational NaN handling)
 */
extern float acsc_r4(float);
extern double acsc_r8(double);
extern long double acsc_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.acot(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      acot_r4(x) -> f32, acot_r8(x) -> f64, acot_re(x) -> f80|f128
 *  
 *  Computes Arccotangent of {x}.
 *  
 *  @x: cotangent value
 *  @retval: arccotangent of {x} in radian
 *  
 *  Mathematical Notation:
 *  $\mathrm{tan}^{-1}(x)$
 *  
 *  Special behaviors:
 *  adopting algorithm: Okumura System, Decomposition Formula
 *  Domain: $\mathbb{R}$
 *  Pole: $\left\{y\in\mathbb{R}:-\frac{\pi}{2}\lt{y}\lt{0}\vee{0}\lt{y}\le\frac{\pi}{2}\right\}$
 *  Arg is +Infinity: return $\frac{pi}{2}$
 *  Arg is -Infinity: return $\neg\frac{pi}{2}$
 *  Arg is NaN: return NaN (computational NaN handling)
 */
extern float acot_r4(float);
extern double acot_r8(double);
extern long double acot_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.quadrant(x, y) -> real (r4/r8/reX)
 *    (Native Code)
 *      quadrant_r4(x, y) -> f32, quadrant_r8(x, y) -> f64, quadrant_re(x, y) -> f80|f128
 *  
 *  Computes Quadrant-XY of two arguments {x} and {y}. Solve of unit is a radian.
 *  Note that the purpose is the same as atan2(), but the order of arguments is different.
 *  
 *  Formal method:
 *  $\theta=\tan^{-1}\frac{y}{x}$
 *
 *  @x: quadrant-XY of x
 *  @y: quadrant-XY of y
 *  @retval: solve of quadrant-XY
 *  
 *  Special behaviors:
 *  adopting algorithm: Quadrant(???????????????)
 *  3 Classes exists:
 *  ::complex_argument (switched by zero)
 *  ::quadrant (switched by finite)
 *  ::radian (switched by infinite)
 *  <#complex_argument>
 *  x is zero, y is non-zero: argument (y is negative: $-\pi/2$, positive: $\pi/2$)
 *  x is non-zero, y is zero: absolute (x is negative: $\pi$, positive: $0$)
 *  <#quadrant>
 *  x is positive finite, y is positive finite: 1st quadrant
 *  x is negative finite, y is positive finite: 2nd quadrant
 *  x is negative finite, y is negative finite: 3rd quadrant
 *  x is positive finite, y is negative finite: 4th quadrant
 *  <#radian>
 *  x is +-finite, y is +infinite: (cartesian: 0-degree -> polar: 90-degree)
 *  x is +infinite, y is +infinite: (cartesian: 45-degree -> polar: 45-degree)
 *  x is +infinite, y is +-finite: (cartesian: 90-degree -> polar: 0-degree)
 *  x is +infinite, y is -infinite: (cartesian: 135-degree -> polar: -45-degree)
 *  x is +finite, y is -infinite: (cartesian: 180-degree -> polar: -90-degree)
 *  x is -infinite, y is +infinite: (cartesian: -45-degree -> polar: 135-degree)
 *  x is -infinite, y is +finite: (cartesian: -90-degree -> polar: 180-degree)
 *  x is -infinite, y is -finite: (cartesian: -90-degree -> polar: -180-degree)
 *  x is -infinite, y is -infinite: (cartesian: -135-degree -> polar: -135-degree)
 *  x is -finite, y is -infinite: (caetesian: -180-degree -> polar: -90-degree)
 *  NOTE:
 *  Solve of no-degree as quadrant(0, 0) is undefined in mathematical view, but in gluemath it returns 0.
 */
extern float quadrant_r4(float, float);
extern double quadrant_r8(double, double);
extern long double quadrant_re(long double, long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.hypot(a, b) -> real (r4/r8/reX)
 *    (Native Code)
 *      hypot_r4(a, b) -> f32, hypot_r8(a, b) -> f64, hypot_re(a, b) -> f80|f128
 *  
 *  Computes the length of the hypotenuse of a right triangle.
 *  This function strictly examines whether the two variables have reached a singular point.
 *  It's more subdividing, but generally 0 or +Infinity is sent out.
 *  
 *  Formal method:
 *  $\left\|\left\{x,y\right\}\right\|=\sqrt{x^2+y^2}$
 *  
 *  @a: triangles base
 *  @b: triangles height
 *  @retval: length of the hypotenuse of a right triangle
 *  
 *  Special behaviors:
 *  adopting algorithm: Moler-Morrison
 *  two arguments has NaN: return NaN (context-switching NaN handling)
 *  two arguments has +-Infinity: return +Infinity (without a special reason)
 *  two arguments has 0: return 0 (without a special reason)
 */
extern float hypot_r4(float, float);
extern double hypot_r8(double, double);
extern long double hypot_re(long double, long double);

/***** Hyperbolic Function with its Reciprocal *****/
/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.sinh(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      sinh_r4(x) -> f32, sinh_r8(x) -> f64, sinh_re(x) -> f80|f128
 *  
 *  Computes Hyperbolic Sine of {x}.
 *  
 *  @x: X-axis
 *  @retval: hyperbolic sine of {x}
 *  
 *  Mathematical Notation:
 *  $\mathrm{sinh}(x)$
 *  
 *  Calculation Formula:
 *  $\frac{e^x}{2}-\frac{e^{-x}}{2}$
 *  
 *  NOTE:
 *  Since the numerical computation of hyperbolic functions has a significant error,
 *  the solution should be obtained by the continued fraction expansion.
 *  However, in gluemath, the exponent and logarithm of the algorithm used
 *  internally are accurate, so they are implemented as defined expressions.
 *  
 *  Special behaviors:
 *  adopting algorithm: As defined expression
 *  Domain: $\mathbb{R}$
 *  Pole: $\mathbb{R}$
 *  Arg is +-Infinity: return +-Infinity
 *  Arg is NaN: return NaN (computational NaN handling)
 */
extern float sinh_r4(float);
extern double sinh_r8(double);
extern long double sinh_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.cosh(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      cosh_r4(x) -> f32, cosh_r8(x) -> f64, cosh_re(x) -> f80|f128
 *  
 *  Computes Hyperbolic Cosine of {x}.
 *  
 *  @x: X-axis
 *  @retval: hyperbolic cosine of {x}
 *  
 *  Mathematical Notation:
 *  $\mathrm{cosh}(x)$
 *  
 *  Calculation Formula:
 *  $\frac{e^{-x}}{2}+\frac{e^x}{2}$
 *  
 *  NOTE:
 *  Since the numerical computation of hyperbolic functions has a significant error,
 *  the solution should be obtained by the continued fraction expansion.
 *  However, in gluemath, the exponent and logarithm of the algorithm used
 *  internally are accurate, so they are implemented as defined expressions.
 *  
 *  Special behaviors:
 *  adopting algorithm: As defined expression
 *  Domain: $\mathbb{R}$
 *  Pole: $\left\{y\in\mathbb{R}:y\leq{1}\right\}$
 *  Arg is +-Infinity: return +Infinity
 *  Arg is NaN: return NaN (computational NaN handling)
 */
extern float cosh_r4(float);
extern double cosh_r8(double);
extern long double cosh_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.tanh(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      tanh_r4(x) -> f32, tanh_r8(x) -> f64, tanh_re(x) -> f80|f128
 *  
 *  Computes Hyperbolic Tangent of {x}.
 *  
 *  @x: X-axis
 *  @retval: hyperbolic tangent of {x}
 *  
 *  Mathematical Notation:
 *  $\mathrm{tanh}(x)$
 *  
 *  Calculation Formula:
 *  $\frac{e^x}{e^{-x}+e^x}-\frac{e^{-x}}{e^{-x}+e^x}$
 *  
 *  NOTE:
 *  Since the numerical computation of hyperbolic functions has a significant error,
 *  the solution should be obtained by the continued fraction expansion.
 *  However, in gluemath, the exponent and logarithm of the algorithm used
 *  internally are accurate, so they are implemented as defined expressions.
 *  
 *  Special behaviors:
 *  adopting algorithm: As defined expression
 *  Domain: $\mathbb{R}$
 *  Pole: $\left\{y\in\mathbb{R}:-1<y<1\right\}$
 *  Arg is +Infinity: return  1.0
 *  Arg is -Infinity: return -1.0
 *  Arg is NaN: return NaN (computational NaN handling)
 */
extern float tanh_r4(float);
extern double tanh_r8(double);
extern long double tanh_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.sech(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      sech_r4(x) -> f32, sech_r8(x) -> f64, sech_re(x) -> f80|f128
 *  
 *  Computes Hyperbolic Secant of {x}.
 *  
 *  @x: X-axis
 *  @retval: hyperbolic secant of {x}
 *  
 *  Mathematical Notation:
 *  $\mathrm{sech}(x)$
 *  
 *  Calculation Formula:
 *  $\frac{1}{\mathrm{cosh}(x)}=\frac{2}{e^{-x}+e^x}$
 
 *  NOTE:
 *  Since the numerical computation of hyperbolic functions has a significant error,
 *  the solution should be obtained by the continued fraction expansion.
 *  However, in gluemath, the exponent and logarithm of the algorithm used
 *  internally are accurate, so they are implemented as defined expressions.
 *  
 *  Special behaviors:
 *  adopting algorithm: As defined expression
 *  Domain: $\mathbb{R}$
 *  Pole: $\left\{ y\in\mathbb{R}:0\lt{y}\leq{1}\right\}$
 *  Arg is +-Infinity: return +Infinity
 *  Arg is NaN: return NaN (computational NaN handling)
 */
extern float sech_r4(float);
extern double sech_r8(double);
extern long double sech_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.csch(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      csch_r4(x) -> f32, csch_r8(x) -> f64, csch_re(x) -> f80|f128
 *  
 *  Computes Hyperbolic Cosecant of {x}.
 *  
 *  @x: X-axis
 *  @retval: hyperbolic cosecant of {x}
 *  
 *  Mathematical Notation:
 *  $\mathrm{csch}(x)$
 *  
 *  Calculation Formula:
 *  $\frac{1}{\mathrm{sinh}(x)}=\frac{2}{e^x-e^{-x}}$
 
 *  NOTE:
 *  Since the numerical computation of hyperbolic functions has a significant error,
 *  the solution should be obtained by the continued fraction expansion.
 *  However, in gluemath, the exponent and logarithm of the algorithm used
 *  internally are accurate, so they are implemented as defined expressions.
 *  
 *  Special behaviors:
 *  adopting algorithm: As defined expression
 *  Domain: $\left\{x\in\mathbb{R}:x\neq{0}\right\}$
 *  Pole: $\left\{y\in\mathbb{R}:y\neq{0}\right\}$
 *  Arg is +Infinity: return 0.0
 *  Arg is -Infinity: return -0.0
 *  Arg is NaN: return NaN (context-switching NaN handling)
 */
extern float csch_r4(float);
extern double csch_r8(double);
extern long double csch_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.coth(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      coth_r4(x) -> f32, coth_r8(x) -> f64, coth_re(x) -> f80|f128
 *  
 *  Computes Hyperbolic Cotangent of {x}.
 *  
 *  @x: X-axis
 *  @retval: hyperbolic cotangent of {x}
 *  
 *  Mathematical Notation:
 *  $\mathrm{coth}(x)$
 *  
 *  Calculation Formula:
 *  $\frac{\mathrm{cosh}(x)}{\mathrm{sinh}(x)}=\frac{e^{-x}+e^x}{e^x-e^{-x}}$
 
 *  NOTE:
 *  Since the numerical computation of hyperbolic functions has a significant error,
 *  the solution should be obtained by the continued fraction expansion.
 *  However, in gluemath, the exponent and logarithm of the algorithm used
 *  internally are accurate, so they are implemented as defined expressions.
 *  
 *  Special behaviors:
 *  adopting algorithm: As defined expression
 *  Domain: $\left\{x\in\mathbb{R}:x\neq{0}\right\}$
 *  Pole: $\left\{y\in\mathbb{R}:y\lt{-1}\,\vee\,y\gt{1}\right\}$
 *  Arg is +Infinity: return 1.0
 *  Arg is -Infinity: return -1.0
 *  Arg is NaN: return NaN (context-switching NaN handling)
 */
extern float coth_r4(float);
extern double coth_r8(double);
extern long double coth_re(long double);

/***** Inverse Hyperbolic Function with its Reciprocal *****/
/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.asinh(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      asinh_r4(x) -> f32, asinh_r8(x) -> f64, asinh_re(x) -> f80|f128
 *  
 *  Computes Hyperbolic Arcsine of {x}.
 *  
 *  @x: X-axis
 *  @retval: hyperbolic arcsine of {x}
 *  
 *  Mathematical Notation:
 *  $\mathrm{sinh}^{-1}(x)$
 *  
 *  Calculation Formula:
 *  $\ln(\sqrt{x^2+1}+x)$
 *  
 *  NOTE:
 *  Since the numerical computation of hyperbolic functions has a significant error,
 *  the solution should be obtained by the continued fraction expansion.
 *  However, in gluemath, the exponent and logarithm of the algorithm used
 *  internally are accurate, so they are implemented as defined expressions.
 *  
 *  Special behaviors:
 *  adopting algorithm: As defined expression
 *  Domain: $\mathbb{R}$
 *  Pole: $\mathbb{R}$
 *  Arg is +-Infinity: return +-Infinity
 *  Arg is NaN: return NaN (computational NaN handling)
 */
extern float asinh_r4(float);
extern double asinh_r8(double);
extern long double asinh_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.acosh(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      acosh_r4(x) -> f32, acosh_r8(x) -> f64, acosh_re(x) -> f80|f128
 *  
 *  Computes Hyperbolic Arccosine of {x}.
 *  
 *  @x: X-axis
 *  @retval: hyperbolic arccosine of {x}
 *  
 *  Mathematical Notation:
 *  $\mathrm{cosh}^{-1}(x)$
 *  
 *  Calculation Formula:
 *  $\ln(x+\sqrt{x-1}\sqrt{x+1})$
 *  
 *  NOTE:
 *  Since the numerical computation of hyperbolic functions has a significant error,
 *  the solution should be obtained by the continued fraction expansion.
 *  However, in gluemath, the exponent and logarithm of the algorithm used
 *  internally are accurate, so they are implemented as defined expressions.
 *  
 *  Special behaviors:
 *  adopting algorithm: As defined expression (Hyperbolic Arcsecant Reciprocal)
 *  Domain: $\left\{x\in\mathbb{R}:x\geq{1}\right\}$
 *  Pole: $\left\{y\in\mathbb{R}:y\geq{0}\right\}$
 *  Arg is +Infinity: return Infinity
 *  Arg is -Infinity: return NaN
 *  Arg is NaN: return NaN (computational NaN handling)
 */
extern float acosh_r4(float);
extern double acosh_r8(double);
extern long double acosh_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.atanh(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      atanh_r4(x) -> f32, atanh_r8(x) -> f64, atanh_re(x) -> f80|f128
 *  
 *  Computes Hyperbolic Arctangent of {x}.
 *  
 *  @x: X-axis
 *  @retval: hyperbolic arctangent of {x}
 *  
 *  Mathematical Notation:
 *  $\mathrm{tanh}^{-1}(x)$
 *  
 *  Calculation Formula:
 *  $\frac{1}{2}\ln(x+1)-\frac{1}{2}\ln(1-x)$
 *  
 *  NOTE:
 *  Since the numerical computation of hyperbolic functions has a significant error,
 *  the solution should be obtained by the continued fraction expansion.
 *  However, in gluemath, the exponent and logarithm of the algorithm used
 *  internally are accurate, so they are implemented as defined expressions.
 *  
 *  Special behaviors:
 *  adopting algorithm: As defined expression
 *  Domain: $\left\{x\in \mathbb{R}:-1<x<1\right\}$
 *  Pole: $\mathbb{R}$
 *  Arg is +-Infinity: return NaN
 *  Arg is NaN: return NaN (computational NaN handling)
 */
extern float atanh_r4(float);
extern double atanh_r8(double);
extern long double atanh_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.asech(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      asech_r4(x) -> f32, asech_r8(x) -> f64, asech_re(x) -> f80|f128
 *  
 *  Computes Hyperbolic Arcsecant of {x}.
 *  
 *  @x: X-axis
 *  @retval: hyperbolic arcsecant of {x}
 *  
 *  Mathematical Notation:
 *  $\mathrm{sech}^{-1}(x)$
 *  
 *  Calculation Formula:
 *  $\mathrm{cosh}^{-1}(\frac{1}{x})$
 *  
 *  NOTE:
 *  Since the numerical computation of hyperbolic functions has a significant error,
 *  the solution should be obtained by the continued fraction expansion.
 *  However, in gluemath, the exponent and logarithm of the algorithm used
 *  internally are accurate, so they are implemented as defined expressions.
 *  
 *  Special behaviors:
 *  adopting algorithm: As defined expression
 *  Domain: $\left\{x\in\mathbb{R}:0\lt{x}\le{1}\right\}$
 *  Pole: $\left\{y\in\mathbb{R}:y\geq{0}\right\}$
 *  Arg is +Infinity: return Infinity
 *  Arg is -Infinity: return NaN
 *  Arg is NaN: return NaN (computational NaN handling)
 */
extern float asech_r4(float);
extern double asech_r8(double);
extern long double asech_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.acsch(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      acsch_r4(x) -> f32, acsch_r8(x) -> f64, acsch_re(x) -> f80|f128
 *  
 *  Computes Hyperbolic Arccosecant of {x}.
 *  
 *  @x: X-axis
 *  @retval: hyperbolic arccosecant of {x}
 *  
 *  Mathematical Notation:
 *  $\mathrm{csch}^{-1}(x)$
 *  
 *  Calculation Formula:
 *  $\mathrm{sinh}^{-1}(\frac{1}{x})$
 *  
 *  NOTE:
 *  Since the numerical computation of hyperbolic functions has a significant error,
 *  the solution should be obtained by the continued fraction expansion.
 *  However, in gluemath, the exponent and logarithm of the algorithm used
 *  internally are accurate, so they are implemented as defined expressions.
 *  
 *  Special behaviors:
 *  adopting algorithm: As defined expression
 *  Domain: $\left\{x\in\mathbb{R}:x\neq{0}\right\}$
 *  Pole: $\left\{y\in\mathbb{R}:y\neq{0}\right\}$
 *  Arg is +-Infinity: return 0.0
 *  Arg is NaN: return NaN (computational NaN handling)
 */
extern float acsch_r4(float);
extern double acsch_r8(double);
extern long double acsch_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.acoth(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      acoth_r4(x) -> f32, acoth_r8(x) -> f64, acoth_re(x) -> f80|f128
 *  
 *  Computes Hyperbolic Arccotangent of {x}.
 *  
 *  @x: X-axis
 *  @retval: hyperbolic arccotangent of {x}
 *  
 *  Mathematical Notation:
 *  $\mathrm{coth}^{-1}(x)$
 *  
 *  Calculation Formula:
 *  $\mathrm{tanh}^{-1}(\frac{1}{x})$
 *  
 *  NOTE:
 *  Since the numerical computation of hyperbolic functions has a significant error,
 *  the solution should be obtained by the continued fraction expansion.
 *  However, in gluemath, the exponent and logarithm of the algorithm used
 *  internally are accurate, so they are implemented as defined expressions.
 *  
 *  Special behaviors:
 *  adopting algorithm: As defined expression
 *  Domain: $\left\{ x\in\mathbb{R}:x\lt{-1}\,\vee\,x\gt{1}\right\}$
 *  Pole: $\left\{y\in\mathbb{R}:y\neq{0}\right\}$
 *  Arg is +-Infinity: return 0.0
 *  Arg is NaN: return NaN (computational NaN handling)
 */
extern float acoth_r4(float);
extern double acoth_r8(double);
extern long double acoth_re(long double);

/***** FP Manipulation Function ****/
/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.frexp(x) -> [real (r4/r8/reX), int] *associated array
 *    (Native Code)
 *      frexp_r4(x, *exp) -> f32, frexp_r8(x, *exp) -> f64, frexp_re(x, *exp) -> f80 | f128
 *  
 *  Decomposes the exponent and fraction of {x}, then return array of each element.
 *  On the native code, writes the exponent as the second argument, and returns the fraction.
 *  From the idea of the exponential decomposition formula, the exponent is incremented and
 *  fraction is normalized by 1/2.
 *  This is an implementation for compatible and is actually simulated in RCM.
 *  We recommend the use of RCM, which is included in the compatibility for language standards.
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
extern float frexp_r4(float, int*);
extern double frexp_r8(double, int*);
extern long double frexp_re(long double, int*);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.ldexp(x, exp) -> real (r4/r8/reX)
 *    (Native Code)
 *      ldexp_r4(x, exp) -> f32, ldexp_r8(x, exp) -> f64, ldexp_re(x, exp) -> f80 | f128
 *  
 *  Computes load exponent i.e. the {exp}-power of {x} by 2.
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
extern float ldexp_r4(float, int);
extern double ldexp_r8(double, int);
extern long double ldexp_re(long double, int);


extern float modf_r4(float, float*);
extern double modf_r8(double, double*);
extern long double modf_re(long double, long double*);


/***** Special Function *****/
/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.erf(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      erf_r4(x) -> f32, erf_r8(x) -> f64, erf_re(x) -> f80|f128
 *  
 *  Computes {x} of gaussian error function.
 *  The concept of the normal distribution was founded by A. de Moivre as the limit of the binomial distribution.
 *  However, the integral of the obtained part cannot be reduced by the elementary function.
 *  This integral is at evaluating the error of astronomical observations for C. F. Gauss,
 *  he used the least squares as known with A. M. Legendre, this name was established.
 *  The actual normal distribution was discovered by extending this error function.
 *  
 *  @x: complex plane of z
 *  @retval: solve of error function
 *  
 *  Calculation Formula:
 *  $\mathrm{erf}(z)=\frac{2}{\sqrt{\pi}}\int_{0}^{z}e^{\neg{t^{2}}}dt$
 *  
 *  Special behaviors:
 *  Co Domain: -Infinity <= z <= Infinity
 *  Arg is Infinity: return 1.0
 *  Arg is -Infinity: return -1.0
 *  Arg is NaN: return NaN (computational NaN handling)
 */
extern float erf_r4(float);
extern double erf_r8(double);
extern long double erf_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.erfc(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      erfc_r4(x) -> f32, erfc_r8(x) -> f64, erfc_re(x) -> f80|f128
 *  
 *  Computes {x} of gaussian complementary error function.
 *  It is essentially the same as the error function, but has some deformation.
 *  
 *  @x: complex plane of z
 *  @retval: solve of error function
 *  
 *  Calculation Formula:
 *  $\mathrm{erfc}(z)=\frac{2}{\sqrt{\pi}}\int_{z}^{\infty}e^{\neg{t^{2}}}dt$
 *  
 *  Special behaviors:
 *  Co Domain: -Infinity <= z <= Infinity
 *  Arg is Infinity: return 0.0
 *  Arg is -Infinity: return 2.0
 *  Arg is NaN: return NaN (computational NaN handling)
 */
extern float erfc_r4(float);
extern double erfc_r8(double);
extern long double erfc_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.erfinv(x) -> real (r8)
 *    (Native Code)
 *      erfinv_r8(x) -> f64
 * 
 *  Computes {x} of error function by {q}.
 *  
 *  @q .. quantile, domain: -1.0 <= q <= 1.0
 *  @retval .. solve of inverse error function
 *  
 *  Special behaviors:
 *  {q} is out of domain: return NaN
 *  {q} is +-Infinity: return NaN
 *  {q} is NaN: return NaN (computational NaN handling)
 */
extern double erfinv_r8(double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.erfcinv(x) -> real (r8)
 *    (Native Code)
 *      erfcinv_r8(x) -> f64
 * 
 *  Computes {x} of complementary error function by {q}.
 *  
 *  @q .. quantile, domain: 0.0 <= q <= 2.0
 *  @retval .. solve of inverse complementary error function
 *  
 *  Special behaviors:
 *  {q} is out of domain: return NaN
 *  {q} is +-Infinity: return NaN
 *  {q} is NaN: return NaN (computational NaN handling)
 */
extern double erfcinv_r8(double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.lgamma(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      lgamma_r4(x) -> f32, lgamma_r8(x) -> f64, lgamma_re(x) -> f80|f128
 *  
 *  Computes logarithm of gamma function of x.
 *  It is not strictly a standard library of C.
 *  Originally discovered from integer theory and complex numbers as gamma
 *  functions may have been too early to be a POSIX library of C
 *  because it goes back and forth between infinity and negative solutions
 *  and has values that would not normally be captured by numerical calculation
 *  standards.
 *  
 *  @x: complex plane of z
 *  @retval: solve of logarithm of gamma function without imaginary number
 *  
 *  Special behaviors:
 *  (Based on POSIX)
 *  Arg is negative: (implementary dependent)
 *  Arg is Infinity: return Infinity
 *  Arg is -Infinity: return NaN (undefined)
 *  Arg is NaN: return NaN (context-switching NaN handling)
 *  
 *  Note:
 *  Originally this function is a complex factorial, but, since it is frequently
 *  used not only in complex analysis, so also in statistics,
 *
 *    For Python:
 *      rmath.lgamma(real) -> complex
 *    For Ruby:
 *      Rmath.lgamma(Float) -> Complex
 *  
 *  And than
 *  
 *    For Python:
 *      rmath.lgamma(real) -> real
 *    For Ruby:
 *      Rmath.lgamma(Float) -> Float
 *  
 *  So it is better to match the type of the argument.
 */
extern float lgamma_r4(float);
extern double lgamma_r8(double);
extern long double lgamma_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.gamma(x) -> real (r4/r8/reX)
 *    (Native Code)
 *      gamma_r4(x) -> f32, gamma_r8(x) -> f64, gamma_re(x) -> f80|f128
 *  
 *  Computes gamma function of x.
 *  The name of the "gamma function" known today is the definition of Legendre
 *  as a generalization of factorials, so many people mention the "Euler integral-
 *  the Second Kind" discovered by L. Euler. (The first kind is "Beta Function")
 *  The integral formulation
 *  $\begin{matrix}
 *   \Gamma(z)=\int_{0}^{\infty}e^{\neg{t}}t^{z\neg{1}}dt & (\Re(z)>0) \\
 *   \end{matrix}$
 *  It can be said that this is a Gamma function without imaginary roots of
 *  the complex factorial.
 *  
 *  @x: complex plane of z
 *  @retval: solve of gamma function without imaginary number
 *  
 *  Special behaviors:
 *  (Based on POSIX)
 *  Arg is negative: (implementary dependent)
 *  Arg is Infinity: return Infinity
 *  Arg is -Infinity: return NaN (undefined)
 *  Arg is NaN: return NaN (context-switching NaN handling)
 */
extern float gamma_r4(float);
extern double gamma_r8(double);
extern long double gamma_re(long double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.lbeta(a, b) -> real (r8)
 *    (Native Code)
 *      lbeta_r8(a, b) -> real (r8)
 *
 *  Computes the Logarithm of Beta function of {a} and {b}.
 *  The definition formula is $\ln(\mathrm{B}(a,b))$, but it is calculated directly.
 *  
 *  The Euler beta function (Euler integral the 1st kind) is a matrix factorial 
 *  and a multivalent of the complex integral. It is unknown what kind of mapping
 *  this integral has.
 *  Negative {x} makes the analytic continuation much more complicate than the Euler-
 *  gamma function.
 *  
 *    ----
 *    RMath.beta(2, -0.5) #=> -4
 *    
 *    RMath.lbeta(2, -0.5) #=> 1.38629436111989
 *    RMath.lbeta(2+0i, -0.5) #=> (1.38629436111989+3.14159265358979i)
 *    
 *    RMath.exp(RMath.lbeta(2, -0.5)) #=> 4
 *    RMath.exp(RMath.lbeta(2+0i, -0.5)) #=> -4
 *    ----
 *
 *  @a .. factorial (general)
 *  @b .. factorial (determinant)
 *  @retval .. solve of logarithm of beta function
 */
extern double lbeta_r8(double, double);
extern double lbeta_r_r8(double, double, int*);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.beta(a, b) -> real (r8)
 *    (Native Code)
 *      beta_r8(a, b) -> real (r8)
 *
 *  Computes the Beta function of {a} and {b}. (Euler Integral the 1st kind)
 *  
 *  @a .. factorial (general)
 *  @b .. factorial (determinant)
 *  @retval .. solve of beta function
 */
extern double beta_r8(double, double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.riemann_zeta(s) -> real (r8)
 *    (Native Code)
 *      riemann_zeta_r8(s) -> real (r8)
 *  
 *  Computes the Riemann zeta function of {s}.
 *  This function is of vital importance in the history of mathematics.
 *  In the first place, the zeta function refers to a huge number of special functions,
 *  and among them, the one related to the ring of integers is the Riemann zeta function.
 *  It was L. Euler who discovered it, but B. Riemann extended it to complex numbers.
 *  
 *  @s .. complex plane of {s}
 *  @retval .. solve of riemann zeta function
 *  
 *  Special behaviors:
 *  {s} is of the even negative integers: 0.0 (so called the trivial zeros)
 *    Although it can be derived by functional equation, the sign value is inverted.
 *    Therefore, it is corrected with a context switch.
 */
extern double riemann_zeta_r8(double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.j0(x) -> real (r8)
 *      RMath.j1(x) -> real (r8)
 *      RMath.jn(n, x) -> real (r8)
 *    (Native Code)
 *    :: 0th
 *      j0_r8(x) -> real (r8)
 *    :: 1st
 *      j1_r8(x) -> real (r8)
 *    :: nth integer
 *      jn_r8(n, x) -> real (r8)
 *  
 *  Computes the Bessel Function the 1st kind of {x}.
 *  
 *  @n .. order (finite order that is important when it comes to integers)
 *  @x .. X-axis
 *  @retval .. solve of bessel function the 1st kind
 *  
 *  NOTE:
 *    Integer nth the farther away from 0, the more out-of-range the principal value and slower the process;
 *    The effective range is -24 <= n <=24 at best.
 */
extern double j0_r8(double);
extern double j1_r8(double);
extern double jn_r8(int, double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.y0(x) -> real (r8)
 *      RMath.y1(x) -> real (r8)
 *      RMath.yn(n, x) -> real (r8)
 *    (Native Code)
 *    :: 0th
 *      y0_r8(x) -> real (r8)
 *    :: 1st
 *      y1_r8(x) -> real (r8)
 *    :: nth integer
 *      yn_r8(n, x) -> real (r8)
 *  
 *  Computes the Bessel Function the 2nd kind of {x}.
 *  
 *  @n .. order (finite order that is important when it comes to integers)
 *  @x .. X-axis
 *  @retval .. solve of bessel function the 2nd kind
 *  
 *  NOTE:
 *    Integer nth the farther away from 0, the more out-of-range the principal value and slower the process;
 *    The effective range is -24 <= n <=24 at best.
 */
extern double y0_r8(double);
extern double y1_r8(double);
extern double yn_r8(int, double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.i0(x) -> real (r8)
 *      RMath.i1(x) -> real (r8)
 *      RMath.in(n, x) -> real (r8)
 *    (Native Code)
 *    :: 0th
 *      i0_r8(x) -> real (r8)
 *    :: 1st
 *      i1_r8(x) -> real (r8)
 *    :: nth integer
 *      in_r8(n, x) -> real (r8)
 *  
 *  Computes the Modified Bessel Function the 1st kind of {x}.
 *  
 *  @n .. order (finite order that is important when it comes to integers)
 *  @x .. X-axis
 *  @retval .. solve of modified bessel function the 1st kind
 *  
 *  NOTE:
 *    Integer nth the farther away from 0, the more out-of-range the principal value and slower the process;
 *    The effective range is -24 <= n <=24 at best.
 */
extern double i0_r8(double);
extern double i1_r8(double);
extern double in_r8(int, double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.k0(x) -> real (r8)
 *      RMath.k1(x) -> real (r8)
 *      RMath.kn(n, x) -> real (r8)
 *    (Native Code)
 *    :: 0th
 *      k0_r8(x) -> real (r8)
 *    :: 1st
 *      k1_r8(x) -> real (r8)
 *    :: nth integer
 *      kn_r8(n, x) -> real (r8)
 *  
 *  Computes the Modified Bessel Function the 2nd kind of {x}.
 *  
 *  @n .. order (finite order that is important when it comes to integers)
 *  @x .. X-axis
 *  @retval .. solve of modified bessel function the 2nd kind
 *  
 *  NOTE:
 *    Integer nth the farther away from 0, the more out-of-range the principal value and slower the process;
 *    The effective range is -24 <= n <=24 at best.
 */
extern double k0_r8(double);
extern double k1_r8(double);
extern double kn_r8(int, double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.ei(x) -> real (r8)
 *    (Native Code)
 *      ei_r8(x) -> real (r8)
 *
 *  Computes the Exponential Integral of {x}.
 *  This function, which uses integrals in the infinite product of the exponent as a variable,
 *  is closely related to euler integrals, which are also the bounds of the exponent.
 *  
 *  @x .. complex plane of z
 *  @retval .. solve of exponential integral
 *  
 *  Special behaviors:
 *  Arg is Infinity: return Infinity
 *  Arg is -Infinity: return 0.0
 *  Arg is NaN: return NaN (context-switching NaN handling)
 */
extern double ei_r8(double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.li(x) -> real (r8)
 *    (Native Code)
 *      li_r8(x) -> real (r8)
 *
 *  Computes the Logarithmic Integral of {x}.
 *  This function is equivalent to: $Ei(ln(z))$
 *  
 *  @x .. complex plane of z
 *  @retval .. solve of logarithmic integral
 *  
 *  Special behaviors:
 *  Arg is negative: computational returning NaN (solve is in complex plane so undefined)
 *  Arg is Infinity: return Infinity
 *  Arg is -Infinity: return NaN (undefined)
 *  Arg is NaN: return NaN (computational NaN handling)
 */
extern double li_r8(double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.si(x) -> real (r8)
 *    (Native Code)
 *      si_r8(x) -> real (r8)
 *
 *  Computes the Sine Integral of {x}.
 *  
 *  @x .. complex plane of z
 *  @retval .. solve of sine integral
 */
extern double si_r8(double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.ci(x) -> real (r8)
 *    (Native Code)
 *      ci_r8(x) -> real (r8)
 *
 *  Computes the Cosine Integral of {x}.
 *  
 *  @x .. complex plane of z
 *  @retval .. solve of cosine integral
 */
extern double ci_r8(double);

/**** Euler Integral Functions Extension ****/

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.gamma(a, x, kind: 2, regular: true) -> real (r8)
 *      (Multiplex Overload)
 *    (Native Code)
 *    :: regularized, 1st
 *      gammaincr1(a, x) -> real (r8)
 *    :: regularized, 2nd
 *      gammaincr2(a, x) -> real (r8)
 *    :: incomplete, 1st
 *      gammainc1(a, x) -> real (r8)
 *    :: incomplete, 2nd
 *      gammainc2(a, x) -> real (r8)
 *  
 *  Computes the incomplete gamma function of {a} and {x}.
 *  This is a normalized variant that is easy to use for numerical analysis.
 *  It is a complex quantity function, and if {a} is a natural number other than 0,
 *  the negative {x} should also be determined for a solution, but it is designed to return NaN.
 *  
 *  @a .. factorial of prime
 *  @x .. limits of integral as 1st: 0 -> x, 2nd: x -> infinity
 *  @kind: .. Kind (keyword argument). 1 or 2. Default: 2
 *  @regular: .. Regularized or Non-regularized(keyword argument). Boolean. Default: true (Regularized)
 *  @retval .. solve of incomplete gamma integrals (but complex solve sends out NaN)
 *  
 *  Special behaviors:
 *  gammaincr1: supports the 1st kind
 *  gammaincr2: supports the 2nd kind
 *  The basic behavior follows the generalized incomplete gamma function.
 */
extern double gammaincr1_r8(double, double);
extern double gammaincr2_r8(double, double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.gamma(a, x0, x1, regular: true) -> real (r8)
 *      (Multiplex Overload)
 *    (Native Code)
 *    :: regularized
 *      gammaincrg(a, x0, x1) -> real (r8)
 *    :: generalized
 *      gammaincg(a, x0, x1) -> real (r8)
 *  
 *  Computes the generalized incomplete gamma function of {a} and {x0}, {x1}.
 *  Unlike p-adically field, this ABI calculates the real solution steadily.
 *  (Regularization does not necessarily solve between 0 and 1)
 *  
 *  @a .. factorial of prime
 *  @x0 .. lower limits of integral
 *  @x1 .. upper limits of integral
 *  @regular: .. Regularized or Non-regularized(keyword argument). Boolean. Default: true (Regularized)
 *  @retval .. solve of incomplete gamma integrals (but complex solve sends out NaN)
 *  
 *  Special behaviors:
 *  nonregular as limits of integral $\int_{x0}^{x1}$ of:
 *    $\int_0^\infty$: equivalent to (complete) gamma function, $a \ge 0$, (negative a always sends out Infinity)
 *    $\int_{-\infty}^0$: equivalent to (complete) gamma function, $a \le 0$ (positive a always sends out 0.0)
 *    $\int_{-\infty}^\infty$: equivalent to (complete) gamma function, $a \in \mathbb{R}$
 *    $\int_0^{\mathbb{R}}$: equivalent to incomplete gamma function the 1st kind
 *    $\int_{\mathbb{R}^\infty$: equivalent to incomplete gamma function the 2nd kind
 *  secondary behavior:
 *  {a} is NaN: always return NaN
 *  {a} is branch in (-Infinity, 0]: continuation as 'infinitely' ideal class field
 *  {a} is branch in [0, +Infinity): continuation as ideal class field
 */

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.beta(x, a, b, regular: true) -> real (r8)
 *      (Multiplex Overload)
 *    (Native Code)
 *    :: regularized
 *      betaincr(x, a, b) -> real (r8)
 *    :: incomplete
 *      betainc(x, a, b) -> real (r8)
 *
 *  Computes the Incomplete beta function of {x}, {a} and {b}.
 *  An incomplete beta function is basically a complex function,
 *  so it is internally calculated as a complex number.
 *  If an imaginary number does not appear, return the real number, and if it appears, return NaN.
 *  Although it is not very useful except for the domain "0 <= x <= 1" which is the principal value,
 *  it is prepared for analytic continuation.
 *  
 *  @x .. upper limits of integral as 0 -> x
 *  @a .. factorial (general)
 *  @b .. factorial (determinant)
 *  @regular: .. Regularized or Non-regularized(keyword argument). Boolean. Default: true (Regularized)
 *  @retval .. solve of incomplete beta function (but complex solve sends out NaN)
 */

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.gamma_p(a, x) -> real (r8)
 *      RMath.gamma_q(a, x) -> real (r8)
 *    (Native Code)
 *    :: p-adic
 *      p_gamma_r8(a, x) -> real (r8)
 *    :: q-analog
 *      q_gamma_r8(a, x) -> real (r8)
 *  
 *  Computes the p-adic gamma function of {a} and {x}. The infinite multivalence analysis function.
 *  The deform of regularized incomplete gamma function.
 *  It is prepared for numerical analysis. If it cannot converge, returns NaN.
 *  
 *  @a .. normalized factorial of prime
 *  @x .. limits of integral
 *  @retval .. solve of gamma function both of p-adic or q-analog
 *  
 *  Special behaviors:
 *  p_gamma: p-adic
 *  q_gamma: q-analog
 *  cannot convergence's mechanism:
 *    The arguments are always out of the calculation range or given nonnumeric or infinite.
 *  
 *  NOTE:
 *  The p-adic special function is defined by Y. Morita (1975) in a positive way. His Gamma function is $\Gamma_p(s)$.
 *  The p-adically field refers to the extraction of the regular rules of these function,
 *  so there are a huge number even if it is said that the p-adic gamma function in a word.
 *  Among them, the generalized one is the gamma star function $\Gamma^\ast(s)$.
 */
extern double p_gamma_r8(double, double);
extern double q_gamma_r8(double, double);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.gamma_p(a, x0, x1) -> real (r8)
 *      RMath.gamma_q(a, x0, x1) -> real (r8)
 *      (Multiplex Overload)
 *    (Native Code)
 *    :: p-adic
 *      p_gammag_r8(a, x0, x1) -> real (r8)
 *    :: q-analog
 *      q_gammag_r8(a, x0, x1) -> real (r8)
 *  
 *  Computes the p-adic gamma function of {a}, {x0} and {x1}.
 *  This function is equivalent to the regularized generalized incomplete gamma function, but extracts only the principal value.
 *  Otherwise, it sends out 0 or 1, or NaN. This function should be used for statistical accumulation.
 *  
 *  @a .. normalized factorial of prime
 *  @x0 .. lower limits of integral
 *  @x1 .. upper limits of integral
 *  @retval .. solve of gamma function both of p-adic or q-analog
 */

/*
 *  call-seq:
 *    (UserLevel Code)
 *      RMath.beta_p(x, a, b) -> real (r8)
 *      RMath.beta_q(x, a, b) -> real (r8)
 *    (Native Code)
 *    :: p-adic
 *      p_beta_r8(x, a, b) -> real (r8)
 *    :: q-analog
 *      q_beta_r8(x, a, b) -> real (r8)
 *  
 *  Computes the p-adic beta function of {x}, {a} and {b}. The infinite multivalence analysis function.
 *  The deform of regularized incomplete beta function.
 *  It is prepared for numerical analysis. If it cannot converge, returns NaN.
 *  
 *  @x .. upper limits of integral, $\int_0^x$
 *  @a .. normalized factorial (general)
 *  @b .. normalized factorial (determinant)
 *  @retval .. solve of beta function both of p-adic or q-analog
 *  
 *  Special behaviors:
 *  p_beta: p-adic
 *  q_beta: q-analog
 *  cannot convergence's mechanism:
 *    The arguments are always out of the calculation range or given nonnumeric or infinite.
 */
extern double p_beta_r8(double, double, double);
extern double q_beta_r8(double, double, double);

#if defined(__cplusplus)
}
#endif

#endif /* GLUEMATH_REALMATH_H */
