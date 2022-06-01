/*******************************************************************************
	Complex Gamma and Error function on C99 Resource
*******************************************************************************/
#ifndef GML_C99_GAMERF_INCLUDE_H
#define GML_C99_GAMERF_INCLUDE_H

#if defined(__cplusplus)
extern "C"{
#endif

#include <complex.h>

extern float _Complex cerff(float _Complex);
extern double _Complex cerf(double _Complex);
extern long double _Complex cerfl(long double _Complex);

extern float _Complex cerfcf(float _Complex);
extern double _Complex cerfc(double _Complex);
extern long double _Complex cerfcl(long double _Complex);

extern float _Complex cgammaf(float _Complex);
extern double _Complex cgamma(double _Complex);
long double _Complex cgammal(long double _Complex);


#if defined(__cplusplus)
}
#endif

#endif /* GML_C99_GAMERF_INCLUDE_H */
