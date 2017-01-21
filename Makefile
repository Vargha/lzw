
CFLAGS=-std=c99 -Wall -pedantic

lzw: main.o bits.o
	gcc main.o bits.o	-o lzw

main.o: main.c bits.h
	gcc -c $(CFLAGS) main.c

bits.o: bits.c bits.h
	gcc -c $(CFLAGS) bits.c

clean:
		rm lzw *.o
