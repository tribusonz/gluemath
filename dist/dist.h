/*******************************************************************************
	GLUE-Math Library -- Distribution C Compiler ABI

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GLUEMATH_DISTRIBUTION_H
#define GLUEMATH_DISTRIBUTION_H

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
 *  - Implementation of Standard Normal Distribution -
 *  Characteristics of Standard Normal N(0,1), its more than half are constants.
 *  The inline coefficient vector is follows:
 *  mean: 0.0
 *  mode: 0.0
 *  stdev: 1.0
 *  covariance: 1.0
 *  skewness: 0.0
 *  kurtosis: 3.0
 *  kurtosis3: 0.0
 *  median: 0.0
 *  iqr: $2\,\sqrt{2}\,\mathrm{erfc}^{-1}(\frac{1}{2}) \approx$ 1.34897950039216348640
 *  siqr: $\sqrt{2}\,\mathrm{erfc}^{-1}(\frac{1}{2}) \approx$ 0.67448975019608174320
 *  momental_skewness: 0.0
 *  charfunc: calculate $e^{\neg{x^{2}/2}}$
 *  mgfunc: calculate $e^{x^{2}/2}$
 *  fmgfunc: calculate $e^{\ln^{2}(x)/2}$
 *  
 *  Where, $\mathrm{erfc}^{\neg1}(x)$ is inverse complementary error function,
 *         $\ln^{2}(x)$ is polylogarithm. difinition is: $(\ln(a)\ln_{a}(x))^{2}$
 *  Reference: https://www.wolframalpha.com/input/?i=log%5E2%28x%29
*******************************************************************************/

/*
 *  C ABI: snormpdf(x) -> f64
 *  
 *  Computes {x} of Standard Normal PDF.
 *  
 *  @x: X-axis, -Infinity <= x <= Infinity
 *  @retval: solve of {x} the standard normal PDF
 *  
 *  Calculation Formula:
 *  $\frac{e^{x^{2}/2}}{\sqrt{2\pi}$
 *  
 *  Special behaviors:
 *  {x} is +-Infinity: return 0.0
 *  {x} is NaN: return NaN (computational NaN handling)
 */
extern double gml_snormpdf(double);
#define snormpdf gml_snormpdf

/*
 *  C ABI: snormcdf(x) -> f64
 *  C ABI: snormcdfc(x) -> f64
 *  
 *  Computes quantiles that {x} of Standard Normal CDF.
 *  
 *  @x: X-axis (lower/upper order), -Infinity <= x <= Infinity
 *  @retval: quantile of {x} the standard normal CDF
 *  
 *  Calculation Formula:
 *  $P\left(X\leq{x}\right)=\frac{1}{2}\,\mathrm{erfc}(\neg\frac{x}{\sqrt{2}})$
 *  Where, $\mathrm{erfc}(x)$ is Complementary error function.
 *  
 *  Special behaviors:
 *  {x} is -Infinity: return 0.0 (lower)
 *  {x} is Infinity: return 1.0 (lower)
 *  {x} is NaN: return NaN (computational NaN handling)
 */
extern double gml_snormcdf(double);
#define snormcdf gml_snormcdf
extern double gml_snormcdfc(double);
#define snormcdfc gml_snormcdfc

/*
 *  C ABI: snormcdfinv(q) -> f64
 *  C ABI: snormcdfcinv(q) -> f64
 *  
 *  Computes {x} of Standard Normal CDF.
 *  
 *  @q: quantile (lower/upper order),  0 <= q <= 1
 *  @retval: solve of {x} the standard normal CDF
 *  
 *  Calculation Formula:
 *  $P^{\neg1}\left(q\right)=\neg\sqrt{2}\,\mathrm{erfc}^{\neg1}\left(2q\right),\,\mathrm{But}\:0\leq{q}\leq1$
 *  Where, $\mathrm{erfc}^{\neg1}(x)$ is inverse complementary error function.
 *  
 *  Special behaviors:
 *  Co-domain: 0 <= q <= 1
 *  If domain error: return NaN (computational NaN handling)
 */
extern double gml_snormcdfinv(double);
#define snormcdfinv gml_snormcdfinv
extern double gml_snormcdfcinv(double);
#define snormcdfcinv gml_snormcdfcinv

/* Standard Normal Distribution: Mean */
// snormmean: to vec, 0.0

/* Standard Normal Distribution: Mode */
// snormmode: to vec, 0.0

/* Standard Normal Distribution: Standard Deviation */
// snormstdev: to vec, 1.0

/* Standard Normal Distribution: Covariance */
// snormcov: to vec, 1.0

/* Standard Normal Distribution: Skewness */
// snormskew: to vec, 0.0

/* Standard Normal Distribution: Kurtsis */
// snormkurt: to vec, 3.0

