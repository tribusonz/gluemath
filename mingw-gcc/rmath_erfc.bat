gcc -Wall -Wextra -O3 -c realmath/erfc_r4.c
gcc -Wall -Wextra -O3 -c realmath/erfc_r8.c
gcc -Wall -Wextra -O3 -c realmath/erfc_re.c
gcc -Wall -Wextra -O3 -o bin/rmath_erfc test/rmath_erfc.c erfc_r4.o erfc_r8.o erfc_re.o
