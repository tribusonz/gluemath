/*******************************************************************************
Fast Fourier/Cosine/Sine Transform
    dimension   :three
    data length :power of 2
    decimation  :frequency
    radix       :split-radix, row-column
    data        :inplace
    table       :use
functions
    cdft3d: Complex Discrete Fourier Transform
    rdft3d: Real Discrete Fourier Transform
    ddct3d: Discrete Cosine Transform
    ddst3d: Discrete Sine Transform
function prototypes
    void cdft3d(int, int, int, int, double ***, double *, int *, double *);
    void rdft3d(int, int, int, int, double ***, double *, int *, double *);
    void rdft3dsort(int, int, int, int, double ***);
    void ddct3d(int, int, int, int, double ***, double *, int *, double *);
    void ddst3d(int, int, int, int, double ***, double *, int *, double *);
necessary package
    fftsg.c  : 1D-FFT package
macro definitions
    USE_FFT3D_PTHREADS : default=not defined
        FFT3D_MAX_THREADS     : must be 2^N, default=4
        FFT3D_THREADS_BEGIN_N : default=65536
    USE_FFT3D_WINTHREADS : default=not defined
        FFT3D_MAX_THREADS     : must be 2^N, default=4
        FFT3D_THREADS_BEGIN_N : default=131072
*******************************************************************************/
#ifndef FFTSG3D_H
#define FFTSG3D_H

