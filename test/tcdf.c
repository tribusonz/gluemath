/*******************************************************************************
    GLUE-Math test routine: tcdf() Integer df

	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "../dist/dist.h"
#include <stdio.h>
#include <stdlib.h>
/*******************************************************************************
MinGW 64bit gcc build:
$ gcc -Wall -Wextra -O3 -o bin/tcdf test/tcdf.c dist/tcdf.c dist/tcdfc.c

And test result:
***** p_t(t, df) *****
  t   df=1             df=2             df=5             df=20
-5.0 0.06283295818900 0.01887477567531 0.00205235799003 0.00003436514290
-4.5 0.06960448727306 0.02300095399714 0.00319976817316 0.00010938560587
-4.0 0.07797913037737 0.02859547920897 0.00516170774042 0.00035176164656
-3.5 0.08858553278290 0.03641367502723 0.00864221589265 0.00112756157653
-3.0 0.10241638234957 0.04773298313335 0.01504962394873 0.00353794939561
-2.5 0.12111894159084 0.06480586011076 0.02724504967119 0.01061677271957
-2.0 0.14758361765043 0.09175170953614 0.05096973941493 0.02963276772329
-1.5 0.18716704181100 0.13619656244550 0.09695184012124 0.07461788558463
-1.0 0.25000000000000 0.21132486540519 0.18160873382456 0.16462828858585
-0.5 0.35241638234957 0.33333333333333 0.31914943582046 0.31126592114051
 0.0 0.50000000000000 0.50000000000000 0.50000000000000 0.50000000000000
 0.5 0.64758361765043 0.66666666666667 0.68085056417954 0.68873407885949
 1.0 0.75000000000000 0.78867513459481 0.81839126617544 0.83537171141415
 1.5 0.81283295818900 0.86380343755450 0.90304815987876 0.92538211441537
 2.0 0.85241638234957 0.90824829046386 0.94903026058507 0.97036723227671
 2.5 0.87888105840916 0.93519413988924 0.97275495032881 0.98938322728043
 3.0 0.89758361765043 0.95226701686665 0.98495037605127 0.99646205060439
 3.5 0.91141446721710 0.96358632497277 0.99135778410735 0.99887243842347
 4.0 0.92202086962263 0.97140452079103 0.99483829225958 0.99964823835344
 4.5 0.93039551272694 0.97699904600286 0.99680023182684 0.99989061439413
 5.0 0.93716704181100 0.98112522432469 0.99794764200997 0.99996563485710
***** q_t(t, df) *****
  t   df=1             df=2             df=5             df=20
-5.0 0.93716704181100 0.98112522432469 0.99794764200997 0.99996563485710
-4.5 0.93039551272694 0.97699904600286 0.99680023182684 0.99989061439413
-4.0 0.92202086962263 0.97140452079103 0.99483829225958 0.99964823835344
-3.5 0.91141446721710 0.96358632497277 0.99135778410735 0.99887243842347
-3.0 0.89758361765043 0.95226701686665 0.98495037605127 0.99646205060439
-2.5 0.87888105840916 0.93519413988924 0.97275495032881 0.98938322728043
-2.0 0.85241638234957 0.90824829046386 0.94903026058507 0.97036723227671
-1.5 0.81283295818900 0.86380343755450 0.90304815987876 0.92538211441537
-1.0 0.75000000000000 0.78867513459481 0.81839126617544 0.83537171141415
-0.5 0.64758361765043 0.66666666666667 0.68085056417954 0.68873407885949
 0.0 0.50000000000000 0.50000000000000 0.50000000000000 0.50000000000000
 0.5 0.35241638234957 0.33333333333333 0.31914943582046 0.31126592114051
 1.0 0.25000000000000 0.21132486540519 0.18160873382456 0.16462828858585
 1.5 0.18716704181100 0.13619656244550 0.09695184012124 0.07461788558463
 2.0 0.14758361765043 0.09175170953614 0.05096973941493 0.02963276772329
 2.5 0.12111894159084 0.06480586011076 0.02724504967119 0.01061677271957
 3.0 0.10241638234957 0.04773298313335 0.01504962394873 0.00353794939561
 3.5 0.08858553278290 0.03641367502723 0.00864221589265 0.00112756157653
 4.0 0.07797913037737 0.02859547920897 0.00516170774042 0.00035176164656
 4.5 0.06960448727306 0.02300095399714 0.00319976817316 0.00010938560587
 5.0 0.06283295818900 0.01887477567531 0.00205235799003 0.00003436514290
*******************************************************************************/

int
main(void)
{
	int i;
	double t;

	printf("***** p_t(t, df) *****\n");
	printf("  t   %-16s %-16s %-16s %-16s\n",
	    "df=1", "df=2", "df=5", "df=20");
	for (i = -10; i <= 10; i++) {
		t = 0.5 * i;
		printf("%4.1f %16.14f %16.14f %16.14f %16.14f\n",
		    t, tcdf(t,1), tcdf(t, 2), tcdf(t, 5), tcdf(t, 20));
	}
	printf("***** q_t(t, df) *****\n");
	printf("  t   %-16s %-16s %-16s %-16s\n",
	    "df=1", "df=2", "df=5", "df=20");
	for (i = -10; i <= 10; i++) {
		t = 0.5 * i;
		printf("%4.1f %16.14f %16.14f %16.14f %16.14f\n",
		    t, tcdfc(t,1), tcdfc(t, 2), tcdfc(t, 5), tcdfc(t, 20));
	}

	return 0;
}