#ifndef KERNEL_ACM_1006_H
#define KERNEL_ACM_1006_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "matherrstat.h"

// see source file 'kernel.c'
extern matherrstatus_t G_func(double*,double,double);
extern matherrstatus_t G_funccheck(double,double,char*);
extern matherrstatus_t deltagammainc(double*,double*,char*,double,double,double,double);
extern matherrstatus_t deltagammainccheck(double,double,double,double,char*);
extern matherrstatus_t scientific_notation(double*,double*,double,double);
extern double deltagammaincsolver(double, double);

#if defined(__cplusplus)
}
#endif

#endif /* KERNEL_ACM_1006_H */
