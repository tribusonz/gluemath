/*******************************************************************************
	Rounding Mode (Intel CPU main, Windows and Linux)
	
	Original Algorithm Author:
	  Masahide Kashiwagi, Waseda University
*******************************************************************************/

extern void roundnear(void);
extern void rounddown(void);
extern void roundup(void);
extern void roundchop(void);

#if defined(_WIN32) || defined(_WIN64) // Windows
# if defined (_WIN64) // Windows 64 bit
#  include <emmintrin.h> // for _mm_getcsr , _mm_setcsr
void
roundnear(void)
{
	unsigned long int mode2; // 32 bit unsigned
	mode2 = _mm_getcsr();
	mode2 &= ~0x00006000;
	_mm_setcsr(mode2);
}
void
rounddown(void)
{
	unsigned long int mode2; // 32 bit unsigned
	mode2 = _mm_getcsr();
	mode2 &= ~0x00006000;
	mode2 |= 0x00002000;
	_mm_setcsr(mode2);
}
void
roundup(void)
{
	unsigned long int mode2; // 32 bit unsigned
	mode2 = _mm_getcsr();
	mode2 &= ~0x00006000;
	mode2 |= 0x00004000;
	_mm_setcsr(mode2);
}
void
roundchop(void)
{
	unsigned long int mode2; // 32 bit unsigned
	mode2 = _mm_getcsr();
	mode2 |= 0x00006000;
	_mm_setcsr(mode2);
}
# elif defined(_WIN32) // Windows 32 bit
#  if _M_IX86_FP == 2
#   include <emmintrin.h> // for _mm_getcsr , _mm_setcsr
#  endif
void
roundnear(void)
{
	unsigned short int mode1; // 16 bit unsigned
	unsigned long int mode2; // 32 bit unsigned
	_asm { fnstcw mode1 }
	mode1 &= ~0x0c00;
	_asm { fldcw mode1 }
#  if _M_IX86_FP == 2
	mode2 = _mm_getcsr();
	mode2 &= ~0x00006000;
	_mm_setcsr(mode2);
#  endif
}
void
rounddown(void)
{
	unsigned short int mode1; // 16 bit unsigned
	unsigned long int mode2; // 32 bit unsigned
	_asm { fnstcw mode1 }
	mode1 &= ~0x0c00;
	mode1 |= 0x0400;
	_asm { fldcw mode1 }
#  if _M_IX86_FP == 2
	mode2 = _mm_getcsr();
	mode2 &= ~0x00006000;
	mode2 |= 0x00002000;
	_mm_setcsr(mode2);
#  endif
}
void
roundup(void)
{
	unsigned short int mode1; // 16 bit unsigned
	unsigned long int mode2; // 32 bit unsigned
	_asm { fnstcw mode1 }
	mode1 &= ~0x0c00;
	mode1 |= 0x0800;
	_asm { fldcw mode1 }
#  if _M_IX86_FP == 2
	mode2 = _mm_getcsr();
	mode2 &= ~0x00006000;
	mode2 |= 0x00004000;
	_mm_setcsr(mode2);
#  endif
}
void
roundchop(void)
{
	unsigned short int mode1; // 16 bit unsigned
	unsigned long int mode2; // 32 bit unsigned
	_asm { fnstcw mode1 }
	mode1 |= 0x0c00;
	_asm { fldcw mode1 }
#  if _M_IX86_FP == 2
	mode2 = _mm_getcsr();
	mode2 |= 0x00006000;
	_mm_setcsr(mode2);
#  endif
}
# else // Windows other CPU
#  include <float.h>
void
roundnear(void)
{
	unsigned int cw = 0;
	_controlfp_s(&cw, _RC_NEAR, _MCW_RC);
}
void
rounddown(void)
{
	unsigned int cw = 0;
	_controlfp_s(&cw, _RC_DOWN, _MCW_RC);
}
void
roundup(void)
{
	unsigned int cw = 0;
	_controlfp_s(&cw, _RC_UP, _MCW_RC);
}
void
roundchop(void)
{
	unsigned int cw = 0;
	_controlfp_s(&cw, _RC_CHOP, _MCW_RC);
}
# endif
#else // Linux , etc
# if defined(__x86_64__) // Linux 64 bit
void
roundnear(void)
{
	unsigned long int mode2; // 32 bit unsigned
	__asm__ __volatile__ ("stmxcsr  %0" : "=m"(mode2));
	mode2 &= ~0x00006000;
	__asm__ __volatile__ ("ldmxcsr  %0" : : "m"(mode2));
}
void
rounddown(void)
{
	unsigned long int mode2; // 32 bit unsigned
	__asm__ __volatile__ ("stmxcsr  %0" : "=m"(mode2));
	mode2 &= ~0x00006000;
	mode2 |= 0x00002000;
	__asm__ __volatile__ ("ldmxcsr  %0" : : " m"(mode2));
}
void
roundup(void)
{
	unsigned long int mode2; // 32 bit unsigned
	__asm__ __volatile__ ("stmxcsr  %0" : "=m"(mode2));
	mode2 &= ~0x00006000;
	mode2 |= 0x00004000;
	__asm__ __volatile__ ("ldmxcsr  %0" : : "m"(mode2));
}
void
roundchop(void)
{
	unsigned long int mode2; // 32 bit unsigned
	__asm__ __volatile__ ("stmxcsr  %0" : "=m"(mode2));
	mode2 |= 0x00006000;
	__asm__ __volatile__ ("ldmxcsr  %0" : : "m"(mode2));
}
# elif defined (__i386__) // Linux 32 bit
void
roundnear(void)
{
	unsigned short int mode1; // 16 bit unsigned
	unsigned long int mode2; // 32 bit unsigned
	__asm__ __volatile__ ("fnstcw  %0" : "=m"(mode1));
	mode1 &= ~0x0c00;
	__asm__ __volatile__ ("fldcw  %0" : : "m"(mode1));
#  if defined (__SSE2_MATH__)
	__asm__ __volatile__ ("stmxcsr  %0" : "=m"(mode2));
	mode2 &= ~0x00006000;
	__asm__ __volatile__ ("ldmxcsr  %0" : : "m"(mode2));
#  endif
}
void
rounddown(void)
{
	unsigned short int mode1; // 16 bit unsigned
	unsigned long int mode2; // 32 bit unsigned
	__asm__ __volatile__ ("fnstcw  %0" : "=m"(mode1));
	mode1 &= ~0x0c00;
	mode1 |= 0x0400;
	__asm__ __volatile__ ("fldcw  %0" : : "m"(mode1));
#  if defined (__SSE2_MATH__)
	__asm__ __volatile__ ("stmxcsr  %0" : "=m"(mode2));
	mode2 &= ~0x00006000;
	mode2 |= 0x00002000;
	__asm__ __volatile__ ("ldmxcsr  %0" : : "m"(mode2));
#  endif
}
void
roundup(void)
{
	unsigned short int mode1; // 16 bit unsigned
	unsigned long int mode2; // 32 bit unsigned
	__asm__ __volatile__ ("fnstcw  %0" : "=m"(mode1));
	mode1 &= ~0x0c00;
	mode1 |= 0x0800;
	__asm__ __volatile__ ("fldcw  %0" : : "m"(mode1));
#  if defined (__SSE2_MATH__)
	__asm__ __volatile__ ("stmxcsr  %0" : "=m"(mode2));
	mode2 &= ~0x00006000;
	mode2 |= 0x00004000;
	__asm__ __volatile__ ("ldmxcsr  %0" : : "m"(mode2));
#  endif
}
void
roundchop(void)
{
	unsigned short int mode1; // 16 bit unsigned
	unsigned long int mode2; // 32 bit unsigned
	__asm__ __volatile__ ("fnstcw  %0" : "=m"(mode1));
	mode1 |= 0x0c00;
	__asm__ __volatile__ ("fldcw  %0" : : "m"(mode1));
#  if defined(__SSE2_MATH__)
	__asm__ __volatile__ ("stmxcsr  %0" : "=m"(mode2));
	mode2 |= 0x00006000;
	__asm__ __volatile__ ("ldmxcsr  %0" : : "m"(mode2));
#  endif
}
# else // Linux other CPU
#  include <fenv.h>
void
roundnear(void)
{
	fesetround(FE_TONEAREST);
}
void
rounddown(void)
{
	fesetround(FE_DOWNWARD);
}
void
roundup(void)
{
	fesetround(FE_UPWARD);
}
void
roundchop(void)
{
	fesetround(FE_TOWARDZERO);
}
# endif
#endif


