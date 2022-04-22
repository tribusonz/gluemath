/*******************************************************************************
	GLUE-Math Library: Window Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  "Sound-Programming Guide", Naofumi Aoki, Gijutsu Hyouron Sha
	  ISBN978-4-7741-5522-7
********************************************************************************/
#ifndef GLUEMATH_WFUNK_H
#define GLUEMATH_WFUNK_H

#ifdef __cplusplus
extern "C" {
#endif

/*
	It is based on Dr. Naofumi Aoki's algorithm. It is his idea that the size of 
	the window function is odd and even are the formula is different.
	
	In FIR, by default, the hanning window is used. But it can also be changed to
	other window functions. The sinc function to be weighted is good, so you may
	not feel much effect.
*/

/*
 *  call-seq:
 *    (UserLevel Code)
 *      Window.hanning(n) -> Vector
 *    (Native Code)
 *      hanningwin(N, w) -> int
 *  
 *  Create a Hanning Window's vector, then return vector's count.
 *
 *  @N: number of vector
 *  @w: vector (double)
 *  @retval: count of creates
 */
extern int hanningwin(int, double*);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      Window.hamming(n) -> Vector
 *    (Native Code)
 *      hammingwin(N, w) -> int
 *  
 *  Create a Hamming Window's vector, then return vector's count.
 *
 *  @N: number of vector
 *  @w: vector (double)
 *  @retval: count of creates
 */
extern int hammingwin(int, double*);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      Window.rectangular(n) -> Vector
 *    (Native Code)
 *      rectangularwin(N, w) -> int
 *  
 *  Create a Rectangular Window's vector, then return vector's count.
 *
 *  @N: number of vector
 *  @w: vector (double)
 *  @retval: count of creates
 */
extern int rectangularwin(int, double*);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      Window.bartlett(n) -> Vector
 *    (Native Code)
 *      bartlettwin(N, w) -> int
 *  
 *  Create a Bartlett Window's vector, then return vector's count.
 *
 *  @N: number of vector
 *  @w: vector (double)
 *  @retval: count of creates
 */
extern int bartlettwin(int, double*);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      Window.blackman(n) -> Vector
 *    (Native Code)
 *      blackmanwin(N, w) -> int
 *  
 *  Create a Blackman Window's vector, then return vector's count.
 *
 *  @N: number of vector
 *  @w: vector (double)
 *  @retval: count of creates
 */
extern int blackmanwin(int, double*);

/*
 *  call-seq:
 *    (UserLevel Code)
 *      Window.gauss(n, sigma: 2.5) -> Vector
 *    (Native Code)
 *      gausswin(sigma, N, w) -> int
 *  
 *  Create a Gaussian Window's vector, then return vector's count.
 *
 *  @sigma: window parameter, default is 2.5
 *  @N: number of vector
 *  @w: vector (double)
 *  @retval: count of creates
 */
extern int gausswin(double, int, double*);

#ifdef __cplusplus
}
#endif

#endif /* GLUEMATH_WFUNK_H */
