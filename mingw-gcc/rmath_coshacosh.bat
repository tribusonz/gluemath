gcc -Wall -Wextra -O3 -c realmath/acosh_r8.c
gcc -Wall -Wextra -O3 -c realmath/acosh_re.c
gcc -Wall -Wextra -O3 -c realmath/acosh_r4.c
gcc -Wall -Wextra -O3 -c realmath/cosh_r8.c
gcc -Wall -Wextra -O3 -c realmath/cosh_re.c
gcc -Wall -Wextra -O3 -c realmath/cosh_r4.c
gcc -o bin/rmath_coshacosh test/rmath_coshacosh.c acosh_r8.o acosh_re.o acosh_r4.o cosh_r8.o cosh_re.o cosh_r4.o
