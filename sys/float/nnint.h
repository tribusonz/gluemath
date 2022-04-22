/*******************************************************************************
	GLUE-Math primitive implementation: Nearest Neighbor Integer

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/

#ifndef floor
# define floor gml_floor
# include "../../internal/ur/floor.h"
static inline double
gml_floor(double x)
{
	return floor_core(x);
}
#endif

#ifndef floorl
# define floorl gml_floorl
# include "../../internal/ur/floorl.h"
static inline long double
gml_floorl(long double x)
{
	return floorl_core(x);
}
#endif

#ifndef floorf
# define floorf gml_floorf
# include "../../internal/ur/floorf.h"
static inline float
gml_floorf(float x)
{
	return floorf_core(x);
}
#endif

#ifndef ceil
# define ceil gml_ceil
# include "../../internal/ur/ceil.h"
static inline double
gml_ceil(double x)
{
	return ceil_core(x);
}
#endif

#ifndef ceill
# define ceill gml_ceill
# include "../../internal/ur/ceill.h"
static inline long double
gml_ceill(long double x)
{
	return ceill_core(x);
}
#endif

#ifndef ceilf
# define ceilf gml_ceilf
# include "../../internal/ur/ceilf.h"
static inline float
gml_ceilf(float x)
{
	return ceilf_core(x);
}
#endif

#ifndef trunc
# define trunc gml_trunc
# include "../../internal/ur/trunc.h"
static inline double
gml_trunc(double x)
{
	return trunc_core(x);
}
#endif

#ifndef truncl
# define truncl gml_truncl
# include "../../internal/ur/truncl.h"
static inline long double
gml_truncl(long double x)
{
	return truncl_core(x);
}
#endif

#ifndef truncf
# define truncf gml_truncf
# include "../../internal/ur/truncf.h"
static inline float
gml_truncf(float x)
{
	return truncf_core(x);
}
#endif

#ifndef round
# define round gml_round
# include "../../internal/ur/round.h"
static inline double
gml_round(double x)
{
	return round_core(x);
}
#endif

#ifndef roundl
# define roundl gml_roundl
# include "../../internal/ur/roundl.h"
static inline long double
gml_roundl(long double x)
{
	return roundl_core(x);
}
#endif

#ifndef roundf
# define roundf gml_roundf
# include "../../internal/ur/roundf.h"
static inline float
gml_roundf(float x)
{
	return roundf_core(x);
}
#endif
