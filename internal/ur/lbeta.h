/*******************************************************************************
	GLUE Math Library: Logarithm of Beta Function

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_LBETA_DBL_INTERNAL
#define GML_LBETA_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: fmod, lgamma, log, pow
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "fmod.h"
#include "lgamma.h"
#include "log.h"
#include "pow.h"
#include "log1p.h"
#include "round.h"

// Declare prototypes of subroutine
static inline double ur_logbeta_r(double, double, int*);
static inline double lbeta_r_nega(double, double, int*);
static inline double lbeta_r_inta_pos(double, double);
static inline double lbeta_r_inta_neg(double, double, int*);
static inline double lbeta_r_inta8_form(int, double);
static inline double lbeta_r_binom_pos(double, double);
static inline double lbeta_r_binom_neg(double, double, int*);
static inline double lbeta_negbetabinom(double, double, int*);
static inline double lbeta_algdiv(double, double);

static inline double
lbeta_core(double a, double b)
{
	int signp = 1;
	return ur_logbeta_r(a, b, &signp);
}

static inline double
ur_logbeta_r(double a, double b, int *signp)
{
	double y;
	int attr = 0x0;
	*signp = 1;
	/*
	 * Classifying attributes
	 * 0x00 ... NULL
	 * 0x01 ... b := Infinite
	 * 0x02 ... b := Finite
	 * 0x04 ... b := IntegerPart
	 * 0x08 ... b has sign
	 * 0x10 ... a := Infinite
	 * 0x20 ... a := Finite
	 * 0x40 ... a := IntegerPart
	 * 0x80 ... a has sign
	 */
	switch (fpclassify(y = fmod_core(b, 1))) {
	case FP_NAN:
	case FP_INFINITE:
		if (isinf(b))
		{
			attr |= 0x01; // Infinite
			if (b < 0)  attr |= 0x08;
		}
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		b = round_core(b);
//		if (b == 0)  return HUGE_VAL; // ComplexInfinity
		attr |= 0x04; // IntegerPart
		if (b < 0)  attr |= 0x08;
		break;
	default:
		attr |= 0x02; // Finite
		if (b < 0)  attr |= 0x08;
		break;
	}
	switch (fpclassify(y = fmod_core(a, 1))) {
	case FP_NAN:
	case FP_INFINITE:
		if (isinf(a))
		{
			attr |= 0x10; // Infinite
			if (a < 0)  attr |= 0x80;
		}
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		a = round_core(a);
//		if (a == 0)  return HUGE_VAL; // ComplexInfinity
		attr |= 0x40; // IntegerPart
		if (a < 0)  attr |= 0x80;
		break;
	default:
		attr |= 0x20; // Finite
		if (a < 0)  attr |= 0x80;
		break;
	}
	/* ContextSwitch of attribute */
	// Row attribute (argument b):
	// 0x01: +Infinite
	// 0x02: +Finite
	// 0x04: +IntegerPart
	// 0x09: -Infinite
	// 0x0A: -Finite
	// 0x0C: -IntegerPart
	// Column attribute (argument a):
	// 0x10: +Infinite
	// 0x20: +Finite
	// 0x40: +IntegerPart
	// 0x90: -Infinite
	// 0xA0: -Finite
	// 0xC0: -IntegerPart

	/* MatrixSwitching */
	switch (attr) {
	// ---- Infinite vectorize ----
	// 0x11: logB(+Infinity, +Infinity) = [-Infinity, +1]
	case 0x11:
		return -HUGE_VAL;
		break;
	// 0x12: logB(+Infinity, +Finite) = [-Infinity, +1]
	case 0x12:
		return -HUGE_VAL;
		break;
	// 0x14: logB(+Infinity, +IntegerPart) = [-Infinity, +1]
	case 0x14:
		return (int)b == 0 ? HUGE_VAL : -HUGE_VAL;
		break;
	// 0x19: logB(+Infinity, -Infinity) = [NaN, -1] (Undefined)
	case 0x19:
		*signp = -1;
		return NAN;
		break;
	// 0x1A: logB(+Infinity, -Finite) =
	//        Infinity, sign: |b| is even: +1, odd: -1
	case 0x1A:
		if ((int)fmod_core(b, 2) == 1)
			*signp = -1;
		return HUGE_VAL;
		break;
	// 0x1C: logB(+Infinity, -IntegerPart) = [NaN, -1]
	case 0x1C:
		if ((int)b == 0)  return HUGE_VAL;
		*signp = -1;
		return NAN;
		break;
	// ---- Finite vectorize ----
	// 0x21: logB(+Finite, +Infinite) = equality to 0x12
	case 0x21:
		return -HUGE_VAL;
		break;
	// 0x22: logB(+Finite, +Finite) = 
	//       [loggamma(a)+loggamma(b)-loggamma(a+b), +1]
	case 0x22:
		if (isinf(y = lgamma_core(a + b)))  return -HUGE_VAL;
		return lgamma_core(a) + lgamma_core(b) - y;
		break;
	// 0x24: logB(+Finite+, +IntegerPart) = equality to 0x42 (swap a and b)
	case 0x24:
		return lbeta_r_inta_pos(b, a);
		break;
	// 0x29: logB(+Finite, -Infinite) = equality to 0x92
	case 0x29:
		return HUGE_VAL;
		break;
	// 0x2A: logB(+Finite, -Finite) = equality to 0xA2
	case 0x2A:
		return lbeta_r_nega(b, a, signp);
		break;
	// 0x2C: logB(+Finite, -IntegerPart) = [Infinity, +1]  (injectivity to positive infinity)
	case 0x2C:
		return HUGE_VAL;
		break;
	// ---- IntegerPart vectorize ----
	// 0x41: logB(+IntegerPart, +Infinite) = equality to 0x14
	case 0x41:
		return (int)a == 0 ? HUGE_VAL : -HUGE_VAL;
		break;
	// 0x42: logB(+IntegerPart, +Finite) = 
	//       [log((a - 1)!)+loggamma(b)-loggamma(a+b), +1]
	case 0x42:
		return lbeta_r_inta_pos(a, b);
		break;
	// 0x44: logB(+IntegerPart, +IntegerPart) = calculate BetaBinomial (positive)
	case 0x44:
		return lbeta_r_binom_pos(a, b);
		break;
	// 0x49: logB(+IntegerPart, -Infinite) = equality to 0x94 (swap a and b)
	case 0x49:
		if ((int)a == 0)  return HUGE_VAL;
		else if ((int)fmod_core(a, 2) == 1)
			*signp = -1;
		return -HUGE_VAL;
		break;
	// 0x4A: logB(+IntegerPart, -Finite) =
	//       [log((a - 1)!)+loggamma(b)-loggamma(a+b), (-1 or 1)]
	case 0x4A:
		return lbeta_r_inta_neg(a, b, signp);
		break;
	// 0x4C: logB(+IntegerPart, -IntegerPart) = calculate BetaBinomial (across negative)
	case 0x4C:
		return lbeta_r_binom_neg(a, b, signp);
		break;
	// ---- NegativeInfinite vectorize ----
	// 0x91: logB(-Infinite, +Infinite) = [NaN, -1] (Undefined)
	case 0x91:
		*signp = -1;
		return NAN;
		break;
	// 0x92: logB(-Infinite, +Finite) = [Infinity, +1]
	case 0x92:
		return HUGE_VAL;
		break;
	// 0x94: logB(-Infinite, +IntegerPart) =
	//        -Infinity, sign: |b| is even: +1, odd: -1
	case 0x94:
		if ((int)b == 0)  return HUGE_VAL;
		else if ((int)fmod_core(b, 2) == 1)
			*signp = -1;
		return -HUGE_VAL;
		break;
	// 0x99: logB(-Infinite, -Infinite) = [NaN, -1] (Undefined)
	case 0x99:
		*signp = -1;
		return NAN;
		break;
	// 0x9A: logB(-Infinite, -Finite) = [NaN, -1]
	case 0x9A:
		*signp = -1;
		return NAN;
		break;
	// 0x9C: logB(-Infinite, -IntegerPart) = [NaN, -1]
	case 0x9C:
		if ((int)b == 0)  return HUGE_VAL;
		*signp = -1;
		return NAN;
		break;
	// ---- NegativeFinite vectorize ----
	// 0xA1: logB(-Finite, +Infinite) = equality to 0x1A (swap a and b)
	case 0xA1:
		if ((int)fmod_core(a, 2) == 1)
			*signp = -1;
		return HUGE_VAL;
		break;
	// 0xA2: logB(-Finite, +Finite) = 
	//       [loggamma(a) + loggamma(b) - loggamma(b - a), -1 or 1]
	case 0xA2:
		return lbeta_r_nega(a, b, signp);
		break;
	// 0xA4: logB(-Finite, +IntegerPart) = equality to 0x4A
	case 0xA4:
		return lbeta_r_inta_neg(b, a, signp);
		break;
	// 0xA9: logB(-Finite, -Infinite) = equality to 0x9A
	case 0xA9:
		*signp = -1;
		return NAN;
		break;
	// 0xAA: logB(-Finite, -Finite) = Negative Beta Binomial
	case 0xAA:
		return lbeta_negbetabinom(a, b, signp);
	// 0xAC: logB(-Finite, -IntegerPart) = equality to 0xCA
	case 0xAC:
		return HUGE_VAL;
		break;
	// ---- NegativeIntegerPart vectorize ----
	// 0xC1: logB(-IntegerPart, +Infinite) =  equality to 0x1C
	case 0xC1:
		if ((int)a == 0)  return HUGE_VAL;
		*signp = -1;
		return NAN;
		break;
	// 0xC2: logB(-IntegerPart, +Finite) = equality to 0x2C
	case 0xC2:
		return HUGE_VAL;
		break;
	// 0xC4: logB(-IntegerPart, +IntegerPart) = calculate BetaBinomial (across negative)
	case 0xC4:
		return lbeta_r_binom_neg(b, a, signp);
		break;
	// 0xC9: logB(-IntegerPart, -Infinite) = equality to 0x9C
	case 0xC9:
		if ((int)a == 0)  return HUGE_VAL;
		*signp = -1;
		return NAN;
		break;
	// 0xCA: logB(-IntegerPart, -Finite) = [Infinity, +1]  (injectivity to positive infinity)
	case 0xCA:
		return HUGE_VAL;
		break;
	// 0xCC: logB(-IntegerPart, -IntegerPart) = [Infinity, +1]
	//       (BetaBinomial out-of-range)
	case 0xCC:
		return HUGE_VAL;
		break;
	default:
		return NAN;
		break;
	}
}

