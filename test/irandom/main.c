/*******************************************************************************
 	 irandom.c -- 幾何分布
 	           -- 2項分布
 	           -- Poisson (ポアソン) 分布
 	           
 	           奥村教授のテストルーチン
*******************************************************************************/
#include "../../sys/random/random.h"
#include "../../dist/dist.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*******************************************************************************
MinGW 64bit gcc build:
$ gcc -Wall -Wextra -O3 -lm -o bin/irandom test/irandom.c dist/binomrng.c dist/poissrng.c dist/geomrng.c

Random Variate Test:
<Geometric Distribution p=1percent>
***** メニュー *****
  1: 幾何分布
  2: ２項分布
  3: ポアソン分布
? 1
引数 (1個)? 0.01
個数? 10000
   0:   0.0%
   1:   1.1%
   2:   0.9%
   3:   0.9%
   4:   1.0%
   5:   0.8%
   6:   1.1%
   7:   0.9%
   8:   1.0%
   9:   1.0%
  10:   1.0%
  11:   0.8%
  12:   0.9%
  13:   0.9%
  14:   0.9%
  15:   1.0%
  16:   0.8%
  17:   0.8%
  18:   0.7%
  19:   0.9%
平均 99.1063  標準偏差 96.9889

<Binomial Distribution n=50, p=0.175>
***** メニュー *****
  1: 幾何分布
  2: ２項分布
  3: ポアソン分布
? 2
引数 (2個)? 50 0.175
個数? 10000
   0:   0.0%
   1:   0.1%
   2:   0.4%
   3:   1.2%
   4:   2.9%
   5:   6.3%
   6:   9.6%
   7:  12.8%
   8:  14.2%
   9:  15.0%
  10:  12.7%
  11:   9.8%
  12:   6.8%
  13:   4.1%
  14:   2.2%
  15:   1.1%
  16:   0.5%
  17:   0.2%
  18:   0.1%
  19:   0.0%
平均 8.7365  標準偏差 2.65672

<Poisson Distribution lambda=30.5>
***** メニュー *****
  1: 幾何分布
  2: ２項分布
  3: ポアソン分布
? 3
引数 (1個)? 30.5
個数? 10000
   0:   0.0%
   1:   0.0%
   2:   0.0%
   3:   0.0%
   4:   0.0%
   5:   0.0%
   6:   0.0%
   7:   0.0%
   8:   0.0%
   9:   0.0%
  10:   0.0%
  11:   0.0%
  12:   0.0%
  13:   0.0%
  14:   0.1%
  15:   0.1%
  16:   0.1%
  17:   0.2%
  18:   0.6%
  19:   0.6%
平均 30.4733  標準偏差 5.48409
*******************************************************************************/

int
main(void)
{
    int i, choice, x = 0, n, histo[20];
    double a, b, s1, s2;

    init_genrand((unsigned long)time(NULL));  /* 初期化 */

    printf("***** メニュー *****\n");
    printf("  1: 幾何分布\n");
    printf("  2: ２項分布\n");
    printf("  3: ポアソン分布\n");
    printf("? ");  scanf("%d", &choice);

    switch(choice) {
    case 1: case 3:
        printf("引数 (1個)? ");  scanf("%lf", &a);  break;
    case 2:
        printf("引数 (2個)? ");  scanf("%lf%lf", &a, &b);  break;
    }
    printf("個数? ");  scanf("%d", &n);

    for (i = 0; i < 20; i++) histo[i] = 0;
    s1 = s2 = 0;
    for (i = 0; i < n; i++) {
        switch(choice) {
        case 1: x = geomrng(a);  break;
        case 2: x = binomrng(a, b);  break;
        case 3: x = poissrng(a);  break;
        }
        if (x >= 0 && x < 20) histo[x]++;
        s1 += x;  s2 += x * x;
    }

    for (i = 0; i < 20; i++)
        printf("%4d: %5.1f%%\n", i, 100.0 * histo[i] / n);
    s1 /= n;  s2 = sqrt((s2 - n * s1 * s1) / (n - 1));
    printf("平均 %g  標準偏差 %g\n", s1, s2);

    return 0;
}
