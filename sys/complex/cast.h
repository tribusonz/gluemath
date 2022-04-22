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
	return z.real;
}

// float complex to double
static inline double
fctod(fcomplex z)
{
	return (double)z.real;
}

// float complex to long double
static inline long double
fctold(fcomplex z)
{
	return (long double)z.real;
}


/******************************************************************************/
// double complex to float
static inline float
dctof(dcomplex z)
{
	return (float)z.real;
}

// double complex to double
static inline double
dctod(dcomplex z)
{
	return z.real;
}

// double complex to long double
static inline long double
dctold(dcomplex z)
{
	return (long double)z.real;
}

/******************************************************************************/
// long double complex to float
static inline float
lctof(lcomplex z)
{
	return (float)z.real;
}

// long double complex to double
static inline double
lctod(lcomplex z)
{
	return (double)z.real;
}

// long double complex to long double
static inline long double
lctold(lcomplex z)
{
	return z.real;
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
	return (char)z.real;
}

// float complex to signed short
static inline short
fctosht(fcomplex z)
{
	return (short)z.real;
}

// float complex to signed int
static inline int
fctoi(fcomplex z)
{
	return (int)z.real;
}

// float complex to long int
static inline long
fctol(fcomplex z)
{
	return (long)z.real;
}

// float complex to long long int
static inline long long
fctoll(fcomplex z)
{
	return (long long)z.real;
}

/******************************************************************************/
// float complex to unsigned char
static inline unsigned char
fctouc(fcomplex z)
{
	return (unsigned char)z.real;
}

// float complex to unsigned short
static inline unsigned short
fctousht(fcomplex z)
{
	return (unsigned short)z.real;
}

// float complex to unsigned int
static inline unsigned
fctoui(fcomplex z)
{
	return (unsigned)z.real;
}

// float complex to unsigned long int
static inline unsigned long
fctoul(fcomplex z)
{
	return (unsigned long)z.real;
}

// float complex to unsigned long long int
static inline unsigned long long
fctoull(fcomplex z)
{
	return (unsigned long long)z.real;
}

