/* -------- multiple precision routines -------- */
#ifndef MP_H
#define MP_H

#if defined(__cplusplus)
extern "C" {
#endif

/* ---- floating point format ----
    data := data[0] * pow(radix, data[1]) * 
            (data[2] + data[3]/radix + data[4]/radix/radix + ...), 
    data[0]       : sign (1;data>0, -1;data<0, 0;data==0)
    data[1]       : exponent (0;data==0)
    data[2...n+1] : digits
   ---- function prototypes ----
    void mp_load_0(int n, int radix, int out[]);
    void mp_load_1(int n, int radix, int out[]);
    void mp_copy(int n, int radix, int in[], int out[]);
    void mp_round(int n, int radix, int m, int inout[]);
    int mp_cmp(int n, int radix, int in1[], int in2[]);
    void mp_add(int n, int radix, int in1[], int in2[], int out[]);
    void mp_sub(int n, int radix, int in1[], int in2[], int out[]);
    void mp_imul(int n, int radix, int in1[], int in2, int out[]);
    int mp_idiv(int n, int radix, int in1[], int in2, int out[]);
    void mp_idiv_2(int n, int radix, int in[], int out[]);
    double mp_mul_radix_test(int n, int radix, int nfft, 
            double tmpfft[], int ip[], double w[]);
    void mp_mul(int n, int radix, int in1[], int in2[], int out[], 
            int tmp[], int nfft, double tmp1fft[], double tmp2fft[], 
            double tmp3fft[], int ip[], double w[]);
    void mp_squ(int n, int radix, int in[], int out[], int tmp[], 
            int nfft, double tmp1fft[], double tmp2fft[], 
            int ip[], double w[]);
    void mp_mulh(int n, int radix, int in1[], int in2[], int out[], 
            int nfft, double in1fft[], double outfft[], 
            int ip[], double w[]);
    void mp_squh(int n, int radix, int in[], int out[], 
            int nfft, double inoutfft[], int ip[], double w[]);
    int mp_inv(int n, int radix, int in[], int out[], 
            int tmp1[], int tmp2[], int nfft, 
            double tmp1fft[], double tmp2fft[], int ip[], double w[]);
    int mp_sqrt(int n, int radix, int in[], int out[], 
            int tmp1[], int tmp2[], int nfft, 
            double tmp1fft[], double tmp2fft[], int ip[], double w[]);
    void mp_sprintf(int n, int log10_radix, int in[], char out[]);
    void mp_sscanf(int n, int log10_radix, char in[], int out[]);
    void mp_fprintf(int n, int log10_radix, int in[], FILE *fout);
   ----
*/

#include <stdio.h>  // type FILE

extern void mp_load_0(int, int, int*);
extern void mp_load_1(int, int, int*);
extern void mp_copy(int, int, int*, int*);
extern void mp_round(int, int, int, int*);
extern int mp_cmp(int, int, int*, int*);
extern void mp_add(int, int, int*, int*, int*);
extern void mp_sub(int, int, int*, int*, int*);
extern void mp_imul(int, int, int*, int, int*);
extern int mp_idiv(int, int, int*, int, int*);
extern void mp_idiv_2(int, int, int*, int*);
extern double mp_mul_radix_test(int, int, int, double*, int*, double*);
extern void mp_mul(
  int, int, int*, int*, int*, int*, int,
  double*, double*, double*, int*, double*);
extern void mp_squ(
  int, int, int*, int*, int*, int,
  double*, double*, int*, double*);
extern void mp_mulh(
  int, int, int*, int*, int*, 
  int, double*, double*, int*, double*);
extern void mp_squh(
  int, int, int*, int*, int,
  double*, int*, double*);
extern int mp_inv(
  int, int, int*, int*, int*, int*, int, 
  double*, double*, int*, double*);
extern int mp_sqrt(
  int, int, int*, int*, int*, int*, int, 
  double*, double*, int*, double*);
extern void mp_sprintf(int, int, int*, char*);
extern void mp_sscanf(int, int, char*, int*);
extern void mp_fprintf(int, int, int*, FILE*);

#if defined(__cplusplus)
}
#endif

#endif /* MP_H */
