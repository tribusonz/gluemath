gcc -Wall -Wextra -O3 -Iquadrature -c quadrature/intde.c
gcc -Wall -Wextra -O3 -Iquadrature -c quadrature/intdei.c
gcc -Wall -Wextra -O3 -Iquadrature -c quadrature/intdeo.c
gcc -Wall -Wextra -O3 -Irealmath -c realmath/exp_r8.c
gcc -Wall -Wextra -O3 -Irealmath -c realmath/sqrt_r8.c
gcc -Wall -Wextra -O3 -Irealmath -c realmath/sin_r8.c
gcc -Wall -Wextra -O3 -Irealmath -c realmath/cos_r8.c
gcc -o bin/quadrature_de test/quadrature_de.c intde.o intdei.o intdeo.o exp_r8.o sqrt_r8.o sin_r8.o cos_r8.o
