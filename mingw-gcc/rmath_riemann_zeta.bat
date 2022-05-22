gcc -Wall -Wextra -O3 -c realmath/riemann_zeta_r8.c
gcc -o bin/rmath_riemann_zeta test/rmath_riemann_zeta.c riemann_zeta_r8.o
