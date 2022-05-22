gcc -Wall -Wextra -O3 -c realmath/log10_r4.c
gcc -Wall -Wextra -O3 -c realmath/log10_r8.c
gcc -Wall -Wextra -O3 -c realmath/log10_re.c
gcc -o bin/rmath_log10 test/rmath_log10.c log10_r8.o log10_re.o log10_r4.o
