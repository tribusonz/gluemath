gcc -Wall -Wextra -O3 -c realmath/expm1_r4.c
gcc -Wall -Wextra -O3 -c realmath/expm1_r8.c
gcc -Wall -Wextra -O3 -c realmath/expm1_re.c
gcc -o bin/rmath_expm1 test/rmath_expm1.c expm1_r4.o expm1_r8.o expm1_re.o
