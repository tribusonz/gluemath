/*******************************************************************************
	GLUE-Math Library: Inverse of Complementary Error Function

	Author:
	  Takuya Ooura (Original algorithm)
	  Hironobu Inatsuka aka tribusonz (Part of modify)
	License:
	  GPL + X11(MIT)
	Reference:
	  Ooura's Mathematical Software Packages
*******************************************************************************/
#ifndef GML_ERFCINV_DBL_INTERNAL
#define GML_ERFCINV_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "exp.h"
#include "log.h"
#include "sqrt.h"

/* inverse of error function in double precision, by Takuya OURA */
static inline double
ur_erfcinv(register double y)
{
	static const double
	qa = 9.16461398268964e-01, 
	qb = 2.31729200323405e-01, 
	qc = 4.88826640273108e-01, 
	qd = 1.24610454613712e-01, 
	q[] =
	{
		 4.99999303439796e-01, 
		 1.16065025341614e-01, 
		 1.50689047360223e-01, 
		 2.69999308670029e-01, 
		-7.28846765585675e-02
	},
	pa = 3.97886080735226000e+00, 
	pb = 1.20782237635245222e-01, 
	p[] =
	{
		 2.44044510593190935e-01, 
		 4.34397492331430115e-01, 
		 6.86265948274097816e-01, 
		 9.56464974744799006e-01, 
		 1.16374581931560831e+00, 
		 1.21448730779995237e+00, 
		 1.05375024970847138e+00, 
		 7.13657635868730364e-01, 
		 3.16847638520135944e-01, 
		 1.47297938331485121e-02, 
		-1.05872177941595488e-01, 
		-7.43424357241784861e-02, 
		 2.20995927012179067e-03, 
		 3.46494207789099922e-02, 
		 1.42961988697898018e-02, 
		-1.18598117047771104e-02, 
		-1.12749169332504870e-02, 
		 3.39721910367775861e-03, 
		 6.85649426074558612e-03, 
		-7.71708358954120939e-04, 
		-3.51287146129100025e-03, 
		 1.05739299623423047e-04, 
		 1.12648096188977922e-03
	};
	register double s, t, u, w, x, z;
	
	if (y != y)  return y;
	
	z = y;
	if (y > 1)  z = 2 - y;

	w = qa - log_core(z);
	u = sqrt_core(w);
	s = (log_core(u) + qc) / w;
	t = 1 / (u + qb);
	x = u * (1 - s * (s * qd + 0.5)) - 
	    ((((q[4] * t + q[3]) * t + q[2]) * t + q[1]) * t + q[0]) * t;
	t = pa / (x + pa);
	u = t - 0.5;
	s = (((((((((p[22] *
	    u + p[21]) * u + p[20]) * u + p[19]) * u + p[18]) * u + p[17]) *
	    u + p[16]) * u + p[15]) * u + p[14]) * u + p[13]) * u + p[12];
	s = ((((((((((((s * u + p[11]) * u + p[10]) *
	    u + p[ 9]) * u + p[ 8]) * u + p[ 7]) * u + p[ 6]) * u + p[ 5]) *
	    u + p[ 4]) * u + p[ 3]) * u + p[ 2]) * u + p[ 1]) * u + p[ 0]) *
	    t - z * exp_core(x * x - pb);
	x += s * (x * s + 1);
	if (y > 1)  x = -x;
	return x;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ERFCINV_DBL_INTERNAL */
