gcc -Wall -Wextra -O3 -c realmath/tan_r4.c
gcc -Wall -Wextra -O3 -c realmath/tan_r8.c
gcc -Wall -Wextra -O3 -c realmath/tan_re.c
gcc -Wall -Wextra -O3 -c realmath/atan_r4.c
gcc -Wall -Wextra -O3 -c realmath/atan_r8.c
gcc -Wall -Wextra -O3 -c realmath/atan_re.c
gcc -o bin/rmath_tanatan test/rmath_tanatan.c tan_r4.o tan_r8.o tan_re.o atan_r4.o atan_r8.o atan_re.o