// Real routine in a is negarive
static inline double
lbeta_r_nega(double a, double b, int *signp)
{
	double ya, yb, yab;
	int signp_a = 1, signp_b = 1, signp_ab = 1;

	if ((b - a) < 8)
	{
		ya = ur_loggamma_r(a, &signp_a);
		yb = ur_loggamma_r(b, &signp_b);
		yab = ur_loggamma_r(a + b, &signp_b);
		*signp = signp_a * signp_b * signp_ab;
		return ya + yb - yab;
	}
	else /* if ((b - a) >= 8) */
		return ur_loggamma_r(a, signp) + lbeta_algdiv(a, b);
}

// Integer a of logbeta, positive routine
static inline double
lbeta_r_inta_pos(double a, double b)
{
	double y = 0;

	if (a < 8)
	{
		y = lbeta_r_inta8_form((int)a, b);
		if (!(y == 0))
			return log_core(y) + logfactorial_core(a - 1);
	}
	if (a <= INT_MAX)
		if (b >= 8)
			return logfactorial_core(a - 1) + lbeta_algdiv(a, b);
		else
			return logfactorial_core(a - 1) +
			       lgamma_core(b) - lgamma_core(a + b);
	else
		if (b >= 8)
			return lgamma_core(a) + lbeta_algdiv(a, b);
		else
			return lgamma_core(a) + lgamma_core(b) - lgamma_core(a + b);
}

