NMAX_FLAGS = -DNMAX=65536 -DNMAXSQRT=256

# ---- for GNU gcc ----

CC := gcc

CFLAGS := -Wall -Wextra

OFLAGS := -O2

INCLUDE := -I../include



all: test4g test8g testsg


test4g : testxg.o fft4g.o
	$(CC) testxg.o fft4g.o -lm -o test4g

test8g : testxg.o fft8g.o
	$(CC) testxg.o fft8g.o -lm -o test8g

testsg : testxg.o fftsg.o
	$(CC) testxg.o fftsg.o -lm -o testsg



testxg.o : testxg.c
	$(CC) $(CFLAGS) $(OFLAGS) $(NMAX_FLAGS) -c testxg.c -o testxg.o



fft4g.o : ../src/fft4g.c
	$(CC) $(CFLAGS) $(OFLAGS) $(INCLUDE) -c ../src/fft4g.c -o fft4g.o

fft8g.o : ../src/fft8g.c
	$(CC) $(CFLAGS) $(OFLAGS) $(INCLUDE) -c ../src/fft8g.c -o fft8g.o

fftsg.o : ../src/fftsg.c
	$(CC) $(CFLAGS) $(OFLAGS) $(INCLUDE) -c ../src/fftsg.c -o fftsg.o





clean:
	rm -f *.o

