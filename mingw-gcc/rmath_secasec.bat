gcc -Wall -Wextra -O3 -c realmath/asec_r4.c
gcc -Wall -Wextra -O3 -c realmath/asec_r8.c
gcc -Wall -Wextra -O3 -c realmath/asec_re.c
gcc -Wall -Wextra -O3 -c realmath/sec_r4.c
gcc -Wall -Wextra -O3 -c realmath/sec_r8.c
gcc -Wall -Wextra -O3 -c realmath/sec_re.c
gcc -o bin/rmath_secasec test/rmath_secasec.c asec_r8.o asec_re.o asec_r4.o sec_r8.o sec_re.o sec_r4.o