/* Standard Normal Distribution: Kurtsis Minus 3 */
// snormkurt3: to vec, 0.0

/* Standard Normal Distribution: Median */
// snormmed: to vec, 0.0

/*
 *  C ABI: snormcharfunc(x) -> f64
 *  
 *  Computes x of Characteristic Function for Standard Normal.
 *  N(0, 1) of characteristics does not have an imaginary part.
 */
extern double gml_snormcharfunc(double);
#define snormcharfunc gml_snormcharfunc

/*
 *  C ABI: snormmgfunc(x) -> f64
 *  
 *  Computes x of Moment-Generating Function for Standard Normal.
 */
extern double gml_snormmgfunc(double);
#define snormmgfunc gml_snormmgfunc

/*
 *  C ABI: snormfmgfunc(x) -> f64
 *  
 *  Computes x of Factorial Moment-Generating Function for Standard Normal.
 */
extern double gml_snormfmgfunc(double);
#define snormfmgfunc gml_snormfmgfunc

/*
 *  C ABI: normpdf(x, mu, sigma) -> f64
 *  
 *  Computes {x; mu, sigma} of Normal PDF.
 *  
 *  @x: X-axis, -Infinity <= x <= Infinity
 *  @mu: mean
 *  @sigma: standard deviation (positive direction)
 *  @retval: solve of {x} the normal PDF
 *  
 *  Calculation Formula:
 *  $\frac{e^{\neg(x-\mu)^{2}/(2\sigma^{2})}}{\sqrt{2\pi}\sigma}$
 *  
 *  Special behaviors:
 *  {x} is +-Infinity: return 0.0
 *  {x} is NaN: return NaN (computational NaN handling)
 *  {sigma} is zero or negative number: return 0.0
 *  {x} is $\Re$ and either or neither parameters have NaN: return 0.0
 */
extern double gml_normpdf(double, double, double);
#define normpdf gml_normpdf

/*
 *  C ABI: normcdf(x, mu, sigma) -> f64
 *  C ABI: normcdfc(x, mu, sigma) -> f64
 *  
 *  Computes quantiles that {x; mu, sigma} of Normal CDF.
 *  
 *  @x: X-axis (lower/upper order), -Infinity <= x <= Infinity
 *  @mu: mean
 *  @sigma: standard deviation (positive direction)
 *  @retval: quantile of {x; mu, sigma} the normal CDF
 *  
 *  Calculation Formula:
 *  $P\left(X\leq{x}\right)=\frac{1}{2}\,\mathrm{erfc}(\neg\frac{x}{\sqrt{2}})$
 *  Where, $\mathrm{erfc}(x)$ is Complementary error function.
 *  
 *  Special behaviors:
 *  {x} is -Infinity: return 0.0 (lower)
 *  {x} is Infinity: return 1.0 (lower)
 *  {x} is NaN: return NaN (computational NaN handling)
 *  {sigma} is zero or negative number: return 0.0
 *  {x} is $\Re$ and either or neither parameters have NaN: return 0.0
 */
extern double gml_normcdf(double, double, double);
#define normcdf gml_normcdf
extern double gml_normcdfc(double, double, double);
#define normcdfc gml_normcdfc

/*
 *  C ABI: normcdfinv(q, mu, sigma) -> f64
 *  C ABI: normcdfcinv(q, mu, sigma) -> f64
 *  
 *  Computes {x} of Normal CDF.
 *  
 *  @q: quantile (lower/upper order),  0 <= q <= 1
 *  @mu: mean
 *  @sigma: standard deviation (positive direction)
 *  @retval: solve of {x} the standard normal CDF
 *  
 *  Calculation Formula:
 *  $P^{\neg1}\left(q\right)=\neg\sqrt{2}\,\mathrm{erfc}^{\neg1}\left(2q\right),\,\mathrm{But}\:0\leq{q}\leq1$
 *  Where, $\mathrm{erfc}^{\neg1}(x)$ is inverse complementary error function.
 *  
 *  Special behaviors:
 *  Co-domain: 0 <= q <= 1
 *  If domain error: return NaN (computational NaN handling)
 *  {sigma} is zero or negative number: return 0.0
 *  {x} is $\Re$ and either or neither parameters have NaN: return NaN
 */
extern double gml_normcdfinv(double, double, double);
#define normcdfinv gml_normcdfinv
extern double gml_normcdfcinv(double, double, double);
#define normcdfcinv gml_normcdfcinv

/*******************************************************************************
 *  - Implementation of Chi-Square Distribution -
*******************************************************************************/

