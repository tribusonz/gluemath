gcc -Wall -Wextra -O3 -c realmath/asin_r4.c
gcc -Wall -Wextra -O3 -c realmath/asin_r8.c
gcc -Wall -Wextra -O3 -c realmath/asin_re.c
gcc -Wall -Wextra -O3 -c realmath/sin_r4.c
gcc -Wall -Wextra -O3 -c realmath/sin_r8.c
gcc -Wall -Wextra -O3 -c realmath/sin_re.c
gcc -o bin/rmath_sinasin test/rmath_sinasin.c asin_r8.o asin_re.o asin_r4.o sin_r8.o sin_re.o sin_r4.o