// Integer a of logbeta, negative routine
static inline double
lbeta_r_inta_neg(double a, double b, int *signp)
{
	double y = 0, yb = 0, yab = 0;
	int signp_b, signp_ab;

	if (a <= INT_MAX)
	{
		if (a < 8)
		{
			y = lbeta_r_inta8_form((int)a, b);
			// for 'infinitely' ideal field
			if (((a + b - 1) > 0) || !(y == 0))
			{
				if (y < 0) { *signp = -1; y = -y; }
				return log_core(y) + logfactorial_core(a - 1);
			}
		}
		else
		{
			// for 'infinitely' ideal field
			if ((a + b) >= 0)
			{
				yb = ur_loggamma_r(b, &signp_b);
				yab = ur_loggamma_r(a + b, &signp_ab);
				*signp = signp_b * signp_ab;
				return logfactorial_core(a - 1) + yb - yab;
			}
		}
		// for ideal field
		if (fmod_core(a, 2) > 0.5)  *signp = -1;
		y = logfactorial_core(a - 1) + lbeta_algdiv(a, -(a + b - 1));
	}
	else
	{
		// for 'infinitely' ideal field
		if ((a + b) >= 0)
		{
			yb = ur_loggamma_r(b, &signp_b);
			yab = ur_loggamma_r(a + b, &signp_ab);
			*signp = signp_b * signp_ab;
			return lgamma_core(a) + yb - yab;
		}
		// for ideal field
		if (fmod_core(a, 2) > 0.5)  *signp = -1;
		y = lgamma_core(a) + lbeta_algdiv(a, -(a + b - 1));
	}
	return y;
}

