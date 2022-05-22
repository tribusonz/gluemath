gcc -Wall -Wextra -O3 -c realmath/exp2_r4.c
gcc -Wall -Wextra -O3 -c realmath/exp2_r8.c
gcc -Wall -Wextra -O3 -c realmath/exp2_re.c
gcc -Wall -Wextra -O3 -o bin/rmath_exp2 test/rmath_exp2.c exp2_r4.o exp2_r8.o exp2_re.o
