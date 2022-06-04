/*******************************************************************************
Fast Fourier/Cosine/Sine Transform
    dimension   :two
    data length :power of 2
    decimation  :frequency
    radix       :split-radix, row-column
    data        :inplace
    table       :use
functions
    cdft2d: Complex Discrete Fourier Transform
    rdft2d: Real Discrete Fourier Transform
    ddct2d: Discrete Cosine Transform
    ddst2d: Discrete Sine Transform
function prototypes
    void cdft2d(int, int, int, double **, double *, int *, double *);
    void rdft2d(int, int, int, double **, double *, int *, double *);
    void rdft2dsort(int, int, int, double **);
    void ddct2d(int, int, int, double **, double *, int *, double *);
    void ddst2d(int, int, int, double **, double *, int *, double *);
necessary package
    fftsg.c  : 1D-FFT package
macro definitions
    USE_FFT2D_PTHREADS : default=not defined
        FFT2D_MAX_THREADS     : must be 2^N, default=4
        FFT2D_THREADS_BEGIN_N : default=65536
    USE_FFT2D_WINTHREADS : default=not defined
        FFT2D_MAX_THREADS     : must be 2^N, default=4
        FFT2D_THREADS_BEGIN_N : default=131072
*******************************************************************************/
#ifndef FFTSG2D_H
#define FFTSG2D_H

