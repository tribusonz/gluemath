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

// Structures used in fork
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

typedef struct {
	c_primitive_types_t type;
	c_primitive_value_t value;
} c_operand_t ;

// Library Call: Addition
extern void
 gluemath_libcall_add(
  c_operand_t *op1, c_operand_t *op2, c_operand_t *retval, int autocast
 );

// Library Call: Subtraction
extern void
 gluemath_libcall_sub(
  c_operand_t *op1, c_operand_t *op2, c_operand_t *retval, int autocast
 );

// Library Call: Multiply
extern void
 gluemath_libcall_mul(
  c_operand_t *op1, c_operand_t *op2, c_operand_t *retval, int autocast
 );

// Library Call: Division
extern void
 gluemath_libcall_div(
  c_operand_t *op1, c_operand_t *op2, c_operand_t *retval, int autocast
 );

// Library Call: Modulo
extern void
 gluemath_libcall_mod(
  c_operand_t *op1, c_operand_t *op2, c_operand_t *retval, int autocast
 );

// Library Call: Powers
extern void
 gluemath_libcall_pow(
  c_operand_t *op1, c_operand_t *op2, c_operand_t *retval, int autocast
 );

// Library Call: Absolute Value
extern void
 gluemath_libcall_abs(
  c_operand_t *op1, c_operand_t *retval, int autocast
 );

// Library Call: Complex Argument
extern void
 gluemath_libcall_arg(
  c_operand_t *op1, c_operand_t *retval, int autocast
 );

// Library Call: Complex Conjugate
extern void
 gluemath_libcall_conj(
  c_operand_t *op1, c_operand_t *retval, int autocast
 );

// Library Call: Complex Real-part
extern void
 gluemath_libcall_creal(
  c_operand_t *op1, c_operand_t *retval, int autocast
 );

// Library Call: Complex Imaginary-part
extern void
 gluemath_libcall_cimag(
  c_operand_t *op1, c_operand_t *retval, int autocast
 );

// Library Call: Unary Minus
extern void
 gluemath_libcall_uminus(
  c_operand_t *op1, c_operand_t *retval, int autocast
 );

#if defined(__cplusplus)
}
#endif

#endif /* GML_INTRINSIC_H */
