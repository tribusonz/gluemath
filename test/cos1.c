/*******************************************************************************
	GLUE-Math test suite: 1 - cos()
*******************************************************************************/
#include "../realmath/realmath.h"
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#define PI 3.1415926535897932384626433832795L
/*******************************************************************************
MinGW 64bit gcc build:
$ gcc -Wall -Wextra -O3 -o bin/cos1 test/cos1.c realmath/cos1_r8.c realmath/cos1_re.c realmath/cos1_r4.c

And test result:
GLUE-Math with POSIX standard
Test Suite:
  1 - cos()

x(deg) cos1(x)
-720 0.000000  0.00000000000000   0.00000000000000000
-705 0.034074  0.03407417371093   0.03407417371093171
-690 0.133974  0.13397459621556   0.13397459621556135
-675 0.292893  0.29289321881345   0.29289321881345248
-660 0.500000  0.50000000000000   0.50000000000000000
-645 0.741181  0.74118095489748   0.74118095489747924
-630 1.000000  1.00000000000000   1.00000000000000000
-615 1.258819  1.25881904510252   1.25881904510252076
-600 1.500000  1.50000000000000   1.50000000000000000
-585 1.707107  1.70710678118655   1.70710678118654752
-570 1.866025  1.86602540378444   1.86602540378443865
-555 1.965926  1.96592582628907   1.96592582628906829
-540 2.000000  2.00000000000000   2.00000000000000000
-525 1.965926  1.96592582628907   1.96592582628906829
-510 1.866025  1.86602540378444   1.86602540378443865
-495 1.707107  1.70710678118655   1.70710678118654752
-480 1.500000  1.50000000000000   1.50000000000000000
-465 1.258819  1.25881904510252   1.25881904510252076
-450 1.000000  1.00000000000000   1.00000000000000000
-435 0.741181  0.74118095489748   0.74118095489747924
-420 0.500000  0.50000000000000   0.50000000000000000
-405 0.292893  0.29289321881345   0.29289321881345248
-390 0.133975  0.13397459621556   0.13397459621556135
-375 0.034074  0.03407417371093   0.03407417371093171
-360 0.000000  0.00000000000000   0.00000000000000000
-345 0.034074  0.03407417371093   0.03407417371093171
-330 0.133975  0.13397459621556   0.13397459621556135
-315 0.292893  0.29289321881345   0.29289321881345248
-300 0.500000  0.50000000000000   0.50000000000000000
-285 0.741181  0.74118095489748   0.74118095489747924
-270 1.000000  1.00000000000000   1.00000000000000000
-255 1.258819  1.25881904510252   1.25881904510252076
-240 1.500000  1.50000000000000   1.50000000000000000
-225 1.707107  1.70710678118655   1.70710678118654752
-210 1.866025  1.86602540378444   1.86602540378443865
-195 1.965926  1.96592582628907   1.96592582628906829
-180 2.000000  2.00000000000000   2.00000000000000000
-165 1.965926  1.96592582628907   1.96592582628906829
-150 1.866025  1.86602540378444   1.86602540378443865
-135 1.707107  1.70710678118655   1.70710678118654752
-120 1.500000  1.50000000000000   1.50000000000000000
-105 1.258819  1.25881904510252   1.25881904510252076
 -90 1.000000  1.00000000000000   1.00000000000000000
 -75 0.741181  0.74118095489748   0.74118095489747924
 -60 0.500000  0.50000000000000   0.50000000000000000
 -45 0.292893  0.29289321881345   0.29289321881345248
 -30 0.133975  0.13397459621556   0.13397459621556135
 -15 0.034074  0.03407417371093   0.03407417371093171
   0 0.000000  0.00000000000000   0.00000000000000000
  15 0.034074  0.03407417371093   0.03407417371093171
  30 0.133975  0.13397459621556   0.13397459621556135
  45 0.292893  0.29289321881345   0.29289321881345248
  60 0.500000  0.50000000000000   0.50000000000000000
  75 0.741181  0.74118095489748   0.74118095489747924
  90 1.000000  1.00000000000000   1.00000000000000000
 105 1.258819  1.25881904510252   1.25881904510252076
 120 1.500000  1.50000000000000   1.50000000000000000
 135 1.707107  1.70710678118655   1.70710678118654752
 150 1.866025  1.86602540378444   1.86602540378443865
 165 1.965926  1.96592582628907   1.96592582628906829
 180 2.000000  2.00000000000000   2.00000000000000000
 195 1.965926  1.96592582628907   1.96592582628906829
 210 1.866025  1.86602540378444   1.86602540378443865
 225 1.707107  1.70710678118655   1.70710678118654752
 240 1.500000  1.50000000000000   1.50000000000000000
 255 1.258819  1.25881904510252   1.25881904510252076
 270 1.000000  1.00000000000000   1.00000000000000000
 285 0.741181  0.74118095489748   0.74118095489747924
 300 0.500000  0.50000000000000   0.50000000000000000
 315 0.292893  0.29289321881345   0.29289321881345248
 330 0.133975  0.13397459621556   0.13397459621556135
 345 0.034074  0.03407417371093   0.03407417371093171
 360 0.000000  0.00000000000000   0.00000000000000000
 375 0.034074  0.03407417371093   0.03407417371093171
 390 0.133975  0.13397459621556   0.13397459621556135
 405 0.292893  0.29289321881345   0.29289321881345248
 420 0.500000  0.50000000000000   0.50000000000000000
 435 0.741181  0.74118095489748   0.74118095489747924
 450 1.000000  1.00000000000000   1.00000000000000000
 465 1.258819  1.25881904510252   1.25881904510252076
 480 1.500000  1.50000000000000   1.50000000000000000
 495 1.707106  1.70710678118655   1.70710678118654752
 510 1.866025  1.86602540378444   1.86602540378443865
 525 1.965926  1.96592582628907   1.96592582628906829
 540 2.000000  2.00000000000000   2.00000000000000000
 555 1.965926  1.96592582628907   1.96592582628906829
 570 1.866026  1.86602540378444   1.86602540378443865
 585 1.707107  1.70710678118655   1.70710678118654752
 600 1.500000  1.50000000000000   1.50000000000000000
 615 1.258819  1.25881904510252   1.25881904510252076
 630 1.000000  1.00000000000000   1.00000000000000000
 645 0.741181  0.74118095489748   0.74118095489747924
 660 0.500001  0.50000000000000   0.50000000000000000
 675 0.292893  0.29289321881345   0.29289321881345248
 690 0.133974  0.13397459621556   0.13397459621556135
 705 0.034074  0.03407417371093   0.03407417371093171
 720 0.000000  0.00000000000000   0.00000000000000000
*******************************************************************************/
/* テスト用 */
int
main(void)
{
	float c1f; double c1; long double c1l;
	
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  1 - cos()");
	puts("");

	printf("x(deg) cos1(x)\n");
	for (volatile int i = -720; i <= 720; i += 15) {
		c1f = cos1_r4(i * (PI / 180));
		c1  = cos1_r8(i * (PI / 180));
		c1l = cos1_re(i * (PI / 180));
		printf("%4d %6.6f %17.14f %21.17Lf\n", i, c1f, c1, c1l);
	}
	return 0;
}
