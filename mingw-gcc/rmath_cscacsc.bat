gcc -Wall -Wextra -O3 -c realmath/acsc_r8.c
gcc -Wall -Wextra -O3 -c realmath/acsc_re.c 
gcc -Wall -Wextra -O3 -c realmath/acsc_r4.c 
gcc -Wall -Wextra -O3 -c realmath/csc_r8.c 
gcc -Wall -Wextra -O3 -c realmath/csc_re.c 
gcc -Wall -Wextra -O3 -c realmath/csc_r4.c
gcc -o bin/rmath_cscacsc test/rmath_cscacsc.c acsc_r8.o acsc_re.o acsc_r4.o csc_r8.o csc_re.o csc_r4.o
