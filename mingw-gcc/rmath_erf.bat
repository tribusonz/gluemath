gcc -Wall -Wextra -O3 -c realmath/erf_r4.c
gcc -Wall -Wextra -O3 -c realmath/erf_r8.c
gcc -Wall -Wextra -O3 -c realmath/erf_re.c
gcc -o bin/rmath_erf test/rmath_erf.c erf_r4.o erf_r8.o erf_re.o
