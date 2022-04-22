/*******************************************************************************
	GLUE-Math FP information

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "info.h"
#include "../../internal/sys/primitive/float/info.h"

char
flt_has_subnorm(void)
{
	get_flt_info();
	return flt_info.has_subnorm;
}

unsigned char
flt_radix(void)
{
	get_flt_info();
	return flt_info.radix;
}

unsigned char
flt_mant_dig(void)
{
	get_flt_info();
	return flt_info.mant_dig;
}

float
flt_epsilon(void)
{
	get_flt_info();
	return flt_info.epsilon;
}

char
flt_eps_10_exp(void)
{
	get_flt_info();
	return flt_info.eps_10_exp;
}

unsigned char
flt_dig(void)
{
	get_flt_info();
	return flt_info.dig;
}

float
flt_max(void)
{
	get_flt_info();
	return flt_info.max;
}

float
flt_min(void)
{
	get_flt_info();
	return flt_info.min;
}

float
flt_true_min(void)
{
	get_flt_info();
	return flt_info.true_min;
}

int
flt_max_exp(void)
{
	get_flt_info();
	return flt_info.max_exp;
}

int
flt_min_exp(void)
{
	get_flt_info();
	return flt_info.min_exp;
}

int
flt_max_10_exp(void)
{
	get_flt_info();
	return flt_info.max_10_exp;
}

int
flt_min_10_exp(void)
{
	get_flt_info();
	return flt_info.min_10_exp;
}

char
dbl_has_subnorm(void)
{
	get_dbl_info();
	return dbl_info.has_subnorm;
}

unsigned char
dbl_radix(void)
{
	get_dbl_info();
	return dbl_info.radix;
}

unsigned char
dbl_mant_dig(void)
{
	get_dbl_info();
	return dbl_info.mant_dig;
}

double
dbl_epsilon(void)
{
	get_dbl_info();
	return dbl_info.epsilon;
}

char
dbl_eps_10_exp(void)
{
	get_dbl_info();
	return dbl_info.eps_10_exp;
}

unsigned char
dbl_dig(void)
{
	get_dbl_info();
	return dbl_info.dig;
}

double
dbl_max(void)
{
	get_dbl_info();
	return dbl_info.max;
}

double
dbl_min(void)
{
	get_dbl_info();
	return dbl_info.min;
}

double
dbl_true_min(void)
{
	get_dbl_info();
	return dbl_info.true_min;
}

int
dbl_max_exp(void)
{
	get_dbl_info();
	return dbl_info.max_exp;
}

int
dbl_min_exp(void)
{
	get_dbl_info();
	return dbl_info.min_exp;
}

int
dbl_max_10_exp(void)
{
	get_dbl_info();
	return dbl_info.max_10_exp;
}

int
dbl_min_10_exp(void)
{
	get_dbl_info();
	return dbl_info.min_10_exp;
}

char
ldbl_has_subnorm(void)
{
	get_ldbl_info();
	return ldbl_info.has_subnorm;
}

unsigned char
ldbl_radix(void)
{
	get_ldbl_info();
	return ldbl_info.radix;
}

unsigned char
ldbl_mant_dig(void)
{
	get_ldbl_info();
	return ldbl_info.mant_dig;
}

long double
ldbl_epsilon(void)
{
	get_ldbl_info();
	return ldbl_info.epsilon;
}

char
ldbl_eps_10_exp(void)
{
	get_ldbl_info();
	return ldbl_info.eps_10_exp;
}

unsigned char
ldbl_dig(void)
{
	get_ldbl_info();
	return ldbl_info.dig;
}

long double
ldbl_max(void)
{
	get_ldbl_info();
	return ldbl_info.max;
}

long double
ldbl_min(void)
{
	get_ldbl_info();
	return ldbl_info.min;
}

long double
ldbl_true_min(void)
{
	get_ldbl_info();
	return ldbl_info.true_min;
}

int
ldbl_max_exp(void)
{
	get_ldbl_info();
	return ldbl_info.max_exp;
}

int
ldbl_min_exp(void)
{
	get_ldbl_info();
	return ldbl_info.min_exp;
}

int
ldbl_max_10_exp(void)
{
	get_ldbl_info();
	return ldbl_info.max_10_exp;
}

int
ldbl_min_10_exp(void)
{
	get_ldbl_info();
	return ldbl_info.min_10_exp;
}
