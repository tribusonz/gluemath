gcc -Wall -Wextra -O3 -c realmath/log1p_r4.c
gcc -Wall -Wextra -O3 -c realmath/log1p_r8.c
gcc -Wall -Wextra -O3 -c realmath/log1p_re.c
gcc -o bin/rmath_log1p test/rmath_log1p.c log1p_r4.o log1p_r8.o log1p_re.o
