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

Trend:  
Python and Ruby committers are looking for a thread-safe mathematical function library, and as a result of providing it because it is frequently used by organizations, it has become a small framework library.  
On the mailing list (organization's), the C++ committee and the R language developers have also decided to adopt it, and Microsoft, Apple and Google are also expected to incorporate it into the operating system.  

Dislike Exception?:  
NO. We welcome exception control by NaN.  
In principle, although in accordance with IEC regulations, the standard does not yet exist as of April 2022. (Although it may be standardized by this gluemath)  
Perhaps both Python and Ruby will be revamping the constructor.  
When we tried to build it with Ruby3 series, the ABI processing is faster than expected, so the user-level thread does not catch up, then it has been core dumped or method overridden is don't work.  

For compiler developers:  
This is based on C99, but some have different specifications. For example, the C99 complex number library specification is made with this as lower compatibility of C++. In other words, it is not compatible with the C99 complex number library.  
If you want to capture this with your compiler software (e.g. gcc or clang, etc...), you may want to add -std=glue99 to the compiler option.  

NOTE:  
The organization has decided to take over the library to Stephen Wolfram (this is not strictly private), and I am prepared to provide the minimum ABI required. POSIX's special functions are also included (corresponding to complex numbers!), and also support parts that are too professional that can not be reached by committers.  

[What's new](whats_new.md)  
[Q and A](q_and_a.md)  