/*
 *  C ABI: chisqpdf(x, nu) -> f64
 *  
 *  Computes probability that {x; nu} of Chi-Squared.
 *  
 *  @x: X-axis (lower/upper order), 0 <= x <= Infinity
 *  @nu: N, degree of freedom (handle integer)
 *  @retval: probability of {x; mu} the chi-squared PDF
 *  
 *  Calculation Formula:
 *  $X\sim{x}_{\nu}^{2}=\left\{\begin{matrix}
 *   \frac{2^{\neg\nu/2}e^{\neg{x/2}}x^{\nu/2\neg{1}}}{\Gamma(\frac{\nu}{2})}& x>0 \\
 *   0 & \rm{Otherwise} \\
 *   \end{matrix}\right.$
 *  Where, $\Gamma(z)$ is Gamma Function, and is DF is natural numbers then $\Gamma(\nu)=(\nu\neg{1})!$.
 *  
 *  NOTE:
 *  Formula uses Gamma Function that has a factorial so number is jumped up.
 *  In interface implementations, it is appropriate to use logarithmic gamma function to find solutions.
 *  
 *  Special behaviors:
 *  {x} is zero or negative number: return 0.0
 *  {x} is +-Infinity: return 0.0
 *  {x} is NaN: return NaN (context-switching NaN handling)
 *  {mu} is zero or negative number: return NaN
 *  {mu} is NaN: return NaN
 */
extern double gml_chisqpdf(double, double);
#define chisqpdf gml_chisqpdf

/*
 *  C ABI: chisqcdf(x, nu) -> f64
 *  C ABI: chisqcdfc(x, nu) -> f64
 *  
 *  Computes quantiles that {x; nu} of Chi-Square CDF.
 *  A dedicated routine is provided, but for special examples such as degrees-of-freedom
 *  the 100 or more, we try to get a solution from an incomplete gamma function.
 *  
 *  @x: X-axis (lower/upper order), 0 <= x <= Infinity
 *  @nu: N, degree of freedom (handle integer)
 *  @retval: quantile of {x; mu} the chi-squared CDF
 *  
 *  Calculation Formula:
 *  $P(X\leq{x})=\left\{\begin{matrix}Q(\frac{\nu}{2}),0,\frac{x}{2})&x>0\\0&\mathrm{Otherwise}\\\end{matrix}\right.$
 *  Where, $Q(\frac{\nu}{2}),0,\frac{x}{2})$ is Genealized Regularized Incomplete Gamma Function.
 *  
 *  Special behaviors:
 *  {x} is zero or negative number: return 0.0 (lower)
 *  {x} is -Infinity: return 0.0 (lower)
 *  {x} is Infinity: return 1.0 (lower)
 *  {x} is NaN: return NaN (context-switching NaN handling)
 *  {mu} is zero or negative number: return NaN
 *  {mu} is NaN: return NaN
 */
extern double gml_chisqcdf(double, double);
#define chisqcdf gml_chisqcdf
extern double gml_chisqcdfc(double, double);
#define chisqcdfc gml_chisqcdfc

/*******************************************************************************
 *  - Implementation of F-Distribution -
*******************************************************************************/

extern double gml_fcdf(double, double, double);
#define fcdf gml_fcdf
extern double gml_fcdfc(double, double, double);
#define fcdfc gml_fcdfc

/*******************************************************************************
 *  - Implementation of  Student's t Distribution -
*******************************************************************************/

extern double gml_tcdf(double, double);
#define tcdf gml_tcdf
extern double gml_tcdfc(double, double);
#define tcdfc gml_tcdfc


/*******************************************************************************
 *  - Implementation of Binomial Distribution -
 *  The basis of normal and poisson - this is a binomial Distribution
 *  Characteristics that it is all useful. It is better to update the inline vector every time a parameter is set.
 *  The inline coefficient vector is follows:
 *  PARAMATER: n= :nu, number of trials. p= :phi, percentile of success
 *  mean: calculate $np$
 *  mode: nil
 *  stdev: calculate $\sqrt{n(1\neg{p})p}$
 *  covariance: calculate $n(1\neg{p})p$
 *  skewness: calculate $\frac{1\neg{2}p}{\sqrt{n(1\neg{p})p}}$
 *  kurtosis: calculate $\frac{1\neg{6}(1\neg{p})p}{n(p\neg{p})p}+3$
 *  kurtosis3: calculate $\frac{\neg{6}p^{2}+6p\neg{1}}{n(p\neg{1})p}$
 *  median: nil
 *  iqr: nil
 *  siqr: nil
 *  momental_skewness: calculate $\frac{1\neg{2}p}{2\sqrt{n(1\neg{p})p}}$
 *  charfunc: calculate $(p\,{e^{\imath{x}}\neg{p}+1})^{n}$
 *  mgfunc: calculate $(p\,(e^{x}\neg{1})+1)^{n}$
 *  fmgfunc: calculate $(p\,(x\neg{1})+1)^{n}$
 *  
 *  Note:
 *  We often see well appeared in the formula that $(1\neg{p})$ is 'percentile of failure'.
 *  This is frequently used when dealing with binomial distribution.
 *  The parameter name is given 'q'. q means 'quantile'.
 *  Covariance $n(1\neg{p})p$ can measuring how far away the binomial coefficient is from the mean as a factorial.
*******************************************************************************/

