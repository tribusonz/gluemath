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
__inline__ __C32 __add_c32__(__C32, __C32);
__inline__ __C64 __add_c64__(__C64, __C64);
__inline__ __C128 __add_c128__(__C128, __C128);

// Operator '-'. Adopt to all C99 standard
__inline__ __C32 __sub_c32__(__C32, __C32);
__inline__ __C64 __sub_c64__(__C64, __C64);
__inline__ __C128 __sub_c128__(__C128, __C128);

// Operator '*'. Adopt to all C99 standard
__inline__ __C32 __mul_c32__(__C32, __C32);
__inline__ __C64 __mul_c64__(__C64, __C64);
__inline__ __C128 __mul_c128__(__C128, __C128);

// Operator '/'. Adopt to all C99 standard
__inline__ __C32 __div_c32__(__C32, __C32);
__inline__ __C64 __div_c64__(__C64, __C64);
__inline__ __C128 __div_c128__(__C128, __C128);

// -std=glue99: Operator '**'.
__inline__ __F32 __pow_f32__(__F32, __F32);
__inline__ __F64 __pow_f64__(__F64, __F64);
__inline__ __F128 __pow_f128__(__F128, __F128);

__inline__ __C32 __pow_c32__(__C32, __C32);
__inline__ __C64 __pow_c64__(__C64, __C64);
__inline__ __C128 __pow_c128__(__C128, __C128);

// -std=glue99: Operator '%'. (Operator Overload)
__inline__ __F32 __mod_f32__(__F32, __F32);
__inline__ __F64 __mod_f64__(__F64, __F64);
__inline__ __F128 __mod_f128__(__F128, __F128);

__inline__ __C32 __mod_c32__(__C32, __C32);
__inline__ __C64 __mod_c64__(__C64, __C64);
__inline__ __C128 __mod_c128__(__C128, __C128);

// -std=glue99: Builtin Function 'abs()'

__inline__ __F32 __abs_f32__(__F32, __F32);
__inline__ __F64 __abs_f64__(__F64, __F64);
__inline__ __F128 __abs_f128__(__F128, __F128);

__inline__ __C32 __abs_c32__(__C32, __C32);
__inline__ __C64 __abs_c64__(__C64, __C64);
__inline__ __C128 __abs_c128__(__C128, __C128);


#endif /* GML_KERNEL_INTRINSIC_H */
