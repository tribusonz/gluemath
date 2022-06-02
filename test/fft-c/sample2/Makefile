# ---- for GNU gcc ----

CC := gcc

CFLAGS := -Wall -Wextra

OFLAGS_FFT := -O6 -ffast-math
OFLAGS_PI := -O6 -ffast-math

INCLUDE := -I../include




all: pi_fft4g pi_fft8g pi_fftsg


pi_fft4g : pi_fft.o fft4g.o mp.o
	$(CC) pi_fft.o fft4g.o mp.o -lm -o pi_fft4g

pi_fft8g : pi_fft.o fft8g.o
	$(CC) pi_fft.o fft8g.o mp.o -lm -o pi_fft8g

pi_fftsg : pi_fft.o fftsg.o
	$(CC) pi_fft.o fftsg.o mp.o -lm -o pi_fftsg


pi_fft.o : pi_fft.c
	$(CC) $(CFLAGS) $(OFLAGS_PI) -c pi_fft.c -o pi_fft.o

mp.o : mp.c
	$(CC) $(CFLAGS) $(OFLAGS_PI) -c mp.c -o mp.o


fft4g.o : ../src/fft4g.c
	$(CC) $(CFLAGS) $(OFLAGS_FFT) $(INCLUDE) -c ../src/fft4g.c -o fft4g.o

fft8g.o : ../src/fft8g.c
	$(CC) $(CFLAGS) $(OFLAGS_FFT) $(INCLUDE) -c ../src/fft8g.c -o fft8g.o

fftsg.o : ../src/fftsg.c
	$(CC) $(CFLAGS) $(OFLAGS_FFT) $(INCLUDE) -c ../src/fftsg.c -o fftsg.o




clean:
	rm -f *.o

