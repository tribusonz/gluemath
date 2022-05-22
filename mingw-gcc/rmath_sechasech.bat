gcc -Wall -Wextra -O3 -c realmath/asech_r4.c
gcc -Wall -Wextra -O3 -c realmath/asech_r8.c
gcc -Wall -Wextra -O3 -c realmath/asech_re.c
gcc -Wall -Wextra -O3 -c realmath/sech_r4.c
gcc -Wall -Wextra -O3 -c realmath/sech_r8.c
gcc -Wall -Wextra -O3 -c realmath/sech_re.c
gcc -o bin/rmath_sechasech test/rmath_sechasech.c asech_r8.o asech_re.o asech_r4.o sech_r8.o sech_re.o sech_r4.o
