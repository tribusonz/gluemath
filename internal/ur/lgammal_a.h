/*******************************************************************************
	GLUE-Math Library: Logarithm of Gamma Function

	Author:
	  Takuya Ooura (Original algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License: GPL + X11(MIT)
	Reference:
		Ooura's Mathematical Software Packages
		- Takuya Ooura
*******************************************************************************/
#ifndef GML_LGAMMA_APPROX_DBL_INTERNAL
#define GML_LGAMMA_APPROX_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: fabsl(), logl(), sinl()
#include "../../sys/float/absolute.h"
#include "logl.h"
#include "sinl.h"

static inline long double
loggammal_a(register long double x, int *signp)
{
	register long double w, y;
	static const long double PI = 3.1415926535897932384626433832795028842e+00;
	static const long double PV = 1.3578122000703946473976913605273518883e+01;
	static const long double PR = 3.1782384299734898421289539143998119380e-06;
	static const long double p[] =
	{
		3.1482070283349300354582623623908339457e-04,
		1.2793741608722984500693458490473661860e-02,
		2.7874830306029980874434569055259616606e-01,
		3.5748763958228570180758258557929027134e+00,
		2.7927280421563325015666935178375281217e+01,
		1.3321384650379738989446885832268784755e+02,
		3.7950405192465422312792634449147935784e+02,
		6.1562149993028259463346808196235292341e+02,
		5.2400400869100650701118261358974985117e+02,
		2.0418766202023711876168179075996496480e+02,
		2.8645619772729108683191342647193554200e+01,
		8.9507210141338984737305834751291040398e-01,
		1.8410863315761265630602733481713520754e-03
	};
	static const long double q[] =
	{
		0.L,
		9.9999999999999999999999999982917706744e-01,
		2.0000000000000000000000014372532510977e+00,
		2.9999999999999999999987806987019196983e+00,
		4.0000000000000000003182289605630538899e+00,
		4.9999999999999999603276569479688692879e+00,
		6.0000000000000030034309156698097129604e+00,
		6.9999999999998375247462698288225315906e+00,
		8.0000000000071915518803021765161684809e+00,
		8.9999999997000681861822653951282600849e+00,
		1.0000000014205005237309132429530491661e+01,
		1.0999998953920119680361242478373085334e+01,
		1.2000238108934194337280539725944422661e+01
	};
	w = x;
	if(x < 0)  w = 1 - x;
	y = logl_core(((((((((((((p[12]  / (w + q[12]) +
	   p[11]) / (w + q[11]) + p[10]) / (w + q[10]) +
	   p[ 9]) / (w + q[ 9]) + p[ 8]) / (w + q[ 8]) +
	   p[ 7]) / (w + q[ 7]) + p[ 6]) / (w + q[ 6]) +
	   p[ 5]) / (w + q[ 5]) + p[ 4]) / (w + q[ 4]) +
	   p[ 3]) / (w + q[ 3]) + p[ 2]) / (w + q[ 2]) +
	   p[ 1]) / (w + q[ 1]) + p[ 0]) /  w + PR)    +
	   (w - 0.5L) * logl_core(w + PV) - w;

	if (x < 0)
	{
		w = PI / sinl_core(PI * x);

		if (w < 0)  *signp = -1;
		else        *signp =  1;

		y = logl_core(fabsl(w)) - y;
	}
	else
		*signp = 1;

	return y;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_LGAMMA_APPROX_DBL_INTERNAL */
