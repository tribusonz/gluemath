/*******************************************************************************
	GLUE-Math - FP information

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GLUE_PRIMITIVE_FP_INFO
#define GLUE_PRIMITIVE_FP_INFO

#if defined(__cplusplus)
extern "C" {
#endif

// Infomation Constants and ABI
/* for float */
typedef struct _FltInfo flt_info_t ;
static flt_info_t flt_info;

/*
 *  C ABI: flt_has_subnorm() -> i8
 * 
 *  Returns integer as support for denormalized numbers in float-type.
 *  When 0 is absent, when 1 is present.
 *  It is equivalent to FLT_HAS_SUBNORM (included C++17), but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: 1
 */
extern char flt_has_subnorm(void);

/*
 *  C ABI: flt_radix() -> u8
 * 
 *  Returns the radix of the float-type exponential representation.
 *  It is equivalent to FLT_RADIX, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: 2
 */
extern unsigned char flt_radix(void);

/*
 *  C ABI: flt_mant_dig() -> u8
 * 
 *  Returns the number of digits in the mantissa part when float is expressed in radix flt_radix().
 *  It is equivalent to FLT_MANT_DIG, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: 24
 */
extern unsigned char flt_mant_dig(void);

/*
 *  C ABI: flt_epsilon() -> f32
 * 
 *  Returns the difference between 1 and next-least 1 (machine epsilon) on the exponential representations.
 *  It is equivalent to FLT_EPSILON, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: 1.19209e-07
 */
extern float flt_epsilon(void);

/*
 *  C ABI: flt_eps_10_exp() -> i8
 * 
 *  Returns the machine epsilon's exponential, for float. 
 *  The standard stipulates that it is 1E-5 (10^{-5}) or less.
 *
 *  MinGW 64bit gcc build: -6
 */
extern char flt_eps_10_exp(void);

/*
 *  C ABI: flt_dig() -> u8
 * 
 *  Returns the maximum number of decimal digits that can be accurately represented by float-type.
 *  It is equivalent to FLT_DIG, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: 6
 */
extern unsigned char flt_dig(void);

/*
 *  C ABI: flt_max() -> f32
 *  
 *  Returns the maximum finite value of float-type.
 *  It is equivalent to FLT_MAX, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: 3.40282e+38
 */
extern float flt_max(void);

/*
 *  C ABI: flt_min() -> f32
 *  
 *  Returns the lowest positive normalized number of float-type.
 *  If the model does not support denormalized numbers, it will be the real number closest to 0.
 *  Therefore, this function, even if it is equivalent to FLT_MIN, varies depending on the environment.
 *
 *  MinGW 64bit gcc build: 1.17549e-38
 */
extern float flt_min(void);

/*
 *  C ABI: flt_true_min() -> f32
 *  
 *  Returns a positive minimum including the denormalized number in the environment, for float-type.
 *  In an environment without denormalized numbers, the lowest normalized number is a value.
 *  This function is equivalent to the FLT_TRUE_MIN of C++17.
 *
 *  MinGW 64bit gcc build: 1.4013e-45
 */
extern float flt_true_min(void);

/*
 *  C ABI: flt_max_exp() -> int
 *  
 *  Returns the largest integer value n, such that the n-1-power of flt_radix() can be represented as a finite value of float.
 *  It is equivalent to FLT_MAX_EXP, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: 128
 */
extern int flt_max_exp(void);

/*
 *  C ABI: flt_min_exp() -> int
 *  
 *  Returns the smallest integer value n, such that the n-1-power of flt_radix() can be represented as a normalized value of float.
 *  It is equivalent to FLT_MIN_EXP, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: -125
 */
extern int flt_min_exp(void);

/*
 *  C ABI: flt_max_10_exp() -> int
 *  
 *  Returns the largest integer value n, such that the n-power of 10 can be represented as a finite value of float.
 *  It is equivalent to FLT_MAX_10_EXP, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: 38
 */
extern int flt_max_10_exp(void);

/*
 *  C ABI: flt_min_10_exp() -> int
 *  
 *  Returns the smallest integer value n, such that the n-power of 10 can be represented as a normalized value of float.
 *  It is equivalent to FLT_MIN_10_EXP, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: -37
 */
extern int flt_min_10_exp(void);

/* for double */
typedef struct _DblInfo dbl_info_t ;
static dbl_info_t dbl_info;