#if defined(cplusplus)
extern "C" {
#endif

/* -------- Complex DFT (Discrete Fourier Transform) --------
    [definition]
        <case1>
            X[k1][k2] = sum_j1=0^n1-1 sum_j2=0^n2-1 x[j1][j2] * 
                            exp(2*pi*i*j1*k1/n1) * 
                            exp(2*pi*i*j2*k2/n2), 0<=k1<n1, 0<=k2<n2
        <case2>
            X[k1][k2] = sum_j1=0^n1-1 sum_j2=0^n2-1 x[j1][j2] * 
                            exp(-2*pi*i*j1*k1/n1) * 
                            exp(-2*pi*i*j2*k2/n2), 0<=k1<n1, 0<=k2<n2
        (notes: sum_j=0^n-1 is a summation from j=0 to n-1)
    [usage]
        <case1>
            ip[0] = 0; // first time only
            cdft2d(n1, 2*n2, 1, a, t, ip, w);
        <case2>
            ip[0] = 0; // first time only
            cdft2d(n1, 2*n2, -1, a, t, ip, w);
    [parameters]
        n1     :data length (int)
                n1 >= 1, n1 = power of 2
        2*n2   :data length (int)
                n2 >= 1, n2 = power of 2
        a[0...n1-1][0...2*n2-1]
               :input/output data (double **)
                input data
                    a[j1][2*j2] = Re(x[j1][j2]), 
                    a[j1][2*j2+1] = Im(x[j1][j2]), 
                    0<=j1<n1, 0<=j2<n2
                output data
                    a[k1][2*k2] = Re(X[k1][k2]), 
                    a[k1][2*k2+1] = Im(X[k1][k2]), 
                    0<=k1<n1, 0<=k2<n2
        t[0...*]
               :work area (double *)
                length of t >= 8*n1,                   if single thread, 
                length of t >= 8*n1*FFT2D_MAX_THREADS, if multi threads, 
                t is dynamically allocated, if t == NULL.
        ip[0...*]
               :work area for bit reversal (int *)
                length of ip >= 2+sqrt(n)
                (n = max(n1, n2))
                ip[0],ip[1] are pointers of the cos/sin table.
        w[0...*]
               :cos/sin table (double *)
                length of w >= max(n1/2, n2/2)
                w[],ip[] are initialized if ip[0] == 0.
    [remark]
        Inverse of 
            cdft2d(n1, 2*n2, -1, a, t, ip, w);
        is 
            cdft2d(n1, 2*n2, 1, a, t, ip, w);
            for (j1 = 0; j1 <= n1 - 1; j1++) {
                for (j2 = 0; j2 <= 2 * n2 - 1; j2++) {
                    a[j1][j2] *= 1.0 / n1 / n2;
                }
            }
        .
*/
extern void cdft2d(int, int, int, double**, double*, int*, double*w);

/* -------- Real DFT / Inverse of Real DFT --------
    [definition]
        <case1> RDFT
            R[k1][k2] = sum_j1=0^n1-1 sum_j2=0^n2-1 a[j1][j2] * 
                            cos(2*pi*j1*k1/n1 + 2*pi*j2*k2/n2), 
                            0<=k1<n1, 0<=k2<n2
            I[k1][k2] = sum_j1=0^n1-1 sum_j2=0^n2-1 a[j1][j2] * 
                            sin(2*pi*j1*k1/n1 + 2*pi*j2*k2/n2), 
                            0<=k1<n1, 0<=k2<n2
        <case2> IRDFT (excluding scale)
            a[k1][k2] = (1/2) * sum_j1=0^n1-1 sum_j2=0^n2-1
                            (R[j1][j2] * 
                            cos(2*pi*j1*k1/n1 + 2*pi*j2*k2/n2) + 
                            I[j1][j2] * 
                            sin(2*pi*j1*k1/n1 + 2*pi*j2*k2/n2)), 
                            0<=k1<n1, 0<=k2<n2
        (notes: R[n1-k1][n2-k2] = R[k1][k2], 
                I[n1-k1][n2-k2] = -I[k1][k2], 
                R[n1-k1][0] = R[k1][0], 
                I[n1-k1][0] = -I[k1][0], 
                R[0][n2-k2] = R[0][k2], 
                I[0][n2-k2] = -I[0][k2], 
                0<k1<n1, 0<k2<n2)
    [usage]
        <case1>
            ip[0] = 0; // first time only
            rdft2d(n1, n2, 1, a, t, ip, w);
        <case2>
            ip[0] = 0; // first time only
            rdft2d(n1, n2, -1, a, t, ip, w);
    [parameters]
        n1     :data length (int)
                n1 >= 2, n1 = power of 2
        n2     :data length (int)
                n2 >= 2, n2 = power of 2
        a[0...n1-1][0...n2-1]
               :input/output data (double **)
                <case1>
                    output data
                        a[k1][2*k2] = R[k1][k2] = R[n1-k1][n2-k2], 
                        a[k1][2*k2+1] = I[k1][k2] = -I[n1-k1][n2-k2], 
                            0<k1<n1, 0<k2<n2/2, 
                        a[0][2*k2] = R[0][k2] = R[0][n2-k2], 
                        a[0][2*k2+1] = I[0][k2] = -I[0][n2-k2], 
                            0<k2<n2/2, 
                        a[k1][0] = R[k1][0] = R[n1-k1][0], 
                        a[k1][1] = I[k1][0] = -I[n1-k1][0], 
                        a[n1-k1][1] = R[k1][n2/2] = R[n1-k1][n2/2], 
                        a[n1-k1][0] = -I[k1][n2/2] = I[n1-k1][n2/2], 
                            0<k1<n1/2, 
                        a[0][0] = R[0][0], 
                        a[0][1] = R[0][n2/2], 
                        a[n1/2][0] = R[n1/2][0], 
                        a[n1/2][1] = R[n1/2][n2/2]
                <case2>
                    input data
                        a[j1][2*j2] = R[j1][j2] = R[n1-j1][n2-j2], 
                        a[j1][2*j2+1] = I[j1][j2] = -I[n1-j1][n2-j2], 
                            0<j1<n1, 0<j2<n2/2, 
                        a[0][2*j2] = R[0][j2] = R[0][n2-j2], 
                        a[0][2*j2+1] = I[0][j2] = -I[0][n2-j2], 
                            0<j2<n2/2, 
                        a[j1][0] = R[j1][0] = R[n1-j1][0], 
                        a[j1][1] = I[j1][0] = -I[n1-j1][0], 
                        a[n1-j1][1] = R[j1][n2/2] = R[n1-j1][n2/2], 
                        a[n1-j1][0] = -I[j1][n2/2] = I[n1-j1][n2/2], 
                            0<j1<n1/2, 
                        a[0][0] = R[0][0], 
                        a[0][1] = R[0][n2/2], 
                        a[n1/2][0] = R[n1/2][0], 
                        a[n1/2][1] = R[n1/2][n2/2]
                ---- output ordering ----
                    rdft2d(n1, n2, 1, a, t, ip, w);
                    rdft2dsort(n1, n2, 1, a);
                    // stored data is a[0...n1-1][0...n2+1]:
                    // a[k1][2*k2] = R[k1][k2], 
                    // a[k1][2*k2+1] = I[k1][k2], 
                    // 0<=k1<n1, 0<=k2<=n2/2.
                    // the stored data is larger than the input data!
                ---- input ordering ----
                    rdft2dsort(n1, n2, -1, a);
                    rdft2d(n1, n2, -1, a, t, ip, w);
        t[0...*]
               :work area (double *)
                length of t >= 8*n1,                   if single thread, 
                length of t >= 8*n1*FFT2D_MAX_THREADS, if multi threads, 
                t is dynamically allocated, if t == NULL.
        ip[0...*]
               :work area for bit reversal (int *)
                length of ip >= 2+sqrt(n)
                (n = max(n1, n2/2))
                ip[0],ip[1] are pointers of the cos/sin table.
        w[0...*]
               :cos/sin table (double *)
                length of w >= max(n1/2, n2/4) + n2/4
                w[],ip[] are initialized if ip[0] == 0.
    [remark]
        Inverse of 
            rdft2d(n1, n2, 1, a, t, ip, w);
        is 
            rdft2d(n1, n2, -1, a, t, ip, w);
            for (j1 = 0; j1 <= n1 - 1; j1++) {
                for (j2 = 0; j2 <= n2 - 1; j2++) {
                    a[j1][j2] *= 2.0 / n1 / n2;
                }
            }
        .
*/
extern void rdft2d(int, int, int, double**, double*, int*, double*);
extern void rdft2dsort(int, int, int, double**);


/* -------- DCT (Discrete Cosine Transform) / Inverse of DCT --------
    [definition]
        <case1> IDCT (excluding scale)
            C[k1][k2] = sum_j1=0^n1-1 sum_j2=0^n2-1 a[j1][j2] * 
                            cos(pi*j1*(k1+1/2)/n1) * 
                            cos(pi*j2*(k2+1/2)/n2), 
                            0<=k1<n1, 0<=k2<n2
        <case2> DCT
            C[k1][k2] = sum_j1=0^n1-1 sum_j2=0^n2-1 a[j1][j2] * 
                            cos(pi*(j1+1/2)*k1/n1) * 
                            cos(pi*(j2+1/2)*k2/n2), 
                            0<=k1<n1, 0<=k2<n2
    [usage]
        <case1>
            ip[0] = 0; // first time only
            ddct2d(n1, n2, 1, a, t, ip, w);
        <case2>
            ip[0] = 0; // first time only
            ddct2d(n1, n2, -1, a, t, ip, w);
    [parameters]
        n1     :data length (int)
                n1 >= 2, n1 = power of 2
        n2     :data length (int)
                n2 >= 2, n2 = power of 2
        a[0...n1-1][0...n2-1]
               :input/output data (double **)
                output data
                    a[k1][k2] = C[k1][k2], 0<=k1<n1, 0<=k2<n2
        t[0...*]
               :work area (double *)
                length of t >= 4*n1,                   if single thread, 
                length of t >= 4*n1*FFT2D_MAX_THREADS, if multi threads, 
                t is dynamically allocated, if t == NULL.
        ip[0...*]
               :work area for bit reversal (int *)
                length of ip >= 2+sqrt(n)
                (n = max(n1/2, n2/2))
                ip[0],ip[1] are pointers of the cos/sin table.
        w[0...*]
               :cos/sin table (double *)
                length of w >= max(n1*3/2, n2*3/2)
                w[],ip[] are initialized if ip[0] == 0.
    [remark]
        Inverse of 
            ddct2d(n1, n2, -1, a, t, ip, w);
        is 
            for (j1 = 0; j1 <= n1 - 1; j1++) {
                a[j1][0] *= 0.5;
            }
            for (j2 = 0; j2 <= n2 - 1; j2++) {
                a[0][j2] *= 0.5;
            }
            ddct2d(n1, n2, 1, a, t, ip, w);
            for (j1 = 0; j1 <= n1 - 1; j1++) {
                for (j2 = 0; j2 <= n2 - 1; j2++) {
                    a[j1][j2] *= 4.0 / n1 / n2;
                }
            }
        .
*/
extern void ddct2d(int, int, int, double**, double*, int*, double*);


/* -------- DST (Discrete Sine Transform) / Inverse of DST --------
    [definition]
        <case1> IDST (excluding scale)
            S[k1][k2] = sum_j1=1^n1 sum_j2=1^n2 A[j1][j2] * 
                            sin(pi*j1*(k1+1/2)/n1) * 
                            sin(pi*j2*(k2+1/2)/n2), 
                            0<=k1<n1, 0<=k2<n2
        <case2> DST
            S[k1][k2] = sum_j1=0^n1-1 sum_j2=0^n2-1 a[j1][j2] * 
                            sin(pi*(j1+1/2)*k1/n1) * 
                            sin(pi*(j2+1/2)*k2/n2), 
                            0<k1<=n1, 0<k2<=n2
    [usage]
        <case1>
            ip[0] = 0; // first time only
            ddst2d(n1, n2, 1, a, t, ip, w);
        <case2>
            ip[0] = 0; // first time only
            ddst2d(n1, n2, -1, a, t, ip, w);
    [parameters]
        n1     :data length (int)
                n1 >= 2, n1 = power of 2
        n2     :data length (int)
                n2 >= 2, n2 = power of 2
        a[0...n1-1][0...n2-1]
               :input/output data (double **)
                <case1>
                    input data
                        a[j1][j2] = A[j1][j2], 0<j1<n1, 0<j2<n2, 
                        a[j1][0] = A[j1][n2], 0<j1<n1, 
                        a[0][j2] = A[n1][j2], 0<j2<n2, 
                        a[0][0] = A[n1][n2]
                        (i.e. A[j1][j2] = a[j1 % n1][j2 % n2])
                    output data
                        a[k1][k2] = S[k1][k2], 0<=k1<n1, 0<=k2<n2
                <case2>
                    output data
                        a[k1][k2] = S[k1][k2], 0<k1<n1, 0<k2<n2, 
                        a[k1][0] = S[k1][n2], 0<k1<n1, 
                        a[0][k2] = S[n1][k2], 0<k2<n2, 
                        a[0][0] = S[n1][n2]
                        (i.e. S[k1][k2] = a[k1 % n1][k2 % n2])
        t[0...*]
               :work area (double *)
                length of t >= 4*n1,                   if single thread, 
                length of t >= 4*n1*FFT2D_MAX_THREADS, if multi threads, 
                t is dynamically allocated, if t == NULL.
        ip[0...*]
               :work area for bit reversal (int *)
                length of ip >= 2+sqrt(n)
                (n = max(n1/2, n2/2))
                ip[0],ip[1] are pointers of the cos/sin table.
        w[0...*]
               :cos/sin table (double *)
                length of w >= max(n1*3/2, n2*3/2)
                w[],ip[] are initialized if ip[0] == 0.
    [remark]
        Inverse of 
            ddst2d(n1, n2, -1, a, t, ip, w);
        is 
            for (j1 = 0; j1 <= n1 - 1; j1++) {
                a[j1][0] *= 0.5;
            }
            for (j2 = 0; j2 <= n2 - 1; j2++) {
                a[0][j2] *= 0.5;
            }
            ddst2d(n1, n2, 1, a, t, ip, w);
            for (j1 = 0; j1 <= n1 - 1; j1++) {
                for (j2 = 0; j2 <= n2 - 1; j2++) {
                    a[j1][j2] *= 4.0 / n1 / n2;
                }
            }
        .
*/
extern void ddst2d(int, int, int, double**, double*, int*, double*);


#if defined(__cplusplus)
}
#endif

#endif /* FFTSG2D_H */
