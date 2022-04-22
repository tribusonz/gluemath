static inline double
ur_bessel_in(int n, double x)
{
	static const double ACC = 200.0; 
	static const int IEXP = numeric_limits<double>::max_exponent/2;
	int j, k;
	double bi, bim, bip, dum, tox, ans;
	if (n == 0)  return i0_core(x);
	if (n == 1)  return i1_core(x);
	if (x * x <= 8.0 * numeric_limits<double>::min())  return 0.0;
	else
	{
		tox = 2.0 / fabs(x);
		bip = ans = 0.0;
		bi = 1.0;
		for (j = 2 * (n + (int)sqrt(ACC * n)); j > 0; j--)
		{
			bim = bip + j * tox * bi;
			bip = bi;
			bi = bim;
			dum = frexp(bi, &k);
			if (k > IEXP)
			{
				ans=ldexp(ans, -IEXP);
				bi=ldexp(bi, -IEXP);
				bip=ldexp(bip, -IEXP);
			}
			if (j == n)  ans = bip;
		}
		ans *= i0(x) / bi;
		return x < 0.0 && (n & 1) ? -ans : ans;
	}
}
