gcc -Wall -Wextra -O3 -c realmath/sqrt_r4.c
gcc -Wall -Wextra -O3 -c realmath/sqrt_r8.c
gcc -Wall -Wextra -O3 -c realmath/sqrt_re.c
gcc -o bin/rmath_sqrt test/rmath_sqrt.c sqrt_r8.o sqrt_re.o sqrt_r4.o
