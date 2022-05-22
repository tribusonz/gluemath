gcc -Wall -Wextra -O3 -c realmath/acos_r4.c
gcc -Wall -Wextra -O3 -c realmath/acos_r8.c
gcc -Wall -Wextra -O3 -c realmath/acos_re.c
gcc -Wall -Wextra -O3 -c realmath/cos_r4.c
gcc -Wall -Wextra -O3 -c realmath/cos_r8.c
gcc -Wall -Wextra -O3 -c realmath/cos_re.c
gcc -o bin/rmath_cosacos test/rmath_cosacos.c acos_r8.o acos_re.o acos_r4.o cos_r8.o cos_re.o cos_r4.o
