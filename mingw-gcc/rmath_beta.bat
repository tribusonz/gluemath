gcc -Wall -Wextra -O3 -c realmath/beta_r8.c
gcc -o bin/rmath_beta test/rmath_beta.c beta_r8.o
