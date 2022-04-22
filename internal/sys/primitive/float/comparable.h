/*******************************************************************************
	FP comparable

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	https://marycore.jp/prog/c-lang/compare-floating-point-number/
*******************************************************************************/
#if !defined(GLUE_PRIMITIVE_FP_COMPARABLE)
# error include sys/float/comparable.h at first
#endif

#ifndef GLUEMATH_FPCOMPARABLE_INTERNAL
#define GLUEMATH_FPCOMPARABLE_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../../../sys/float/comparable.h"
#include "../../../../sys/float/info.h"
#include "info.h"
#include "../../../../sys/float/fpclassify.h"
#include "fpclassify.h"

// comparable functions
static inline int
gml_dbl_cmpt(const double x, const double y, const double tolerance)
{
   return (x > y + tolerance) ? 1 : (y > x + tolerance) ? -1 : 0;
}

static inline int
gml_ldbl_cmpt(const long double x, const long double y, const long double tolerance)
{
   return (x > y + tolerance) ? 1 : (y > x + tolerance) ? -1 : 0;
}

static inline int
gml_flt_cmpt(const float x, const float y, const float tolerance)
{
   return (x > y + tolerance) ? 1 : (y > x + tolerance) ? -1 : 0;
}

// comparable operators
static inline int
gml_dbl_islt(const double x, const double y)
{
	get_dbl_info();
	return (gml_dbl_cmpt(x, y, dbl_info.epsilon) < 0);
}
static inline int
gml_dbl_isle(const double x, const double y)
{
	get_dbl_info();
	return (gml_dbl_cmpt(x, y, dbl_info.epsilon) <= 0);
}
static inline int
gml_dbl_isgt(const double x, const double y)
{
	get_dbl_info();
	return (gml_dbl_cmpt(x, y, dbl_info.epsilon) > 0);
}
static inline int
gml_dbl_isge(const double x, const double y)
{
	get_dbl_info();
	return (gml_dbl_cmpt(x, y, dbl_info.epsilon) >= 0);
}
static inline int
gml_dbl_islg(const double x, const double y)
{
	get_dbl_info();
	return (gml_dbl_cmpt(x, y, dbl_info.epsilon) < 0 || gml_dbl_cmpt(x, y, dbl_info.epsilon) > 0);
}

static inline int
gml_ldbl_islt(const long double x, const long double y)
{
	get_ldbl_info();
	return (gml_ldbl_cmpt(x, y, ldbl_info.epsilon) < 0);
}
static inline int
gml_ldbl_isle(const long double x, const long double y)
{
	get_ldbl_info();
	return (gml_ldbl_cmpt(x, y, ldbl_info.epsilon) <= 0);
}
static inline int
gml_ldbl_isgt(const long double x, const long double y)
{
	get_ldbl_info();
	return (gml_ldbl_cmpt(x, y, ldbl_info.epsilon) > 0);
}
static inline int
gml_ldbl_isge(const long double x, const long double y)
{
	get_ldbl_info();
	return (gml_ldbl_cmpt(x, y, ldbl_info.epsilon) >= 0);
}
static inline int
gml_ldbl_islg(const long double x, const long double y)
{
	get_ldbl_info();
	return (gml_ldbl_cmpt(x, y, ldbl_info.epsilon) < 0 || gml_ldbl_cmpt(x, y, ldbl_info.epsilon) > 0);
}

static inline int
gml_flt_islt(const float x, const float y)
{
	get_flt_info();
	return (gml_flt_cmpt(x, y, flt_info.epsilon) < 0);
}
static inline int
gml_flt_isle(const float x, const float y)
{
	get_flt_info();
	return (gml_flt_cmpt(x, y, flt_info.epsilon) <= 0);
}
static inline int
gml_flt_isgt(const float x, const float y)
{
	get_flt_info();
	return (gml_flt_cmpt(x, y, flt_info.epsilon) > 0);
}
static inline int
gml_flt_isge(const float x, const float y)
{
	get_flt_info();
	return (gml_flt_cmpt(x, y, flt_info.epsilon) >= 0);
}
static inline int
gml_flt_islg(const float x, const float y)
{
	get_flt_info();
	return (gml_flt_cmpt(x, y, flt_info.epsilon) < 0 || gml_flt_cmpt(x, y, flt_info.epsilon) > 0);
}

// IEEE754-2019 minmax
static inline float
gml_flt_fmin(float x, float y)
{
	return (gml_flt_isle(x, y) || isnan(y)) ? x : y;
}

static inline double
gml_dbl_fmin(double x, double y)
{
	return (gml_dbl_isle(x, y) || isnan(y)) ? x : y;
}

static inline long double
gml_ldbl_fmin(long double x, long double y)
{
	return (gml_ldbl_isle(x, y) || isnan(y)) ? x : y;
}

static inline float
gml_flt_fmax(float x, float y)
{
	return (gml_flt_isge(x, y) || isnan(y)) ? x : y;
}

static inline double
gml_dbl_fmax(double x, double y)
{
	return (gml_dbl_isge(x, y) || isnan(y)) ? x : y;
}

static inline long double
gml_ldbl_fmax(long double x, long double y)
{
	return (gml_ldbl_isge(x, y) || isnan(y)) ? x : y;
}

#if defined(__cplusplus)
}
#endif

#endif /* GLUEMATH_FPCOMPARABLE_INTERNAL */
