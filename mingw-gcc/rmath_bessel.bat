gcc -Wall -Wextra -O3 -c realmath/j0_r8.c
gcc -Wall -Wextra -O3 -c realmath/j1_r8.c
gcc -Wall -Wextra -O3 -c realmath/jn_r8.c
gcc -Wall -Wextra -O3 -c realmath/y0_r8.c
gcc -Wall -Wextra -O3 -c realmath/y1_r8.c
gcc -Wall -Wextra -O3 -c realmath/yn_r8.c
gcc -Wall -Wextra -O3 -c realmath/i0_r8.c
gcc -Wall -Wextra -O3 -c realmath/i1_r8.c
gcc -Wall -Wextra -O3 -c realmath/in_r8.c
gcc -Wall -Wextra -O3 -c realmath/k0_r8.c
gcc -Wall -Wextra -O3 -c realmath/k1_r8.c
gcc -Wall -Wextra -O3 -c realmath/kn_r8.c
gcc -o bin/rmath_bessel test/rmath_bessel.c j0_r8.o j1_r8.o jn_r8.o y0_r8.o y1_r8.o yn_r8.o i0_r8.o i1_r8.o in_r8.o k0_r8.o k1_r8.o kn_r8.o
