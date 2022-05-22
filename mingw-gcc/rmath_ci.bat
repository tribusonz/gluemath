gcc -Wall -Wextra -O3 -c realmath/ci_r8.c
gcc -o bin/rmath_ci test/rmath_ci.c ci_r8.o
