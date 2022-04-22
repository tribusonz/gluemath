/*******************************************************************************
	FP comparable

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	https://marycore.jp/prog/c-lang/compare-floating-point-number/
*******************************************************************************/
#ifndef GLUE_PRIMITIVE_FP_COMPARABLE
#define GLUE_PRIMITIVE_FP_COMPARABLE

#if defined(__cplusplus)
extern "C" {
#endif

// comparable functions
#ifndef cmptf
# define cmptf(x, y, t)  gml_flt_cmpt((x), (y), (t))
static inline int gml_flt_cmpt(float, float, float);
#endif

#ifndef cmpt
# define cmpt(x, y, t)  gml_dbl_cmpt((x), (y), (t))
static inline int gml_dbl_cmpt(double, double, double);
#endif

#ifndef cmptl
# define cmptl(x, y, t)  gml_ldbl_cmpt((x), (y), (t))
static inline int gml_ldbl_cmpt(long double, long double, long double);
#endif

// comparable operators
#ifndef isless
static inline int gml_flt_islt(float, float);
static inline int gml_dbl_islt(double, double);
static inline int gml_ldbl_islt(long double, long double);
#endif

#ifndef islessequal
static inline int gml_flt_isle(float, float);
static inline int gml_dbl_isle(double, double);
static inline int gml_ldbl_isle(long double, long double);
#endif

#ifndef isgreater
static inline int gml_flt_isgt(float, float);
static inline int gml_dbl_isgt(double, double);
static inline int gml_ldbl_isgt(long double, long double);
#endif

#ifndef isgreaterequal
static inline int gml_flt_isge(float, float);
static inline int gml_dbl_isge(double, double);
static inline int gml_ldbl_isge(long double, long double);
#endif

#ifndef islessequal
static inline int gml_flt_islg(float, float);
static inline int gml_dbl_islg(double, double);
static inline int gml_ldbl_islg(long double, long double);
#endif

// IEEE754 minmax
#ifndef fminf
# define fminf(x, y)  gml_flt_fmin((x), (y))
static inline float gml_flt_fmin(float, float);
#endif

#ifndef fmin
# define fmin(x, y)  gml_dbl_fmin((x), (y))
static inline double gml_dbl_fmin(double, double);
#endif

#ifndef fminl
# define fminl(x, y)  gml_ldbl_fmin((x), (y));
static inline long double gml_ldbl_fmin(long double, long double);
#endif

#ifndef fmaxf
# define fmaxf(x, y)  gml_flt_fmax((x), (y))
static inline float gml_flt_fmax(float, float);
#endif

#ifndef fmax
# define fmax(x, y)  gml_dbl_fmax((x), (y))
static inline double gml_dbl_fmax(double, double);
#endif

#ifndef fmaxl
# define fmaxl(x, y)  gml_ldbl_fmax((x), (y))
static inline long double gml_ldbl_fmax(long double, long double);
#endif

#if defined(__cplusplus)
}
#endif

#endif /* GLUE_PRIMITIVE_FP_COMPARABLE */
