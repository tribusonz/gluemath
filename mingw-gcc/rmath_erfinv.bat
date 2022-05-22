gcc -Wall -Wextra -O3 -c realmath/erfinv_r8.c
gcc -Wall -Wextra -O3 -c realmath/erfcinv_r8.c
gcc -o bin/rmath_erfinv test/rmath_erfinv.c erfinv_r8.o erfcinv_r8.o
