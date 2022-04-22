/*******************************************************************************
	Random Sampling Library: Continuous Distributions
	
	Reference:
		C gengo ni yoru Hyoujun Algorithm Jiten (Japanese)
		Handbook of the Standard Algorithms in C
		[Gijutsu Hyoron Sha]
		- Haruhiko Okumura

		https://omitakahiro.github.io/random/random_variables_generation.html
		- Takahiro Omi

*******************************************************************************/

/***** Continuous Distributions ***********************************************/

#include <math.h>
#define PI 3.141592653589793238
#define E  2.718281828459045235

/* Normal Distribution (Box-Muller Method) */
double
rand_norm(register double mu, register double sigma)
{
	static int sw = 0;
	static double t, u;

	if (sw == 0) {
		sw = 1;
		t = sqrt(-2 * log(1 - uniform()));  u = 2 * PI * uniform();
		return mu + sigma * t * cos(u);
	} else {
		sw = 0;
		return mu + sigma * t * sin(u);
	}
}

/* Standard Normal Distribution */
double
rand_snorm(void)
{
	static int sw = 0;
	static double r1, r2, s;

	if (sw == 0) {
		sw = 1;
		do {
			r1 = 2 * uniform() - 1;
			r2 = 2 * uniform() - 1;
			s = r1 * r1 + r2 * r2;
		} while (s >= 1 || s == 0);
		s = sqrt(-2 * log(s) / s);
		return r1 * s;
	} else {
		sw = 0;
		return r2 * s;
	}
}

/* Gamma Distribution p(x, kappa/2, theta=1), int (1 - 28) */
static inline double
rand_gamma_int(register int two_a)
{
	register int i;
	register double x, r;

	x = 1;
	for (i = two_a / 2; i > 0; i--) x *= uniform();
	x = -log(x);
	if ((two_a & 1) != 0) {  /* if two_a is odd */
		r = rand_snorm();  x += 0.5 * r * r;
	}
	return x;
}

/* Gamma Distribution p(x, kappa, theta=1),  a > 0 */
static inline double
rand_gamma_t1(register double a)
{
	register double t, u, x, y;

	if (a > 1) {
		t = sqrt(2 * a - 1);
		do {
			do {
				/* ŽŸ‚Ì‚Ss‚Í y = tan(PI * uniform()) ‚Æ“¯’l */
				do {
					x = 1 - uniform();  y = 2 * uniform() - 1;
				} while (x * x + y * y > 1);
				y /= x;
				x = t * y + a - 1;
			} while (x <= 0);
			u = (a - 1) * log(x / (a - 1)) - t * y;
		} while (u < -50 || uniform() > (1 + y * y) * exp(u));
	} else {
		t = E / (a + E);
		do {
			if (uniform() < t) {
				x = pow(uniform(), 1 / a);  y = exp(-x);
			} else {
				x = 1 - log(uniform());  y = pow(x, a - 1);
			}
		} while (uniform() >= y);
	}
	return x;
}


/* Gamma Distribution (p(x, kappa, theta)) */
static inline double
rand_gamma_a(register double kappa, register double theta)
{

	register int int_kappa;
	register double frac_kappa;

	int_kappa  = (int)kappa;
	frac_kappa = kappa - (double)int_kappa;

	double u,uu;
	double b,p,x_frac,x_int;
	int i;

	/*integer part*/
	x_int=0;
	for(i=0;i<int_kappa;i++){
		x_int+=-log(uniform()); // add expnential random number with mean 1
	}

	/*fractional part*/
	if( fabs(frac_kappa) < 0.01 ) x_frac=0;

	else{
		b=(exp(1.0)+frac_kappa)/exp(1.0);
		while(1){

			u=uniform();
			p=b*u;

			uu=uniform();

			if(p<=1.0){
				x_frac=pow(p,1.0/frac_kappa);
				if(uu<=exp(-x_frac)) break;
			}

			else{
				x_frac=-log((b-p)/frac_kappa);
				if(uu<=pow(x_frac,frac_kappa-1.0)) break;
			}

		}
	}

	return (x_int+x_frac)*theta;
}

/* switch */
double
rand_gamma(register double kappa, register double theta)
{
	if (theta == 1.0)
		return (int)kappa == kappa && kappa <= 28 ? rand_gamma_int(kappa) : rand_gamma_t1(kappa);
	return rand_gamma_a(kappa, theta);
}

