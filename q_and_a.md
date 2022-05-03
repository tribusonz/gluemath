# Q and A
  
Q:  
How can I create a library of accuracy error guarantees?  
A:  
Be at the gate of Professor Tomonori Kouya. He is a specialist in numerical calculations.  
https://na-inet.jp/  
  
Q:  
In some functions 0.49999999999... error occurs.  
A:  
Error bound. Some functions are machine-dependent because of the suppression of architecture.  
  
Q:  
Why are you write native code for glue language and in C?  
A:  
There is no post-C language like Python or Ruby, and ABI cannot achieve faster processing than anything written in C.  
  
Q:  
With IEEE754 extended double precision, some functions pick up errors.  
A:  
We do not recommend numerical calculations with extended double precision. This is because the mant number part is cut off in the middle, making it easy to pick up errors.  
