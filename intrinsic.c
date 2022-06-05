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
