#ifndef MATHERRSTATUS_H
#define MATHERRSTATUS_H

#if defined(__cplusplus)
extern "C" {
#endif

typedef enum MathErrStatus {
	E_MATHNOERR = 0,   /* No error */
	/* Domain Errors */
	E_DOMPOSARG,       /* Argument is positive */
	E_DOMNEGARG,       /* Argument is negative */
	E_DOMZERONEGARG,   /* Argument is negative or zero */
	E_DOMZERO,         /* Argument is zero */
	E_DOMLT,           /* Argument is less than something */
	E_DOMLE,           /* Argument is less equal to something */
	E_DOMGT,           /* Argument is greater than something */
	E_DOMGE,           /* Argument is greater equal to something */
	E_DOMNE,           /* Argument is not equal to something */
	E_DOMINFARG,       /* Argument is infinite number */
	E_DOMNANARG,       /* Argument is NaN */
	E_DOMNOSOLVE,      /* The argument have not a solve */
	/* Pole Errors */
	E_RANGEUNDERFLOW,  /* Pole is underflow */
	E_RANGEOVERFLOW,   /* Pole is overflow */
} matherrstatus_t;

#if defined(__cplusplus)
}
#endif

#endif /* MATHERRSTATUS_H */
