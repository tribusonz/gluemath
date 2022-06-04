/*******************************************************************************
	GLUE-Math ABI: Intrinsic
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_INTRINSIC_H
#define GML_INTRINSIC_H

#if defined(__cplusplus)
extern "C" {
#endif



typedef union {
	char               schar;
	unsigned char      uchar;
	short              sshort;
	unsigned short     ushort;
	int                sint;
	unsigned int       uint;
	long               slong;
	unsigned long      ulong;
	long long          slonglong;
	unsigned long long ulonglong;
	float              float32;
	double             float64;
	long double        float128;
	struct { float real, imag; }
	                   complex32;
	struct { double real, imag; }
	                   complex64;
	struct { long double real, imag; }
	                   complex128;
} c_primitive_value_t ;

typedef enum {
	T_SCHAR,
	T_UCHAR,
	T_SSHORT,
	T_USHORT,
	T_SINT,
	T_UINT,
	T_SLONG,
	T_ULONG,
	T_SLONGLONG,
	T_ULONGLONG,
	T_FLOAT32,
	T_FLOAT64,
	T_FLOAT128,
	T_COMPLEX32,
	T_COMPLEX64,
	T_COMPLEX128
} c_primitive_types_t ;

// Library Call: Addition
extern c_primitive_value_t
 gluemath_libcall_add(
  c_primitive_value_t arg1, c_primitive_types_t arg1_type,
  c_primitive_value_t arg2, c_primitive_types_t arg2_type,
  c_primitive_types_t retval_type
 );

// Library Call: Subtraction
extern c_primitive_value_t
 gluemath_libcall_sub(
  c_primitive_value_t arg1, c_primitive_types_t arg1_type,
  c_primitive_value_t arg2, c_primitive_types_t arg2_type,
  c_primitive_types_t retval_type
 );

// Library Call: Multiply
extern c_primitive_value_t
 gluemath_libcall_mul(
  c_primitive_value_t arg1, c_primitive_types_t arg1_type,
  c_primitive_value_t arg2, c_primitive_types_t arg2_type,
  c_primitive_types_t retval_type
 );

// Library Call: Division
extern c_primitive_value_t
 gluemath_libcall_div(
  c_primitive_value_t arg1, c_primitive_types_t arg1_type,
  c_primitive_value_t arg2, c_primitive_types_t arg2_type,
  c_primitive_types_t retval_type
 );

// Library Call: Modulo
extern c_primitive_value_t
 gluemath_libcall_mod(
  c_primitive_value_t arg1, c_primitive_types_t arg1_type,
  c_primitive_value_t arg2, c_primitive_types_t arg2_type,
  c_primitive_types_t retval_type
 );

// Library Call: Powers
extern c_primitive_value_t
 gluemath_libcall_pow(
  c_primitive_value_t arg1, c_primitive_types_t arg1_type,
  c_primitive_value_t arg2, c_primitive_types_t arg2_type,
  c_primitive_types_t retval_type
 );

// Library Call: Absolute Value
extern c_primitive_value_t
 gluemath_libcall_abs(
  c_primitive_value_t arg1, c_primitive_types_t arg1_type,
  c_primitive_types_t retval_type
 );

// Library Call: Complex Argument
extern c_primitive_value_t
 gluemath_libcall_arg(
  c_primitive_value_t arg1, c_primitive_types_t arg1_type,
  c_primitive_types_t retval_type
 );

// Library Call: Complex Conjugate
extern c_primitive_value_t
 gluemath_libcall_conj(
  c_primitive_value_t arg1, c_primitive_types_t arg1_type,
  c_primitive_types_t retval_type
 );

// Library Call: Complex Real-part
extern c_primitive_value_t
 gluemath_libcall_creal(
  c_primitive_value_t arg1, c_primitive_types_t arg1_type,
  c_primitive_types_t retval_type
 );

// Library Call: Complex Imaginary-part
extern c_primitive_value_t
 gluemath_libcall_cimag(
  c_primitive_value_t arg1, c_primitive_types_t arg1_type,
  c_primitive_types_t retval_type
 );

#if defined(__cplusplus)
}
#endif

#endif /* GML_INTRINSIC_H */
