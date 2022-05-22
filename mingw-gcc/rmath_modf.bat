gcc -Wall -Wextra -O3 -c realmath/modf_r4.c
gcc -Wall -Wextra -O3 -c realmath/modf_r8.c
gcc -Wall -Wextra -O3 -c realmath/modf_re.c
gcc -o bin/rmath_modf test/rmath_modf.c modf_r4.o modf_r8.o modf_re.o
