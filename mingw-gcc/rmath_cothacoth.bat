gcc -Wall -Wextra -O3 -c realmath/acoth_r8.c
gcc -Wall -Wextra -O3 -c realmath/acoth_re.c
gcc -Wall -Wextra -O3 -c realmath/acoth_r4.c
gcc -Wall -Wextra -O3 -c realmath/coth_r8.c
gcc -Wall -Wextra -O3 -c realmath/coth_re.c
gcc -Wall -Wextra -O3 -c realmath/coth_r4.c
gcc -o bin/rmath_cothacoth test/rmath_cothacoth.c acoth_r8.o acoth_re.o acoth_r4.o coth_r8.o coth_re.o coth_r4.o
