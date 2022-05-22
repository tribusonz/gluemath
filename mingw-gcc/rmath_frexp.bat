gcc -Wall -Wextra -O3 -c realmath/frexp_r4.c
gcc -Wall -Wextra -O3 -c realmath/frexp_r8.c
gcc -Wall -Wextra -O3 -c realmath/frexp_re.c
gcc -Wall -Wextra -O3 -o bin/rmath_frexp test/rmath_frexp.c frexp_r4.o frexp_r8.o frexp_re.o
