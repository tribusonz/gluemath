gcc -Wall -Wextra -O3 -c realmath/acsch_r4.c
gcc -Wall -Wextra -O3 -c realmath/acsch_r8.c
gcc -Wall -Wextra -O3 -c realmath/acsch_re.c
gcc -Wall -Wextra -O3 -c realmath/csch_r4.c
gcc -Wall -Wextra -O3 -c realmath/csch_r8.c
gcc -Wall -Wextra -O3 -c realmath/csch_re.c
gcc -o bin/rmath_cschacsch test/rmath_cschacsch.c acsch_r4.o acsch_r8.o acsch_re.o csch_r4.o csch_r8.o csch_re.o
