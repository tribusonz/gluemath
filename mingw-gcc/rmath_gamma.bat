gcc -Wall -Wextra -O3 -c realmath/gamma_r4.c
gcc -Wall -Wextra -O3 -c realmath/gamma_r8.c
gcc -Wall -Wextra -O3 -c realmath/gamma_re.c
gcc -o bin/rmath_gamma test/rmath_gamma.c gamma_r8.o gamma_r4.o gamma_re.o