/*
 *  C ABI: dbl_has_subnorm() -> i8
 * 
 *  Returns integer as support for denormalized numbers in double-type.
 *  When 0 is absent, when 1 is present.
 *  It is equivalent to DBL_HAS_SUBNORM (included C++17), but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: 1
 */
extern char dbl_has_subnorm(void);

/*
 *  C ABI: dbl_radix() -> u8
 * 
 *  Returns the radix of the double-type exponential representation.
 *  It is equivalent to FLT_RADIX, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: 2
 */
extern unsigned char dbl_radix(void);

/*
 *  C ABI: dbl_mant_dig() -> u8
 * 
 *  Returns the number of digits in the mantissa part when double-type is expressed in radix dbl_radix().
 *  It is equivalent to DBL_MANT_DIG, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: 53
 */
extern unsigned char dbl_mant_dig(void);

/*
 *  C ABI: dbl_epsilon() -> f64
 * 
 *  Returns the difference between 1 and next-least 1 (machine epsilon) on the exponential representations.
 *  It is equivalent to DBL_EPSILON, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: 2.22045e-16
 */
extern double dbl_epsilon(void);

/*
 *  C ABI: dbl_eps_10_exp() -> i8
 * 
 *  Returns the machine epsilon's exponential, for double.
 *  The standard stipulates that it is 1E-9 (10^{-9}) or less.
 *
 *  MinGW 64bit gcc build: -9
 */
extern char dbl_eps_10_exp(void);

/*
 *  C ABI: dbl_dig() -> u8
 * 
 *  Returns the maximum number of decimal digits that can be accurately represented by double-type.
 *  It is equivalent to DBL_DIG, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: 15
 */
extern unsigned char dbl_dig(void);

/*
 *  C ABI: dbl_max() -> f64
 *  
 *  Returns the maximum finite value of double-type.
 *  It is equivalent to DBL_MAX, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: 1.79769e+308
 */
extern double dbl_max(void);

/*
 *  C ABI: dbl_min() -> f64
 *  
 *  Returns the lowest positive normalized number of double-type.
 *  If the model does not support denormalized numbers, it will be the real number closest to 0.
 *  Therefore, this function, even if it is equivalent to DBL_MIN, varies depending on the environment.
 *
 *  MinGW 64bit gcc build: 2.22507e-308
 */
extern double dbl_min(void);

/*
 *  C ABI: dbl_true_min() -> f64
 *  
 *  Returns a positive minimum including the denormalized number in the environment, for double-type.
 *  In an environment without denormalized numbers, the lowest normalized number is a value.
 *  This function is equivalent to the DBL_TRUE_MIN of C++17.
 *
 *  MinGW 64bit gcc build: 4.94066e-324
 */
extern double dbl_true_min(void);

/*
 *  C ABI: dbl_max_exp() -> int
 *  
 *  Returns the largest integer value n, such that the n-1-power of dbl_radix() can be represented as a finite value of double.
 *  It is equivalent to DBL_MAX_EXP, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: 1024
 */
extern int dbl_max_exp(void);

/*
 *  C ABI: dbl_min_exp() -> int
 *  
 *  Returns the smallest integer value n, such that the n-1-power of dbl_radix() can be represented as a normalized value of double.
 *  It is equivalent to DBL_MIN_EXP, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: -1021
 */
extern int dbl_min_exp(void);

/*
 *  C ABI: dbl_max_10_exp() -> int
 *  
 *  Returns the largest integer value n, such that the n-power of 10 can be represented as a finite value of double.
 *  It is equivalent to DBL_MAX_10_EXP, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: 308
 */
extern int dbl_max_10_exp(void);

/*
 *  C ABI: dbl_min_10_exp() -> int
 *  
 *  Returns the smallest integer value n, such that the n-power of 10 can be represented as a normalized value of double.
 *  It is equivalent to DBL_MIN_10_EXP, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: -307
 */
extern int dbl_min_10_exp(void);

/* for long double */
typedef struct _LDblInfo ldbl_info_t ;
static ldbl_info_t ldbl_info;

/*
 *  C ABI: ldbl_has_subnorm() -> i8
 * 
 *  Returns integer as support for denormalized numbers in long-double-type.
 *  When 0 is absent, when 1 is present.
 *  It is equivalent to DBL_HAS_SUBNORM (included C++17), but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: 1
 */
extern char ldbl_has_subnorm(void);

