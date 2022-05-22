gcc -Wall -Wextra -O3 -c realmath/cos1_r8.c
gcc -Wall -Wextra -O3 -c realmath/cos1_re.c
gcc -Wall -Wextra -O3 -c realmath/cos1_r4.c
gcc -o bin/rmath_cos1 test/rmath_cos1.c cos1_r8.o cos1_re.o cos1_r4.o
