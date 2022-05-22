gcc -Wall -Wextra -O3 -c realmath/quadrant_r8.c
gcc -Wall -Wextra -O3 -c realmath/quadrant_re.c
gcc -Wall -Wextra -O3 -c realmath/quadrant_r4.c
gcc -o bin/rmath_quadrant test/rmath_quadrant.c quadrant_r8.o quadrant_re.o quadrant_r4.o