/*
 *  C ABI: ldbl_radix() -> u8
 * 
 *  Returns the radix of the long-double-type exponential representation.
 *  It is equivalent to FLT_RADIX, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: 2
 */
unsigned char ldbl_radix(void);

/*
 *  C ABI: ldbl_mant_dig() -> u8
 * 
 *  Returns the number of digits in the mantissa part when long-double is expressed in radix ldbl_radix().
 *  It is equivalent to LDBL_MANT_DIG, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: 64  (80-bit extended precision)
 *  gcc build with mlong-double-128: 113
 */
unsigned char ldbl_mant_dig(void);

/*
 *  C ABI: ldbl_epsilon() -> f80 | f128
 * 
 *  Returns the difference between 1 and next-least 1 (machine epsilon) on the exponential representations.
 *  It is equivalent to LDBL_EPSILON, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: 1.0842e-19  (80-bit extended precision)
 *  gcc build with mlong-double-128: (Cannot measure with printf() function)
 */
long double ldbl_epsilon(void);

/*
 *  C ABI: ldbl_eps_10_exp() -> i8
 * 
 *  Returns the machine epsilon's exponential, for long double.
 *  The standard stipulates that it is 1E-9 (10^{-9}) or less.
 *
 *  MinGW 64bit gcc build: -13
 */
char ldbl_eps_10_exp(void);

/*
 *  C ABI: ldbl_dig() -> u8
 * 
 *  Returns the maximum number of decimal digits that can be accurately represented by long-double-type.
 *  It is equivalent to LDBL_DIG, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: 18  (80-bit extended precision)
 *  gcc build with mlong-double-128: 33
 */
unsigned char ldbl_dig(void);

/*
 *  C ABI: ldbl_max() -> f80 | f128
 *  
 *  Returns the maximum finite value of long-double-type.
 *  It is equivalent to LDBL_MAX, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: 1.18973e+4932  (80-bit extended precision)
 *  gcc build with mlong-double-128: (Cannot measure with printf() function)
 */
long double ldbl_max(void);

/*
 *  C ABI: ldbl_min() -> f80 | f128
 *  
 *  Returns the lowest positive normalized number of long-double-type.
 *  If the model does not support denormalized numbers, it will be the real number closest to 0.
 *  Therefore, this function, even if it is equivalent to LDBL_MIN, varies depending on the environment.
 *
 *  MinGW 64bit gcc build: 3.3621e-4932  (80-bit extended precision)
 *  gcc build with mlong-double-128: (Cannot measure with printf() function)
 */
long double ldbl_min(void);

/*
 *  C ABI: ldbl_true_min() -> f80 | f128
 *  
 *  Returns a positive minimum including the denormalized number in the environment, for long-double-type.
 *  In an environment without denormalized numbers, the lowest normalized number is a value.
 *  This function is equivalent to the LDBL_TRUE_MIN of C++17.
 *
 *  MinGW 64bit gcc build: 3.6452e-4951  (80-bit extended precision)
 *  gcc build with mlong-double-128: (Cannot measure with printf() function)
 */
long double ldbl_true_min(void);

/*
 *  C ABI: ldbl_max_exp() -> int
 *  
 *  Returns the largest integer value n, such that the n-1-power of ldbl_radix() can be represented as a finite value of long-double.
 *  It is equivalent to LDBL_MAX_EXP, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: 16384
 */
int ldbl_max_exp(void);

/*
 *  C ABI: ldbl_min_exp() -> int
 *  
 *  Returns the smallest integer value n, such that the n-1-power of ldbl_radix() can be represented as a normalized value of long-double.
 *  It is equivalent to LDBL_MIN_EXP, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: -16381
 */
int ldbl_min_exp(void);

/*
 *  C ABI: ldbl_max_10_exp() -> int
 *  
 *  Returns the largest integer value n, such that the n-power of 10 can be represented as a finite value of long-double.
 *  It is equivalent to LDBL_MAX_10_EXP, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: 4932
 */
int ldbl_max_10_exp(void);

/*
 *  C ABI: ldbl_min_10_exp() -> int
 *  
 *  Returns the smallest integer value n, such that the n-power of 10 can be represented as a normalized value of long-double.
 *  It is equivalent to LDBL_MIN_10_EXP, but this function is derived by calculation.
 *
 *  MinGW 64bit gcc build: -4931
 */
int ldbl_min_10_exp(void);

#if defined(__cplusplus)
}
#endif

#endif /* GLUE_PRIMITIVE_FP_INFO */
