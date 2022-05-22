gcc -Wall -Wextra -O3 -c realmath/lbeta_r8.c
gcc -o bin/rmath_lbeta test/rmath_lbeta.c lbeta_r8.o
