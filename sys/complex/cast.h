/*******************************************************************************
	BLUE-Math Complex Primitive Setting: Cast (Type Convertion)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_COMPLEX_PRIMITIVE_CAST_H
#define GML_COMPLEX_PRIMITIVE_CAST_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "class.h"
#include "../float/huge_val_nan.h"
#include "../float/fpclassify.h"
#include "../../internal/sys/primitive/float/fpclassify.h"

/***** For complex number classes *****/
// float complex to complex
static inline fcomplex fctofc(fcomplex);
static inline dcomplex fctodc(fcomplex);
static inline lcomplex fctolc(fcomplex);

// double complex to complex
static inline fcomplex dctofc(dcomplex);
static inline dcomplex dctodc(dcomplex);
static inline lcomplex dctolc(dcomplex);

// long double complex to complex
static inline fcomplex lctofc(lcomplex);
static inline dcomplex lctodc(lcomplex);
static inline lcomplex lctolc(lcomplex);

/***** For complex class and real classes *****/
// float complex to real
static inline float fctof(fcomplex);
static inline double fctod(fcomplex);
static inline long double fctold(fcomplex);

// double complex to real
static inline float dctof(dcomplex);
static inline double dctod(dcomplex);
static inline long double dctold(dcomplex);

// long double complex to real
static inline float lctof(lcomplex);
static inline double lctod(lcomplex);
static inline long double lctold(lcomplex);

// real to float complex
static inline fcomplex ftofc(float);
static inline fcomplex dtofc(double);
static inline fcomplex ldtofc(long double);

// real to double complex
static inline dcomplex ftodc(float);
static inline dcomplex dtodc(double);
static inline dcomplex ldtodc(long double);

// real to long double complex
static inline lcomplex ftolc(float);
static inline lcomplex dtolc(double);
static inline lcomplex ldtolc(long double);

/***** For complex class and integer classes *****/
// float complex to signed integer class
static inline char fctoc(fcomplex);
static inline short fctosht(fcomplex);
static inline int fctoi(fcomplex);
static inline long fctol(fcomplex);
static inline long long fctoll(fcomplex);

// float complex to unsigned integer class
static inline unsigned char fctouc(fcomplex);
static inline unsigned short fctousht(fcomplex);
static inline unsigned fctoui(fcomplex);
static inline unsigned long fctoul(fcomplex);
static inline unsigned long long fctoull(fcomplex);

// signed integer class to float complex
static inline fcomplex ctofc(char);
static inline fcomplex shttofc(short);
static inline fcomplex itofc(int);
static inline fcomplex ltofc(long);
static inline fcomplex lltofc(long long);

// unsigned integer class to float complex
static inline fcomplex uctofc(unsigned char);
static inline fcomplex ushttofc(unsigned short);
static inline fcomplex uitofc(unsigned);
static inline fcomplex ultofc(unsigned long);
static inline fcomplex ulltofc(unsigned long long);

// double complex to signed integer class
static inline char dctoc(dcomplex);
static inline short dctosht(dcomplex);
static inline int dctoi(dcomplex);
static inline long dctol(dcomplex);
static inline long long dctoll(dcomplex);

// double complex to unsigned integer class
static inline unsigned char dctouc(dcomplex);
static inline unsigned short dctousht(dcomplex);
static inline unsigned dctoui(dcomplex);
static inline unsigned long dctoul(dcomplex);
static inline unsigned long long dctoull(dcomplex);

// signed integer class to double complex
static inline dcomplex ctodc(char);
static inline dcomplex shttodc(short);
static inline dcomplex itodc(int);
static inline dcomplex ltodc(long);
static inline dcomplex lltodc(long long);

// unsigned integer class to double complex
static inline dcomplex uctodc(unsigned char);
static inline dcomplex ushttodc(unsigned short);
static inline dcomplex uitodc(unsigned);
static inline dcomplex ultodc(unsigned long);
static inline dcomplex ulltodc(unsigned long long);

// long double complex to signed integer class
static inline char lctoc(lcomplex);
static inline short lctosht(lcomplex);
static inline int lctoi(lcomplex);
static inline long lctol(lcomplex);
static inline long long lctoll(lcomplex);

// long double complex to unsigned integer class
static inline unsigned char lctouc(lcomplex);
static inline unsigned short lctousht(lcomplex);
static inline unsigned lctoui(lcomplex);
static inline unsigned long lctoul(lcomplex);
static inline unsigned long long lctoull(lcomplex);

