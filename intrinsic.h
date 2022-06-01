/*******************************************************************************
	GLUE-Math Library: Intrinsic

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
/*
 *  This is fork on Compiler's toolchain.
 *  When switched by compiler option, the parser refers to and uses it.
 */
#ifndef GML_KERNEL_INTRINSIC_H
#define GML_KERNEL_INTRINSIC_H

// Operator '+'. Adopt to all C99 standard
extern float complex
	__add_c32__(float complex, float complex);
extern double complex
	__add_c64__(double complex, double complex);
extern long double complex
	__add_c128__(long double complex, long double complex);

// Operator '-'. Adopt to all C99 standard
extern float complex
	__sub_c32__(float complex, float complex);
extern double complex
	__sub_c64__(double complex, double complex);
extern long double complex
	__sub_c128__(long double complex, long double complex);

// Operator '*'. Adopt to all C99 standard
extern float complex
	__mul_c32__(float complex, float complex);
extern double complex
	__mul_c64__(double complex, double complex);
extern long double complex
	__mul_c128__(long double complex, long double complex);

// Operator '/'. Adopt to all C99 standard
extern float complex
	__div_c32__(float complex, float complex);
extern double complex
	__div_c64__(double complex, double complex);
extern long double complex
	__div_c128__(long double complex, long double complex);

// -std=glue99: Operator '**'.
extern float
	__pow_f32__(float, float);
extern double
	__pow_f64__(double, double);
extern long double
	__pow_f128__(long double, long double);

extern float complex
	__pow_c32__(float complex, float complex);
extern double complex
	__pow_c64__(double complex, double complex);
extern long double complex
	__pow_c128__(long double complex, long double complex);

// -std=glue99: Operator '%'. (Operator Overload)
extern float
	__mod_f32__(float, float);
extern double
	__mod_f64__(double, double);
extern long double
	__mod_f128__(long double, long double);

extern float complex
	__mod_c32__(float complex, float complex);
extern double complex
	__mod_c64__(double complex, double complex);
extern long double complex
	__mod_c128__(long double complex, long double complex);

// -std=glue99: Builtin Function 'abs()'
extern float
	__abs_f32__(float, float);
extern double
	__abs_f64__(double, double);
extern long double
	__abs_f128__(long double, long double);

extern float complex
	__abs_c32__(float complex, float complex);
extern double complex
	__abs_c64__(double complex, double complex);
extern long double complex
	__abs_c128__(long double complex, long double complex);


#endif /* GML_KERNEL_INTRINSIC_H */
