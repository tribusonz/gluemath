/*******************************************************************************
	GLUE-Math Standard Library: Radix Converter

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GMLSTD_RADIX_CONVERTER_H
#define GMLSTD_RADIX_CONVERTER_H 1

#if defined(__cplusplus)
extern "C" {
#endif

#define RADCONV_MAX_DECIMAL      1024
#define RADCONV_DOWNCASE            0
#define RADCONV_UPCASE              1
#define RADCONV_VALID_RADIX_MIN     2
#define RADCONV_VALID_RADIX_MAX    36
#define RADCONV_UNARY_AUTO          0
#define RADCONV_UNARY_ENABLE        1
#define RADCONV_UNARY_DISABLE       2

/*
 *  call-seq:
 *    (UserLevel Code)
 *      Radconv.new(x, d) -> Radconv
 *    (Native Code)
 *      radconvn(x, d, m, c[]) -> int
 *      radconvnu(x, d, m, c[]) -> int
 *      radconvnl(x, d, m, c[]) -> int
 *      radconvnul(x, d, m, c[]) -> int
 *      radconvnll(x, d, m, c[]) -> int
 *      radconvnull(x, d, m, c[]) -> int
 * 
 *  The value of the first argument {x} is converted by the radix of the second argument {d},
 *  the length of the third argument {m} is written to the array of the fourth argument {c},
 *  and its length is returned.
 *  If an error occurs, it returns a negative number.
 *  At the user level, it is a class object and returns a structure.
 *  
 *  @x .. the value to refer to
 *        radconvn() for int
 *        radconvnu() for unsigned
 *        radconvnl() for long
 *        radconvnul() for unsigned long
 *        radconvnll() for long long
 *        radconvnull() for unsigned long long
 *  @d .. radix. (2 to 36)
 *  @m .. assign size of @c. (Native code only)
 *  @c .. decimal vector. (Native code only)
 *  @retval .. length of success, or error no.
 *  
 *  ::Exception on ABI::
 *  Return value is -1: If it was not convertion correctly.
 *  Return value is -2: The second argument {d} was outside the specified range.
 */
extern int radconvn(int, int, int, char*);
extern int radconvnu(unsigned, int, int, char*);
extern int radconvnl(long, int, int, char*);
extern int radconvnul(unsigned long, int, int, char*);
extern int radconvnll(long long, int, int, char*);
extern int radconvnull(unsigned long long, int, int, char*);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      Radconv.replace(d) -> Radconv
 *    (Native Code)
 *      radconvr(d1, m1, x1[], d2, m2, x2[]) -> int
 *  
 *  The third argument {x1} which is be self object with specified the length of the-
 *  second argument {m1} and the base is the first argument {d1}, converts to the-
 *  sixth argument {x2} which is be other object with the length of the fifth-
 *  argument {m2} and the base is the fourth argument {d2}, and returns its length.
 *  If an error occurs, it returns a negative number.
 *  At the user level, it is a class object and returns a structure.
 *  
 *  @d1 .. radix of self (Native Code only)
 *  @m1 .. assign size of self (Native Code only)
 *  @x1 .. entity of self (Native Code only)
 *  @d2 .. radix of other
 *  @m2 .. assign size of other (Native Code only)
 *  @x2 .. entity of other (Native Code only)
 *  @retval .. length of success, or error no.
 *  
 *  ::Exception on ABI::
 *  Return value is -1: If it was not convertion correctly.
 *  Return value is -2: The second argument {d} was outside the specified range.
 */
extern int radconvr(int, int, char*, int, int, char*);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      Radconv.to_s -> String
 *    (Native Code)
 *      radconvtos(charcase, unary, size, c[]) -> string
 *  
 *  The fourth argument which the self object, is considered to be the length of
 *  the third argument {size}, and the second argument {unary} determines the unary sign,
 *  formats it with the first argument {charcase}, and returns a string.
 *  
 *  @charcase .. character-case flag
 *  @unary .. unary flag
 *  @size .. size of self (Native Code only)
 *  @c .. entity of self (Native Code only)
 *  @retval .. string convertion of @c
 */
extern char *radconvtos(int, int, int, const char*);


#if defined(__cplusplus)
}
#endif

#endif /* GMLSTD_RADIX_CONVERTER_H */
