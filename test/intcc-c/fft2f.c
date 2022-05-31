/*******************************************************************************
	Fast Fourier/Cosine/Sine Transform
*******************************************************************************/
#include "fft2f.h"

static void
bitrv2(int n, double *a)
{
	int j, j1, k, k1, l, m, m2, n2;
	double xr, xi;
	
	m = n >> 2;
	m2 = m << 1;
	n2 = n - 2;
	k = 0;
	for (j = 0; j <= m2 - 4; j += 4)
	{
		if (j < k)
		{
			xr = a[j];
			xi = a[j + 1];
			a[j] = a[k];
			a[j + 1] = a[k + 1];
			a[k] = xr;
			a[k + 1] = xi;
		}
		else if (j > k)
		{
			j1 = n2 - j;
			k1 = n2 - k;
			xr = a[j1];
			xi = a[j1 + 1];
			a[j1] = a[k1];
			a[j1 + 1] = a[k1 + 1];
			a[k1] = xr;
			a[k1 + 1] = xi;
		}
		k1 = m2 + k;
		xr = a[j + 2];
		xi = a[j + 3];
		a[j + 2] = a[k1];
		a[j + 3] = a[k1 + 1];
		a[k1] = xr;
		a[k1 + 1] = xi;
		l = m;
		while (k >= l)
		{
			k -= l;
			l >>= 1;
		}
		k += l;
	}
}


void
cdft(int n, double wr, double wi, double *a)
{
	void bitrv2(int n, double *a);
	int i, j, k, l, m;
	double wkr, wki, wdr, wdi, ss, xr, xi;
	
	m = n;
	while (m > 4)
	{
		l = m >> 1;
		wkr = 1;
		wki = 0;
		wdr = 1 - 2 * wi * wi;
		wdi = 2 * wi * wr;
		ss = 2 * wdi;
		wr = wdr;
		wi = wdi;
		for (j = 0; j <= n - m; j += m)
		{
			i = j + l;
			xr = a[j] - a[i];
			xi = a[j + 1] - a[i + 1];
			a[j] += a[i];
			a[j + 1] += a[i + 1];
			a[i] = xr;
			a[i + 1] = xi;
			xr = a[j + 2] - a[i + 2];
			xi = a[j + 3] - a[i + 3];
			a[j + 2] += a[i + 2];
			a[j + 3] += a[i + 3];
			a[i + 2] = wdr * xr - wdi * xi;
			a[i + 3] = wdr * xi + wdi * xr;
		}
		for (k = 4; k <= l - 4; k += 4)
		{
			wkr -= ss * wdi;
			wki += ss * wdr;
			wdr -= ss * wki;
			wdi += ss * wkr;
			for (j = k; j <= n - m + k; j += m)
			{
				i = j + l;
				xr = a[j] - a[i];
				xi = a[j + 1] - a[i + 1];
				a[j] += a[i];
				a[j + 1] += a[i + 1];
				a[i] = wkr * xr - wki * xi;
				a[i + 1] = wkr * xi + wki * xr;
				xr = a[j + 2] - a[i + 2];
				xi = a[j + 3] - a[i + 3];
				a[j + 2] += a[i + 2];
				a[j + 3] += a[i + 3];
				a[i + 2] = wdr * xr - wdi * xi;
				a[i + 3] = wdr * xi + wdi * xr;
			}
		}
		m = l;
	}
	if (m > 2)
	{
		for (j = 0; j <= n - 4; j += 4)
		{
			xr = a[j] - a[j + 2];
			xi = a[j + 1] - a[j + 3];
			a[j] += a[j + 2];
			a[j + 1] += a[j + 3];
			a[j + 2] = xr;
			a[j + 3] = xi;
		}
	}
	if (n > 4)  bitrv2(n, a);
}


