gcc -Wall -Wextra -O3 -c realmath/exp_r4.c
gcc -Wall -Wextra -O3 -c realmath/exp_r8.c
gcc -Wall -Wextra -O3 -c realmath/exp_re.c
gcc -o bin/rmath_exp test/rmath_exp.c exp_r4.o exp_r8.o exp_re.o
