/*******************************************************************************
	GLUE-Math Real number Primitive Setting: Cast (Type Convertion)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_FP_PRIMITIVE_CAST_H
#define GML_FP_PRIMITIVE_CAST_H

#if defined(__cplusplus)
extern "C" {
#endif

/***** For real number classes *****/
// float to other FP
static inline float ftof(float);
static inline double ftod(float);
static inline long double ftold(float);

// double to other FP
static inline float dtof(double);
static inline double dtod(double);
static inline long double dtold(double);

// long double to other FP
static inline float ldtof(long double);
static inline double ldtod(long double);
static inline long double ldtold(long double);

/***** For real number class and integer classes *****/
// float to signed integer class
static inline char ftoc(float);
static inline short ftosht(float);
static inline int ftoi(float);
static inline long ftol(float);
static inline long long ftoll(float);

// float to unsigned integer class
static inline unsigned char ftouc(float);
static inline unsigned short ftousht(float);
static inline unsigned ftoui(float);
static inline unsigned long ftoul(float);
static inline unsigned long long ftoull(float);

// signed integer class to float
static inline float ctof(char);
static inline float shttof(short);
static inline float itof(int);
static inline float ltof(long);
static inline float lltof(long long);

// unsigned integer class to float
static inline float uctof(unsigned char);
static inline float ushttof(unsigned short);
static inline float uitof(unsigned);
static inline float ultof(unsigned long);
static inline float ulltof(unsigned long long);

// double to signed integer class
static inline char dtoc(double);
static inline short dtosht(double);
static inline int dtoi(double);
static inline long dtol(double);
static inline long long dtoll(double);

// double to unsigned integer class
static inline unsigned char dtouc(double);
static inline unsigned short dtousht(double);
static inline unsigned dtoui(double);
static inline unsigned long dtoul(double);
static inline unsigned long long dtoull(double);

// signed integer class to double
static inline double ctod(char);
static inline double shttod(short);
static inline double itod(int);
static inline double ltod(long);
static inline double lltod(long long);

// unsigned integer class to double
static inline double uctod(unsigned char);
static inline double ushttod(unsigned short);
static inline double uitod(unsigned);
static inline double ultod(unsigned long);
static inline double ulltod(unsigned long long);

// long double to signed integer class
static inline char ldtoc(long double);
static inline short ldtosht(long double);
static inline int ldtoi(long double);
static inline long ldtol(long double);
static inline long long ldtoll(long double);

// long double to unsigned integer class
static inline unsigned char ldtouc(long double);
static inline unsigned short ldtousht(long double);
static inline unsigned ldtoui(long double);
static inline unsigned long ldtoul(long double);
static inline unsigned long long ldtoull(long double);

// signed integer class to long double
static inline long double ctold(char);
static inline long double shttold(short);
static inline long double itold(int);
static inline long double ltold(long);
static inline long double lltold(long long);

// unsigned integer class to long double
static inline long double uctold(unsigned char);
static inline long double ushttold(unsigned short);
static inline long double uitold(unsigned);
static inline long double ultold(unsigned long);
static inline long double ulltold(unsigned long long);

/******************************************************************************/
// float to float
static inline float
ftof(float x)
{
	return x;
}

// float to double
static inline double
ftod(float x)
{
	return x;
}

// float to long double
static inline long double
ftold(float x)
{
	return x;
}

/******************************************************************************/
// double to float
static inline float
dtof(double x)
{
	return x;
}

// double to double
static inline double
dtod(double x)
{
	return x;
}

// double to long double
static inline long double
dtold(double x)
{
	return x;
}

/******************************************************************************/
// long double to float
static inline float
ldtof(long double x)
{
	return x;
}

// long double to double
static inline double
ldtod(long double x)
{
	return x;
}

// long double to long double
static inline long double
ldtold(long double x)
{
	return x;
}

/******************************************************************************/
// float to signed char
static inline char
ftoc(float x)
{
	return x;
}

// float to signed short
static inline short
ftosht(float x)
{
	return x;
}

// float to signed int
static inline int
ftoi(float x)
{
	return x;
}

// float to long int
static inline long
ftol(float x)
{
	return x;
}

// float to long long int
static inline long long
ftoll(float x)
{
	return x;
}

/******************************************************************************/
// float to unsigned char
static inline unsigned char
ftouc(float x)
{
	return x;
}

// float to unsigned short
static inline unsigned short
ftousht(float x)
{
	return x;
}

// float to unsigned int
static inline unsigned
ftoui(float x)
{
	return x;
}

// float to unsigned long int
static inline unsigned long
ftoul(float x)
{
	return x;
}

// float to unsigned long long int
static inline unsigned long long
ftoull(float x)
{
	return x;
}

