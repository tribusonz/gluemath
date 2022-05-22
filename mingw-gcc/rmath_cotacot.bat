gcc -Wall -Wextra -O3 -c realmath/acot_r8.c
gcc -Wall -Wextra -O3 -c realmath/acot_re.c
gcc -Wall -Wextra -O3 -c realmath/acot_r4.c
gcc -Wall -Wextra -O3 -c realmath/cot_r8.c
gcc -Wall -Wextra -O3 -c realmath/cot_re.c
gcc -Wall -Wextra -O3 -c realmath/cot_r4.c
gcc -Wall -Wextra -O3 -o bin/rmath_cotacot test/rmath_cotacot.c acot_r8.o acot_re.o acot_r4.o cot_r8.o cot_re.o cot_r4.o
