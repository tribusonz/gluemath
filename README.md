# Math library for GLUE-Language C Compiler

A library of mathematical functions for GLUE languages such as Python and Ruby.  
It is a library for compilers, but independent. Include it so that the language compiler is importing it.  
(So it can be adopted by Fortran)  

* Features:  
	* Thread-safe design (POSIX-base)
	* Numerical Verification
	* Portable (Linux, UNIX-like, Windows)
	* Refined Math
	* Complex-number arithmetic (lower compatibility of C++)
	* Distribution Function Support
	* ANSI C Math Support (named as legacy)
	* Adopts C++ naming convention

How to use:  
Typically, you take this as a single library of compilers (e.g. like libquadmath in gcc).  
However, it is not necessary to link as an external library. This is because it also includes setting up language primitive types, and is the positioning of standard library.  
