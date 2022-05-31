/**********************************************************************************

  DELTAGAMMAINC Fast and Accurate Evaluation of a Generalized Incomplete Gamma
  Function. Copyright (C) 2016 Remy Abergel (remy.abergel AT gmail.com), Lionel
  Moisan (Lionel.Moisan AT parisdescartes.fr).

  This file is a part of the DELTAGAMMAINC software, dedicated to the
  computation of a generalized incomplete gammafunction. See the Companion paper
  for a complete description of the algorithm.

  ``Fast and accurate evaluation of a generalized incomplete gamma function''
  (Rémy Abergel, Lionel Moisan), preprint MAP5 nº2016-14, revision 1.

  This program is free software: you can redistribute it and/or modify it under
  the terms of the GNU General Public License as published by the Free Software
  Foundation, either version 3 of the License, or (at your option) any later
  version.

  This program is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
  details.

  You should have received a copy of the GNU General Public License along with
  this program.  If not, see <http://www.gnu.org/licenses/>.

**********************************************************************************/

/*
 * Description: compute (rho,sigma) such as rho*exp(sigma) = I_{x,y}^{mu,p} where
 *
 *     I_{x,y}^{mu,p} = integral over [x,y] of s^(p-1) * exp(-mu*s) ds.
 *
 * Compilation (with gcc): gcc -O3 kernel.c deltagammainc.c -lm -o deltagammainc
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include "1006.h"


static void
display_usage(void)
{
  printf("Usage: deltagammainc [--help] [--verbose] x y mu p\n\n");
  printf("   --help    : display help\n");
  printf("   --verbose : verbose mode (display how the integral was computed)\n");
  printf("   x         : (double) a nonnegative number, possibly infinite (inf)\n");
  printf("   y         : (double) a number, possibly infinite (inf), greater than x\n");
  printf("   mu        : (double) a nonzero real number\n");
  printf("   p         : (double) a positive real number (must be integer if mu<0)\n\n");
  printf("Description:\n\n");
  printf("   Compute (rho,sigma) such as I = rho * exp(sigma), where\n");
  printf("   I = integral over [x,y] of s^{p-1} * exp(-mu*s) ds.\n\n");
}

int
main(int argc, char **argv)
{
	char *x_value=NULL,*y_value=NULL,*mu_value=NULL,*p_value=NULL,vflag=0,method;
	char flag;
	int i,err;
	double rho,sigma,x,y,mu,p,a,b;
	matherrstatus_t errstat;

	/* parser */
	for (i=1;i<argc;i++)
	{
		if (strcmp(argv[i],"--help") == 0)
		{
			display_usage();
			return EXIT_SUCCESS;
		}
		else if (strcmp(argv[i],"--verbose") == 0)
		{
			vflag = 1;
		}
		else if (NULL == x_value)
		{
			x_value = argv[i];
			err = sscanf(x_value,"%lf",&x);
			if (err != 1)
			{
				printf("\nError: could not properly retrieve input argument 'x'.\n");
				display_usage();
				return EXIT_FAILURE;
			}
		}
		else if (NULL == y_value)
		{
			y_value = argv[i];
			err = sscanf(y_value,"%lf",&y);
			if (err != 1)
			{
				printf("\nError: could not properly retrieve input argument 'y'.\n");
				display_usage();
				return EXIT_FAILURE;
			}
		}
		else if (NULL == mu_value)
		{
			mu_value = argv[i];
			err = sscanf(mu_value,"%lf",&mu);
			if (err != 1)
			{
				printf("\nError: could not properly retrieve input argument 'mu'.\n");
				display_usage();
				return EXIT_FAILURE;
			}
		}
		else if (NULL == p_value)
		{
			p_value = argv[i];
			err = sscanf(p_value,"%lf",&p);
			if (err != 1)
			{
				printf("\nError: could not properly retrieve input argument 'p'.\n");
				display_usage();
				return EXIT_FAILURE;
			}
		}
	}
	if ((NULL == x_value) || (NULL == y_value) || (NULL == mu_value) || (NULL == p_value))
	{
		printf("\nError: invalid number of arguments.\n");
		display_usage();
		return EXIT_FAILURE;
	}

	/* chech consistency (can be removed to save time) */
	errstat = deltagammainccheck(x, y, mu, p, &flag);
	if (errstat)
	{
		switch (errstat) {
		case E_DOMNANARG:
			printf("\nError: inputs NaN.\n");
			break;
		case E_DOMNEGARG:
			printf("\nError: input '%c' must be nonnegative!\n", flag);
			break;
		case E_DOMGT:
			printf("\nError: you must choose x <= y!\n");
			break;
		case E_DOMNOSOLVE:
			if (flag == 'y')
				printf("\nError: 'mu' < 0 is not allowed when y = +infinity!\n");
			else if (flag == 'p')
				printf("\nError: non integer values for input 'p' are not allowed when mu < 0!\n");
			break;
		case E_DOMZERONEGARG:
			printf("\nError: you must choose input 'p' such as (p > 0)!\n");
			break;
		case E_DOMZERO:
			printf("\nError: input 'mu' must be nonzero!\n");
			break;
		default:
			break;
		}
		printf("Type deltagammainc --help to display help.\n\n");
		return EXIT_FAILURE;
	}

	/*** compute deltagammainc and printf result ***/
	printf("\nComputing I = integral over [x,y] of s^{p-1} * exp(-mu*s) ds,\n");
	printf("where (hexadecimal): x=%a, y=%a, mu=%a, p=%a,\n",x,y,mu,p);
	printf("(in decimal approx): x=%.*g, y=%.*g, mu=%.*g, p=%.*g.\n\n",
	       DBL_DIG, x, DBL_DIG, y, DBL_DIG, mu, DBL_DIG, p);

	/***************** kernel *****************/
	deltagammainc(&rho,&sigma,&method,x,y,mu,p);
	/**************** end kernel ***************/

	/* deal with verbose mode (print additional information)*/
	if (vflag)
	{
		switch (method)
		{
		case -1 :
			printf("Details: I = 0 because you selected x=y (at machine precision).\n\n");
			break;
		case -2 :
			printf("Details: I is equal to the complete gamma function (up to the normalization factor mu),\n");
			printf("since you selected x=0 and y=infinity. I will be estimated using Pugh's approximation.\n\n");
			break;
		case 1 : // differences
			printf("Details: I will be computed as a difference of integrals I=A-B.\n\n");
			break;
		case 2 : // Romberg
			printf("Details: I will be computed using a Romberg approximation.\n\n");
			break;
		}
	}

	/* manage display with decomposition I = a*10^(b) where a in [1,10) and b integer */
	a=deltagammaincsolver(rho,sigma);
	if (a == 0) printf("Output: I = %.*e\n\n", DBL_DIG, 0.);
	else
	{
		if (a>1e-308 && a<1e308) printf("Output: I = %*.*e\n\n", DBL_DIG, DBL_DIG, a);
		else
		{
			scientific_notation(&a,&b,rho,sigma);
			if (b == (long long int)b)
				printf("Output: I = %.*fe%+03lld\n\n", DBL_DIG, a, (long long int)b);
			else
				printf("Output: I = Huge number\n\n");
		}
	}

	/* display the computed mantissa-exponent representation */
	printf("Representation with double numbers: I = rho*exp(sigma), where\n");
	printf("rho	 = %.e\n", rho);
	printf("sigma = %.e\n\n", sigma);

	return EXIT_SUCCESS;
}
