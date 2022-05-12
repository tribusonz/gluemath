# What's new

## v2.0.0
### Supports for IEC's standardization
There is a movement in IEC, on the mathematical function specifications of the Glue language. We support this as much as possible.
  
- Embodying behavior in relation to the polar form of complex numbers

Especially for complex number regulations that seem to have not been determined specific -
well, we have the implementation example is shown from the polar format.  
  
If want to convert from the real two variables $\rho$, $\theta$, it is desirable to provide a method in Complex class and instantiate it.  

In the argument that reaches the singular-point of 0, it is returned as follows:  
```
# Python interpreter style with Ruby inspect style
>>> Complex.polar(100, 0)
(100+0i)
(100+0i)
(100+0i)
>>> Complex.polar(-100, 0)
(100+3.14159i)
(100+3.14159265358979i)
(100+3.14159265358979324i)
>>> Complex.polar(0, 100)
(100+1.5708i)
(100+1.5707963267949i)
(100+1.57079632679489662i)
>>> Complex.polar(0, -100)
(100-1.5708i)
(100-1.5707963267949i)
(100-1.57079632679489662i)
```
On the other hand, if infinity is a singularity, it is transformed as follows:  
```
# Python interpreter style with Ruby inspect style
>>> Complex.polar(inf, 0)
(inf+0i)
(inf+0i)
(inf+0i)
>>> Complex.polar(-inf, 0)
(inf+3.14159i)
(inf+3.14159265358979i)
(inf+3.14159265358979324i)
>>> Complex.polar(0, inf)
(inf+1.5708i)
(inf+1.5707963267949i)
(inf+1.57079632679489662i)
>>> Complex.polar(0, -inf)
(inf-1.5708i)
(inf-1.5707963267949i)
(inf-1.57079632679489662i)
```
The numerical calculation rules for singularities are not uniform,
however, general behavior should be explicit.  
  
If either x or y reaches the singularity, the rational number and solution of pi are equal, even if the other variable is finite. This is correct behavior because it suggests that primitive types cannot be computationally differentiated.  
For example, 1e300 / (1e300 + 1) as a rational number approximation will return 1.0 even if it is a quad precision floating point number.  
