gcc -Wall -Wextra -O3 -c realmath/log_r4.c
gcc -Wall -Wextra -O3 -c realmath/log_r8.c
gcc -Wall -Wextra -O3 -c realmath/log_re.c
gcc -o bin/rmath_log test/rmath_log.c log_r8.o log_re.o log_r4.o