// form of a = 0 ... 7
static inline double
lbeta_r_inta8_form(int a, double b)
{
	switch (a) {
	case 0:
		return HUGE_VAL;
		break;
	case 1:
		return 1 / b;
		break;
	case 2:
		return 1 / (b * (b + 1));
		break;
	case 3:
		return 1 / (b * (b + 1) * (b + 2));
		break;
	case 4:
		return 1 / (b * (b + 1) * (b + 2) * (b + 3));
		break;
	case 5:
		return 1 / (b * (b + 1) * (b + 2) * (b + 3) * (b + 4));
		break;
	case 6:
		return 1 / (b * (b + 1) * (b + 2) * (b + 3) * (b + 4) * (b + 5));
		break;
	case 7:
		return 1 / (b * (b + 1) * (b + 2) * (b + 3) * (b + 4) * (b + 5) * (b + 6));
		break;
	default:
		return NAN;
		break;
	}
}

// Beta binomial, positive routine
static inline double
lbeta_r_binom_pos(double a, double b)
{
	double y = 0;
	if ((int)a == 0 || (int)b == 0)
		return HUGE_VAL;
	
	if (a > b)  { y = a; a = b; b = y; }

	if (a < 8)
	{
		switch ((int)a) {
		case 1:
			y = b;
			break;
		case 2:
			y = 2 * b + b * (b - 1);
			break;
		case 3:
			// $\frac{b^3 + 3 b^2 + 2 b}{2}$
			// y = (b * b * b + 3 * b * b + 2 * b) / 2;
			// Horner Method: $\frac{(b (b + 2) (b + 1))}{2}$
			y = (b * (b + 2) * (b + 1)) / 2;
			break;
		case 4:
			// $\frac{b^3 + 3 b^2 + 2 b}{2}$
			// y = (b * b * b * b + 6 * b * b * b +
			//      11 * b * b + 6 * b) / 6;
			// Horner Method: $\frac{(b (b + 1) (b + 2) (b + 3))}{6}$
			y = (b * (b + 1) * (b + 2) * (b + 3)) / 6;
			break;
		case 5:
			// $\frac{b^5 + 10 b^4 + 35 b^3 + 50 b^2 + 24 b}{24}$
			// y = (b * b * b * b * b + 10 * b * b * b * b +
			//      35 * b * b * b + 50 * b * b + 24 * b) / 24;
			// Horner Method: $\frac{b (b + 1) (b + 2) (b + 3) (b + 4)}{24}$
			y = (b * (b + 1) * (b + 2) * (b + 3) * (b + 4)) / 24;
			break;
		case 6:
			// $\frac{b^6 + 15 b^5 + 85 b^4 + 225 b^3 + 274 b^2 + 120 b}{120}$
			// y = (b * b * b * b * b * b + 15 * b * b * b * b * b +
			//      85 * b * b * b * b + 225 * b * b * b + 274 * 
			//      b * b + 120 * b) / 120;
			// Horner Method: $\frac{b (b + 1) (b + 2) (b + 3) (b + 4) (b + 5)}{120}$
			y = (b * (b + 1) * (b + 2) * (b + 3) * (b + 4) * (b + 5)) / 120;
			break;
		case 7:
			// $\frac{b^7 + 21 b^6 + 175 b^5 + 735 b^4 + 1624 b^3 + 1764 b^2 + 720 b}{720}$
			// y = (b * b * b * b * b * b * b + 21 * b * b * b * b * b * b +
			//      175 * b * b * b * b * b + 735 * b * b * b * b +
			//      1624 * b * b * b + 1764 * b * b + 720 * b) / 720;
			// Horner Method: $\frac{b (b + 1) (b + 2) (b + 3) (b + 4) (b + 5) (b + 6)}{720}$
			y = (b * (b + 1) * (b + 2) * (b + 3) * (b + 4) * (b + 5) * (b + 6)) / 720;
			break;
		default:
			break;
		}
		if (!isinf(y))
			return -log_core(y);
	}
	else if ((a + b) <= INT_MAX && (b - a) <= 100)
		return logfactorial_core((int)a - 1) +
		       logfactorial_core((int)b - 1) -
		       logfactorial_core((int)(a + b) - 1);

	if (a <= INT_MAX)
		return logfactorial_core(a - 1) + lbeta_algdiv(a, b);
	else
		return lgamma_core(a) + lbeta_algdiv(a, b);
}

