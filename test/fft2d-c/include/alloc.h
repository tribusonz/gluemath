/* ---- memory allocation ---- */
#ifndef FFT_ALLOC_H
#define FFT_ALLOC_H

#if defined(__cplusplus)
extern "C" {
#endif

extern int *alloc_1d_int(int n1);
extern void free_1d_int(int *i);
extern double *alloc_1d_double(int n1);
extern void free_1d_double(double *d);
extern int **alloc_2d_int(int n1, int n2);
extern void free_2d_int(int **ii);
extern double **alloc_2d_double(int n1, int n2);
extern void free_2d_double(double **dd);
extern int ***alloc_3d_int(int n1, int n2, int n3);
extern void free_3d_int(int ***iii);
extern double ***alloc_3d_double(int n1, int n2, int n3);
extern void free_3d_double(double ***ddd);

#if defined(__cplusplus)
}
#endif

#endif /* FFT_ALLOC_H */
