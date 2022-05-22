gcc -Wall -Wextra -O3 -c realmath/p_beta_r8.c
gcc -Wall -Wextra -O3 -c realmath/q_beta_r8.c
gcc -Wall -Wextra -O2 -o bin/rmath_beta_p test/rmath_beta_p.c p_beta_r8.o q_beta_r8.o
