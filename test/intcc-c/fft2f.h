/*******************************************************************************
Fast Fourier/Cosine/Sine Transform
    dimension   :one
    data length :power of 2
    decimation  :frequency
    radix       :2
    data        :inplace
    table       :not use
functions
    cdft: Complex Discrete Fourier Transform
    rdft: Real Discrete Fourier Transform
    ddct: Discrete Cosine Transform
    ddst: Discrete Sine Transform
    dfct: Cosine Transform of RDFT (Real Symmetric DFT)
    dfst: Sine Transform of RDFT (Real Anti-symmetric DFT)
function prototypes
    void cdft(int, double, double, double *);
    void rdft(int, double, double, double *);
    void ddct(int, double, double, double *);
    void ddst(int, double, double, double *);
    void dfct(int, double, double, double *);
    void dfst(int, double, double, double *);
*******************************************************************************/
#ifndef FFT2F_H
#define FFT2F_H

#if defined(__cplusplus)
extern "C" {
#endif

/* -------- Complex DFT (Discrete Fourier Transform) --------
    [definition]
        <case1>
            X[k] = sum_j=0^n-1 x[j]*exp(2*pi*i*j*k/n), 0<=k<n
        <case2>
            X[k] = sum_j=0^n-1 x[j]*exp(-2*pi*i*j*k/n), 0<=k<n
        (notes: sum_j=0^n-1 is a summation from j=0 to n-1)
    [usage]
        <case1>
            cdft(2*n, cos(M_PI/n), sin(M_PI/n), a);
        <case2>
            cdft(2*n, cos(M_PI/n), -sin(M_PI/n), a);
    [parameters]
        2*n          :data length (int)
                      n >= 1, n = power of 2
        a[0...2*n-1] :input/output data (double *)
                      input data
                          a[2*j] = Re(x[j]), a[2*j+1] = Im(x[j]), 0<=j<n
                      output data
                          a[2*k] = Re(X[k]), a[2*k+1] = Im(X[k]), 0<=k<n
    [remark]
        Inverse of 
            cdft(2*n, cos(M_PI/n), -sin(M_PI/n), a);
        is 
            cdft(2*n, cos(M_PI/n), sin(M_PI/n), a);
            for (j = 0; j <= 2 * n - 1; j++) {
                a[j] *= 1.0 / n;
            }
        .
*/
extern void cdft(int, double, double, double*);

/* -------- Real DFT / Inverse of Real DFT --------
    [definition]
        <case1> RDFT
            R[k] = sum_j=0^n-1 a[j]*cos(2*pi*j*k/n), 0<=k<=n/2
            I[k] = sum_j=0^n-1 a[j]*sin(2*pi*j*k/n), 0<k<n/2
        <case2> IRDFT (excluding scale)
            a[k] = R[0]/2 + R[n/2]/2 + 
                   sum_j=1^n/2-1 R[j]*cos(2*pi*j*k/n) + 
                   sum_j=1^n/2-1 I[j]*sin(2*pi*j*k/n), 0<=k<n
    [usage]
        <case1>
            rdft(n, cos(M_PI/n), sin(M_PI/n), a);
        <case2>
            rdft(n, cos(M_PI/n), -sin(M_PI/n), a);
    [parameters]
        n            :data length (int)
                      n >= 2, n = power of 2
        a[0...n-1]   :input/output data (double *)
                      <case1>
                          output data
                              a[2*k] = R[k], 0<=k<n/2
                              a[2*k+1] = I[k], 0<k<n/2
                              a[1] = R[n/2]
                      <case2>
                          input data
                              a[2*j] = R[j], 0<=j<n/2
                              a[2*j+1] = I[j], 0<j<n/2
                              a[1] = R[n/2]
    [remark]
        Inverse of 
            rdft(n, cos(M_PI/n), sin(M_PI/n), a);
        is 
            rdft(n, cos(M_PI/n), -sin(M_PI/n), a);
            for (j = 0; j <= n - 1; j++) {
                a[j] *= 2.0 / n;
            }
        .
*/
extern void rdft(int, double, double, double*);

/* -------- DCT (Discrete Cosine Transform) / Inverse of DCT --------
    [definition]
        <case1> IDCT (excluding scale)
            C[k] = sum_j=0^n-1 a[j]*cos(pi*j*(k+1/2)/n), 0<=k<n
        <case2> DCT
            C[k] = sum_j=0^n-1 a[j]*cos(pi*(j+1/2)*k/n), 0<=k<n
    [usage]
        <case1>
            ddct(n, cos(M_PI/n/2), sin(M_PI/n/2), a);
        <case2>
            ddct(n, cos(M_PI/n/2), -sin(M_PI/n/2), a);
    [parameters]
        n            :data length (int)
                      n >= 2, n = power of 2
        a[0...n-1]   :input/output data (double *)
                      output data
                          a[k] = C[k], 0<=k<n
    [remark]
        Inverse of 
            ddct(n, cos(M_PI/n/2), -sin(M_PI/n/2), a);
        is 
            a[0] *= 0.5;
            ddct(n, cos(M_PI/n/2), sin(M_PI/n/2), a);
            for (j = 0; j <= n - 1; j++) {
                a[j] *= 2.0 / n;
            }
        .
*/
extern void ddct(int, double, double, double*);

/* -------- DST (Discrete Sine Transform) / Inverse of DST --------
    [definition]
        <case1> IDST (excluding scale)
            S[k] = sum_j=1^n A[j]*sin(pi*j*(k+1/2)/n), 0<=k<n
        <case2> DST
            S[k] = sum_j=0^n-1 a[j]*sin(pi*(j+1/2)*k/n), 0<k<=n
    [usage]
        <case1>
            ddst(n, cos(M_PI/n/2), sin(M_PI/n/2), a);
        <case2>
            ddst(n, cos(M_PI/n/2), -sin(M_PI/n/2), a);
    [parameters]
        n            :data length (int)
                      n >= 2, n = power of 2
        a[0...n-1]   :input/output data (double *)
                      <case1>
                          input data
                              a[j] = A[j], 0<j<n
                              a[0] = A[n]
                          output data
                              a[k] = S[k], 0<=k<n
                      <case2>
                          output data
                              a[k] = S[k], 0<k<n
                              a[0] = S[n]
    [remark]
        Inverse of 
            ddst(n, cos(M_PI/n/2), -sin(M_PI/n/2), a);
        is 
            a[0] *= 0.5;
            ddst(n, cos(M_PI/n/2), sin(M_PI/n/2), a);
            for (j = 0; j <= n - 1; j++) {
                a[j] *= 2.0 / n;
            }
        .

 */
extern void ddst(int, double, double, double*);

/* -------- Cosine Transform of RDFT (Real Symmetric DFT) --------
    [definition]
        C[k] = sum_j=0^n a[j]*cos(pi*j*k/n), 0<=k<=n
    [usage]
        dfct(n, cos(M_PI/n), sin(M_PI/n), a);
    [parameters]
        n            :data length - 1 (int)
                      n >= 2, n = power of 2
        a[0...n]     :input/output data (double *)
                      output data
                          a[k] = C[k], 0<=k<=n
    [remark]
        Inverse of 
            a[0] *= 0.5;
            a[n] *= 0.5;
            dfct(n, cos(M_PI/n), sin(M_PI/n), a);
        is 
            a[0] *= 0.5;
            a[n] *= 0.5;
            dfct(n, cos(M_PI/n), sin(M_PI/n), a);
            for (j = 0; j <= n; j++) {
                a[j] *= 2.0 / n;
            }
        .
 */
extern void dfct(int, double, double, double*);

/* -------- Sine Transform of RDFT (Real Anti-symmetric DFT) --------
    [definition]
        S[k] = sum_j=1^n-1 a[j]*sin(pi*j*k/n), 0<k<n
    [usage]
        dfst(n, cos(M_PI/n), sin(M_PI/n), a);
    [parameters]
        n            :data length + 1 (int)
                      n >= 2, n = power of 2
        a[0...n-1]   :input/output data (double *)
                      output data
                          a[k] = S[k], 0<k<n
                      (a[0] is used for work area)
    [remark]
        Inverse of 
            dfst(n, cos(M_PI/n), sin(M_PI/n), a);
        is 
            dfst(n, cos(M_PI/n), sin(M_PI/n), a);
            for (j = 1; j <= n - 1; j++) {
                a[j] *= 2.0 / n;
            }
        .
 */
extern void dfst(int, double, double, double*);

#if defined(__cplusplus)
}
#endif

#endif /* FFT2F_H */