/******************************************************************************/
// signed char to float
static inline float
ctof(char x)
{
	return x;
}

// signed short to float
static inline float
shttof(short x)
{
	return x;
}

// signed int to float
static inline float
itof(int x)
{
	return x;
}

// signed long int to float
static inline float
ltof(long x)
{
	return x;
}

// signed long long int to float
static inline float
lltof(long long x)
{
	return x;
}

/******************************************************************************/
// unsigned char to float
static inline float
uctof(unsigned char x)
{
	return x;
}

// unsigned short to float
static inline float
ushttof(unsigned short x)
{
	return x;
}

// unsigned int to float
static inline float
uitof(unsigned x)
{
	return x;
}

// unsigned long int to float
static inline float
ultof(unsigned long x)
{
	return x;
}

// unsigned long long int to float
static inline float
ulltof(unsigned long long x)
{
	return x;
}

/******************************************************************************/
// double to signed char
static inline char
dtoc(double x)
{
	return x;
}

// double to signed short
static inline short
dtosht(double x)
{
	return x;
}

// double to signed int
static inline int
dtoi(double x)
{
	return x;
}

// double to signed long int
static inline long
dtol(double x)
{
	return x;
}

// double to signed long long int
static inline long long
dtoll(double x)
{
	return x;
}

/******************************************************************************/
// double to unsigned char
static inline unsigned char
dtouc(double x)
{
	return x;
}

// double to unsigned short
static inline unsigned short
dtousht(double x)
{
	return x;
}

// double to unsigned int
static inline unsigned
dtoui(double x)
{
	return x;
}

// double to unsigned long int
static inline unsigned long
dtoul(double x)
{
	return x;
}

// double to unsigned long long int
static inline unsigned long long
dtoull(double x)
{
	return x;
}

/******************************************************************************/

// signed char to double
static inline double
ctod(char x)
{
	return x;
}

// signed short to double
static inline double
shttod(short x)
{
	return x;
}

// signed int to double
static inline double
itod(int x)
{
	return x;
}

// signed long int to double
static inline double
ltod(long x)
{
	return x;
}

// signed long long int to double
static inline double
lltod(long long x)
{
	return x;
}

/******************************************************************************/

// unsigned char to double
static inline double
uctod(unsigned char x)
{
	return x;
}

// unsigned short to double
static inline double
ushttod(unsigned short x)
{
	return x;
}

// unsigned int to double
static inline double
uitod(unsigned x)
{
	return x;
}

// unsigned long int to double
static inline double
ultod(unsigned long x)
{
	return x;
}

// unsigned long long int to double
static inline double
ulltod(unsigned long long x)
{
	return x;
}

/******************************************************************************/

// long double to signed char
static inline char
ldtoc(long double x)
{
	return x;
}

// long double to signed short
static inline short
ldtosht(long double x)
{
	return x;
}

// long double to signed int
static inline int
ldtoi(long double x)
{
	return x;
}

// long double to long int
static inline long
ldtol(long double x)
{
	return x;
}

// long double to long long int
static inline long long
ldtoll(long double x)
{
	return x;
}

/******************************************************************************/
// long double to unsigned char
static inline unsigned char
ldtouc(long double x)
{
	return x;
}

// long double to unsigned short
static inline unsigned short
ldtousht(long double x)
{
	return x;
}

// long double to unsigned int
static inline unsigned
ldtoui(long double x)
{
	return x;
}

// long double to unsigned long int
static inline unsigned long
ldtoul(long double x)
{
	return x;
}

// long double to unsigned long long int
static inline unsigned long long
ldtoull(long double x)
{
	return x;
}

/******************************************************************************/
// signed char to long double
static inline long double
ctold(char x)
{
	return x;
}

// signed short to long double
static inline long double
shttold(short x)
{
	return x;
}

// signed int to long double
static inline long double
itold(int x)
{
	return x;
}

// signed long int to long double
static inline long double
ltold(long x)
{
	return x;
}

// signed long long int to long doouble
static inline long double
lltold(long long x)
{
	return x;
}

/******************************************************************************/
// unsigned char to long double
static inline long double
uctold(unsigned char x)
{
	return x;
}

// unsigned short to long double
static inline long double
ushttold(unsigned short x)
{
	return x;
}

// unsigned int to long double
static inline long double
uitold(unsigned x)
{
	return x;
}

// unsigned long int to long double
static inline long double
ultold(unsigned long x)
{
	return x;
}

// unsigned long long int to long double
static inline long double
ulltold(unsigned long long x)
{
	return x;
}

/******************************************************************************/

#if defined(__cplusplus)
}
#endif

#endif /* GML_FP_PRIMITIVE_CAST_H */

