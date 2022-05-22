gcc -Wall -Wextra -O3 -c realmath/lgamma_r4.c
gcc -Wall -Wextra -O3 -c realmath/lgamma_r8.c
gcc -Wall -Wextra -O3 -c realmath/lgamma_re.c
gcc -o bin/rmath_lgamma test/rmath_lgamma.c lgamma_r8.o lgamma_re.o lgamma_r4.o
