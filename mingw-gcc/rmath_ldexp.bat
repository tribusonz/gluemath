gcc -Wall -Wextra -O3 -c realmath/ldexp_r4.c
gcc -Wall -Wextra -O3 -c realmath/ldexp_r8.c
gcc -Wall -Wextra -O3 -c realmath/ldexp_re.c
gcc -o bin/rmath_ldexp test/rmath_ldexp.c ldexp_r4.o ldexp_r8.o ldexp_re.o