void
rdft(int n, double wr, double wi, double *a)
{
	void cdft(int n, double wr, double wi, double *a);
	int j, k;
	double wkr, wki, wdr, wdi, ss, xr, xi, yr, yi;
	
	if (n > 4)
	{
		wkr = 0;
		wki = 0;
		wdr = wi * wi;
		wdi = wi * wr;
		ss = 4 * wdi;
		wr = 1 - 2 * wdr;
		wi = 2 * wdi;
		if (wi >= 0)
		{
			cdft(n, wr, wi, a);
			xi = a[0] - a[1];
			a[0] += a[1];
			a[1] = xi;
		}
		for (k = (n >> 1) - 4; k >= 4; k -= 4)
		{
			j = n - k;
			xr = a[k + 2] - a[j - 2];
			xi = a[k + 3] + a[j - 1];
			yr = wdr * xr - wdi * xi;
			yi = wdr * xi + wdi * xr;
			a[k + 2] -= yr;
			a[k + 3] -= yi;
			a[j - 2] += yr;
			a[j - 1] -= yi;
			wkr += ss * wdi;
			wki += ss * (0.5 - wdr);
			xr = a[k] - a[j];
			xi = a[k + 1] + a[j + 1];
			yr = wkr * xr - wki * xi;
			yi = wkr * xi + wki * xr;
			a[k] -= yr;
			a[k + 1] -= yi;
			a[j] += yr;
			a[j + 1] -= yi;
			wdr += ss * wki;
			wdi += ss * (0.5 - wkr);
		}
		j = n - 2;
		xr = a[2] - a[j];
		xi = a[3] + a[j + 1];
		yr = wdr * xr - wdi * xi;
		yi = wdr * xi + wdi * xr;
		a[2] -= yr;
		a[3] -= yi;
		a[j] += yr;
		a[j + 1] -= yi;
		if (wi < 0)
		{
			a[1] = 0.5 * (a[0] - a[1]);
			a[0] -= a[1];
			cdft(n, wr, wi, a);
		}
	}
	else
	{
		if (wi < 0)
		{
			a[1] = 0.5 * (a[0] - a[1]);
			a[0] -= a[1];
		}
		if (n > 2)
		{
			xr = a[0] - a[2];
			xi = a[1] - a[3];
			a[0] += a[2];
			a[1] += a[3];
			a[2] = xr;
			a[3] = xi;
		}
		if (wi >= 0)
		{
			xi = a[0] - a[1];
			a[0] += a[1];
			a[1] = xi;
		}
	}
}


void
ddct(int n, double wr, double wi, double *a)
{
	void rdft(int n, double wr, double wi, double *a);
	int j, k, m;
	double wkr, wki, wdr, wdi, ss, xr;
	
	if (n > 2)
	{
		wkr = 0.5;
		wki = 0.5;
		wdr = 0.5 * (wr - wi);
		wdi = 0.5 * (wr + wi);
		ss = 2 * wi;
		if (wi < 0)
		{
			xr = a[n - 1];
			for (k = n - 2; k >= 2; k -= 2)
			{
				a[k + 1] = a[k] - a[k - 1];
				a[k] += a[k - 1];
			}
			a[1] = 2 * xr;
			a[0] *= 2;
			rdft(n, 1 - ss * wi, ss * wr, a);
			xr = wdr;
			wdr = wdi;
			wdi = xr;
			ss = -ss;
		}
		m = n >> 1;
		for (k = 1; k <= m - 3; k += 2)
		{
			j = n - k;
			xr = wdi * a[k] - wdr * a[j];
			a[k] = wdr * a[k] + wdi * a[j];
			a[j] = xr;
			wkr -= ss * wdi;
			wki += ss * wdr;
			xr = wki * a[k + 1] - wkr * a[j - 1];
			a[k + 1] = wkr * a[k + 1] + wki * a[j - 1];
			a[j - 1] = xr;
			wdr -= ss * wki;
			wdi += ss * wkr;
		}
		k = m - 1;
		j = n - k;
		xr = wdi * a[k] - wdr * a[j];
		a[k] = wdr * a[k] + wdi * a[j];
		a[j] = xr;
		a[m] *= wki + ss * wdr;
		if (wi >= 0)
		{
			rdft(n, 1 - ss * wi, ss * wr, a);
			xr = a[1];
			for (k = 2; k <= n - 2; k += 2)
			{
				a[k - 1] = a[k] - a[k + 1];
				a[k] += a[k + 1];
			}
			a[n - 1] = xr;
		}
	}
	else
	{
		if (wi >= 0)
		{
			xr = 0.5 * (wr + wi) * a[1];
			a[1] = a[0] - xr;
			a[0] += xr;
		}
		else
		{
			xr = a[0] - a[1];
			a[0] += a[1];
			a[1] = 0.5 * (wr - wi) * xr;
		}
	}
}


