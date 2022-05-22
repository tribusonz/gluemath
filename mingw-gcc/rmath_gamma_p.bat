gcc -Wall -Wextra -O3 -c realmath/p_gamma_r8.c
gcc -Wall -Wextra -O3 -c realmath/q_gamma_r8.c
gcc -Wall -Wextra -O2 -o bin/rmath_gamma_p test/rmath_gamma_p.c p_gamma_r8.o q_gamma_r8.o
