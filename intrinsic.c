/*******************************************************************************
	GLUE-Math ABI: Intrinsic
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "intrinsic.h"
#include "sys/integer/cast.h"
#include "sys/float/cast.h"
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
			op1->value.float32 = ctof(op1->value.schar);
			op1->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_FLOAT64:
			op1->value.float64 = ctod(op1->value.schar);
			op1->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT128:
			op1->value.float128 = ctold(op1->value.schar);
			op1->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			{
				fcomplex temp = ctofc(op1->value.schar);
				op1->value.complex32.real = temp.real;
				op1->value.complex32.imag = temp.imag;
				op1->type = T_COMPLEX32;
				typecast = T_COMPLEX32;
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = ctodc(op1->value.schar);
				op1->value.complex64.real = temp.real;
				op1->value.complex64.imag = temp.imag;
				op1->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = ctolc(op1->value.schar);
				op1->value.complex128.real = temp.real;
				op1->value.complex128.imag = temp.imag;
				op1->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
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
			op1->value.float32 = uctof(op1->value.uchar);
			op1->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_FLOAT64:
			op1->value.float64 = uctod(op1->value.uchar);
			op1->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT128:
			op1->value.float128 = uctold(op1->value.uchar);
			op1->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			{
				fcomplex temp = uctofc(op1->value.uchar);
				op1->value.complex32.real = temp.real;
				op1->value.complex32.imag = temp.imag;
				op1->type = T_COMPLEX32;
				typecast = T_COMPLEX32;
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = uctodc(op1->value.uchar);
				op1->value.complex64.real = temp.real;
				op1->value.complex64.imag = temp.imag;
				op1->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = uctolc(op1->value.uchar);
				op1->value.complex128.real = temp.real;
				op1->value.complex128.imag = temp.imag;
				op1->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
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
			op1->value.float32 = shttof(op1->value.sshort);
			op1->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_FLOAT64:
			op1->value.float64 = shttod(op1->value.sshort);
			op1->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT128:
			op1->value.float128 = shttold(op1->value.sshort);
			op1->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			{
				fcomplex temp = shttofc(op1->value.sshort);
				op1->value.complex32.real = temp.real;
				op1->value.complex32.imag = temp.imag;
				op1->type = T_COMPLEX32;
				typecast = T_COMPLEX32;
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = shttodc(op1->value.sshort);
				op1->value.complex64.real = temp.real;
				op1->value.complex64.imag = temp.imag;
				op1->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = shttolc(op1->value.sshort);
				op1->value.complex128.real = temp.real;
				op1->value.complex128.imag = temp.imag;
				op1->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
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
			op1->value.float32 = ushttof(op1->value.ushort);
			op1->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_FLOAT64:
			op1->value.float64 = ushttod(op1->value.ushort);
			op1->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT128:
			op1->value.float128 = ushttold(op1->value.ushort);
			op1->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			{
				fcomplex temp = ushttofc(op1->value.ushort);
				op1->value.complex32.real = temp.real;
				op1->value.complex32.imag = temp.imag;
				op1->type = T_COMPLEX32;
				typecast = T_COMPLEX32;
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = ushttodc(op1->value.ushort);
				op1->value.complex64.real = temp.real;
				op1->value.complex64.imag = temp.imag;
				op1->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = ushttolc(op1->value.ushort);
				op1->value.complex128.real = temp.real;
				op1->value.complex128.imag = temp.imag;
				op1->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
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
			op1->value.float32 = itof(op1->value.sint);
			op1->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_FLOAT64:
			op1->value.float64 = itod(op1->value.sint);
			op1->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT128:
			op1->value.float128 = itold(op1->value.sint);
			op1->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			{
				fcomplex temp = itofc(op1->value.sint);
				op1->value.complex32.real = temp.real;
				op1->value.complex32.imag = temp.imag;
				op1->type = T_COMPLEX32;
				typecast = T_COMPLEX32;
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = itodc(op1->value.sint);
				op1->value.complex64.real = temp.real;
				op1->value.complex64.imag = temp.imag;
				op1->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = itolc(op1->value.sint);
				op1->value.complex128.real = temp.real;
				op1->value.complex128.imag = temp.imag;
				op1->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
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
			op1->value.float32 = uitof(op1->value.uint);
			op1->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_FLOAT64:
			op1->value.float64 = uitod(op1->value.uint);
			op1->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT128:
			op1->value.float128 = uitold(op1->value.uint);
			op1->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			{
				fcomplex temp = uitofc(op1->value.uint);
				op1->value.complex32.real = temp.real;
				op1->value.complex32.imag = temp.imag;
				op1->type = T_COMPLEX32;
				typecast = T_COMPLEX32;
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = uitodc(op1->value.uint);
				op1->value.complex64.real = temp.real;
				op1->value.complex64.imag = temp.imag;
				op1->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = uitolc(op1->value.uint);
				op1->value.complex128.real = temp.real;
				op1->value.complex128.imag = temp.imag;
				op1->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
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
			op1->value.float32 = ltof(op1->value.slong);
			op1->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_FLOAT64:
			op1->value.float64 = ltod(op1->value.slong);
			op1->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT128:
			op1->value.float128 = ltold(op1->value.slong);
			op1->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			{
				fcomplex temp = ltofc(op1->value.slong);
				op1->value.complex32.real = temp.real;
				op1->value.complex32.imag = temp.imag;
				op1->type = T_COMPLEX32;
				typecast = T_COMPLEX32;
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = ltodc(op1->value.slong);
				op1->value.complex64.real = temp.real;
				op1->value.complex64.imag = temp.imag;
				op1->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = ltolc(op1->value.slong);
				op1->value.complex128.real = temp.real;
				op1->value.complex128.imag = temp.imag;
				op1->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
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
			op1->value.float32 = ultof(op1->value.ulong);
			op1->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_FLOAT64:
			op1->value.float64 = ultod(op1->value.ulong);
			op1->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT128:
			op1->value.float128 = ultold(op1->value.ulong);
			op1->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			{
				fcomplex temp = ultofc(op1->value.ulong);
				op1->value.complex32.real = temp.real;
				op1->value.complex32.imag = temp.imag;
				op1->type = T_COMPLEX32;
				typecast = T_COMPLEX32;
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = ultodc(op1->value.ulong);
				op1->value.complex64.real = temp.real;
				op1->value.complex64.imag = temp.imag;
				op1->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = ultolc(op1->value.ulong);
				op1->value.complex128.real = temp.real;
				op1->value.complex128.imag = temp.imag;
				op1->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
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
			op1->value.float32 = lltof(op1->value.slonglong);
			op1->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_FLOAT64:
			op1->value.float64 = lltod(op1->value.slonglong);
			op1->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT128:
			op1->value.float128 = lltold(op1->value.slonglong);
			op1->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			{
				fcomplex temp = lltofc(op1->value.slonglong);
				op1->value.complex32.real = temp.real;
				op1->value.complex32.imag = temp.imag;
				op1->type = T_COMPLEX32;
				typecast = T_COMPLEX32;
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = lltodc(op1->value.slonglong);
				op1->value.complex64.real = temp.real;
				op1->value.complex64.imag = temp.imag;
				op1->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = lltolc(op1->value.slonglong);
				op1->value.complex128.real = temp.real;
				op1->value.complex128.imag = temp.imag;
				op1->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
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
			op1->value.float32 = ulltof(op1->value.ulonglong);
			op1->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_FLOAT64:
			op1->value.float64 = ulltod(op1->value.ulonglong);
			op1->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT128:
			op1->value.float128 = ulltold(op1->value.ulonglong);
			op1->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			{
				fcomplex temp = ulltofc(op1->value.ulonglong);
				op1->value.complex32.real = temp.real;
				op1->value.complex32.imag = temp.imag;
				op1->type = T_COMPLEX32;
				typecast = T_COMPLEX32;
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = ulltodc(op1->value.ulonglong);
				op1->value.complex64.real = temp.real;
				op1->value.complex64.imag = temp.imag;
				op1->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = ulltolc(op1->value.ulonglong);
				op1->value.complex128.real = temp.real;
				op1->value.complex128.imag = temp.imag;
				op1->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
			break;
		default:
			break;
		}
		break;
	case T_FLOAT32:
		switch (op2->type) {
		case T_SCHAR:
			op2->value.float32 = ctof(op2->value.schar);
			op2->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_UCHAR:
			op2->value.float32 = uctof(op2->value.uchar);
			op2->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_SSHORT:
			op2->value.float32 = shttof(op2->value.sshort);
			op2->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_USHORT:
			op2->value.float32 = ushttof(op2->value.ushort);
			op2->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_SINT:
			op2->value.float32 = itof(op2->value.sint);
			op2->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_UINT:
			op2->value.float32 = uitof(op2->value.uint);
			op2->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_SLONG:
			op2->value.float32 = ltof(op2->value.slong);
			op2->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_ULONG:
			op2->value.float32 = ultof(op2->value.ulong);
			op2->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_SLONGLONG:
			op2->value.float32 = lltof(op2->value.slonglong);
			op2->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_ULONGLONG:
			op2->value.float32 = ulltof(op2->value.ulonglong);
			op2->type = T_FLOAT32;
			typecast = T_FLOAT32;
			break;
		case T_FLOAT32:
			typecast = T_FLOAT32;
			break;
		case T_FLOAT64:
			op1->value.float64 = ftod(op1->value.float32);
			op1->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT128:
			op1->value.float128 = ftold(op1->value.float32);
			op1->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			{
				fcomplex temp = ftofc(op1->value.float32);
				op1->value.complex32.real = temp.real;
				op1->value.complex32.imag = temp.imag;
				op1->type = T_COMPLEX32;
				typecast = T_COMPLEX32;
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = ftodc(op1->value.float32);
				op1->value.complex64.real = temp.real;
				op1->value.complex64.imag = temp.imag;
				op1->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = ftolc(op1->value.float32);
				op1->value.complex128.real = temp.real;
				op1->value.complex128.imag = temp.imag;
				op1->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
			break;
		default:
			break;
		}
		break;
	case T_FLOAT64:
		switch (op2->type) {
		case T_SCHAR:
			op2->value.float64 = ctod(op2->value.schar);
			op2->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_UCHAR:
			op2->value.float64 = uctod(op2->value.uchar);
			op2->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_SSHORT:
			op2->value.float64 = shttod(op2->value.sshort);
			op2->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_USHORT:
			op2->value.float64 = ushttod(op2->value.ushort);
			op2->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_SINT:
			op2->value.float64 = itod(op2->value.sint);
			op2->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_UINT:
			op2->value.float64 = uitod(op2->value.uint);
			op2->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_SLONG:
			op2->value.float64 = ltod(op2->value.slong);
			op2->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_ULONG:
			op2->value.float64 = ultod(op2->value.ulong);
			op2->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_SLONGLONG:
			op2->value.float64 = lltod(op2->value.slonglong);
			op2->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_ULONGLONG:
			op2->value.float64 = ulltod(op2->value.ulonglong);
			op2->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT32:
			op2->value.float64 = ftod(op2->value.float32);
			op2->type = T_FLOAT64;
			typecast = T_FLOAT64;
			break;
		case T_FLOAT64:
			typecast = T_FLOAT64;
			break;
		case T_FLOAT128:
			op1->value.float128 = dtold(op1->value.float64);
			op1->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			{
				dcomplex temp = dtodc(op1->value.float64);
				op1->value.complex64.real = temp.real;
				op1->value.complex64.imag = temp.imag;
				op1->type = T_COMPLEX64;
				temp = fctodc(fcbuild(
				       op2->value.complex32.real,
				       op2->value.complex32.imag));
				op2->value.complex64.real = temp.real;
				op2->value.complex64.imag = temp.imag;
				op2->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_COMPLEX64:
			{
				dcomplex temp = dtodc(op1->value.float64);
				op1->value.complex64.real = temp.real;
				op1->value.complex64.imag = temp.imag;
				op1->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = dtolc(op1->value.float64);
				op1->value.complex128.real = temp.real;
				op1->value.complex128.imag = temp.imag;
				op1->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
			break;
		default:
			break;
		}
		break;
	case T_FLOAT128:
		switch (op2->type) {
		case T_SCHAR:
			op2->value.float128 = ctold(op2->value.schar);
			op2->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_UCHAR:
			op2->value.float128 = uctold(op2->value.uchar);
			op2->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_SSHORT:
			op2->value.float128 = shttold(op2->value.sshort);
			op2->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_USHORT:
			op2->value.float128 = ushttold(op2->value.ushort);
			op2->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_SINT:
			op2->value.float128 = itold(op2->value.sint);
			op2->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_UINT:
			op2->value.float128 = uitold(op2->value.uint);
			op2->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_SLONG:
			op2->value.float128 = ltold(op2->value.slong);
			op2->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_ULONG:
			op2->value.float128 = ultold(op2->value.ulong);
			op2->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_SLONGLONG:
			op2->value.float128 = lltold(op2->value.slonglong);
			op2->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_ULONGLONG:
			op2->value.float128 = ulltold(op2->value.ulonglong);
			op2->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_FLOAT32:
			op2->value.float128 = ftold(op2->value.float32);
			op2->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_FLOAT64:
			op2->value.float128 = dtold(op2->value.float64);
			op2->type = T_FLOAT128;
			typecast = T_FLOAT128;
			break;
		case T_FLOAT128:
			typecast = T_FLOAT128;
			break;
		case T_COMPLEX32:
			{
				lcomplex temp = ldtolc(op1->value.float128);
				op1->value.complex128.real = temp.real;
				op1->value.complex128.imag = temp.imag;
				op1->type = T_COMPLEX128;
				temp = fctolc(fcbuild(
				       op2->value.complex32.real,
				       op2->value.complex32.imag));
				op2->value.complex128.real = temp.real;
				op2->value.complex128.imag = temp.imag;
				op2->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
			break;
		case T_COMPLEX64:
			{
				lcomplex temp = ldtolc(op1->value.float128);
				op1->value.complex128.real = temp.real;
				op1->value.complex128.imag = temp.imag;
				op1->type = T_COMPLEX128;
				temp = dctolc(cbuild(
				       op2->value.complex64.real,
				       op2->value.complex64.imag));
				op2->value.complex128.real = temp.real;
				op2->value.complex128.imag = temp.imag;
				op2->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = ldtolc(op1->value.float128);
				op1->value.complex128.real = temp.real;
				op1->value.complex128.imag = temp.imag;
				op1->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
			break;
		default:
			break;
		}
		break;
	case T_COMPLEX32:
		switch (op2->type) {
		case T_SCHAR:
			{
				fcomplex temp = ctofc(op2->value.schar);
				op2->value.complex32.real = temp.real;
				op2->value.complex32.imag = temp.imag;
				op2->type = T_COMPLEX32;
				typecast = T_COMPLEX32;
			}
			break;
		case T_UCHAR:
			{
				fcomplex temp = uctofc(op2->value.uchar);
				op2->value.complex32.real = temp.real;
				op2->value.complex32.imag = temp.imag;
				op2->type = T_COMPLEX32;
				typecast = T_COMPLEX32;
			}
			break;
		case T_SSHORT:
			{
				fcomplex temp = shttofc(op2->value.sshort);
				op2->value.complex32.real = temp.real;
				op2->value.complex32.imag = temp.imag;
				op2->type = T_COMPLEX32;
				typecast = T_COMPLEX32;
			}
			break;
		case T_USHORT:
			{
				fcomplex temp = ushttofc(op2->value.ushort);
				op2->value.complex32.real = temp.real;
				op2->value.complex32.imag = temp.imag;
				op2->type = T_COMPLEX32;
				typecast = T_COMPLEX32;
			}
			break;
		case T_SINT:
			{
				fcomplex temp = itofc(op2->value.sint);
				op2->value.complex32.real = temp.real;
				op2->value.complex32.imag = temp.imag;
				op2->type = T_COMPLEX32;
				typecast = T_COMPLEX32;
			}
			break;
		case T_UINT:
			{
				fcomplex temp = uitofc(op2->value.uint);
				op2->value.complex32.real = temp.real;
				op2->value.complex32.imag = temp.imag;
				op2->type = T_COMPLEX32;
				typecast = T_COMPLEX32;
			}
			break;
		case T_SLONG:
			{
				fcomplex temp = ltofc(op2->value.slong);
				op2->value.complex32.real = temp.real;
				op2->value.complex32.imag = temp.imag;
				op2->type = T_COMPLEX32;
				typecast = T_COMPLEX32;
			}
			break;
		case T_ULONG:
			{
				fcomplex temp = ultofc(op2->value.ulong);
				op2->value.complex32.real = temp.real;
				op2->value.complex32.imag = temp.imag;
				op2->type = T_COMPLEX32;
				typecast = T_COMPLEX32;
			}
			break;
		case T_SLONGLONG:
			{
				fcomplex temp = lltofc(op2->value.slonglong);
				op2->value.complex32.real = temp.real;
				op2->value.complex32.imag = temp.imag;
				op2->type = T_COMPLEX32;
				typecast = T_COMPLEX32;
			}
			break;
		case T_ULONGLONG:
			{
				fcomplex temp = ulltofc(op2->value.ulonglong);
				op2->value.complex32.real = temp.real;
				op2->value.complex32.imag = temp.imag;
				op2->type = T_COMPLEX32;
				typecast = T_COMPLEX32;
			}
			break;
		case T_FLOAT32:
			{
				fcomplex temp = ftofc(op2->value.float32);
				op2->value.complex32.real = temp.real;
				op2->value.complex32.imag = temp.imag;
				op2->type = T_COMPLEX32;
				typecast = T_COMPLEX32;
			}
			break;
		case T_FLOAT64:
			{
				dcomplex temp = fctodc(fcbuild(
				                op1->value.complex32.real,
				                op1->value.complex32.imag));
				op1->value.complex64.real = temp.real;
				op1->value.complex64.imag = temp.imag;
				op1->type = T_COMPLEX64;
				temp = dtodc(op2->value.float64);
				op2->value.complex64.real = temp.real;
				op2->value.complex64.imag = temp.imag;
				op2->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_FLOAT128:
			{
				lcomplex temp = fctolc(fcbuild(
				                op1->value.complex32.real,
				                op1->value.complex32.imag));
				op1->value.complex128.real = temp.real;
				op1->value.complex128.imag = temp.imag;
				op1->type = T_COMPLEX128;
				temp = ldtolc(op2->value.float128);
				op2->value.complex128.real = temp.real;
				op2->value.complex128.imag = temp.imag;
				op2->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
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
				op1->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_COMPLEX128:
			{
				lcomplex temp = fctolc(fcbuild(
				                op1->value.complex32.real,
				                op1->value.complex32.imag));
				op1->value.complex128.real = temp.real;
				op1->value.complex128.imag = temp.imag;
				op1->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
			break;
		default:
			break;
		}
		break;
	case T_COMPLEX64:
		switch (op2->type) {
		case T_SCHAR:
			{
				dcomplex temp = ctodc(op2->value.schar);
				op2->value.complex64.real = temp.real;
				op2->value.complex64.imag = temp.imag;
				op2->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_UCHAR:
			{
				dcomplex temp = uctodc(op2->value.uchar);
				op2->value.complex64.real = temp.real;
				op2->value.complex64.imag = temp.imag;
				op2->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_SSHORT:
			{
				dcomplex temp = shttodc(op2->value.sshort);
				op2->value.complex64.real = temp.real;
				op2->value.complex64.imag = temp.imag;
				op2->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_USHORT:
			{
				dcomplex temp = ushttodc(op2->value.ushort);
				op2->value.complex64.real = temp.real;
				op2->value.complex64.imag = temp.imag;
				op2->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_SINT:
			{
				dcomplex temp = itodc(op2->value.sint);
				op2->value.complex64.real = temp.real;
				op2->value.complex64.imag = temp.imag;
				op2->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_UINT:
			{
				dcomplex temp = uitodc(op2->value.uint);
				op2->value.complex64.real = temp.real;
				op2->value.complex64.imag = temp.imag;
				op2->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_SLONG:
			{
				dcomplex temp = ltodc(op2->value.slong);
				op2->value.complex64.real = temp.real;
				op2->value.complex64.imag = temp.imag;
				op2->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_ULONG:
			{
				dcomplex temp = ultodc(op2->value.ulong);
				op2->value.complex64.real = temp.real;
				op2->value.complex64.imag = temp.imag;
				op2->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_SLONGLONG:
			{
				dcomplex temp = ltodc(op2->value.slonglong);
				op2->value.complex64.real = temp.real;
				op2->value.complex64.imag = temp.imag;
				op2->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_ULONGLONG:
			{
				dcomplex temp = ultodc(op2->value.ulonglong);
				op2->value.complex64.real = temp.real;
				op2->value.complex64.imag = temp.imag;
				op2->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_FLOAT32:
			{
				dcomplex temp = ftodc(op2->value.float32);
				op2->value.complex64.real = temp.real;
				op2->value.complex64.imag = temp.imag;
				op2->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_FLOAT64:
			{
				dcomplex temp = dtodc(op2->value.float64);
				op2->value.complex64.real = temp.real;
				op2->value.complex64.imag = temp.imag;
				op2->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
			break;
		case T_FLOAT128:
			{
				lcomplex temp = dctolc(cbuild(
				                op1->value.complex64.real,
				                op1->value.complex64.imag));
				op1->value.complex128.real = temp.real;
				op1->value.complex128.imag = temp.imag;
				op1->type = T_COMPLEX128;
				temp = ldtolc(op2->value.float128);
				op2->value.complex128.real = temp.real;
				op2->value.complex128.imag = temp.imag;
				op2->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
			break;
		case T_COMPLEX32:
			{
				dcomplex temp = fctodc(fcbuild(
				                op2->value.complex32.real,
				                op2->value.complex32.imag));
				op2->value.complex64.real = temp.real;
				op2->value.complex64.imag = temp.imag;
				op2->type = T_COMPLEX64;
				typecast = T_COMPLEX64;
			}
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
				op1->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
			break;
		default:
			break;
		}
		break;
	case T_COMPLEX128:
		switch (op2->type) {
		case T_SCHAR:
			{
				lcomplex temp = ctolc(op2->value.schar);
				op2->value.complex128.real = temp.real;
				op2->value.complex128.imag = temp.imag;
				op2->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
			break;
		case T_UCHAR:
			{
				lcomplex temp = uctolc(op2->value.uchar);
				op2->value.complex128.real = temp.real;
				op2->value.complex128.imag = temp.imag;
				op2->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
			break;
		case T_SSHORT:
			{
				lcomplex temp = shttolc(op2->value.sshort);
				op2->value.complex128.real = temp.real;
				op2->value.complex128.imag = temp.imag;
				op2->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
			break;
		case T_USHORT:
			{
				lcomplex temp = ushttolc(op2->value.ushort);
				op2->value.complex128.real = temp.real;
				op2->value.complex128.imag = temp.imag;
				op2->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
			break;
		case T_SINT:
			{
				lcomplex temp = itolc(op2->value.sint);
				op2->value.complex128.real = temp.real;
				op2->value.complex128.imag = temp.imag;
				op2->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
			break;
		case T_UINT:
			{
				lcomplex temp = uitolc(op2->value.uint);
				op2->value.complex128.real = temp.real;
				op2->value.complex128.imag = temp.imag;
				op2->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
			break;
		case T_SLONG:
			{
				lcomplex temp = ltolc(op2->value.slong);
				op2->value.complex128.real = temp.real;
				op2->value.complex128.imag = temp.imag;
				op2->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
			break;
		case T_ULONG:
			{
				lcomplex temp = ultolc(op2->value.ulong);
				op2->value.complex128.real = temp.real;
				op2->value.complex128.imag = temp.imag;
				op2->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
			break;
		case T_SLONGLONG:
			{
				lcomplex temp = lltolc(op2->value.slonglong);
				op2->value.complex128.real = temp.real;
				op2->value.complex128.imag = temp.imag;
				op2->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
			break;
		case T_ULONGLONG:
			{
				lcomplex temp = ulltolc(op2->value.ulonglong);
				op2->value.complex128.real = temp.real;
				op2->value.complex128.imag = temp.imag;
				op2->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
			break;
		case T_FLOAT32:
			{
				lcomplex temp = ftolc(op2->value.float32);
				op2->value.complex128.real = temp.real;
				op2->value.complex128.imag = temp.imag;
				op2->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
			break;
		case T_FLOAT64:
			{
				lcomplex temp = dtolc(op2->value.float64);
				op2->value.complex128.real = temp.real;
				op2->value.complex128.imag = temp.imag;
				op2->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
			break;
		case T_FLOAT128:
			{
				lcomplex temp = ltolc(op2->value.float128);
				op2->value.complex128.real = temp.real;
				op2->value.complex128.imag = temp.imag;
				op2->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
			break;
		case T_COMPLEX32:
			{
				lcomplex temp = fctolc(fcbuild(
				                op2->value.complex32.real,
				                op2->value.complex32.imag));
				op2->value.complex128.real = temp.real;
				op2->value.complex128.imag = temp.imag;
				op2->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
			break;
		case T_COMPLEX64:
			{
				lcomplex temp = dctolc(cbuild(
				                op2->value.complex64.real,
				                op2->value.complex64.imag));
				op2->value.complex128.real = temp.real;
				op2->value.complex128.imag = temp.imag;
				op2->type = T_COMPLEX128;
				typecast = T_COMPLEX128;
			}
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
			retv->value.schar = uctoc(orgv->value.uchar);
			break;
		case T_SSHORT:
			retv->value.schar = shttoc(orgv->value.sshort);
			break;
		case T_USHORT:
			retv->value.schar = ushttoc(orgv->value.ushort);
			break;
		case T_SINT:
			retv->value.schar = itoc(orgv->value.sint);
			break;
		case T_UINT:
			retv->value.schar = uitoc(orgv->value.uint);
			break;
		case T_SLONG:
			retv->value.schar = ltoc(orgv->value.slong);
			break;
		case T_ULONG:
			retv->value.schar = ultoc(orgv->value.ulong);
			break;
		case T_SLONGLONG:
			retv->value.schar = lltoc(orgv->value.slonglong);
			break;
		case T_ULONGLONG:
			retv->value.schar = ulltoc(orgv->value.ulonglong);
			break;
		case T_FLOAT32:
			retv->value.schar = ftoc(orgv->value.float32);
			break;
		case T_FLOAT64:
			retv->value.schar = dtoc(orgv->value.float64);
			break;
		case T_FLOAT128:
			retv->value.schar = ldtoc(orgv->value.float128);
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
			retv->value.uchar = ctouc(orgv->value.schar);
			break;
		case T_UCHAR:
			retv->value = orgv->value;
			break;
		case T_SSHORT:
			retv->value.uchar = shttouc(orgv->value.sshort);
			break;
		case T_USHORT:
			retv->value.uchar = ushttouc(orgv->value.ushort);
			break;
		case T_SINT:
			retv->value.uchar = itouc(orgv->value.sint);
			break;
		case T_UINT:
			retv->value.uchar = uitouc(orgv->value.uint);
			break;
		case T_SLONG:
			retv->value.uchar = ltouc(orgv->value.slong);
			break;
		case T_ULONG:
			retv->value.uchar = ultouc(orgv->value.ulong);
			break;
		case T_SLONGLONG:
			retv->value.uchar = lltouc(orgv->value.slonglong);
			break;
		case T_ULONGLONG:
			retv->value.uchar = ulltouc(orgv->value.ulonglong);
			break;
		case T_FLOAT32:
			retv->value.uchar = ftouc(orgv->value.float32);
			break;
		case T_FLOAT64:
			retv->value.uchar = dtouc(orgv->value.float64);
			break;
		case T_FLOAT128:
			retv->value.uchar = ldtouc(orgv->value.float128);
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
			retv->value.sshort = ctosht(orgv->value.schar);
			break;
		case T_UCHAR:
			retv->value.sshort = uctosht(orgv->value.uchar);
			break;
		case T_SSHORT:
			retv->value = orgv->value;
			break;
		case T_USHORT:
			retv->value.sshort = ushttosht(orgv->value.ushort);
			break;
		case T_SINT:
			retv->value.sshort = itosht(orgv->value.sint);
			break;
		case T_UINT:
			retv->value.sshort = uitosht(orgv->value.uint);
			break;
		case T_SLONG:
			retv->value.sshort = ltosht(orgv->value.slong);
			break;
		case T_ULONG:
			retv->value.sshort = ultosht(orgv->value.ulong);
			break;
		case T_SLONGLONG:
			retv->value.sshort = lltosht(orgv->value.slonglong);
			break;
		case T_ULONGLONG:
			retv->value.sshort = ulltosht(orgv->value.ulonglong);
			break;
		case T_FLOAT32:
			retv->value.sshort = ftosht(orgv->value.float32);
			break;
		case T_FLOAT64:
			retv->value.sshort = dtosht(orgv->value.float64);
			break;
		case T_FLOAT128:
			retv->value.sshort = ldtosht(orgv->value.float128);
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
			retv->value.ushort = ctousht(orgv->value.schar);
			break;
		case T_UCHAR:
			retv->value.ushort = uctousht(orgv->value.uchar);
			break;
		case T_SSHORT:
			retv->value.ushort = shttousht(orgv->value.sshort);
			break;
		case T_USHORT:
			retv->value = orgv->value;
			break;
		case T_SINT:
			retv->value.ushort = itousht(orgv->value.sint);
			break;
		case T_UINT:
			retv->value.ushort = uitousht(orgv->value.uint);
			break;
		case T_SLONG:
			retv->value.ushort = ltousht(orgv->value.slong);
			break;
		case T_ULONG:
			retv->value.ushort = ultousht(orgv->value.ulong);
			break;
		case T_SLONGLONG:
			retv->value.ushort = lltousht(orgv->value.slonglong);
			break;
		case T_ULONGLONG:
			retv->value.ushort = ulltousht(orgv->value.ulonglong);
			break;
		case T_FLOAT32:
			retv->value.ushort = ftousht(orgv->value.float32);
			break;
		case T_FLOAT64:
			retv->value.ushort = dtousht(orgv->value.float64);
			break;
		case T_FLOAT128:
			retv->value.ushort = ldtousht(orgv->value.float128);
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
			retv->value.sint = ctoi(orgv->value.schar);
			break;
		case T_UCHAR:
			retv->value.sint = uctoi(orgv->value.uchar);
			break;
		case T_SSHORT:
			retv->value.sint = shttoi(orgv->value.sshort);
			break;
		case T_USHORT:
			retv->value.sint = ushttoi(orgv->value.ushort);
			break;
		case T_SINT:
			retv->value = orgv->value;
			break;
		case T_UINT:
			retv->value.sint = uitoi(orgv->value.uint);
			break;
		case T_SLONG:
			retv->value.sint = ltoi(orgv->value.slong);
			break;
		case T_ULONG:
			retv->value.sint = ultoi(orgv->value.ulong);
			break;
		case T_SLONGLONG:
			retv->value.sint = lltoi(orgv->value.slonglong);
			break;
		case T_ULONGLONG:
			retv->value.sint = ulltoi(orgv->value.ulonglong);
			break;
		case T_FLOAT32:
			retv->value.sint = ftoi(orgv->value.float32);
			break;
		case T_FLOAT64:
			retv->value.sint = dtoi(orgv->value.float64);
			break;
		case T_FLOAT128:
			retv->value.sint = ldtoi(orgv->value.float128);
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
			retv->value.uint = ctoui(orgv->value.schar);
			break;
		case T_UCHAR:
			retv->value.uint = uctoui(orgv->value.uchar);
			break;
		case T_SSHORT:
			retv->value.uint = shttoui(orgv->value.sshort);
			break;
		case T_USHORT:
			retv->value.uint = ushttoui(orgv->value.ushort);
			break;
		case T_SINT:
			retv->value.uint = itoui(orgv->value.sint);
			break;
		case T_UINT:
			retv->value = orgv->value;
			break;
		case T_SLONG:
			retv->value.uint = ltoui(orgv->value.slong);
			break;
		case T_ULONG:
			retv->value.uint = ultoui(orgv->value.ulong);
			break;
		case T_SLONGLONG:
			retv->value.uint = lltoui(orgv->value.slonglong);
			break;
		case T_ULONGLONG:
			retv->value.uint = ulltoui(orgv->value.ulonglong);
			break;
		case T_FLOAT32:
			retv->value.uint = ftoui(orgv->value.float32);
			break;
		case T_FLOAT64:
			retv->value.uint = dtoui(orgv->value.float64);
			break;
		case T_FLOAT128:
			retv->value.uint = ldtoui(orgv->value.float128);
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
			retv->value.slong = ctol(orgv->value.schar);
			break;
		case T_UCHAR:
			retv->value.slong = uctol(orgv->value.uchar);
			break;
		case T_SSHORT:
			retv->value.slong = shttol(orgv->value.sshort);
			break;
		case T_USHORT:
			retv->value.slong = ushttol(orgv->value.ushort);
			break;
		case T_SINT:
			retv->value.slong = itol(orgv->value.sint);
			break;
		case T_UINT:
			retv->value.slong = uitol(orgv->value.uint);
			break;
		case T_SLONG:
			retv->value = orgv->value;
			break;
		case T_ULONG:
			retv->value.slong = ultol(orgv->value.ulong);
			break;
		case T_SLONGLONG:
			retv->value.slong = lltol(orgv->value.slonglong);
			break;
		case T_ULONGLONG:
			retv->value.slong = ulltol(orgv->value.ulonglong);
			break;
		case T_FLOAT32:
			retv->value.slong = ftol(orgv->value.float32);
			break;
		case T_FLOAT64:
			retv->value.slong = dtol(orgv->value.float64);
			break;
		case T_FLOAT128:
			retv->value.slong = ldtol(orgv->value.float128);
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
			retv->value.ulong = ctoul(orgv->value.schar);
			break;
		case T_UCHAR:
			retv->value.ulong = uctoul(orgv->value.uchar);
			break;
		case T_SSHORT:
			retv->value.ulong = shttoul(orgv->value.sshort);
			break;
		case T_USHORT:
			retv->value.ulong = ushttoul(orgv->value.ushort);
			break;
		case T_SINT:
			retv->value.ulong = itoul(orgv->value.sint);
			break;
		case T_UINT:
			retv->value.ulong = uitoul(orgv->value.uint);
			break;
		case T_SLONG:
			retv->value.ulong = ltoul(orgv->value.slong);
			break;
		case T_ULONG:
			retv->value = orgv->value;
			break;
		case T_SLONGLONG:
			retv->value.ulong = lltoul(orgv->value.slonglong);
			break;
		case T_ULONGLONG:
			retv->value.ulong = ulltoul(orgv->value.ulonglong);
			break;
		case T_FLOAT32:
			retv->value.ulong = ftoul(orgv->value.float32);
			break;
		case T_FLOAT64:
			retv->value.ulong = dtoul(orgv->value.float64);
			break;
		case T_FLOAT128:
			retv->value.ulong = ldtoul(orgv->value.float128);
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
			retv->value.slonglong = ctoll(orgv->value.schar);
			break;
		case T_UCHAR:
			retv->value.slonglong = uctoll(orgv->value.uchar);
			break;
		case T_SSHORT:
			retv->value.slonglong = shttoll(orgv->value.sshort);
			break;
		case T_USHORT:
			retv->value.slonglong = ushttoll(orgv->value.ushort);
			break;
		case T_SINT:
			retv->value.slonglong = itoll(orgv->value.sint);
			break;
		case T_UINT:
			retv->value.slonglong = uitoll(orgv->value.uint);
			break;
		case T_SLONG:
			retv->value.slonglong = ltoll(orgv->value.slong);
			break;
		case T_ULONG:
			retv->value.slonglong = ultoll(orgv->value.ulong);
			break;
		case T_SLONGLONG:
			retv->value = orgv->value;
			break;
		case T_ULONGLONG:
			retv->value.slonglong = ulltoll(orgv->value.ulonglong);
			break;
		case T_FLOAT32:
			retv->value.slonglong = ftoll(orgv->value.float32);
			break;
		case T_FLOAT64:
			retv->value.slonglong = dtoll(orgv->value.float64);
			break;
		case T_FLOAT128:
			retv->value.slonglong = ldtoll(orgv->value.float128);
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
			retv->value.ulonglong = ctoull(orgv->value.schar);
			break;
		case T_UCHAR:
			retv->value.ulonglong = uctoull(orgv->value.uchar);
			break;
		case T_SSHORT:
			retv->value.ulonglong = shttoull(orgv->value.sshort);
			break;
		case T_USHORT:
			retv->value.ulonglong = ushttoull(orgv->value.ushort);
			break;
		case T_SINT:
			retv->value.ulonglong = itoull(orgv->value.sint);
			break;
		case T_UINT:
			retv->value.ulonglong = uitoull(orgv->value.uint);
			break;
		case T_SLONG:
			retv->value.ulonglong = ltoull(orgv->value.slong);
			break;
		case T_ULONG:
			retv->value.ulonglong = ultoull(orgv->value.ulong);
			break;
		case T_SLONGLONG:
			retv->value.ulonglong = lltoull(orgv->value.slonglong);
			break;
		case T_ULONGLONG:
			retv->value = orgv->value;
			break;
		case T_FLOAT32:
			retv->value.ulonglong = ftoull(orgv->value.float32);
			break;
		case T_FLOAT64:
			retv->value.ulonglong = dtoull(orgv->value.float64);
			break;
		case T_FLOAT128:
			retv->value.ulonglong = ldtoull(orgv->value.float128);
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
			retv->value.float32 = ctof(orgv->value.schar);
			break;
		case T_UCHAR:
			retv->value.float32 = uctof(orgv->value.uchar);
			break;
		case T_SSHORT:
			retv->value.float32 = shttof(orgv->value.sshort);
			break;
		case T_USHORT:
			retv->value.float32 = ushttof(orgv->value.ushort);
			break;
		case T_SINT:
			retv->value.float32 = itof(orgv->value.sint);
			break;
		case T_UINT:
			retv->value.float32 = uitof(orgv->value.uint);
			break;
		case T_SLONG:
			retv->value.float32 = ltof(orgv->value.slong);
			break;
		case T_ULONG:
			retv->value.float32 = ultof(orgv->value.ulong);
			break;
		case T_SLONGLONG:
			retv->value.float32 = lltof(orgv->value.slonglong);
			break;
		case T_ULONGLONG:
			retv->value.float32 = ulltof(orgv->value.ulonglong);
			break;
		case T_FLOAT32:
			retv->value = orgv->value;
			break;
		case T_FLOAT64:
			retv->value.float32 = dtof(orgv->value.float64);
			break;
		case T_FLOAT128:
			retv->value.float32 = ldtof(orgv->value.float128);
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
			retv->value.float64 = ctod(orgv->value.schar);
			break;
		case T_UCHAR:
			retv->value.float64 = uctod(orgv->value.uchar);
			break;
		case T_SSHORT:
			retv->value.float64 = shttod(orgv->value.sshort);
			break;
		case T_USHORT:
			retv->value.float64 = ushttod(orgv->value.ushort);
			break;
		case T_SINT:
			retv->value.float64 = itod(orgv->value.sint);
			break;
		case T_UINT:
			retv->value.float64 = uitod(orgv->value.uint);
			break;
		case T_SLONG:
			retv->value.float64 = ltod(orgv->value.slong);
			break;
		case T_ULONG:
			retv->value.float64 = ultod(orgv->value.ulong);
			break;
		case T_SLONGLONG:
			retv->value.float64 = lltod(orgv->value.slonglong);
			break;
		case T_ULONGLONG:
			retv->value.float64 = ulltod(orgv->value.ulonglong);
			break;
		case T_FLOAT32:
			retv->value.float64 = ftod(orgv->value.float32);
			break;
		case T_FLOAT64:
			retv->value = orgv->value;
			break;
		case T_FLOAT128:
			retv->value.float64 = ldtod(orgv->value.float128);
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
			retv->value.float128 = ctold(orgv->value.schar);
			break;
		case T_UCHAR:
			retv->value.float128 = uctold(orgv->value.uchar);
			break;
		case T_SSHORT:
			retv->value.float128 = shttold(orgv->value.sshort);
			break;
		case T_USHORT:
			retv->value.float128 = ushttold(orgv->value.ushort);
			break;
		case T_SINT:
			retv->value.float128 = itold(orgv->value.sint);
			break;
		case T_UINT:
			retv->value.float128 = uitold(orgv->value.uint);
			break;
		case T_SLONG:
			retv->value.float128 = ltold(orgv->value.slong);
			break;
		case T_ULONG:
			retv->value.float128 = ultold(orgv->value.ulong);
			break;
		case T_SLONGLONG:
			retv->value.float128 = lltold(orgv->value.slonglong);
			break;
		case T_ULONGLONG:
			retv->value.float128 = ulltold(orgv->value.ulonglong);
			break;
		case T_FLOAT32:
			retv->value.float128 = ftold(orgv->value.float32);
			break;
		case T_FLOAT64:
			retv->value.float128 = dtold(orgv->value.float64);
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
