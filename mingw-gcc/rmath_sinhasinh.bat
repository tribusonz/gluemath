gcc -Wall -Wextra -O3 -c realmath/sinh_r4.c
gcc -Wall -Wextra -O3 -c realmath/sinh_r8.c
gcc -Wall -Wextra -O3 -c realmath/sinh_re.c
gcc -Wall -Wextra -O3 -c realmath/asinh_r4.c
gcc -Wall -Wextra -O3 -c realmath/asinh_r8.c
gcc -Wall -Wextra -O3 -c realmath/asinh_re.c
gcc -o bin/rmath_sinhasinh test/rmath_sinhasinh.c asinh_r8.o asinh_re.o asinh_r4.o sinh_r8.o sinh_re.o sinh_r4.o
