/*******************************************************************************
	GLUE-Math ABI: Intrinsic
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "intrinsic.h"
#include "sys/complex/class.h"
#include "sys/complex/build.h"
#include "sys/complex/cast.h"
#include "sys/complex/arithmetic.h"
#include "sys/complex/powers.h"
#include "sys/complex/absolute.h"
#include "sys/complex/argument.h"
#include "sys/complex/conjugate.h"
#include "sys/complex/polar.h"
#include "sys/complex/unary.h"


// Arithmetic convertion
static inline c_primitive_types_t
autocast_2operands(c_operand_t *op1, c_operand_t *op2)
{
	c_primitive_types_t typecast = T_SINT;
	
	switch (op1->type) {
	case T_SCHAR:
		switch (op2->type) {
		case T_SCHAR:
			break;
		case T_UCHAR:
			break;
		case T_SSHORT:
			break;
		case T_USHORT:
			break;
		case T_SINT:
			break;
		case T_UINT:
			typecast = T_UINT;
			break;
		case T_SLONG:
			typecast = T_SLONG;
			break;
		case T_ULONG:
			typecast = T_ULONG;
			break;
		case T_SLONGLONG:
			typecast = T_SLONGLONG;
			break;
		case T_ULONGLONG:
			typecast = T_ULONGLONG;
			break;
		case T_FLOAT32:
			op1->value.float32 = (float)op1->value.schar;
			op1->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_FLOAT64:
			op1->value.float64 = (double)op1->value.schar;
			op1->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT128:
			op1->value.float128 = (long double)op1->value.schar;
			op1->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			op1->value.complex32.real = (float)op1->value.schar;
			op1->value.complex32.imag = 0.0;
			op1->type = T_COMPLEX32;
			typecast = T_COMPLEX32;
			break;
		case T_COMPLEX64:
			op1->value.complex64.real = (double)op1->value.schar;
			op1->value.complex64.imag = 0.0;
			op1->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_COMPLEX128:
			op1->value.complex128.real = (long double)op1->value.schar;
			op1->value.complex128.imag = 0.0L;
			op1->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		default:
			break;
		}
		break;
	case T_UCHAR:
		switch (op2->type) {
		case T_SCHAR:
			break;
		case T_UCHAR:
			break;
		case T_SSHORT:
			break;
		case T_USHORT:
			break;
		case T_SINT:
			break;
		case T_UINT:
			typecast = T_UINT;
			break;
		case T_SLONG:
			typecast = T_SLONG;
			break;
		case T_ULONG:
			typecast = T_ULONG;
			break;
		case T_SLONGLONG:
			typecast = T_SLONGLONG;
			break;
		case T_ULONGLONG:
			typecast = T_ULONGLONG;
			break;
		case T_FLOAT32:
			op1->value.float32 = (float)op1->value.uchar;
			op1->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_FLOAT64:
			op1->value.float64 = (double)op1->value.uchar;
			op1->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT128:
			op1->value.float128 = (long double)op1->value.uchar;
			op1->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			op1->value.complex32.real = (float)op1->value.uchar;
			op1->value.complex32.imag = 0.0;
			op1->type = T_COMPLEX32;
			typecast = T_COMPLEX32;
			break;
		case T_COMPLEX64:
			op1->value.complex64.real = (double)op1->value.uchar;
			op1->value.complex64.imag = 0.0;
			op1->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_COMPLEX128:
			op1->value.complex128.real = (long double)op1->value.uchar;
			op1->value.complex128.imag = 0.0L;
			op1->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		default:
			break;
		}
		break;
	case T_SSHORT:
		switch (op2->type) {
		case T_SCHAR:
			break;
		case T_UCHAR:
			break;
		case T_SSHORT:
			break;
		case T_USHORT:
			break;
		case T_SINT:
			break;
		case T_UINT:
			typecast = T_UINT;
			break;
		case T_SLONG:
			typecast = T_SLONG;
			break;
		case T_ULONG:
			typecast = T_ULONG;
			break;
		case T_SLONGLONG:
			typecast = T_SLONGLONG;
			break;
		case T_ULONGLONG:
			typecast = T_ULONGLONG;
			break;
		case T_FLOAT32:
			op1->value.float32 = (float)op1->value.sshort;
			op1->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_FLOAT64:
			op1->value.float64 = (double)op1->value.sshort;
			op1->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT128:
			op1->value.float128 = (long double)op1->value.sshort;
			op1->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			op1->value.complex32.real = (float)op1->value.sshort;
			op1->value.complex32.imag = 0.0;
			op1->type = T_COMPLEX32;
			typecast = T_COMPLEX32;
			break;
		case T_COMPLEX64:
			op1->value.complex64.real = (double)op1->value.sshort;
			op1->value.complex64.imag = 0.0;
			op1->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_COMPLEX128:
			op1->value.complex128.real = (long double)op1->value.sshort;
			op1->value.complex128.imag = 0.0L;
			op1->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		default:
			break;
		}
		break;
	case T_USHORT:
		switch (op2->type) {
		case T_SCHAR:
			break;
		case T_UCHAR:
			break;
		case T_SSHORT:
			break;
		case T_USHORT:
			break;
		case T_SINT:
			break;
		case T_UINT:
			typecast = T_UINT;
			break;
		case T_SLONG:
			typecast = T_SLONG;
			break;
		case T_ULONG:
			typecast = T_ULONG;
			break;
		case T_SLONGLONG:
			typecast = T_SLONGLONG;
			break;
		case T_ULONGLONG:
			typecast = T_ULONGLONG;
			break;
		case T_FLOAT32:
			op1->value.float32 = (float)op1->value.ushort;
			op1->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_FLOAT64:
			op1->value.float64 = (double)op1->value.ushort;
			op1->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT128:
			op1->value.float128 = (long double)op1->value.ushort;
			op1->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			op1->value.complex32.real = (float)op1->value.ushort;
			op1->value.complex32.imag = 0.0;
			op1->type = T_COMPLEX32;
			typecast = T_COMPLEX32;
			break;
		case T_COMPLEX64:
			op1->value.complex64.real = (double)op1->value.ushort;
			op1->value.complex64.imag = 0.0;
			op1->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_COMPLEX128:
			op1->value.complex128.real = (long double)op1->value.ushort;
			op1->value.complex128.imag = 0.0L;
			op1->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		default:
			break;
		}
		break;
	case T_SINT:
		switch (op2->type) {
		case T_SCHAR:
			break;
		case T_UCHAR:
			break;
		case T_SSHORT:
			break;
		case T_USHORT:
			break;
		case T_SINT:
			break;
		case T_UINT:
			typecast = T_UINT;
			break;
		case T_SLONG:
			typecast = T_SLONG;
			break;
		case T_ULONG:
			typecast = T_ULONG;
			break;
		case T_SLONGLONG:
			typecast = T_SLONGLONG;
			break;
		case T_ULONGLONG:
			typecast = T_ULONGLONG;
			break;
		case T_FLOAT32:
			op1->value.float32 = (float)op1->value.sint;
			op1->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_FLOAT64:
			op1->value.float64 = (double)op1->value.sint;
			op1->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT128:
			op1->value.float128 = (long double)op1->value.sint;
			op1->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			op1->value.complex32.real = (float)op1->value.sint;
			op1->value.complex32.imag = 0.0;
			op1->type = T_COMPLEX32;
			typecast = T_COMPLEX32;
			break;
		case T_COMPLEX64:
			op1->value.complex64.real = (double)op1->value.sint;
			op1->value.complex64.imag = 0.0;
			op1->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_COMPLEX128:
			op1->value.complex128.real = (long double)op1->value.sint;
			op1->value.complex128.imag = 0.0L;
			op1->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		default:
			break;
		}
		break;
	case T_UINT:
		switch (op2->type) {
		case T_SCHAR:
			break;
		case T_UCHAR:
			break;
		case T_SSHORT:
			break;
		case T_USHORT:
			break;
		case T_SINT:
			typecast = T_SINT;
			break;
		case T_UINT:
			typecast = T_UINT;
			break;
		case T_SLONG:
			typecast = T_SLONG;
			break;
		case T_ULONG:
			typecast = T_ULONG;
			break;
		case T_SLONGLONG:
			typecast = T_SLONGLONG;
			break;
		case T_ULONGLONG:
			typecast = T_ULONGLONG;
			break;
		case T_FLOAT32:
			op1->value.float32 = (float)op1->value.uint;
			op1->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_FLOAT64:
			op1->value.float64 = (double)op1->value.uint;
			op1->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT128:
			op1->value.float128 = (long double)op1->value.uint;
			op1->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			op1->value.complex32.real = (float)op1->value.uint;
			op1->value.complex32.imag = 0.0;
			op1->type = T_COMPLEX32;
			typecast = T_COMPLEX32;
			break;
		case T_COMPLEX64:
			op1->value.complex64.real = (double)op1->value.uint;
			op1->value.complex64.imag = 0.0;
			op1->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_COMPLEX128:
			op1->value.complex128.real = (long double)op1->value.uint;
			op1->value.complex128.imag = 0.0L;
			op1->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		default:
			break;
		}
		break;
	case T_SLONG:
		switch (op2->type) {
		case T_SCHAR:
			typecast = T_SLONG;
			break;
		case T_UCHAR:
			typecast = T_ULONG;
			break;
		case T_SSHORT:
			typecast = T_SLONG;
			break;
		case T_USHORT:
			typecast = T_ULONG;
			break;
		case T_SINT:
			typecast = T_SLONG;
			break;
		case T_UINT:
			typecast = T_ULONG;
			break;
		case T_SLONG:
			typecast = T_SLONG;
			break;
		case T_ULONG:
			typecast = T_ULONG;
			break;
		case T_SLONGLONG:
			typecast = T_SLONGLONG;
			break;
		case T_ULONGLONG:
			typecast = T_ULONGLONG;
			break;
		case T_FLOAT32:
			op1->value.float32 = (float)op1->value.slong;
			op1->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_FLOAT64:
			op1->value.float64 = (double)op1->value.slong;
			op1->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT128:
			op1->value.float128 = (long double)op1->value.slong;
			op1->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			op1->value.complex32.real = (float)op1->value.slong;
			op1->value.complex32.imag = 0.0;
			op1->type = T_COMPLEX32;
			typecast = T_COMPLEX32;
			break;
		case T_COMPLEX64:
			op1->value.complex64.real = (double)op1->value.slong;
			op1->value.complex64.imag = 0.0;
			op1->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_COMPLEX128:
			op1->value.complex128.real = (long double)op1->value.slong;
			op1->value.complex128.imag = 0.0L;
			op1->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		default:
			break;
		}
		break;
	case T_ULONG:
		switch (op2->type) {
		case T_SCHAR:
			typecast = T_SLONG;
			break;
		case T_UCHAR:
			typecast = T_ULONG;
			break;
		case T_SSHORT:
			typecast = T_SLONG;
			break;
		case T_USHORT:
			typecast = T_ULONG;
			break;
		case T_SINT:
			typecast = T_SLONG;
			break;
		case T_UINT:
			typecast = T_ULONG;
			break;
		case T_SLONG:
			typecast = T_SLONG;
			break;
		case T_ULONG:
			typecast = T_ULONG;
			break;
		case T_SLONGLONG:
			typecast = T_SLONGLONG;
			break;
		case T_ULONGLONG:
			typecast = T_ULONGLONG;
			break;
		case T_FLOAT32:
			op1->value.float32 = (float)op1->value.ulong;
			op1->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_FLOAT64:
			op1->value.float64 = (double)op1->value.ulong;
			op1->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT128:
			op1->value.float128 = (long double)op1->value.ulong;
			op1->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			op1->value.complex32.real = (float)op1->value.ulong;
			op1->value.complex32.imag = 0.0;
			op1->type = T_COMPLEX32;
			typecast = T_COMPLEX32;
			break;
		case T_COMPLEX64:
			op1->value.complex64.real = (double)op1->value.ulong;
			op1->value.complex64.imag = 0.0;
			op1->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_COMPLEX128:
			op1->value.complex128.real = (long double)op1->value.ulong;
			op1->value.complex128.imag = 0.0L;
			op1->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		default:
			break;
		}
		break;
	case T_SLONGLONG:
		switch (op2->type) {
		case T_SCHAR:
			typecast = T_SLONGLONG;
			break;
		case T_UCHAR:
			typecast = T_ULONGLONG;
			break;
		case T_SSHORT:
			typecast = T_SLONGLONG;
			break;
		case T_USHORT:
			typecast = T_ULONGLONG;
			break;
		case T_SINT:
			typecast = T_SLONGLONG;
			break;
		case T_UINT:
			typecast = T_ULONGLONG;
			break;
		case T_SLONG:
			typecast = T_SLONGLONG;
			break;
		case T_ULONG:
			typecast = T_ULONGLONG;
			break;
		case T_SLONGLONG:
			typecast = T_SLONGLONG;
			break;
		case T_ULONGLONG:
			typecast = T_ULONGLONG;
			break;
		case T_FLOAT32:
			op1->value.float32 = (float)op1->value.slonglong;
			op1->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_FLOAT64:
			op1->value.float64 = (double)op1->value.slonglong;
			op1->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT128:
			op1->value.float128 = (long double)op1->value.slonglong;
			op1->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			op1->value.complex32.real = (float)op1->value.slonglong;
			op1->value.complex32.imag = 0.0;
			op1->type = T_COMPLEX32;
			typecast = T_COMPLEX32;
			break;
		case T_COMPLEX64:
			op1->value.complex64.real = (double)op1->value.slonglong;
			op1->value.complex64.imag = 0.0;
			op1->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_COMPLEX128:
			op1->value.complex128.real = (long double)op1->value.slonglong;
			op1->value.complex128.imag = 0.0L;
			op1->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		default:
			break;
		}
		break;
	case T_ULONGLONG:
		switch (op2->type) {
		case T_SCHAR:
			typecast = T_SLONGLONG;
			break;
		case T_UCHAR:
			typecast = T_ULONGLONG;
			break;
		case T_SSHORT:
			typecast = T_SLONGLONG;
			break;
		case T_USHORT:
			typecast = T_ULONGLONG;
			break;
		case T_SINT:
			typecast = T_SLONGLONG;
			break;
		case T_UINT:
			typecast = T_ULONGLONG;
			break;
		case T_SLONG:
			typecast = T_SLONGLONG;
			break;
		case T_ULONG:
			typecast = T_ULONGLONG;
			break;
		case T_SLONGLONG:
			typecast = T_SLONGLONG;
			break;
		case T_ULONGLONG:
			typecast = T_ULONGLONG;
			break;
		case T_FLOAT32:
			op1->value.float32 = (float)op1->value.ulonglong;
			op1->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_FLOAT64:
			op1->value.float64 = (double)op1->value.ulonglong;
			op1->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT128:
			op1->value.float128 = (long double)op1->value.ulonglong;
			op1->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			op1->value.complex32.real = (float)op1->value.ulonglong;
			op1->value.complex32.imag = 0.0;
			op1->type = T_COMPLEX32;
			typecast = T_COMPLEX32;
			break;
		case T_COMPLEX64:
			op1->value.complex64.real = (double)op1->value.ulonglong;
			op1->value.complex64.imag = 0.0;
			op1->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_COMPLEX128:
			op1->value.complex128.real = (long double)op1->value.ulonglong;
			op1->value.complex128.imag = 0.0L;
			op1->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		default:
			break;
		}
		break;
	case T_FLOAT32:
		switch (op2->type) {
		case T_SCHAR:
			op2->value.float32 = (float)op2->value.schar;
			op2->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_UCHAR:
			op2->value.float32 = (float)op2->value.uchar;
			op2->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_SSHORT:
			op2->value.float32 = (float)op2->value.sshort;
			op2->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_USHORT:
			op2->value.float32 = (float)op2->value.ushort;
			op2->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_SINT:
			op2->value.float32 = (float)op2->value.sint;
			op2->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_UINT:
			op2->value.float32 = (float)op2->value.uint;
			op2->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_SLONG:
			op2->value.float32 = (float)op2->value.slong;
			op2->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_ULONG:
			op2->value.float32 = (float)op2->value.ulong;
			op2->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_SLONGLONG:
			op2->value.float32 = (float)op2->value.slonglong;
			op2->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_ULONGLONG:
			op2->value.float32 = (float)op2->value.ulonglong;
			op2->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_FLOAT32:
			typecast = T_FLOAT32;
			break;
		case T_FLOAT64:
			op1->value.float64 = (double)op1->value.float32;
			op1->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT128:
			op1->value.float128 = (long double)op1->value.float32;
			op1->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			op1->value.complex32.real = op1->value.float32;
			op1->value.complex32.imag = 0.0;
			op1->type = T_COMPLEX32;
			typecast = T_COMPLEX32;
			break;
		case T_COMPLEX64:
			op1->value.complex64.real = (double)op1->value.float32;
			op1->value.complex64.imag = 0.0;
			op1->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_COMPLEX128:
			op1->value.complex128.real = (long double)op1->value.float32;
			op1->value.complex128.imag = 0.0L;
			op1->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		default:
			break;
		}
		break;
	case T_FLOAT64:
		switch (op2->type) {
		case T_SCHAR:
			op2->value.float64 = (double)op2->value.schar;
			op2->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_UCHAR:
			op2->value.float64 = (double)op2->value.uchar;
			op2->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_SSHORT:
			op2->value.float64 = (double)op2->value.sshort;
			op2->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_USHORT:
			op2->value.float64 = (double)op2->value.ushort;
			op2->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_SINT:
			op2->value.float64 = (double)op2->value.sint;
			op2->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_UINT:
			op2->value.float64 = (double)op2->value.uint;
			op2->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_SLONG:
			op2->value.float64 = (double)op2->value.slong;
			op2->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_ULONG:
			op2->value.float64 = (double)op2->value.ulong;
			op2->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_SLONGLONG:
			op2->value.float64 = (double)op2->value.slonglong;
			op2->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_ULONGLONG:
			op2->value.float64 = (double)op2->value.ulonglong;
			op2->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT32:
			op2->value.float64 = (double)op2->value.float32;
			op2->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT64:
			typecast = T_FLOAT64;
			break;
		case T_FLOAT128:
			op1->value.float128 = (long double)op1->value.float64;
			op1->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			op1->value.complex64.real = op1->value.float64;
			op1->value.complex64.imag = 0.0;
			op1->type = T_COMPLEX64;
			{
				dcomplex temp;
				temp.real = (double)op2->value.complex32.real;
				temp.imag = (double)op2->value.complex32.imag;
				op2->value.complex64.real = temp.real;
				op2->value.complex64.imag = temp.imag;
			}
			op2->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_COMPLEX64:
			op1->value.complex64.real = op1->value.float64;
			op1->value.complex64.imag = 0.0;
			op1->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_COMPLEX128:
			op1->value.complex128.real = (long double)op1->value.float64;
			op1->value.complex128.imag = 0.0L;
			op1->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		default:
			break;
		}
		break;
	case T_FLOAT128:
		switch (op2->type) {
		case T_SCHAR:
			op2->value.float128 = (long double)op2->value.schar;
			op2->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_UCHAR:
			op2->value.float128 = (long double)op2->value.uchar;
			op2->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_SSHORT:
			op2->value.float128 = (long double)op2->value.sshort;
			op2->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_USHORT:
			op2->value.float128 = (long double)op2->value.ushort;
			op2->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_SINT:
			op2->value.float128 = (long double)op2->value.sint;
			op2->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_UINT:
			op2->value.float128 = (long double)op2->value.uint;
			op2->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_SLONG:
			op2->value.float128 = (long double)op2->value.slong;
			op2->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_ULONG:
			op2->value.float128 = (long double)op2->value.ulong;
			op2->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_SLONGLONG:
			op2->value.float128 = (long double)op2->value.slonglong;
			op2->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_ULONGLONG:
			op2->value.float128 = (long double)op2->value.ulonglong;
			op2->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_FLOAT32:
			op2->value.float128 = (long double)op2->value.float32;
			op2->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_FLOAT64:
			op2->value.float128 = (long double)op2->value.float64;
			op2->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_FLOAT128:
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			op1->value.complex128.real = op1->value.float128;
			op1->value.complex128.imag = 0.0L;
			op1->type = T_COMPLEX128;
			{
				lcomplex temp;
				temp.real = (long double)op2->value.complex32.real;
				temp.imag = (long double)op2->value.complex32.imag;
				op2->value.complex128.real = temp.real;
				op2->value.complex128.imag = temp.imag;
			}
			op2->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		case T_COMPLEX64:
			op1->value.complex128.real = op1->value.float128;
			op1->value.complex128.imag = 0.0L;
			op1->type = T_COMPLEX128;
			{
				lcomplex temp;
				temp.real = (long double)op2->value.complex64.real;
				temp.imag = (long double)op2->value.complex64.imag;
				op2->value.complex128.real = temp.real;
				op2->value.complex128.imag = temp.imag;
			}
			op2->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		case T_COMPLEX128:
			op1->value.complex128.real = op1->value.float128;
			op1->value.complex128.imag = 0.0L;
			op1->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		default:
			break;
		}
		break;
	case T_COMPLEX32:
		switch (op2->type) {
		case T_SCHAR:
			op2->value.complex32.real = (float)op2->value.schar;
			op2->value.complex32.imag = 0.0;
			op2->type = T_COMPLEX32;
			typecast = T_COMPLEX32;
			break;
		case T_UCHAR:
			op2->value.complex32.real = (float)op2->value.uchar;
			op2->value.complex32.imag = 0.0;
			op2->type = T_COMPLEX32;
			typecast = T_COMPLEX32;
			break;
		case T_SSHORT:
			op2->value.complex32.real = (float)op2->value.sshort;
			op2->value.complex32.imag = 0.0;
			op2->type = T_COMPLEX32;
			typecast = T_COMPLEX32;
			break;
		case T_USHORT:
			op2->value.complex32.real = (float)op2->value.ushort;
			op2->value.complex32.imag = 0.0;
			op2->type = T_COMPLEX32;
			typecast = T_COMPLEX32;
			break;
		case T_SINT:
			op2->value.complex32.real = (float)op2->value.sint;
			op2->value.complex32.imag = 0.0;
			op2->type = T_COMPLEX32;
			typecast = T_COMPLEX32;
			break;
		case T_UINT:
			op2->value.complex32.real = (float)op2->value.uint;
			op2->value.complex32.imag = 0.0;
			op2->type = T_COMPLEX32;
			typecast = T_COMPLEX32;
			break;
		case T_SLONG:
			op2->value.complex32.real = (float)op2->value.slong;
			op2->value.complex32.imag = 0.0;
			op2->type = T_COMPLEX32;
			typecast = T_COMPLEX32;
			break;
		case T_ULONG:
			op2->value.complex32.real = (float)op2->value.ulong;
			op2->value.complex32.imag = 0.0;
			op2->type = T_COMPLEX32;
			typecast = T_COMPLEX32;
			break;
		case T_SLONGLONG:
			op2->value.complex32.real = (float)op2->value.slonglong;
			op2->value.complex32.imag = 0.0;
			op2->type = T_COMPLEX32;
			typecast = T_COMPLEX32;
			break;
		case T_ULONGLONG:
			op2->value.complex32.real = (float)op2->value.ulonglong;
			op2->value.complex32.imag = 0.0;
			op2->type = T_COMPLEX32;
			typecast = T_COMPLEX32;
			break;
		case T_FLOAT32:
			op2->value.complex32.real = op2->value.float32;
			op2->value.complex32.imag = 0.0;
			op2->type = T_COMPLEX32;
			typecast = T_COMPLEX32;
			break;
		case T_FLOAT64:
			{
				dcomplex temp = fctodc(fcbuild(
				                op1->value.complex32.real,
				                op1->value.complex32.imag));
				op1->value.complex64.real = temp.real;
				op1->value.complex64.imag = temp.imag;
			}
			op1->type = T_COMPLEX64;
			op2->value.complex64.real = op2->value.float64;
			op2->value.complex64.imag = 0.0;
			op2->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_FLOAT128:
			{
				lcomplex temp = fctolc(fcbuild(
				                op1->value.complex32.real,
				                op1->value.complex32.imag));
				op1->value.complex128.real = temp.real;
				op1->value.complex128.imag = temp.imag;
			}
			op1->type = T_COMPLEX128;
			op2->value.complex128.real = op2->value.float128;
			op2->value.complex128.imag = 0.0L;
			op2->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		case T_COMPLEX32:
			typecast = T_COMPLEX32;
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = fctodc(fcbuild(
				                op1->value.complex32.real,
				                op1->value.complex32.imag));
				op1->value.complex64.real = temp.real;
				op1->value.complex64.imag = temp.imag;
			}
			op1->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = fctolc(fcbuild(
				                op1->value.complex32.real,
				                op1->value.complex32.imag));
				op1->value.complex128.real = temp.real;
				op1->value.complex128.imag = temp.imag;
			}
			op1->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		default:
			break;
		}
		break;
	case T_COMPLEX64:
		switch (op2->type) {
		case T_SCHAR:
			op2->value.complex64.real = (double)op2->value.schar;
			op2->value.complex64.imag = 0.0;
			op2->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_UCHAR:
			op2->value.complex64.real = (double)op2->value.uchar;
			op2->value.complex64.imag = 0.0;
			op2->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_SSHORT:
			op2->value.complex64.real = (double)op2->value.sshort;
			op2->value.complex64.imag = 0.0;
			op2->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_USHORT:
			op2->value.complex64.real = (double)op2->value.ushort;
			op2->value.complex64.imag = 0.0;
			op2->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_SINT:
			op2->value.complex64.real = (double)op2->value.sint;
			op2->value.complex64.imag = 0.0;
			op2->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_UINT:
			op2->value.complex64.real = (double)op2->value.uint;
			op2->value.complex64.imag = 0.0;
			op2->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_SLONG:
			op2->value.complex64.real = (double)op2->value.slong;
			op2->value.complex64.imag = 0.0;
			op2->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_ULONG:
			op2->value.complex64.real = (double)op2->value.ulong;
			op2->value.complex64.imag = 0.0;
			op2->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_SLONGLONG:
			op2->value.complex64.real = (double)op2->value.slonglong;
			op2->value.complex64.imag = 0.0;
			op2->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_ULONGLONG:
			op2->value.complex64.real = (double)op2->value.ulonglong;
			op2->value.complex64.imag = 0.0;
			op2->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_FLOAT32:
			op2->value.complex64.real = (double)op2->value.float32;
			op2->value.complex64.imag = 0.0;
			op2->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_FLOAT64:
			op2->value.complex64.real = op2->value.float64;
			op2->value.complex64.imag = 0.0;
			op2->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_FLOAT128:
			{
				lcomplex temp = dctolc(cbuild(
				                op1->value.complex64.real,
				                op1->value.complex64.imag));
				op1->value.complex128.real = temp.real;
				op1->value.complex128.imag = temp.imag;
			}
			op1->type = T_COMPLEX128;
			op2->value.complex128.real = op2->value.float128;
			op2->value.complex128.imag = 0.0L;
			op2->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		case T_COMPLEX32:
			{
				dcomplex temp = fctodc(fcbuild(
				                op2->value.complex32.real,
				                op2->value.complex32.imag));
				op2->value.complex64.real = temp.real;
				op2->value.complex64.imag = temp.imag;
			}
			op2->type = T_COMPLEX64;
			typecast = T_COMPLEX64;
			break;
		case T_COMPLEX64:
			typecast = T_COMPLEX64;
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = dctolc(cbuild(
				                op1->value.complex64.real,
				                op1->value.complex64.imag));
				op1->value.complex128.real = temp.real;
				op1->value.complex128.imag = temp.imag;
			}
			op1->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		default:
			break;
		}
		break;
	case T_COMPLEX128:
		switch (op2->type) {
		case T_SCHAR:
			op2->value.complex128.real = (long double)op2->value.schar;
			op2->value.complex128.imag = 0.0;
			op2->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		case T_UCHAR:
			op2->value.complex128.real = (long double)op2->value.uchar;
			op2->value.complex128.imag = 0.0;
			op2->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		case T_SSHORT:
			op2->value.complex128.real = (long double)op2->value.sshort;
			op2->value.complex128.imag = 0.0;
			op2->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		case T_USHORT:
			op2->value.complex128.real = (long double)op2->value.ushort;
			op2->value.complex128.imag = 0.0;
			op2->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		case T_SINT:
			op2->value.complex128.real = (long double)op2->value.sint;
			op2->value.complex128.imag = 0.0;
			op2->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		case T_UINT:
			op2->value.complex128.real = (long double)op2->value.uint;
			op2->value.complex128.imag = 0.0;
			op2->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		case T_SLONG:
			op2->value.complex128.real = (long double)op2->value.slong;
			op2->value.complex128.imag = 0.0;
			op2->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		case T_ULONG:
			op2->value.complex128.real = (long double)op2->value.ulong;
			op2->value.complex128.imag = 0.0;
			op2->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		case T_SLONGLONG:
			op2->value.complex128.real = (long double)op2->value.slonglong;
			op2->value.complex128.imag = 0.0;
			op2->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		case T_ULONGLONG:
			op2->value.complex128.real = (long double)op2->value.ulonglong;
			op2->value.complex128.imag = 0.0;
			op2->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		case T_FLOAT32:
			op2->value.complex128.real = (long double)op2->value.float32;
			op2->value.complex128.imag = 0.0L;
			op2->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		case T_FLOAT64:
			op2->value.complex128.real = (long double)op2->value.float64;
			op2->value.complex128.imag = 0.0L;
			op2->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		case T_FLOAT128:
			op2->value.complex128.real = op2->value.float128;
			op2->value.complex128.imag = 0.0L;
			op2->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		case T_COMPLEX32:
			{
				lcomplex temp = fctolc(fcbuild(
				                op2->value.complex32.real,
				                op2->value.complex32.imag));
				op2->value.complex128.real = temp.real;
				op2->value.complex128.imag = temp.imag;
			}
			op2->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		case T_COMPLEX64:
			{
				lcomplex temp = dctolc(cbuild(
				                op2->value.complex64.real,
				                op2->value.complex64.imag));
				op2->value.complex128.real = temp.real;
				op2->value.complex128.imag = temp.imag;
			}
			op2->type = T_COMPLEX128;
			typecast = T_COMPLEX128;
			break;
		case T_COMPLEX128:
			typecast = T_COMPLEX128;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return typecast;
}


// Arithmetic Directly Cast
void
adcast(c_operand_t *orgv, c_operand_t *retv)
{
	switch (retv->type) {
	case T_SCHAR:
		switch (orgv->type) {
		case T_SCHAR:
			retv->value = orgv->value;
			break;
		case T_UCHAR:
			retv->value.schar = (char)orgv->value.uchar;
			break;
		case T_SSHORT:
			retv->value.schar = (char)orgv->value.sshort;
			break;
		case T_USHORT:
			retv->value.schar = (char)orgv->value.ushort;
			break;
		case T_SINT:
			retv->value.schar = (char)orgv->value.sint;
			break;
		case T_UINT:
			retv->value.schar = (char)orgv->value.uint;
			break;
		case T_SLONG:
			retv->value.schar = (char)orgv->value.slong;
			break;
		case T_ULONG:
			retv->value.schar = (char)orgv->value.ulong;
			break;
		case T_SLONGLONG:
			retv->value.schar = (char)orgv->value.slonglong;
			break;
		case T_ULONGLONG:
			retv->value.schar = (char)orgv->value.ulonglong;
			break;
		case T_FLOAT32:
			retv->value.schar = (char)orgv->value.float32;
			break;
		case T_FLOAT64:
			retv->value.schar = (char)orgv->value.float64;
			break;
		case T_FLOAT128:
			retv->value.schar = (char)orgv->value.float128;
			break;
		case T_COMPLEX32:
			{
				fcomplex temp = fcbuild(
				                orgv->value.complex32.real,
				                orgv->value.complex32.imag);
				retv->value.schar = fctoc(temp);
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = cbuild(
				                orgv->value.complex64.real,
				                orgv->value.complex64.imag);
				retv->value.schar = dctoc(temp);
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = lcbuild(
				                orgv->value.complex128.real,
				                orgv->value.complex128.imag);
				retv->value.schar = lctoc(temp);
			}
			break;
		default:
			break;
		}
		break;
	case T_UCHAR:
		switch (orgv->type) {
		case T_SCHAR:
			retv->value.uchar = (unsigned char)orgv->value.schar;
			break;
		case T_UCHAR:
			retv->value = orgv->value;
			break;
		case T_SSHORT:
			retv->value.uchar = (unsigned char)orgv->value.sshort;
			break;
		case T_USHORT:
			retv->value.uchar = (unsigned char)orgv->value.ushort;
			break;
		case T_SINT:
			retv->value.uchar = (unsigned char)orgv->value.sint;
			break;
		case T_UINT:
			retv->value.uchar = (unsigned char)orgv->value.uint;
			break;
		case T_SLONG:
			retv->value.uchar = (unsigned char)orgv->value.sint;
			break;
		case T_ULONG:
			retv->value.uchar = (unsigned char)orgv->value.ulong;
			break;
		case T_SLONGLONG:
			retv->value.uchar = (unsigned char)orgv->value.slonglong;
			break;
		case T_ULONGLONG:
			retv->value.uchar = (unsigned char)orgv->value.ulonglong;
			break;
		case T_FLOAT32:
			retv->value.uchar = (unsigned char)orgv->value.float32;
			break;
		case T_FLOAT64:
			retv->value.uchar = (unsigned char)orgv->value.float64;
			break;
		case T_FLOAT128:
			retv->value.uchar = (unsigned char)orgv->value.float128;
			break;
		case T_COMPLEX32:
			{
				fcomplex temp = fcbuild(
				                orgv->value.complex32.real,
				                orgv->value.complex32.imag);
				retv->value.uchar = fctouc(temp);
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = cbuild(
				                orgv->value.complex64.real,
				                orgv->value.complex64.imag);
				retv->value.uchar = dctouc(temp);
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = lcbuild(
				                orgv->value.complex128.real,
				                orgv->value.complex128.imag);
				retv->value.uchar = lctouc(temp);
			}
			break;
		default:
			break;
		}
		break;
	case T_SSHORT:
		switch (orgv->type) {
		case T_SCHAR:
			retv->value.sshort = (short)orgv->value.schar;
			break;
		case T_UCHAR:
			retv->value.sshort = (short)orgv->value.uchar;
			break;
		case T_SSHORT:
			retv->value = orgv->value;
			break;
		case T_USHORT:
			retv->value.sshort = (short)orgv->value.ushort;
			break;
		case T_SINT:
			retv->value.sshort = (short)orgv->value.sint;
			break;
		case T_UINT:
			retv->value.sshort = (short)orgv->value.uint;
			break;
		case T_SLONG:
			retv->value.sshort = (short)orgv->value.slong;
			break;
		case T_ULONG:
			retv->value.sshort = (short)orgv->value.ulong;
			break;
		case T_SLONGLONG:
			retv->value.sshort = (short)orgv->value.slonglong;
			break;
		case T_ULONGLONG:
			retv->value.sshort = (short)orgv->value.ulonglong;
			break;
		case T_FLOAT32:
			retv->value.sshort = (short)orgv->value.float32;
			break;
		case T_FLOAT64:
			retv->value.sshort = (short)orgv->value.float64;
			break;
		case T_FLOAT128:
			retv->value.sshort = (short)orgv->value.float128;
			break;
		case T_COMPLEX32:
			{
				fcomplex temp = fcbuild(
				                orgv->value.complex32.real,
				                orgv->value.complex32.imag);
				retv->value.sshort = fctosht(temp);
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = cbuild(
				                orgv->value.complex64.real,
				                orgv->value.complex64.imag);
				retv->value.sshort = dctosht(temp);
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = lcbuild(
				                orgv->value.complex128.real,
				                orgv->value.complex128.imag);
				retv->value.sshort = lctosht(temp);
			}
			break;
		default:
			break;
		}
		break;
	case T_USHORT:
		switch (orgv->type) {
		case T_SCHAR:
			retv->value.ushort = (unsigned short)orgv->value.schar;
			break;
		case T_UCHAR:
			retv->value.ushort = (unsigned short)orgv->value.uchar;
			break;
		case T_SSHORT:
			retv->value.ushort = (unsigned short)orgv->value.sshort;
			break;
		case T_USHORT:
			retv->value = orgv->value;
			break;
		case T_SINT:
			retv->value.ushort = (unsigned short)orgv->value.sint;
			break;
		case T_UINT:
			retv->value.ushort = (unsigned short)orgv->value.uint;
			break;
		case T_SLONG:
			retv->value.ushort = (unsigned short)orgv->value.slong;
			break;
		case T_ULONG:
			retv->value.ushort = (unsigned short)orgv->value.ulong;
			break;
		case T_SLONGLONG:
			retv->value.ushort = (unsigned short)orgv->value.slonglong;
			break;
		case T_ULONGLONG:
			retv->value.ushort = (unsigned short)orgv->value.ulonglong;
			break;
		case T_FLOAT32:
			retv->value.ushort = (unsigned short)orgv->value.float32;
			break;
		case T_FLOAT64:
			retv->value.ushort = (unsigned short)orgv->value.float64;
			break;
		case T_FLOAT128:
			retv->value.ushort = (unsigned short)orgv->value.float128;
			break;
		case T_COMPLEX32:
			{
				fcomplex temp = fcbuild(
				                orgv->value.complex32.real,
				                orgv->value.complex32.imag);
				retv->value.ushort = fctousht(temp);
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = cbuild(
				                orgv->value.complex64.real,
				                orgv->value.complex64.imag);
				retv->value.ushort = dctousht(temp);
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = lcbuild(
				                orgv->value.complex128.real,
				                orgv->value.complex128.imag);
				retv->value.ushort = lctousht(temp);
			}
			break;
		default:
			break;
		}
		break;
	case T_SINT:
		switch (orgv->type) {
		case T_SCHAR:
			retv->value.sint = (int)orgv->value.schar;
			break;
		case T_UCHAR:
			retv->value.sint = (int)orgv->value.uchar;
			break;
		case T_SSHORT:
			retv->value.sint = (int)orgv->value.sshort;
			break;
		case T_USHORT:
			retv->value.sint = (int)orgv->value.ushort;
			break;
		case T_SINT:
			retv->value = orgv->value;
			break;
		case T_UINT:
			retv->value.sint = (int)orgv->value.uint;
			break;
		case T_SLONG:
			retv->value.sint = (int)orgv->value.slong;
			break;
		case T_ULONG:
			retv->value.sint = (int)orgv->value.ulong;
			break;
		case T_SLONGLONG:
			retv->value.sint = (int)orgv->value.slonglong;
			break;
		case T_ULONGLONG:
			retv->value.sint = (int)orgv->value.ulonglong;
			break;
		case T_FLOAT32:
			retv->value.sint = (int)orgv->value.float32;
			break;
		case T_FLOAT64:
			retv->value.sint = (int)orgv->value.float64;
			break;
		case T_FLOAT128:
			retv->value.sint = (int)orgv->value.float128;
			break;
		case T_COMPLEX32:
			{
				fcomplex temp = fcbuild(
				                orgv->value.complex32.real,
				                orgv->value.complex32.imag);
				retv->value.sint = fctoi(temp);
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = cbuild(
				                orgv->value.complex64.real,
				                orgv->value.complex64.imag);
				retv->value.sint = dctoi(temp);
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = lcbuild(
				                orgv->value.complex128.real,
				                orgv->value.complex128.imag);
				retv->value.sint = lctoi(temp);
			}
			break;
		default:
			break;
		}
		break;
	case T_UINT:
		switch (orgv->type) {
		case T_SCHAR:
			retv->value.uint = (unsigned int)orgv->value.schar;
			break;
		case T_UCHAR:
			retv->value.uint = (unsigned int)orgv->value.uchar;
			break;
		case T_SSHORT:
			retv->value.uint = (unsigned int)orgv->value.sshort;
			break;
		case T_USHORT:
			retv->value.uint = (unsigned int)orgv->value.ushort;
			break;
		case T_SINT:
			retv->value.uint = (unsigned int)orgv->value.sint;
			break;
		case T_UINT:
			retv->value.uint = (unsigned int)orgv->value.uint;
			break;
		case T_SLONG:
			retv->value.uint = (unsigned int)orgv->value.slong;
			break;
		case T_ULONG:
			retv->value.uint = (unsigned int)orgv->value.ulong;
			break;
		case T_SLONGLONG:
			retv->value.uint = (unsigned int)orgv->value.slonglong;
			break;
		case T_ULONGLONG:
			retv->value.uint = (unsigned int)orgv->value.ulonglong;
			break;
		case T_FLOAT32:
			retv->value.uint = (unsigned int)orgv->value.float32;
			break;
		case T_FLOAT64:
			retv->value.uint = (unsigned int)orgv->value.float64;
			break;
		case T_FLOAT128:
			retv->value.uint = (unsigned int)orgv->value.float128;
			break;
		case T_COMPLEX32:
			{
				fcomplex temp = fcbuild(
				                orgv->value.complex32.real,
				                orgv->value.complex32.imag);
				retv->value.uint = fctoui(temp);
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = cbuild(
				                orgv->value.complex64.real,
				                orgv->value.complex64.imag);
				retv->value.uint = dctoui(temp);
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = lcbuild(
				                orgv->value.complex128.real,
				                orgv->value.complex128.imag);
				retv->value.uint = lctoui(temp);
			}
			break;
		default:
			break;
		}
		break;
	case T_SLONG:
		switch (orgv->type) {
		case T_SCHAR:
			retv->value.slong = (long)orgv->value.schar;
			break;
		case T_UCHAR:
			retv->value.slong = (long)orgv->value.uchar;
			break;
		case T_SSHORT:
			retv->value.slong = (long)orgv->value.sshort;
			break;
		case T_USHORT:
			retv->value.slong = (long)orgv->value.ushort;
			break;
		case T_SINT:
			retv->value.slong = (long)orgv->value.sint;
			break;
		case T_UINT:
			retv->value.slong = (long)orgv->value.uint;
			break;
		case T_SLONG:
			retv->value = orgv->value;
			break;
		case T_ULONG:
			retv->value.slong = (long)orgv->value.ulong;
			break;
		case T_SLONGLONG:
			retv->value.slong = (long)orgv->value.slonglong;
			break;
		case T_ULONGLONG:
			retv->value.slong = (long)orgv->value.ulonglong;
			break;
		case T_FLOAT32:
			retv->value.slong = (long)orgv->value.float32;
			break;
		case T_FLOAT64:
			retv->value.slong = (long)orgv->value.float64;
			break;
		case T_FLOAT128:
			retv->value.slong = (long)orgv->value.float128;
			break;
		case T_COMPLEX32:
			{
				fcomplex temp = fcbuild(
				                orgv->value.complex32.real,
				                orgv->value.complex32.imag);
				retv->value.slong = fctol(temp);
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = cbuild(
				                orgv->value.complex64.real,
				                orgv->value.complex64.imag);
				retv->value.slong = dctol(temp);
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = lcbuild(
				                orgv->value.complex128.real,
				                orgv->value.complex128.imag);
				retv->value.slong = lctol(temp);
			}
			break;
		default:
			break;
		}
		break;
	case T_ULONG:
		switch (orgv->type) {
		case T_SCHAR:
			retv->value.ulong = (unsigned long)orgv->value.schar;
			break;
		case T_UCHAR:
			retv->value.ulong = (unsigned long)orgv->value.uchar;
			break;
		case T_SSHORT:
			retv->value.ulong = (unsigned long)orgv->value.sshort;
			break;
		case T_USHORT:
			retv->value.ulong = (unsigned long)orgv->value.ushort;
			break;
		case T_SINT:
			retv->value.ulong = (unsigned long)orgv->value.sint;
			break;
		case T_UINT:
			retv->value.ulong = (unsigned long)orgv->value.uint;
			break;
		case T_SLONG:
			retv->value.ulong = (unsigned long)orgv->value.slong;
			break;
		case T_ULONG:
			retv->value = orgv->value;
			break;
		case T_SLONGLONG:
			retv->value.ulong = (unsigned long)orgv->value.slonglong;
			break;
		case T_ULONGLONG:
			retv->value.ulong = (unsigned long)orgv->value.ulonglong;
			break;
		case T_FLOAT32:
			retv->value.ulong = (unsigned long)orgv->value.float32;
			break;
		case T_FLOAT64:
			retv->value.ulong = (unsigned long)orgv->value.float64;
			break;
		case T_FLOAT128:
			retv->value.ulong = (unsigned long)orgv->value.float128;
			break;
		case T_COMPLEX32:
			{
				fcomplex temp = fcbuild(
				                orgv->value.complex32.real,
				                orgv->value.complex32.imag);
				retv->value.ulong = fctoul(temp);
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = cbuild(
				                orgv->value.complex64.real,
				                orgv->value.complex64.imag);
				retv->value.ulong = dctoul(temp);
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = lcbuild(
				                orgv->value.complex128.real,
				                orgv->value.complex128.imag);
				retv->value.ulong = lctoul(temp);
			}
			break;
		default:
			break;
		}
		break;
	case T_SLONGLONG:
		switch (orgv->type) {
		case T_SCHAR:
			retv->value.slonglong = (long long)orgv->value.schar;
			break;
		case T_UCHAR:
			retv->value.slonglong = (long long)orgv->value.uchar;
			break;
		case T_SSHORT:
			retv->value.slonglong = (long long)orgv->value.sshort;
			break;
		case T_USHORT:
			retv->value.slonglong = (long long)orgv->value.ushort;
			break;
		case T_SINT:
			retv->value.slonglong = (long long)orgv->value.sint;
			break;
		case T_UINT:
			retv->value.slonglong = (long long)orgv->value.uint;
			break;
		case T_SLONG:
			retv->value.slonglong = (long long)orgv->value.slong;
			break;
		case T_ULONG:
			retv->value.slonglong = (long long)orgv->value.ulong;
			break;
		case T_SLONGLONG:
			retv->value = orgv->value;
			break;
		case T_ULONGLONG:
			retv->value.slonglong = (long long)orgv->value.ulonglong;
			break;
		case T_FLOAT32:
			retv->value.slonglong = (long long)orgv->value.float32;
			break;
		case T_FLOAT64:
			retv->value.slonglong = (long long)orgv->value.float64;
			break;
		case T_FLOAT128:
			retv->value.slonglong = (long long)orgv->value.float128;
			break;
		case T_COMPLEX32:
			{
				fcomplex temp = fcbuild(
				                orgv->value.complex32.real,
				                orgv->value.complex32.imag);
				retv->value.slonglong = fctoll(temp);
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = cbuild(
				                orgv->value.complex64.real,
				                orgv->value.complex64.imag);
				retv->value.slonglong = dctoll(temp);
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = lcbuild(
				                orgv->value.complex128.real,
				                orgv->value.complex128.imag);
				retv->value.slonglong = lctoll(temp);
			}
			break;
		default:
			break;
		}
		break;
	case T_ULONGLONG:
		switch (orgv->type) {
		case T_SCHAR:
			retv->value.ulonglong = (unsigned long long)orgv->value.schar;
			break;
		case T_UCHAR:
			retv->value.ulonglong = (unsigned long long)orgv->value.uchar;
			break;
		case T_SSHORT:
			retv->value.ulonglong = (unsigned long long)orgv->value.sshort;
			break;
		case T_USHORT:
			retv->value.ulonglong = (unsigned long long)orgv->value.ushort;
			break;
		case T_SINT:
			retv->value.ulonglong = (unsigned long long)orgv->value.sint;
			break;
		case T_UINT:
			retv->value.ulonglong = (unsigned long long)orgv->value.uint;
			break;
		case T_SLONG:
			retv->value.ulonglong = (unsigned long long)orgv->value.slong;
			break;
		case T_ULONG:
			retv->value.ulonglong = (unsigned long long)orgv->value.ulong;
			break;
		case T_SLONGLONG:
			retv->value.ulonglong = (unsigned long long)orgv->value.slonglong;
			break;
		case T_ULONGLONG:
			retv->value = orgv->value;
			break;
		case T_FLOAT32:
			retv->value.ulonglong = (unsigned long long)orgv->value.float32;
			break;
		case T_FLOAT64:
			retv->value.ulonglong = (unsigned long long)orgv->value.float64;
			break;
		case T_FLOAT128:
			retv->value.ulonglong = (unsigned long long)orgv->value.float128;
			break;
		case T_COMPLEX32:
			{
				fcomplex temp = fcbuild(
				                orgv->value.complex32.real,
				                orgv->value.complex32.imag);
				retv->value.ulonglong = fctoull(temp);
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = cbuild(
				                orgv->value.complex64.real,
				                orgv->value.complex64.imag);
				retv->value.ulonglong = dctoull(temp);
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = lcbuild(
				                orgv->value.complex128.real,
				                orgv->value.complex128.imag);
				retv->value.ulonglong = lctoull(temp);
			}
			break;
		default:
			break;
		}
		break;
	case T_FLOAT32:
		switch (orgv->type) {
		case T_SCHAR:
			retv->value.float32 = (float)orgv->value.schar;
			break;
		case T_UCHAR:
			retv->value.float32 = (float)orgv->value.uchar;
			break;
		case T_SSHORT:
			retv->value.float32 = (float)orgv->value.sshort;
			break;
		case T_USHORT:
			retv->value.float32 = (float)orgv->value.ushort;
			break;
		case T_SINT:
			retv->value.float32 = (float)orgv->value.sint;
			break;
		case T_UINT:
			retv->value.float32 = (float)orgv->value.uint;
			break;
		case T_SLONG:
			retv->value.float32 = (float)orgv->value.slong;
			break;
		case T_ULONG:
			retv->value.float32 = (float)orgv->value.ulong;
			break;
		case T_SLONGLONG:
			retv->value.float32 = (float)orgv->value.slonglong;
			break;
		case T_ULONGLONG:
			retv->value.float32 = (float)orgv->value.ulonglong;
			break;
		case T_FLOAT32:
			retv->value = orgv->value;
			break;
		case T_FLOAT64:
			retv->value.float32 = (float)orgv->value.float64;
			break;
		case T_FLOAT128:
			retv->value.float32 = (float)orgv->value.float128;
			break;
		case T_COMPLEX32:
			{
				fcomplex temp = fcbuild(
				                orgv->value.complex32.real,
				                orgv->value.complex32.imag);
				retv->value.float32 = fctof(temp);
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = cbuild(
				                orgv->value.complex64.real,
				                orgv->value.complex64.imag);
				retv->value.float32 = dctof(temp);
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = lcbuild(
				                orgv->value.complex128.real,
				                orgv->value.complex128.imag);
				retv->value.float32 = lctof(temp);
			}
			break;
		default:
			break;
		}
		break;
	case T_FLOAT64:
		switch (orgv->type) {
		case T_SCHAR:
			retv->value.float64 = (double)orgv->value.schar;
			break;
		case T_UCHAR:
			retv->value.float64 = (double)orgv->value.uchar;
			break;
		case T_SSHORT:
			retv->value.float64 = (double)orgv->value.sshort;
			break;
		case T_USHORT:
			retv->value.float64 = (double)orgv->value.ushort;
			break;
		case T_SINT:
			retv->value.float64 = (double)orgv->value.sint;
			break;
		case T_UINT:
			retv->value.float64 = (double)orgv->value.uint;
			break;
		case T_SLONG:
			retv->value.float64 = (double)orgv->value.slong;
			break;
		case T_ULONG:
			retv->value.float64 = (double)orgv->value.ulong;
			break;
		case T_SLONGLONG:
			retv->value.float64 = (double)orgv->value.slonglong;
			break;
		case T_ULONGLONG:
			retv->value.float64 = (double)orgv->value.ulonglong;
			break;
		case T_FLOAT32:
			retv->value.float64 = (double)orgv->value.float32;
			break;
		case T_FLOAT64:
			retv->value = orgv->value;
			break;
		case T_FLOAT128:
			retv->value.float64 = (double)orgv->value.float128;
			break;
		case T_COMPLEX32:
			{
				fcomplex temp = fcbuild(
				                orgv->value.complex32.real,
				                orgv->value.complex32.imag);
				retv->value.float64 = fctod(temp);
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = cbuild(
				                orgv->value.complex64.real,
				                orgv->value.complex64.imag);
				retv->value.float64 = dctod(temp);
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = lcbuild(
				                orgv->value.complex128.real,
				                orgv->value.complex128.imag);
				retv->value.float64 = lctod(temp);
			}
			break;
		default:
			break;
		}
		break;
	case T_FLOAT128:
		switch (orgv->type) {
		case T_SCHAR:
			retv->value.float128 = (long double)orgv->value.schar;
			break;
		case T_UCHAR:
			retv->value.float128 = (long double)orgv->value.uchar;
			break;
		case T_SSHORT:
			retv->value.float128 = (long double)orgv->value.sshort;
			break;
		case T_USHORT:
			retv->value.float128 = (long double)orgv->value.ushort;
			break;
		case T_SINT:
			retv->value.float128 = (long double)orgv->value.sint;
			break;
		case T_UINT:
			retv->value.float128 = (long double)orgv->value.uint;
			break;
		case T_SLONG:
			retv->value.float128 = (long double)orgv->value.slong;
			break;
		case T_ULONG:
			retv->value.float128 = (long double)orgv->value.ulong;
			break;
		case T_SLONGLONG:
			retv->value.float128 = (long double)orgv->value.slonglong;
			break;
		case T_ULONGLONG:
			retv->value.float128 = (long double)orgv->value.ulonglong;
			break;
		case T_FLOAT32:
			retv->value.float128 = (long double)orgv->value.float32;
			break;
		case T_FLOAT64:
			retv->value.float128 = (long double)orgv->value.float64;
			break;
		case T_FLOAT128:
			retv->value = orgv->value;
			break;
		case T_COMPLEX32:
			{
				fcomplex temp = fcbuild(
				                orgv->value.complex32.real,
				                orgv->value.complex32.imag);
				retv->value.float128 = fctold(temp);
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = cbuild(
				                orgv->value.complex64.real,
				                orgv->value.complex64.imag);
				retv->value.float128 = dctold(temp);
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = lcbuild(
				                orgv->value.complex128.real,
				                orgv->value.complex128.imag);
				retv->value.float128 = lctold(temp);
			}
			break;
		default:
			break;
		}
		break;
	case T_COMPLEX32:
		switch (orgv->type) {
		case T_SCHAR:
			{
				fcomplex temp = ctofc(orgv->value.schar);
				retv->value.complex32.real = temp.real;
				retv->value.complex32.imag = temp.imag;
			}
			break;
		case T_UCHAR:
			{
				fcomplex temp = uctofc(orgv->value.uchar);
				retv->value.complex32.real = temp.real;
				retv->value.complex32.imag = temp.imag;
			}
			break;
		case T_SSHORT:
			{
				fcomplex temp = shttofc(orgv->value.sshort);
				retv->value.complex32.real = temp.real;
				retv->value.complex32.imag = temp.imag;
			}
			break;
		case T_USHORT:
			{
				fcomplex temp = ushttofc(orgv->value.ushort);
				retv->value.complex32.real = temp.real;
				retv->value.complex32.imag = temp.imag;
			}
			break;
		case T_SINT:
			{
				fcomplex temp = itofc(orgv->value.sint);
				retv->value.complex32.real = temp.real;
				retv->value.complex32.imag = temp.imag;
			}
			break;
		case T_UINT:
			{
				fcomplex temp = uitofc(orgv->value.uint);
				retv->value.complex32.real = temp.real;
				retv->value.complex32.imag = temp.imag;
			}
			break;
		case T_SLONG:
			{
				fcomplex temp = ltofc(orgv->value.slong);
				retv->value.complex32.real = temp.real;
				retv->value.complex32.imag = temp.imag;
			}
			break;
		case T_ULONG:
			{
				fcomplex temp = ultofc(orgv->value.ulong);
				retv->value.complex32.real = temp.real;
				retv->value.complex32.imag = temp.imag;
			}
			break;
		case T_SLONGLONG:
			{
				fcomplex temp = lltofc(orgv->value.slonglong);
				retv->value.complex32.real = temp.real;
				retv->value.complex32.imag = temp.imag;
			}
			break;
		case T_ULONGLONG:
			{
				fcomplex temp = ulltofc(orgv->value.ulonglong);
				retv->value.complex32.real = temp.real;
				retv->value.complex32.imag = temp.imag;
			}
			break;
		case T_FLOAT32:
			{
				fcomplex temp = ftofc(orgv->value.float32);
				retv->value.complex32.real = temp.real;
				retv->value.complex32.imag = temp.imag;
			}
			break;
		case T_FLOAT64:
			{
				fcomplex temp = dtofc(orgv->value.float64);
				retv->value.complex32.real = temp.real;
				retv->value.complex32.imag = temp.imag;
			}
			break;
		case T_FLOAT128:
			{
				fcomplex temp = ldtofc(orgv->value.float128);
				retv->value.complex32.real = temp.real;
				retv->value.complex32.imag = temp.imag;
			}
			break;
		case T_COMPLEX32:
			retv->value = orgv->value;
			break;
		case T_COMPLEX64:
			{
				fcomplex temp = dctofc(cbuild(
				                orgv->value.complex64.real,
				                orgv->value.complex64.imag));
				retv->value.complex32.real = temp.real;
				retv->value.complex32.imag = temp.imag;
			}
			break;
		case T_COMPLEX128:
			{
				fcomplex temp = lctofc(lcbuild(
				                orgv->value.complex128.real,
				                orgv->value.complex128.imag));
				retv->value.complex32.real = temp.real;
				retv->value.complex32.imag = temp.imag;
			}
			break;
		default:
			break;
		}
		break;
	case T_COMPLEX64:
		switch (orgv->type) {
		case T_SCHAR:
			{
				dcomplex temp = ctodc(orgv->value.schar);
				retv->value.complex64.real = temp.real;
				retv->value.complex64.imag = temp.imag;
			}
			break;
		case T_UCHAR:
			{
				dcomplex temp = uctodc(orgv->value.schar);
				retv->value.complex64.real = temp.real;
				retv->value.complex64.imag = temp.imag;
			}
			break;
		case T_SSHORT:
			{
				dcomplex temp = shttodc(orgv->value.sshort);
				retv->value.complex64.real = temp.real;
				retv->value.complex64.imag = temp.imag;
			}
			break;
		case T_USHORT:
			{
				dcomplex temp = ushttodc(orgv->value.ushort);
				retv->value.complex64.real = temp.real;
				retv->value.complex64.imag = temp.imag;
			}
			break;
		case T_SINT:
			{
				dcomplex temp = itodc(orgv->value.sint);
				retv->value.complex64.real = temp.real;
				retv->value.complex64.imag = temp.imag;
			}
			break;
		case T_UINT:
			{
				dcomplex temp = uitodc(orgv->value.uint);
				retv->value.complex64.real = temp.real;
				retv->value.complex64.imag = temp.imag;
			}
			break;
		case T_SLONG:
			{
				dcomplex temp = ltodc(orgv->value.slong);
				retv->value.complex64.real = temp.real;
				retv->value.complex64.imag = temp.imag;
			}
			break;
		case T_ULONG:
			{
				dcomplex temp = ultodc(orgv->value.ulong);
				retv->value.complex64.real = temp.real;
				retv->value.complex64.imag = temp.imag;
			}
			break;
		case T_SLONGLONG:
			{
				dcomplex temp = lltodc(orgv->value.slonglong);
				retv->value.complex64.real = temp.real;
				retv->value.complex64.imag = temp.imag;
			}
			break;
		case T_ULONGLONG:
			{
				dcomplex temp = ulltodc(orgv->value.ulonglong);
				retv->value.complex64.real = temp.real;
				retv->value.complex64.imag = temp.imag;
			}
			break;
		case T_FLOAT32:
			{
				dcomplex temp = ftodc(orgv->value.float32);
				retv->value.complex64.real = temp.real;
				retv->value.complex64.imag = temp.real;
			}
			break;
		case T_FLOAT64:
			{
				dcomplex temp = dtodc(orgv->value.float64);
				retv->value.complex64.real = temp.real;
				retv->value.complex64.imag = temp.imag;
			}
			break;
		case T_FLOAT128:
			{
				dcomplex temp = ltodc(orgv->value.float128);
				retv->value.complex64.real = temp.real;
				retv->value.complex64.imag = temp.imag;
			}
			break;
		case T_COMPLEX32:
			{
				dcomplex temp = fctodc(fcbuild(
				                orgv->value.complex32.real,
				                orgv->value.complex32.imag));
				retv->value.complex64.real = temp.real;
				retv->value.complex64.imag = temp.imag;
			}
			break;
		case T_COMPLEX64:
			retv->value = orgv->value;
			break;
		case T_COMPLEX128:
			{
				dcomplex temp = lctodc(lcbuild(
				                orgv->value.complex128.real,
				                orgv->value.complex128.imag));
				retv->value.complex64.real = temp.real;
				retv->value.complex64.imag = temp.imag;
			}
			break;
		default:
			break;
		}
		break;
	case T_COMPLEX128:
		switch (orgv->type) {
		case T_SCHAR:
			{
				lcomplex temp = ctolc(orgv->value.schar);
				retv->value.complex128.real = temp.real;
				retv->value.complex128.imag = temp.imag;
			}
			break;
		case T_UCHAR:
			{
				lcomplex temp = uctolc(orgv->value.uchar);
				retv->value.complex128.real = temp.real;
				retv->value.complex128.imag = temp.imag;
			}
			break;
		case T_SSHORT:
			{
				lcomplex temp = shttolc(orgv->value.sshort);
				retv->value.complex128.real = temp.real;
				retv->value.complex128.imag = temp.imag;
			}
			break;
		case T_USHORT:
			{
				lcomplex temp = ushttolc(orgv->value.ushort);
				retv->value.complex128.real = temp.real;
				retv->value.complex128.imag = temp.imag;
			}
			break;
		case T_SINT:
			{
				lcomplex temp = itolc(orgv->value.sint);
				retv->value.complex128.real = temp.real;
				retv->value.complex128.imag = temp.imag;
			}
			break;
		case T_UINT:
			{
				lcomplex temp = uitolc(orgv->value.uint);
				retv->value.complex128.real = temp.real;
				retv->value.complex128.imag = temp.imag;
			}
			break;
		case T_SLONG:
			{
				lcomplex temp = ltolc(orgv->value.slong);
				retv->value.complex128.real = temp.real;
				retv->value.complex128.imag = temp.imag;
			}
			break;
		case T_ULONG:
			{
				lcomplex temp = ultolc(orgv->value.ulong);
				retv->value.complex128.real = temp.real;
				retv->value.complex128.imag = temp.imag;
			}
			break;
		case T_SLONGLONG:
			{
				lcomplex temp = lltolc(orgv->value.slonglong);
				retv->value.complex128.real = temp.real;
				retv->value.complex128.imag = temp.imag;
			}
			break;
		case T_ULONGLONG:
			{
				lcomplex temp = ulltolc(orgv->value.ulonglong);
				retv->value.complex128.real = temp.real;
				retv->value.complex128.imag = temp.imag;
			}
			break;
		case T_FLOAT32:
			{
				lcomplex temp = ftolc(orgv->value.float32);
				retv->value.complex128.real = temp.real;
				retv->value.complex128.imag = temp.imag;
			}
			break;
		case T_FLOAT64:
			{
				lcomplex temp = dtolc(orgv->value.float64);
				retv->value.complex128.real = temp.real;
				retv->value.complex128.imag = temp.imag;
			}
			break;
		case T_FLOAT128:
			{
				lcomplex temp = ldtolc(orgv->value.float128);
				retv->value.complex128.real = temp.real;
				retv->value.complex128.imag = temp.imag;
			}
			break;
		case T_COMPLEX32:
			{
				lcomplex temp = fctolc(fcbuild(
				                orgv->value.complex32.real,
				                orgv->value.complex32.imag));
				retv->value.complex128.real = temp.real;
				retv->value.complex128.imag = temp.imag;
			}
			break;
		case T_COMPLEX64:
			{
				lcomplex temp = dctolc(cbuild(
				                orgv->value.complex64.real,
				                orgv->value.complex64.imag));
				retv->value.complex128.real = temp.real;
				retv->value.complex128.imag = temp.imag;
			}
			break;
		case T_COMPLEX128:
			retv->value = orgv->value;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}