// signed integer class to long double complex
static inline lcomplex ctolc(char);
static inline lcomplex shttolc(short);
static inline lcomplex itolc(int);
static inline lcomplex ltolc(long);
static inline lcomplex lltolc(long long);

// unsigned integer class to long double complex
static inline lcomplex uctolc(unsigned char);
static inline lcomplex ushttolc(unsigned short);
static inline lcomplex uitolc(unsigned);
static inline lcomplex ultolc(unsigned long);
static inline lcomplex ulltolc(unsigned long long);

/******************************************************************************/
// float complex to float complex
static inline fcomplex
fctofc(fcomplex z)
{
	return z;
}

// float complex to double complex
static inline dcomplex
fctodc(fcomplex z)
{
	dcomplex dz = { (double)z.real, (double)z.imag };
	return dz;
}

// float complex to long double complex
static inline lcomplex
fctolc(fcomplex z)
{
	lcomplex ldz = { (long double)z.real, (long double)z.imag };
	return ldz;
}

/******************************************************************************/
// double complex to float complex
static inline fcomplex
dctofc(dcomplex z)
{
	fcomplex fz = { (float)z.real, (float)z.imag };
	return fz;
}

// double complex to double complex
static inline dcomplex
dctodc(dcomplex z)
{
	return z;
}

// double complex to long double complex
static inline lcomplex
dctolc(dcomplex z)
{
	lcomplex ldz = { (long double)z.real, (long double)z.imag };
	return ldz;
}

/******************************************************************************/
// long double complex to float complex
static inline fcomplex
lctofc(lcomplex z)
{
	fcomplex fz = { (float)z.real, (float)z.imag };
	return fz;
}

// long double complex to double complex
static inline dcomplex
lctodc(lcomplex z)
{
	dcomplex dz = { (double)z.real, (double)z.imag };
	return dz;
}

// long double complex to long double complex
static inline lcomplex
lctolc(lcomplex z)
{
	return z;
}

/******************************************************************************/
// float complex to float
static inline float
fctof(fcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return z.real;
		break;
	default:
		return NAN;
	}
}

// float complex to double
static inline double
fctod(fcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (double)z.real;
		break;
	default:
		return NAN;
	}
}

// float complex to long double
static inline long double
fctold(fcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (long double)z.real;
		break;
	default:
		return NAN;
	}
}

/******************************************************************************/
// double complex to float
static inline float
dctof(dcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (float)z.real;
		break;
	default:
		return NAN;
	}
}

// double complex to double
static inline double
dctod(dcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return z.real;
		break;
	default:
		return NAN;
	}
}

// double complex to long double
static inline long double
dctold(dcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (long double)z.real;
		break;
	default:
		return NAN;
	}
}

/******************************************************************************/
// long double complex to float
static inline float
lctof(lcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (float)z.real;
		break;
	default:
		return NAN;
	}
}

// long double complex to double
static inline double
lctod(lcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (double)z.real;
		break;
	default:
		return NAN;
	}
}

// long double complex to long double
static inline long double
lctold(lcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return z.real;
		break;
	default:
		return NAN;
	}
}

/******************************************************************************/
// float to float complex
static inline fcomplex
ftofc(float x)
{
	fcomplex z = { x, 0 };
	return z;
}

// double to float complex
static inline fcomplex
dtofc(double x)
{
	fcomplex z = { (float)x, 0 };
	return z;
}

// long double to float complex
static inline fcomplex
ldtofc(long double x)
{
	fcomplex z = { (float)x, 0 };
	return z;
}

/******************************************************************************/
// float to double complex
static inline dcomplex
ftodc(float x)
{
	dcomplex z = { (double)x, 0 };
	return z;
}

// double to double complex
static inline dcomplex
dtodc(double x)
{
	dcomplex z = { x, 0 };
	return z;
}

// long double to double complex
static inline dcomplex
ldtodc(long double x)
{
	dcomplex z = { (double)x, 0 };
	return z;
}

/******************************************************************************/
// float to long double complex
static inline lcomplex
ftolc(float x)
{
	lcomplex z = { (long double)x, 0 };
	return z;
}

// double to long double complex
static inline lcomplex
dtolc(double x)
{
	lcomplex z = { (long double)x, 0 };
	return z;
}

// long double to long double complex
static inline lcomplex
ldtolc(long double x)
{
	lcomplex z = { x, 0 };
	return z;
}