/******************************************************************************/
// signed char to float complex
static inline fcomplex
ctofc(char x)
{
	fcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

// signed short to float complex
static inline fcomplex
shttofc(short x)
{
	fcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

// signed int to float complex
static inline fcomplex
itofc(int x)
{
	fcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

// signed long int to float complex
static inline fcomplex
ltofc(long x)
{
	fcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

// signed long long int to float complex
static inline fcomplex
lltofc(long long x)
{
	fcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

/******************************************************************************/
// unsigned char to float complex
static inline fcomplex
uctofc(unsigned char x)
{
	fcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

// unsigned short to float complex
static inline fcomplex
ushttofc(unsigned short x)
{
	fcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

// unsigned int to float complex
static inline fcomplex
uitofc(unsigned x)
{
	fcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

// unsigned long int to float complex
static inline fcomplex
ultofc(unsigned long x)
{
	fcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

// unsigned long long int to float complex
static inline fcomplex
ulltofc(unsigned long long x)
{
	fcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

/******************************************************************************/
// signed char to double complex
static inline char
dctoc(dcomplex z)
{
	return (char)z.real;
}

// signed short to double complex
static inline short
dctosht(dcomplex z)
{
	return (short)z.real;
}

// signed int to double complex
static inline int
dctoi(dcomplex z)
{
	return (int)z.real;
}

// signed long int to double complex
static inline long
dctol(dcomplex z)
{
	return (long)z.real;
}

// signed long long int to double complex
static inline long long
dctoll(dcomplex z)
{
	return (long long)z.real;
}

/******************************************************************************/
// double complex to unsigned char
static inline unsigned char
dctouc(dcomplex z)
{
	return (unsigned char)z.real;
}

// double complex to unsigned short
static inline unsigned short
dctousht(dcomplex z)
{
	return (unsigned short)z.real;
}

// double complex to unsigned int
static inline unsigned
dctoui(dcomplex z)
{
	return (unsigned)z.real;
}

// double complex to unsigned long int
static inline unsigned long
dctoul(dcomplex z)
{
	return (unsigned long)z.real;
}

// double complex to unsigned long long int
static inline unsigned long long
dctoull(dcomplex z)
{
	return (unsigned long long)z.real;
}

/******************************************************************************/

// signed char to double complex
static inline dcomplex
ctodc(char x)
{
	dcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

// signed short to double complex
static inline dcomplex
shttodc(short x)
{
	dcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

// signed int to double complex
static inline dcomplex
itodc(int x)
{
	dcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

// signed long int to double complex
static inline dcomplex
ltodc(long x)
{
	dcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

// signed long long int to double complex
static inline dcomplex
lltodc(long long x)
{
	dcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

/******************************************************************************/

// unsigned char to double complex
static inline dcomplex
uctodc(unsigned char x)
{
	dcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

// unsigned short to double complex
static inline dcomplex
ushttodc(unsigned short x)
{
	dcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

// unsigned int to double complex
static inline dcomplex
uitodc(unsigned x)
{
	dcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

// unsigned long int to double complex
static inline dcomplex
ultodc(unsigned long x)
{
	dcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

// unsigned long long int to double complex
static inline dcomplex
ulltodc(unsigned long long x)
{
	dcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

/******************************************************************************/

// long double complex to signed char
static inline char
lctoc(lcomplex z)
{
	return (char)z.real;
}

// long double complex to signed short
static inline short
lctosht(lcomplex z)
{
	return (short)z.real;
}

// long double complex to signed int
static inline int
lctoi(lcomplex z)
{
	return (int)z.real;
}

// long double complex to long int
static inline long
lctol(lcomplex z)
{
	return (long)z.real;
}

// long double complex to long long int
static inline long long
lctoll(lcomplex z)
{
	return (long long)z.real;
}

/******************************************************************************/
// long double complex to unsigned char
static inline unsigned char
lctouc(lcomplex z)
{
	return (unsigned char)z.real;
}

// long double complex to unsigned short
static inline unsigned short
lctousht(lcomplex z)
{
	return (unsigned short)z.real;
}

// long double complex to unsigned int
static inline unsigned
lctoui(lcomplex z)
{
	return (unsigned)z.real;
}

// long double complex to unsigned long int
static inline unsigned long
lctoul(lcomplex z)
{
	return (unsigned long)z.real;
}

// long double complex to unsigned long long int
static inline unsigned long long
lctoull(lcomplex z)
{
	return (unsigned long long)z.real;
}

/******************************************************************************/
// signed char to long double complex
static inline lcomplex
ctolc(char x)
{
	lcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

// signed short to long double complex
static inline lcomplex
shttolc(short x)
{
	lcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

// signed int to long double complex
static inline lcomplex
itolc(int x)
{
	lcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

// signed long int to long double complex
static inline lcomplex
ltolc(long x)
{
	lcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

// signed long long int to long doouble complex
static inline lcomplex
lltolc(long long x)
{
	lcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

/******************************************************************************/
// unsigned char to long double complex
static inline lcomplex
uctolc(unsigned char x)
{
	lcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

// unsigned short to long double complex
static inline lcomplex
ushttolc(unsigned short x)
{
	lcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

// unsigned int to long double complex
static inline lcomplex
uitolc(unsigned x)
{
	lcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

// unsigned long int to long double complex
static inline lcomplex
ultolc(unsigned long x)
{
	lcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

// unsigned long long int to long double complex
static inline lcomplex
ulltolc(unsigned long long x)
{
	lcomplex z;
	z.real = x; z.imag = 0;
	return z;
}

/******************************************************************************/

#if defined(__cplusplus)
}
#endif

#endif /* GML_COMPLEX_PRIMITIVE_CAST_H */