/* Beta Distribution */
static inline double
beta_rnd(register double a, register double b)
{
	register double x, y;

	do {
		x = pow(uniform(), 1 / a);  y = pow(uniform(), 1 / b);
	} while (x + y > 1);
	return x / (x + y);
}

double
rand_beta(register double alpha, register double beta)
{
	if (alpha < 0 || beta < 0)  return 0;
	return beta_rnd(alpha, beta);
}

/* Cauchy Distribution */
double
rand_cauchy(register double mu, register double gamma)
{
    return mu + gamma*tan(PI*(uniform()-0.5));
}

/* Log-normal Distribution */
double
rand_lognorm(register double mu, register double sigma)
{
	register double p = mu + sigma * sqrt(-2.0 * log(uniform())) * sin(2.0 * PI * uniform());
	return exp(p);
}

/* Chi-Square Distribution */
static inline double
chisq_rnd1(register int n)
{
	int i;
	double s, t;

	s = 0;
	for (i = 0; i < n; i++) {  t = rand_snorm();  s += t * t;  }
	return s;
}

static inline double
chisq_rnd(register double n)
{
	if (n <= 0)  return 0.0;
	return 2 * rand_gamma_t1(0.5 * n);
}

double
rand_chisq(register double n)
{
	if (n == fabs(n) && n <= 5)
		return chisq_rnd1((int)n);
	return chisq_rnd(n);
}

/* t-Distribution */
double
rand_t(register double n)
{
	register double a, b, c;

	if (n <= 2) return rand_snorm() / sqrt(rand_chisq(n) / n);
	do {
		a = rand_snorm();
		b = a * a / (n - 2);
		c = log(1 - uniform()) / (1 - 0.5 * n);
	} while (exp(-b-c) > 1 - b);
	return a / sqrt((1 - 2.0 / n) * (1 - b));
}

/* F-Distribution */
double
rand_f(register double n1, register double n2)
{
	if (n1 <= 0 || n2 <= 0)  return 0.0;
	return (rand_chisq(n1) * n2) / (rand_chisq(n2) * n1);
}

/* Weibull Distribution */
double
rand_weibull(register double alpha, register double beta)
{
	if (signbit(alpha) || alpha == 0.0 ||
	    signbit(beta) || beta == 0.0)
		return 0.0;
	return beta * pow(-log(1 - uniform()), 1 / alpha);
}

/* Triangular Distribution */
double
rand_triangular(void)
{
	return uniform() - uniform();
}

/* Power Distribution */
static inline double
power_rnd1(register int n)
{
	register int i;
	register double p, r;

	p = uniform();
	for (i = 0; i < n; i++)
		if ((r = uniform()) > p) p = r;
	return p;
}

static inline double
power_rnd(register double n)
{
	return pow(uniform(), 1.0 / (n + 1));
}

double
rand_power(register double n)
{
	if (signbit(n))  return 0.0;
	else if (n == fabs(n) && n <= 8)
		return power_rnd1((int)n);
	return power_rnd(n);
}

/* Logistic Distribution */
static inline double
logistic_rnd(register double mu, register double beta)
{
	register double r;
	
	r = uniform();
	return mu - beta * log(r / (1 - r));
}

double
rand_logistic(register double mu, register double beta)
{
	if (signbit(mu))  return 0.0;
	return logistic_rnd(mu, beta);
}

/* Exponential Distribution */
double
rand_exp(register double lambda)
{
	register double u = uniform();

	if (u == 0.0 || lambda <= 0)  return 0.0;
	return -log(uniform()) / lambda;
}

/* Inverse Gaussian Distribution */
double
rand_igauss(register double mu, register double lambda)
{
	register double x, y, w, z;
	x = sqrt(-2.0 * log(uniform())) * sin(2.0 * PI * uniform());
	y = x * x; //chi-squared
	w= mu + 0.5 * y * mu * mu / lambda -(0.5 * mu / lambda) *
	   sqrt(4.0 * mu * lambda * y + mu * mu * y * y);
	z = uniform();
 
	if (z < mu / (mu + w)) return w;
	/* else */             return mu*mu/w;
}

/* Pareto Distribution */
double
rand_pareto(register double kappa, register double alpha)
{
	if (kappa <= 0.0 || alpha <= 0.0)  return 0.0;
	return kappa * pow(1 - uniform(), -1 / alpha);
}