/******************************************************************************/
// float complex to signed char
static inline char
fctoc(fcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (char)z.real;
		break;
	default:
		return 0;
	}
}

// float complex to signed short
static inline short
fctosht(fcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (short)z.real;
		break;
	default:
		return 0;
	}
}

// float complex to signed int
static inline int
fctoi(fcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (int)z.real;
		break;
	default:
		return 0;
	}
}

// float complex to long int
static inline long
fctol(fcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (long)z.real;
		break;
	default:
		return 0;
	}
}

// float complex to long long int
static inline long long
fctoll(fcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (long long)z.real;
		break;
	default:
		return 0;
	}
}

/******************************************************************************/
// float complex to unsigned char
static inline unsigned char
fctouc(fcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (unsigned char)z.real;
		break;
	default:
		return 0;
	}
}

// float complex to unsigned short
static inline unsigned short
fctousht(fcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (unsigned short)z.real;
		break;
	default:
		return 0;
	}
}

// float complex to unsigned int
static inline unsigned
fctoui(fcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (unsigned)z.real;
		break;
	default:
		return 0;
	}
}

// float complex to unsigned long int
static inline unsigned long
fctoul(fcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (unsigned long)z.real;
		break;
	default:
		return 0;
	}
}

// float complex to unsigned long long int
static inline unsigned long long
fctoull(fcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (unsigned long long)z.real;
		break;
	default:
		return 0;
	}
}

/******************************************************************************/
// signed char to float complex
static inline fcomplex
ctofc(char x)
{
	fcomplex z = { x, 0 };
	return z;
}

// signed short to float complex
static inline fcomplex
shttofc(short x)
{
	fcomplex z = { x, 0 };
	return z;
}

// signed int to float complex
static inline fcomplex
itofc(int x)
{
	fcomplex z = { x, 0 };
	return z;
}

// signed long int to float complex
static inline fcomplex
ltofc(long x)
{
	fcomplex z = { x, 0 };
	return z;
}

// signed long long int to float complex
static inline fcomplex
lltofc(long long x)
{
	fcomplex z = { x, 0 };
	return z;
}

/******************************************************************************/
// unsigned char to float complex
static inline fcomplex
uctofc(unsigned char x)
{
	fcomplex z = { x, 0 };
	return z;
}

// unsigned short to float complex
static inline fcomplex
ushttofc(unsigned short x)
{
	fcomplex z = { x, 0 };
	return z;
}

// unsigned int to float complex
static inline fcomplex
uitofc(unsigned x)
{
	fcomplex z = { x, 0 };
	return z;
}

// unsigned long int to float complex
static inline fcomplex
ultofc(unsigned long x)
{
	fcomplex z = { x, 0 };
	return z;
}

// unsigned long long int to float complex
static inline fcomplex
ulltofc(unsigned long long x)
{
	fcomplex z = { x, 0 };
	return z;
}

/******************************************************************************/
// signed char to double complex
static inline char
dctoc(dcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (char)z.real;
		break;
	default:
		return 0;
	}
}

// signed short to double complex
static inline short
dctosht(dcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (short)z.real;
		break;
	default:
		return 0;
	}
}

// signed int to double complex
static inline int
dctoi(dcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (int)z.real;
		break;
	default:
		return 0;
	}
}

// signed long int to double complex
static inline long
dctol(dcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (long)z.real;
		break;
	default:
		return 0;
	}
}

// signed long long int to double complex
static inline long long
dctoll(dcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (long long)z.real;
		break;
	default:
		return 0;
	}
}

/******************************************************************************/
// double complex to unsigned char
static inline unsigned char
dctouc(dcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (unsigned char)z.real;
		break;
	default:
		return 0;
	}
}

// double complex to unsigned short
static inline unsigned short
dctousht(dcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (unsigned short)z.real;
		break;
	default:
		return 0;
	}
}

// double complex to unsigned int
static inline unsigned
dctoui(dcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (unsigned)z.real;
		break;
	default:
		return 0;
	}
}

// double complex to unsigned long int
static inline unsigned long
dctoul(dcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (unsigned long)z.real;
		break;
	default:
		return 0;
	}
}

// double complex to unsigned long long int
static inline unsigned long long
dctoull(dcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (unsigned long long)z.real;
		break;
	default:
		return 0;
	}
}

/******************************************************************************/

// signed char to double complex
static inline dcomplex
ctodc(char x)
{
	dcomplex z = { x, 0 };
	return z;
}

