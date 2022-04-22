/*******************************************************************************
	GLUE-Math test suite: Real numbers Modulo
*******************************************************************************/
#include "../sys/float/modulo.h"
#include "../sys/float/huge_val_nan.h"
#include <stdio.h>
/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -o bin/fmod test/fmod.c

And Test Result:
GLUE-Math with POSIX standard
Test Suite:
  Real numbers Modulo

moduloのテスト (double)
    x %     y    fmod
    1 %   256:      1
    1 %  -256:   -255
   -1 %   256:    255
   -1 %  -256:     -1

    1 %     0:    nan
   -1 %     0:    nan
    0 %     1:      0
    0 %    -1:      0
    0 %   inf:    nan
    0 %  -inf:    nan

  inf %     1:    nan
 -inf %     1:    nan
    1 %   inf:    nan
    1 %  -inf:    nan
  inf %   inf:    nan
  inf %  -inf:    nan
 -inf %   inf:    nan
 -inf %  -inf:    nan

  nan %   nan:    nan

moduloのテスト (long double)
    x %     y    fmod
    1 %   256:      1
    1 %  -256:   -255
   -1 %   256:    255
   -1 %  -256:     -1

    1 %     0:    nan
   -1 %     0:    nan
    0 %     1:      0
    0 %    -1:      0
    0 %   inf:    nan
    0 %  -inf:    nan

  inf %     1:    nan
 -inf %     1:    nan
    1 %   inf:    nan
    1 %  -inf:    nan
  inf %   inf:    nan
  inf %  -inf:    nan
 -inf %   inf:    nan
 -inf %  -inf:    nan

  nan %   nan:    nan

moduloのテスト (float)
    x %     y    fmod
    1 %   256:      1
    1 %  -256:   -255
   -1 %   256:    255
   -1 %  -256:     -1

    1 %     0:    nan
   -1 %     0:    nan
    0 %     1:      0
    0 %    -1:      0
    0 %   inf:    nan
    0 %  -inf:    nan

  inf %     1:    nan
 -inf %     1:    nan
    1 %   inf:    nan
    1 %  -inf:    nan
  inf %   inf:    nan
  inf %  -inf:    nan
 -inf %   inf:    nan
 -inf %  -inf:    nan

  nan %   nan:    nan
*******************************************************************************/

int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Real numbers Modulo");
	puts("");

#define print_fmod(x,y) (printf("%5g %% %5g:  %5g\n", (double)(x), (double)(y), fmod(x, y)))

	puts("moduloのテスト (double)");
	puts("    x %     y    fmod");
	print_fmod(1, 256);
	print_fmod(1, -256);
	print_fmod(-1, 256);
	print_fmod(-1, -256);
	puts("");
	print_fmod(1, 0);
	print_fmod(-1, 0);
	print_fmod(0, 1);
	print_fmod(0, -1);
	print_fmod(0, HUGE_VAL);
	print_fmod(0, -HUGE_VAL);
	puts("");
	print_fmod(HUGE_VAL, 1);
	print_fmod(-HUGE_VAL, 1);
	print_fmod(1, HUGE_VAL);
	print_fmod(1, -HUGE_VAL);
	print_fmod(HUGE_VAL, HUGE_VAL);
	print_fmod(HUGE_VAL, -HUGE_VAL);
	print_fmod(-HUGE_VAL, HUGE_VAL);
	print_fmod(-HUGE_VAL, -HUGE_VAL);
	puts("");
	print_fmod(NAN, NAN);
	puts("");

#define print_fmodl(x,y) (printf("%5Lg %% %5Lg:  %5Lg\n", (long double)(x), (long double)(y), fmodl(x, y)))

	puts("moduloのテスト (long double)");
	puts("    x %     y    fmod");
	print_fmodl(1.L, 256.L);
	print_fmodl(1.L, -256.L);
	print_fmodl(-1.L, 256.L);
	print_fmodl(-1.L, -256.L);
	puts("");
	print_fmodl(1.L, 0.L);
	print_fmodl(-1.L, 0.L);
	print_fmodl(0.L, 1.L);
	print_fmodl(0.L, -1.L);
	print_fmodl(0.L, HUGE_VALL);
	print_fmodl(0.L, -HUGE_VALL);
	puts("");
	print_fmodl(HUGE_VALL, 1.L);
	print_fmodl(-HUGE_VALL, 1.L);
	print_fmodl(1.L, HUGE_VALL);
	print_fmodl(1.L, -HUGE_VALL);
	print_fmodl(HUGE_VALL, HUGE_VALL);
	print_fmodl(HUGE_VALL, -HUGE_VALL);
	print_fmodl(-HUGE_VALL, HUGE_VALL);
	print_fmodl(-HUGE_VALL, -HUGE_VALL);
	puts("");
	print_fmodl(NAN, NAN);
	puts("");

#define print_fmodf(x,y) (printf("%5g %% %5g:  %5g\n", (float)(x), (float)(y), fmodf(x, y)))

	puts("moduloのテスト (float)");
	puts("    x %     y    fmod");
	print_fmodf(1, 256);
	print_fmodf(1, -256);
	print_fmodf(-1, 256);
	print_fmodf(-1, -256);
	puts("");
	print_fmodf(1, 0);
	print_fmodf(-1, 0);
	print_fmodf(0, 1);
	print_fmodf(0, -1);
	print_fmodf(0, HUGE_VALF);
	print_fmodf(0, -HUGE_VALF);
	puts("");
	print_fmodf(HUGE_VALF, 1);
	print_fmodf(-HUGE_VALF, 1);
	print_fmodf(1, HUGE_VALF);
	print_fmodf(1, -HUGE_VALF);
	print_fmodf(HUGE_VALF, HUGE_VALF);
	print_fmodf(HUGE_VALF, -HUGE_VALF);
	print_fmodf(-HUGE_VALF, HUGE_VALF);
	print_fmodf(-HUGE_VALF, -HUGE_VALF);
	puts("");
	print_fmodf(NAN, NAN);
	puts("");

	return 0;
}