#if defined(__cplusplus)
extern "C" {
#endif

/* -------- Complex DFT (Discrete Fourier Transform) --------
    [definition]
        <case1>
            X[k1][k2][k3] = sum_j1=0^n1-1 sum_j2=0^n2-1 sum_j3=0^n3-1
                                x[j1][j2][j3] * 
                                exp(2*pi*i*j1*k1/n1) * 
                                exp(2*pi*i*j2*k2/n2) * 
                                exp(2*pi*i*j3*k3/n3), 
                                0<=k1<n1, 0<=k2<n2, 0<=k3<n3
        <case2>
            X[k1][k2][k3] = sum_j1=0^n1-1 sum_j2=0^n2-1 sum_j3=0^n3-1
                                x[j1][j2][j3] * 
                                exp(-2*pi*i*j1*k1/n1) * 
                                exp(-2*pi*i*j2*k2/n2) * 
                                exp(-2*pi*i*j3*k3/n3), 
                                0<=k1<n1, 0<=k2<n2, 0<=k3<n3
        (notes: sum_j=0^n-1 is a summation from j=0 to n-1)
    [usage]
        <case1>
            ip[0] = 0; // first time only
            cdft3d(n1, n2, 2*n3, 1, a, t, ip, w);
        <case2>
            ip[0] = 0; // first time only
            cdft3d(n1, n2, 2*n3, -1, a, t, ip, w);
    [parameters]
        n1     :data length (int)
                n1 >= 1, n1 = power of 2
        n2     :data length (int)
                n2 >= 1, n2 = power of 2
        2*n3   :data length (int)
                n3 >= 1, n3 = power of 2
        a[0...n1-1][0...n2-1][0...2*n3-1]
               :input/output data (double ***)
                input data
                    a[j1][j2][2*j3] = Re(x[j1][j2][j3]), 
                    a[j1][j2][2*j3+1] = Im(x[j1][j2][j3]), 
                    0<=j1<n1, 0<=j2<n2, 0<=j3<n3
                output data
                    a[k1][k2][2*k3] = Re(X[k1][k2][k3]), 
                    a[k1][k2][2*k3+1] = Im(X[k1][k2][k3]), 
                    0<=k1<n1, 0<=k2<n2, 0<=k3<n3
        t[0...*]
               :work area (double *)
                length of t >= max(8*n1, 8*n2),        if single thread, 
                length of t >= max(8*n1, 8*n2)*FFT3D_MAX_THREADS, 
                                                       if multi threads, 
                t is dynamically allocated, if t == NULL.
        ip[0...*]
               :work area for bit reversal (int *)
                length of ip >= 2+sqrt(n)
                (n = max(n1, n2, n3))
                ip[0],ip[1] are pointers of the cos/sin table.
        w[0...*]
               :cos/sin table (double *)
                length of w >= max(n1/2, n2/2, n3/2)
                w[],ip[] are initialized if ip[0] == 0.
    [remark]
        Inverse of 
            cdft3d(n1, n2, 2*n3, -1, a, t, ip, w);
        is 
            cdft3d(n1, n2, 2*n3, 1, a, t, ip, w);
            for (j1 = 0; j1 <= n1 - 1; j1++) {
                for (j2 = 0; j2 <= n2 - 1; j2++) {
                    for (j3 = 0; j3 <= 2 * n3 - 1; j3++) {
                        a[j1][j2][j3] *= 1.0 / n1 / n2 / n3;
                    }
                }
            }
        .
*/
extern void cdft3d(int, int, int, int, double***, double*, int*, double*);


/* -------- Real DFT / Inverse of Real DFT --------
    [definition]
        <case1> RDFT
            R[k1][k2][k3] = sum_j1=0^n1-1 sum_j2=0^n2-1 sum_j3=0^n3-1
                                a[j1][j2][j3] * 
                                cos(2*pi*j1*k1/n1 + 2*pi*j2*k2/n2 + 
                                    2*pi*j3*k3/n3), 
                                0<=k1<n1, 0<=k2<n2, 0<=k3<n3
            I[k1][k2][k3] = sum_j1=0^n1-1 sum_j2=0^n2-1 sum_j3=0^n3-1
                                a[j1][j2][j3] * 
                                sin(2*pi*j1*k1/n1 + 2*pi*j2*k2/n2 + 
                                    2*pi*j3*k3/n3), 
                                0<=k1<n1, 0<=k2<n2, 0<=k3<n3
        <case2> IRDFT (excluding scale)
            a[k1][k2][k3] = (1/2) * sum_j1=0^n1-1 sum_j2=0^n2-1 sum_j3=0^n3-1
                                (R[j1][j2][j3] * 
                                cos(2*pi*j1*k1/n1 + 2*pi*j2*k2/n2 + 
                                    2*pi*j3*k3/n3) + 
                                I[j1][j2][j3] * 
                                sin(2*pi*j1*k1/n1 + 2*pi*j2*k2/n2 + 
                                    2*pi*j3*k3/n3)), 
                                0<=k1<n1, 0<=k2<n2, 0<=k3<n3
        (notes: R[(n1-k1)%n1][(n2-k2)%n2][(n3-k3)%n3] = R[k1][k2][k3], 
                I[(n1-k1)%n1][(n2-k2)%n2][(n3-k3)%n3] = -I[k1][k2][k3], 
                0<=k1<n1, 0<=k2<n2, 0<=k3<n3)
    [usage]
        <case1>
            ip[0] = 0; // first time only
            rdft3d(n1, n2, n3, 1, a, t, ip, w);
        <case2>
            ip[0] = 0; // first time only
            rdft3d(n1, n2, n3, -1, a, t, ip, w);
    [parameters]
        n1     :data length (int)
                n1 >= 2, n1 = power of 2
        n2     :data length (int)
                n2 >= 2, n2 = power of 2
        n3     :data length (int)
                n3 >= 2, n3 = power of 2
        a[0...n1-1][0...n2-1][0...n3-1]
               :input/output data (double ***)
                <case1>
                    output data
                        a[k1][k2][2*k3] = R[k1][k2][k3]
                                        = R[(n1-k1)%n1][(n2-k2)%n2][n3-k3], 
                        a[k1][k2][2*k3+1] = I[k1][k2][k3]
                                          = -I[(n1-k1)%n1][(n2-k2)%n2][n3-k3], 
                            0<=k1<n1, 0<=k2<n2, 0<k3<n3/2, 
                            (n%m : n mod m), 
                        a[k1][k2][0] = R[k1][k2][0]
                                     = R[(n1-k1)%n1][n2-k2][0], 
                        a[k1][k2][1] = I[k1][k2][0]
                                     = -I[(n1-k1)%n1][n2-k2][0], 
                        a[k1][n2-k2][1] = R[(n1-k1)%n1][k2][n3/2]
                                        = R[k1][n2-k2][n3/2], 
                        a[k1][n2-k2][0] = -I[(n1-k1)%n1][k2][n3/2]
                                        = I[k1][n2-k2][n3/2], 
                            0<=k1<n1, 0<k2<n2/2, 
                        a[k1][0][0] = R[k1][0][0]
                                    = R[n1-k1][0][0], 
                        a[k1][0][1] = I[k1][0][0]
                                    = -I[n1-k1][0][0], 
                        a[k1][n2/2][0] = R[k1][n2/2][0]
                                       = R[n1-k1][n2/2][0], 
                        a[k1][n2/2][1] = I[k1][n2/2][0]
                                       = -I[n1-k1][n2/2][0], 
                        a[n1-k1][0][1] = R[k1][0][n3/2]
                                       = R[n1-k1][0][n3/2], 
                        a[n1-k1][0][0] = -I[k1][0][n3/2]
                                       = I[n1-k1][0][n3/2], 
                        a[n1-k1][n2/2][1] = R[k1][n2/2][n3/2]
                                          = R[n1-k1][n2/2][n3/2], 
                        a[n1-k1][n2/2][0] = -I[k1][n2/2][n3/2]
                                          = I[n1-k1][n2/2][n3/2], 
                            0<k1<n1/2, 
                        a[0][0][0] = R[0][0][0], 
                        a[0][0][1] = R[0][0][n3/2], 
                        a[0][n2/2][0] = R[0][n2/2][0], 
                        a[0][n2/2][1] = R[0][n2/2][n3/2], 
                        a[n1/2][0][0] = R[n1/2][0][0], 
                        a[n1/2][0][1] = R[n1/2][0][n3/2], 
                        a[n1/2][n2/2][0] = R[n1/2][n2/2][0], 
                        a[n1/2][n2/2][1] = R[n1/2][n2/2][n3/2]
                <case2>
                    input data
                        a[j1][j2][2*j3] = R[j1][j2][j3]
                                        = R[(n1-j1)%n1][(n2-j2)%n2][n3-j3], 
                        a[j1][j2][2*j3+1] = I[j1][j2][j3]
                                          = -I[(n1-j1)%n1][(n2-j2)%n2][n3-j3], 
                            0<=j1<n1, 0<=j2<n2, 0<j3<n3/2, 
                        a[j1][j2][0] = R[j1][j2][0]
                                     = R[(n1-j1)%n1][n2-j2][0], 
                        a[j1][j2][1] = I[j1][j2][0]
                                     = -I[(n1-j1)%n1][n2-j2][0], 
                        a[j1][n2-j2][1] = R[(n1-j1)%n1][j2][n3/2]
                                        = R[j1][n2-j2][n3/2], 
                        a[j1][n2-j2][0] = -I[(n1-j1)%n1][j2][n3/2]
                                        = I[j1][n2-j2][n3/2], 
                            0<=j1<n1, 0<j2<n2/2, 
                        a[j1][0][0] = R[j1][0][0]
                                    = R[n1-j1][0][0], 
                        a[j1][0][1] = I[j1][0][0]
                                    = -I[n1-j1][0][0], 
                        a[j1][n2/2][0] = R[j1][n2/2][0]
                                       = R[n1-j1][n2/2][0], 
                        a[j1][n2/2][1] = I[j1][n2/2][0]
                                       = -I[n1-j1][n2/2][0], 
                        a[n1-j1][0][1] = R[j1][0][n3/2]
                                       = R[n1-j1][0][n3/2], 
                        a[n1-j1][0][0] = -I[j1][0][n3/2]
                                       = I[n1-j1][0][n3/2], 
                        a[n1-j1][n2/2][1] = R[j1][n2/2][n3/2]
                                          = R[n1-j1][n2/2][n3/2], 
                        a[n1-j1][n2/2][0] = -I[j1][n2/2][n3/2]
                                          = I[n1-j1][n2/2][n3/2], 
                            0<j1<n1/2, 
                        a[0][0][0] = R[0][0][0], 
                        a[0][0][1] = R[0][0][n3/2], 
                        a[0][n2/2][0] = R[0][n2/2][0], 
                        a[0][n2/2][1] = R[0][n2/2][n3/2], 
                        a[n1/2][0][0] = R[n1/2][0][0], 
                        a[n1/2][0][1] = R[n1/2][0][n3/2], 
                        a[n1/2][n2/2][0] = R[n1/2][n2/2][0], 
                        a[n1/2][n2/2][1] = R[n1/2][n2/2][n3/2]
                ---- output ordering ----
                    rdft3d(n1, n2, n3, 1, a, t, ip, w);
                    rdft3dsort(n1, n2, n3, 1, a);
                    // stored data is a[0...n1-1][0...n2-1][0...n3+1]:
                    // a[k1][k2][2*k3] = R[k1][k2][k3], 
                    // a[k1][k2][2*k3+1] = I[k1][k2][k3], 
                    // 0<=k1<n1, 0<=k2<n2, 0<=k3<=n3/2.
                    // the stored data is larger than the input data!
                ---- input ordering ----
                    rdft3dsort(n1, n2, n3, -1, a);
                    rdft3d(n1, n2, n3, -1, a, t, ip, w);
        t[0...*]
               :work area (double *)
                length of t >= max(8*n1, 8*n2),        if single thread, 
                length of t >= max(8*n1, 8*n2)*FFT3D_MAX_THREADS, 
                                                       if multi threads, 
                t is dynamically allocated, if t == NULL.
        ip[0...*]
               :work area for bit reversal (int *)
                length of ip >= 2+sqrt(n)
                (n = max(n1, n2, n3/2))
                ip[0],ip[1] are pointers of the cos/sin table.
        w[0...*]
               :cos/sin table (double *)
                length of w >= max(n1/2, n2/2, n3/4) + n3/4
                w[],ip[] are initialized if ip[0] == 0.
    [remark]
        Inverse of 
            rdft3d(n1, n2, n3, 1, a, t, ip, w);
        is 
            rdft3d(n1, n2, n3, -1, a, t, ip, w);
            for (j1 = 0; j1 <= n1 - 1; j1++) {
                for (j2 = 0; j2 <= n2 - 1; j2++) {
                    for (j3 = 0; j3 <= n3 - 1; j3++) {
                        a[j1][j2][j3] *= 2.0 / n1 / n2 / n3;
                    }
                }
            }
        .
*/
extern void rdft3dsort(int, int, int, int, double***);
extern void rdft3d(int, int, int, int, double***, double*, int*, double*);


/* -------- DCT (Discrete Cosine Transform) / Inverse of DCT --------
    [definition]
        <case1> IDCT (excluding scale)
            C[k1][k2][k3] = sum_j1=0^n1-1 sum_j2=0^n2-1 sum_j3=0^n3-1
                                a[j1][j2][j3] * 
                                cos(pi*j1*(k1+1/2)/n1) * 
                                cos(pi*j2*(k2+1/2)/n2) * 
                                cos(pi*j3*(k3+1/2)/n3), 
                                0<=k1<n1, 0<=k2<n2, 0<=k3<n3
        <case2> DCT
            C[k1][k2][k3] = sum_j1=0^n1-1 sum_j2=0^n2-1 sum_j3=0^n3-1
                                a[j1][j2][j3] * 
                                cos(pi*(j1+1/2)*k1/n1) * 
                                cos(pi*(j2+1/2)*k2/n2) * 
                                cos(pi*(j3+1/2)*k3/n3), 
                                0<=k1<n1, 0<=k2<n2, 0<=k3<n3
    [usage]
        <case1>
            ip[0] = 0; // first time only
            ddct3d(n1, n2, n3, 1, a, t, ip, w);
        <case2>
            ip[0] = 0; // first time only
            ddct3d(n1, n2, n3, -1, a, t, ip, w);
    [parameters]
        n1     :data length (int)
                n1 >= 2, n1 = power of 2
        n2     :data length (int)
                n2 >= 2, n2 = power of 2
        n3     :data length (int)
                n3 >= 2, n3 = power of 2
        a[0...n1-1][0...n2-1][0...n3-1]
               :input/output data (double ***)
                output data
                    a[k1][k2][k3] = C[k1][k2][k3], 
                        0<=k1<n1, 0<=k2<n2, 0<=k3<n3
        t[0...*]
               :work area (double *)
                length of t >= max(4*n1, 4*n2),        if single thread, 
                length of t >= max(4*n1, 4*n2)*FFT3D_MAX_THREADS, 
                                                       if multi threads, 
                t is dynamically allocated, if t == NULL.
        ip[0...*]
               :work area for bit reversal (int *)
                length of ip >= 2+sqrt(n)
                (n = max(n1/2, n2/2, n3/2))
                ip[0],ip[1] are pointers of the cos/sin table.
        w[0...*]
               :cos/sin table (double *)
                length of w >= max(n1*3/2, n2*3/2, n3*3/2)
                w[],ip[] are initialized if ip[0] == 0.
    [remark]
        Inverse of 
            ddct3d(n1, n2, n3, -1, a, t, ip, w);
        is 
            for (j1 = 0; j1 <= n1 - 1; j1++) {
                for (j2 = 0; j2 <= n2 - 1; j2++) {
                    a[j1][j2][0] *= 0.5;
                }
                for (j3 = 0; j3 <= n3 - 1; j3++) {
                    a[j1][0][j3] *= 0.5;
                }
            }
            for (j2 = 0; j2 <= n2 - 1; j2++) {
                for (j3 = 0; j3 <= n3 - 1; j3++) {
                    a[0][j2][j3] *= 0.5;
                }
            }
            ddct3d(n1, n2, n3, 1, a, t, ip, w);
            for (j1 = 0; j1 <= n1 - 1; j1++) {
                for (j2 = 0; j2 <= n2 - 1; j2++) {
                    for (j3 = 0; j3 <= n3 - 1; j3++) {
                        a[j1][j2][j3] *= 8.0 / n1 / n2 / n3;
                    }
                }
            }
        .
*/
extern void ddct3d(int, int, int, int, double***, double*, int*, double*);


/* -------- DST (Discrete Sine Transform) / Inverse of DST --------
    [definition]
        <case1> IDST (excluding scale)
            S[k1][k2][k3] = sum_j1=1^n1 sum_j2=1^n2 sum_j3=1^n3
                                A[j1][j2][j3] * 
                                sin(pi*j1*(k1+1/2)/n1) * 
                                sin(pi*j2*(k2+1/2)/n2) * 
                                sin(pi*j3*(k3+1/2)/n3), 
                                0<=k1<n1, 0<=k2<n2, 0<=k3<n3
        <case2> DST
            S[k1][k2][k3] = sum_j1=0^n1-1 sum_j2=0^n2-1 sum_j3=0^n3-1
                                a[j1][j2][j3] * 
                                sin(pi*(j1+1/2)*k1/n1) * 
                                sin(pi*(j2+1/2)*k2/n2) * 
                                sin(pi*(j3+1/2)*k3/n3), 
                                0<k1<=n1, 0<k2<=n2, 0<k3<=n3
    [usage]
        <case1>
            ip[0] = 0; // first time only
            ddst3d(n1, n2, n3, 1, a, t, ip, w);
        <case2>
            ip[0] = 0; // first time only
            ddst3d(n1, n2, n3, -1, a, t, ip, w);
    [parameters]
        n1     :data length (int)
                n1 >= 2, n1 = power of 2
        n2     :data length (int)
                n2 >= 2, n2 = power of 2
        n3     :data length (int)
                n3 >= 2, n3 = power of 2
        a[0...n1-1][0...n2-1][0...n3-1]
               :input/output data (double ***)
                <case1>
                    input data
                        a[j1%n1][j2%n2][j3%n3] = A[j1][j2][j3], 
                            0<j1<=n1, 0<j2<=n2, 0<j3<=n3, 
                            (n%m : n mod m)
                    output data
                        a[k1][k2][k3] = S[k1][k2][k3], 
                            0<=k1<n1, 0<=k2<n2, 0<=k3<n3
                <case2>
                    output data
                        a[k1%n1][k2%n2][k3%n3] = S[k1][k2][k3], 
                            0<k1<=n1, 0<k2<=n2, 0<k3<=n3
        t[0...*]
               :work area (double *)
                length of t >= max(4*n1, 4*n2),        if single thread, 
                length of t >= max(4*n1, 4*n2)*FFT3D_MAX_THREADS, 
                                                       if multi threads, 
                t is dynamically allocated, if t == NULL.
        ip[0...*]
               :work area for bit reversal (int *)
                length of ip >= 2+sqrt(n)
                (n = max(n1/2, n2/2, n3/2))
                ip[0],ip[1] are pointers of the cos/sin table.
        w[0...*]
               :cos/sin table (double *)
                length of w >= max(n1*3/2, n2*3/2, n3*3/2)
                w[],ip[] are initialized if ip[0] == 0.
    [remark]
        Inverse of 
            ddst3d(n1, n2, n3, -1, a, t, ip, w);
        is 
            for (j1 = 0; j1 <= n1 - 1; j1++) {
                for (j2 = 0; j2 <= n2 - 1; j2++) {
                    a[j1][j2][0] *= 0.5;
                }
                for (j3 = 0; j3 <= n3 - 1; j3++) {
                    a[j1][0][j3] *= 0.5;
                }
            }
            for (j2 = 0; j2 <= n2 - 1; j2++) {
                for (j3 = 0; j3 <= n3 - 1; j3++) {
                    a[0][j2][j3] *= 0.5;
                }
            }
            ddst3d(n1, n2, n3, 1, a, t, ip, w);
            for (j1 = 0; j1 <= n1 - 1; j1++) {
                for (j2 = 0; j2 <= n2 - 1; j2++) {
                    for (j3 = 0; j3 <= n3 - 1; j3++) {
                        a[j1][j2][j3] *= 8.0 / n1 / n2 / n3;
                    }
                }
            }
        .
*/
extern void ddst3d(int, int, int, int, double***, double*, int*, double*);

#if defined(cplusplus)
}
#endif

#endif /* FFTSG3D_H */
