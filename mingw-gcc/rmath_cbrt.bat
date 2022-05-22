gcc -Wall -Wextra -O3 -c realmath/cbrt_r4.c
gcc -Wall -Wextra -O3 -c realmath/cbrt_r8.c
gcc -Wall -Wextra -O3 -c realmath/cbrt_re.c
gcc -o bin/rmath_cbrt test/rmath_cbrt.c cbrt_r8.o cbrt_re.o cbrt_r4.o
