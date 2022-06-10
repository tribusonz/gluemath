/*******************************************************************************
	GLUE-Math Library: Gaussian Error Function
	
	Author:
	  Takuya Ooura (Original Algorithm)
	  Hironobu Inatsuka aka tribusonz (C ABI modify)
	License:
	  GPL + X11(MIT)
	Reference:
	  Ooura's Mathematical Software Packages
*******************************************************************************/
#ifndef GML_ERF_LDBLCMPLX_INTERNAL
#define GML_ERF_LDBLCMPLX_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/complex/class.h"
#include "../../sys/complex/arithmetic.h"
#include "../../sys/complex/unary.h"
#include "../../sys/complex/cast.h"
#include "../../sys/float/absolute.h"
#include "cerfcl.h"

#if 0
// C99 complex ver.
long double _Complex
cerfl(long double _Complex x)
{
	static const long double
	p0  =  1.1283791670955125738961589031215451717e+00,
	p1  = -3.7612638903183752463205296770718172390e-01,
	p2  =  1.1283791670955125738961589031215451717e-01,
	p3  = -2.6866170645131251759432354836227265993e-02,
	p4  =  5.2239776254421878421118467737108572763e-03,
	p5  = -8.5483270234508528325466583569814028158e-04,
	p6  =  1.2055332981789664251027338708563516792e-04,
	p7  = -1.4925650358406250977462419353459592218e-05,
	p8  =  1.6462114365889247401612962522198079652e-06,
	p9  = -1.6365844691234924317393003677039026555e-07,
	p10 =  1.4807192815879217239546050945892452597e-08,
	p11 = -1.2290555301717927352982888136906778836e-09,
	p12 =  9.4227590646504109706202142382951971074e-11,
	p13 = -6.7113668551641103779346255258512799910e-12;

	if (fabsl(creall(x)) + fabsl(cimagl(x)) >= 0.125)
		if (creall(x) >= 0)
			return 1 - cerfcl(x);
		else
			return cerfcl(-x) - 1;
	else
	{
		long double _Complex y = x * x;
		return (((((((((((((p13 *
		        y + p12) *  y + p11) *
		        y + p10) *  y + p9)  *
		        y + p8)  *  y + p7)  *
		        y + p6)  *  y + p5)  *
		        y + p4)  *  y + p3)  *
		        y + p2)  *  y + p1)  *
		        y + p0)  * x;
	}
}
#endif

static inline lcomplex
cerfl_core(lcomplex x)
{
	static const long double
	p0  =  1.1283791670955125738961589031215451717e+00,
	p1  = -3.7612638903183752463205296770718172390e-01,
	p2  =  1.1283791670955125738961589031215451717e-01,
	p3  = -2.6866170645131251759432354836227265993e-02,
	p4  =  5.2239776254421878421118467737108572763e-03,
	p5  = -8.5483270234508528325466583569814028158e-04,
	p6  =  1.2055332981789664251027338708563516792e-04,
	p7  = -1.4925650358406250977462419353459592218e-05,
	p8  =  1.6462114365889247401612962522198079652e-06,
	p9  = -1.6365844691234924317393003677039026555e-07,
	p10 =  1.4807192815879217239546050945892452597e-08,
	p11 = -1.2290555301717927352982888136906778836e-09,
	p12 =  9.4227590646504109706202142382951971074e-11,
	p13 = -6.7113668551641103779346255258512799910e-12;

	if (fabsl(x.real) + fabsl(x.imag) >= 0.125)
		if (x.real >= 0)
			return lc_sub(ldtolc(1), cerfcl_core(x));
		else
			return lc_sub(cerfcl_core(lc_uminus(x)), ldtolc(1));
	else
	{
		lcomplex y = lc_mul(x, x);
		return 
		lc_mul(lc_add(
		  lc_mul(lc_add(
		    lc_mul(lc_add(
		      lc_mul(lc_add(
		        lc_mul(lc_add(
		          lc_mul(lc_add(
		            lc_mul(lc_add(
		              lc_mul(lc_add(
		                lc_mul(lc_add(
		                  lc_mul(lc_add(
		                    lc_mul(lc_add(
		                      lc_mul(lc_add(
		                        lc_mul(lc_add(
		                        lc_mul(ldtolc(p13), y),
		                        ldtolc(p12)), y),
		                      ldtolc(p11)), y),
		                    ldtolc(p10)), y),
		                  ldtolc(p9)), y),
		                ldtolc(p8)), y),
		              ldtolc(p7)), y),
		            ldtolc(p6)), y),
		          ldtolc(p5)), y),
		        ldtolc(p4)), y),
		      ldtolc(p3)), y),
		    ldtolc(p2)), y),
		  ldtolc(p1)), y),
		ldtolc(p0)), x);
	}
}


#if defined(__cplusplus)
}
#endif

#endif /* GML_ERF_LDBLCMPLX_INTERNAL */
