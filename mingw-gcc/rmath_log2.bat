gcc -Wall -Wextra -O3 -c realmath/log2_r4.c
gcc -Wall -Wextra -O3 -c realmath/log2_r8.c
gcc -Wall -Wextra -O3 -c realmath/log2_re.c
gcc -o bin/rmath_log2 test/rmath_log2.c log2_r8.o log2_re.o log2_r4.o
