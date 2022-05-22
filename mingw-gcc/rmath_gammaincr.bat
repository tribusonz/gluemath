gcc -Wall -Wextra -O3 -c realmath/gammaincr1_r8.c
gcc -Wall -Wextra -O3 -c realmath/gammaincr2_r8.c
gcc -o bin/rmath_gammaincr test/rmath_gammaincr.c gammaincr1_r8.o gammaincr2_r8.o