/*
 *  C ABI: binompmf(x, nu, phi) -> f64
 *  
 *  Computes solve of Bi(n, p) that the {x} of probability.
 *  
 *  @x: number of success, 0 <= x <= n
 *  @nu: number of trials (bernoulli trials), 1 .. MAX
 *  @phi: percentile, 0 <= phi <= 1
 *  @retval: solve of binomial PMF
 *  
 *  Calculation Formula:
 *  $P\left(X=x\right)=\left\{\begin{matrix}p^{x}\binom{n}{x}\left(1\neg{p}\right)^{n\neg{x}}&0\leq{x}\leq{n}\\0&\mathrm{Otherwise}\\\end{matrix}\right.$
 *  Where, $\binom{n}{r}$ is Binomial Coefficients.
 */
extern double gml_binompmf(int, int, double);
#define binompmf gml_binompmf

extern double gml_binomcdf(double, int, double);
#define binomcdf gml_binomcdf
extern double gml_binomcdfc(double, int, double);
#define binomcdfc gml_binomcdfc

extern double gml_binomcdfinv(double, int, double);
#define binomcdfinv gml_binomcdfinv
extern double gml_binomcdfcinv(double, int, double);
#define binomcdfcinv gml_binomcdfcinv

extern int gml_binomrng(int, double);
#define binomrng gml_binomrng

/*******************************************************************************
 *  - Implementation of Poisson Distribution -
*******************************************************************************/

/*
 *  call-seq:
 *    (UserLevel Code)
 *      Distribution.poisson#p(x) -> real (r8)
 *    (Native Code)
 *      poisspmf(x, lambda) -> real (r8)
 *  
 *  Computes solve of $Poisson(\lambda)$ that the {x} of probability.
 *  In order to find a solution, the factorial and exponential are divided,
 *  but this causes a top digit overflow, so it is calculated internally by
 *  logarithm.
 *  
 *  $
 *  \begin{array}{rcl}
 *  P(X=x) & = & \frac{e^{-\lambda}\lambda^x}{x!} \\
 *  & = & e^{\ln(\frac{e^{-\lambda}\lambda^x}{x!})} \\
 *  & = & e^{-\ln(x!)+\lambda+x\ln(\lambda)}
 *  \end{array}
 *  $
 *  Where, $n!$ is factorial function, $e^x$ is exponential function, $\ln(x)$
 *  is logarithm function.
 *  
 *  @x: X-axis (Integer type), positive direction
 *  @lambda: level off [out], positive direction
 *  @retval: solve Poisson {np} PMF
 *  
 */
extern double gml_poisspmf(int, double);
#define poisspmf gml_poisspmf

extern double gml_poisscdf(double, double);
#define poisscdf gml_poisscdf
extern double gml_poisscdfc(double, double);
#define poisscdfc gml_poisscdfc

/*
 *  C ABI: poisscdfinv(q) -> f64
 *  C ABI: poisscdfcinv(q) -> f64
 *  
 *  Computes number-of-trials of Poisson CDF as real.
 *  
 *  @q: quantile (lower/upper order),  0 <= q <= 1
 *  @lambda: level off [out], positive direction
 *  @retval: solve Poisson {np} on quantile
 */
extern double gml_poisscdfinv(double, double);
#define poisscdfinv gml_poisscdfinv
extern double gml_poisscdfcinv(double, double);
#define poisscdfcinv gml_poisscdfcinv

extern int gml_poissrng(double);
#define poissrng gml_poissrng

/*******************************************************************************
 *  - Implementation of Geometric Distribution -


 * NOTE:
 * The cumulative analysis of geometric distribution is not unique because of
 * the discrete type. Here, accumulation and inverse accumulation analyze
 * integer values, allowing some errors, but at the same time divergence as a-
 * fraction. Therefore, the inverse cumulative analysis results are not
 * necessarily equivalent to cumulative x.
*******************************************************************************/
extern double gml_geompmf(int, double);
#define geompmf gml_geompmf

extern double gml_geomcdf(double, double);
#define geomcdf gml_geomcdf
extern double gml_geomcdfc(double, double);
#define geomcdfc gml_geomcdfc


extern double gml_geomcdfinv(double, double);
#define geomcdfinv gml_geomcdfinv
extern double gml_geomcdfcinv(double, double);
#define geomcdfcinv gml_geomcdfcinv

extern int gml_geomrng(double);
#define geomrng gml_geomrng

#if defined(__cplusplus)
}
#endif

#endif /* GLUEMATH_DISTRIBUTION_H */