// Beta Binomial across negative: a = pos, b = neg
static inline double
lbeta_r_binom_neg(double a, double b, int *signp)
{
	*signp = 1;
	if ((int)a == 0 || (int)b == 0)
		return HUGE_VAL;
	else if ((a + b - 1) > 0)
	{
//		if ((int)fmod_core(b, 2) == 1)
		if (fmod_core(b, 2) > 0.5)  // 丸め誤差対策
			*signp = -1;
		return HUGE_VAL;
	}
	else
	{
//		if ((int)fmod_core(a, 2) == 1)
		if (fmod_core(a, 2) > 0.5)  // 丸め誤差対策
			*signp = -1;
		return lbeta_r_binom_pos(a, -(a + b - 1));
	}
}

// Logarithm of Negative Beta Binomial
static inline double
lbeta_negbetabinom(double a, double b, int *signp)
{
	double ya, yb, yab;
	int signp_a, signp_b, signp_ab;
	
	ya = ur_loggamma_r(a, &signp_a);
	yb = ur_loggamma_r(b, &signp_b);
	yab = ur_loggamma_r(a + b, &signp_ab);
	*signp = signp_a * signp_b * signp_ab;
	return ya + yb - yab;
}

// computes ln(Gamma(b) / Gamma(a + b)) when 8 <= b.
// coded by John Burkardt
static inline double
lbeta_algdiv(double a, double b)
{
	static const double C[6] = 
	{
		 0.833333333333333e-01, -0.277777777760991e-02,
		 0.793650666825390e-03, -0.595202931351870e-03,
		 0.837308034031215e-03, -0.165322962780713e-02
	};
	double c, d, h, s11, s3, s5, s7, s9;
	double t, T1, u, v, value, w, x, x2;

	if (b <= a)
	{
		h = b / a;
		c = 1.0 / (1.0 + h);
		x = h / (1.0 + h);
		d = a + (b - 0.5);
	}
	else
	{
		h = a / b;
		c = h / (1.0 + h);
		x = 1.0 / (1.0 + h);
		d = b + (a - 0.5);
	}

	//  SET SN = (1 - X^N)/(1 - X)
	x2  = x * x;
	s3  = 1.0 + (x + x2);
	s5  = 1.0 + (x + x2 * s3);
	s7  = 1.0 + (x + x2 * s5);
	s9  = 1.0 + (x + x2 * s7);
	s11 = 1.0 + (x + x2 * s9);

	// SET W = DEL(B) - DEL(A + B)
	t = pow_core(1.0 / b, 2.0);

	w = ((((C[5] * s11 * t
	      + C[4] * s9) * t
	      + C[3] * s7) * t
	      + C[2] * s5) * t
	      + C[1] * s3) * t
	      + C[0];

	w = w * (c / b);

	// Combine the results.
	T1 = a / b;
	u = d * log1p_core(T1);
	v = a * (log_core(b) - 1.0);

	if (v < u)  value = w - v - u;
	else        value = w - u - v;

	return value;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_LBETA_DBL_INTERNAL */
