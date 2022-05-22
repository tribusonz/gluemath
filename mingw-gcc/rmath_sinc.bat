gcc -Wall -Wextra -O3 -c realmath/sinc_r8.c
gcc -o bin/rmath_sinc test/rmath_sinc.c sinc_r8.o