// signed short to double complex
static inline dcomplex
shttodc(short x)
{
	dcomplex z = { x, 0 };
	return z;
}

// signed int to double complex
static inline dcomplex
itodc(int x)
{
	dcomplex z = { x, 0 };
	return z;
}

// signed long int to double complex
static inline dcomplex
ltodc(long x)
{
	dcomplex z = { x, 0 };
	return z;
}

// signed long long int to double complex
static inline dcomplex
lltodc(long long x)
{
	dcomplex z = { x, 0 };
	return z;
}

/******************************************************************************/

// unsigned char to double complex
static inline dcomplex
uctodc(unsigned char x)
{
	dcomplex z = { x, 0 };
	return z;
}

// unsigned short to double complex
static inline dcomplex
ushttodc(unsigned short x)
{
	dcomplex z = { x, 0 };
	return z;
}

// unsigned int to double complex
static inline dcomplex
uitodc(unsigned x)
{
	dcomplex z = { x, 0 };
	return z;
}

// unsigned long int to double complex
static inline dcomplex
ultodc(unsigned long x)
{
	dcomplex z = { x, 0 };
	return z;
}

// unsigned long long int to double complex
static inline dcomplex
ulltodc(unsigned long long x)
{
	dcomplex z = { x, 0 };
	return z;
}

/******************************************************************************/

// long double complex to signed char
static inline char
lctoc(lcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (char)z.real;
		break;
	default:
		return 0;
	}
}

// long double complex to signed short
static inline short
lctosht(lcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (short)z.real;
		break;
	default:
		return 0;
	}
}

// long double complex to signed int
static inline int
lctoi(lcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (int)z.real;
		break;
	default:
		return 0;
	}
}

// long double complex to long int
static inline long
lctol(lcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (long)z.real;
		break;
	default:
		return 0;
	}
}

// long double complex to long long int
static inline long long
lctoll(lcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (long long)z.real;
		break;
	default:
		return 0;
	}
}

/******************************************************************************/
// long double complex to unsigned char
static inline unsigned char
lctouc(lcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (unsigned char)z.real;
		break;
	default:
		return 0;
	}
}

// long double complex to unsigned short
static inline unsigned short
lctousht(lcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (unsigned short)z.real;
		break;
	default:
		return 0;
	}
}

// long double complex to unsigned int
static inline unsigned
lctoui(lcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (unsigned)z.real;
		break;
	default:
		return 0;
	}
}

// long double complex to unsigned long int
static inline unsigned long
lctoul(lcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (unsigned long)z.real;
		break;
	default:
		return 0;
	}
}

// long double complex to unsigned long long int
static inline unsigned long long
lctoull(lcomplex z)
{
	switch (fpclassify(z.imag)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return (unsigned long long)z.real;
		break;
	default:
		return 0;
	}
}

/******************************************************************************/
// signed char to long double complex
static inline lcomplex
ctolc(char x)
{
	lcomplex z = { x, 0 };
	return z;
}

// signed short to long double complex
static inline lcomplex
shttolc(short x)
{
	lcomplex z = { x, 0 };
	return z;
}

// signed int to long double complex
static inline lcomplex
itolc(int x)
{
	lcomplex z = { x, 0 };
	return z;
}

// signed long int to long double complex
static inline lcomplex
ltolc(long x)
{
	lcomplex z = { x, 0 };
	return z;
}

// signed long long int to long doouble complex
static inline lcomplex
lltolc(long long x)
{
	lcomplex z = { x, 0 };
	return z;
}

/******************************************************************************/
// unsigned char to long double complex
static inline lcomplex
uctolc(unsigned char x)
{
	lcomplex z = { x, 0 };
	return z;
}

// unsigned short to long double complex
static inline lcomplex
ushttolc(unsigned short x)
{
	lcomplex z = { x, 0 };
	return z;
}

// unsigned int to long double complex
static inline lcomplex
uitolc(unsigned x)
{
	lcomplex z = { x, 0 };
	return z;
}

// unsigned long int to long double complex
static inline lcomplex
ultolc(unsigned long x)
{
	lcomplex z = { x, 0 };
	return z;
}

// unsigned long long int to long double complex
static inline lcomplex
ulltolc(unsigned long long x)
{
	lcomplex z = { x, 0 };
	return z;
}

/******************************************************************************/

#if defined(__cplusplus)
}
#endif

#endif /* GML_COMPLEX_PRIMITIVE_CAST_H */

