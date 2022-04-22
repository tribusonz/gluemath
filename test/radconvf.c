/*******************************************************************************
	Radix Converter for FP
*******************************************************************************/
#define RADCONV_UNARY_AUTO          0
#define RADCONV_UNARY_ENABLE        1
#define RADCONV_UNARY_DISABLE       2

typedef struct {
	char flag; // -4 ... Negative Finite
	           // -3 ... Negative Denormal
	           // -2 ... Negative Zero
	           // -1 ... Negative Infinity
	           //  0 ... NaN
	           //  1 ... Infinity
	           //  2 ... Zero
	           //  3 ... Denormal
	           //  4 ... Finite
	int exponent;
	unsigned long frac[1];
} radconvf_t ;

char *
radconvtosf(int charcase, int unary, int size, radconvf_t *radconv)
{
	static char s[1024];
	char *ptr = s;

	if (charcase || size)  s[0] = '\0'; // maybe_unused, ƒRƒ“ƒpƒCƒ‰‚ð‚¾‚Ü‚·

	switch (radconv->flag) {
	case -4: // -Finite
		break;
	case -3: // -Denormal
		break;
	case -2: // -Zero
		if (unary != RADCONV_UNARY_DISABLE)
			*ptr++ = '-';
		*ptr++ = '0'; *ptr++ = '.'; *ptr++ = '0';
		break;
	case -1: // -Infinity
		if (unary != RADCONV_UNARY_DISABLE)
			*ptr++ = '-';
		*ptr++ = 'I'; *ptr++ = 'n'; *ptr++ = 'f';
		*ptr++ = 'i'; *ptr++ = 'n'; *ptr++ = 'i';
		*ptr++ = 't'; *ptr++ = 'y';
		break;
	case 0: // NaN
		*ptr++ = 'N'; *ptr++ = 'a'; *ptr++ = 'N';
		break;
	case 1: // Infinity
		if (unary == RADCONV_UNARY_ENABLE)
			*ptr++ = '+';
		*ptr++ = 'I'; *ptr++ = 'n'; *ptr++ = 'f';
		*ptr++ = 'i'; *ptr++ = 'n'; *ptr++ = 'i';
		*ptr++ = 't'; *ptr++ = 'y';
		break;
	case 2: // Zero
		if (unary == RADCONV_UNARY_ENABLE)
			*ptr++ = '+';
		*ptr++ = '0'; *ptr++ = '.'; *ptr++ = '0';
		break;
	case 3: // Denormal
		break;
	case 4: // Finite
		break;
	default:
		break;
	}
	*ptr = '\0';
	return s;
}

#include <stdio.h>
int
main(void)
{
	static radconvf_t radconv;
	radconv.flag = 0;
	radconv.exponent = 0;
	radconv.frac[0] = 0;

	printf("NaN is %s\n", radconvtosf(0, RADCONV_UNARY_AUTO, 0, &radconv));
	radconv.flag = 1;
	printf("Infinity is %s\n", radconvtosf(0, RADCONV_UNARY_AUTO, 0, &radconv));
	radconv.flag = -1;
	printf("NegativeInfinity is %s\n", radconvtosf(0, RADCONV_UNARY_AUTO, 0, &radconv));
	radconv.flag = 2;
	printf("Zero is %s\n", radconvtosf(0, RADCONV_UNARY_AUTO, 0, &radconv));
	radconv.flag = -2;
	printf("NegativeZero is %s\n", radconvtosf(0, RADCONV_UNARY_AUTO, 0, &radconv));
	
	return 0;
}
