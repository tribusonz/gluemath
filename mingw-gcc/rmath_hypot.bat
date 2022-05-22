gcc -Wall -Wextra -O3 -c realmath/hypot_r4.c
gcc -Wall -Wextra -O3 -c realmath/hypot_r8.c
gcc -Wall -Wextra -O3 -c realmath/hypot_re.c
gcc -Wall -Wextra -O3 -c realmath/atan_r8.c
gcc -o bin/rmath_hypot test/rmath_hypot.c hypot_r8.o hypot_re.o hypot_r4.o atan_r8.o