void
ddst(int n, double wr, double wi, double *a)
{
	void rdft(int n, double wr, double wi, double *a);
	int j, k, m;
	double wkr, wki, wdr, wdi, ss, xr;
	
	if (n > 2)
	{
		wkr = 0.5;
		wki = 0.5;
		wdr = 0.5 * (wr - wi);
		wdi = 0.5 * (wr + wi);
		ss = 2 * wi;
		if (wi < 0)
		{
			xr = a[n - 1];
			for (k = n - 2; k >= 2; k -= 2)
			{
				a[k + 1] = a[k] + a[k - 1];
				a[k] -= a[k - 1];
			}
			a[1] = -2 * xr;
			a[0] *= 2;
			rdft(n, 1 - ss * wi, ss * wr, a);
			xr = wdr;
			wdr = -wdi;
			wdi = xr;
			wkr = -wkr;
		}
		m = n >> 1;
		for (k = 1; k <= m - 3; k += 2)
		{
			j = n - k;
			xr = wdi * a[j] - wdr * a[k];
			a[k] = wdr * a[j] + wdi * a[k];
			a[j] = xr;
			wkr -= ss * wdi;
			wki += ss * wdr;
			xr = wki * a[j - 1] - wkr * a[k + 1];
			a[k + 1] = wkr * a[j - 1] + wki * a[k + 1];
			a[j - 1] = xr;
			wdr -= ss * wki;
			wdi += ss * wkr;
		}
		k = m - 1;
		j = n - k;
		xr = wdi * a[j] - wdr * a[k];
		a[k] = wdr * a[j] + wdi * a[k];
		a[j] = xr;
		a[m] *= wki + ss * wdr;
		if (wi >= 0)
		{
			rdft(n, 1 - ss * wi, ss * wr, a);
			xr = a[1];
			for (k = 2; k <= n - 2; k += 2)
			{
				a[k - 1] = a[k + 1] - a[k];
				a[k] += a[k + 1];
			}
			a[n - 1] = -xr;
		}
	}
	else
	{
		if (wi >= 0)
		{
			xr = 0.5 * (wr + wi) * a[1];
			a[1] = xr - a[0];
			a[0] += xr;
		}
		else
		{
			xr = a[0] + a[1];
			a[0] -= a[1];
			a[1] = 0.5 * (wr - wi) * xr;
		}
	}
}


static void
bitrv(int n, double *a)
{
	int j, k, l, m, m2, n1;
	double xr;
	
	if (n > 2)
	{
		m = n >> 2;
		m2 = m << 1;
		n1 = n - 1;
		k = 0;
		for (j = 0; j <= m2 - 2; j += 2)
		{
			if (j < k)
			{
				xr = a[j];
				a[j] = a[k];
				a[k] = xr;
			}
			else if (j > k)
			{
				xr = a[n1 - j];
				a[n1 - j] = a[n1 - k];
				a[n1 - k] = xr;
			}
			xr = a[j + 1];
			a[j + 1] = a[m2 + k];
			a[m2 + k] = xr;
			l = m;
			while (k >= l)
			{
				k -= l;
				l >>= 1;
			}
			k += l;
		}
	}
}


void
dfct(int n, double wr, double wi, double *a)
{
	void ddct(int n, double wr, double wi, double *a);
	void bitrv(int n, double *a);
	int j, k, m, mh;
	double xr, xi, an;
	
	m = n >> 1;
	for (j = 0; j <= m - 1; j++)
	{
		k = n - j;
		xr = a[j] + a[k];
		a[j] -= a[k];
		a[k] = xr;
	}
	an = a[n];
	while (m >= 2)
	{
		ddct(m, wr, wi, a);
		xr = 1 - 2 * wi * wi;
		wi *= 2 * wr;
		wr = xr;
		bitrv(m, a);
		mh = m >> 1;
		xi = a[m];
		a[m] = a[0];
		a[0] = an - xi;
		an += xi;
		for (j = 1; j <= mh - 1; j++)
		{
			k = m - j;
			xr = a[m + k];
			xi = a[m + j];
			a[m + j] = a[j];
			a[m + k] = a[k];
			a[j] = xr - xi;
			a[k] = xr + xi;
		}
		xr = a[mh];
		a[mh] = a[m + mh];
		a[m + mh] = xr;
		m = mh;
	}
	xi = a[1];
	a[1] = a[0];
	a[0] = an + xi;
	a[n] = an - xi;
	bitrv(n, a);
}


void
dfst(int n, double wr, double wi, double *a)
{
	void ddst(int n, double wr, double wi, double *a);
	void bitrv(int n, double *a);
	int j, k, m, mh;
	double xr, xi;
	
	m = n >> 1;
	for (j = 1; j <= m - 1; j++)
	{
		k = n - j;
		xr = a[j] - a[k];
		a[j] += a[k];
		a[k] = xr;
	}
	a[0] = a[m];
	while (m >= 2)
	{
		ddst(m, wr, wi, a);
		xr = 1 - 2 * wi * wi;
		wi *= 2 * wr;
		wr = xr;
		bitrv(m, a);
		mh = m >> 1;
		for (j = 1; j <= mh - 1; j++)
		{
			k = m - j;
			xr = a[m + k];
			xi = a[m + j];
			a[m + j] = a[j];
			a[m + k] = a[k];
			a[j] = xr + xi;
			a[k] = xr - xi;
		}
		a[m] = a[0];
		a[0] = a[m + mh];
		a[m + mh] = a[mh];
		m = mh;
	}
	a[1] = a[0];
	a[0] = 0;
	bitrv(n, a);
}

