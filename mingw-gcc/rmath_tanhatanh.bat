gcc -Wall -Wextra -O3 -c realmath/tanh_r8.c
gcc -Wall -Wextra -O3 -c realmath/tanh_re.c
gcc -Wall -Wextra -O3 -c realmath/tanh_r4.c
gcc -Wall -Wextra -O3 -c realmath/atanh_r8.c
gcc -Wall -Wextra -O3 -c realmath/atanh_re.c
gcc -Wall -Wextra -O3 -c realmath/atanh_r4.c
gcc -o bin/rmath_tanhatanh test/rmath_tanhatanh.c tanh_r8.o tanh_re.o tanh_r4.o atanh_r8.o atanh_re.o atanh_r4.o
