
CFLAGS=-std=c99 -Wall -pedantic

lzw: main.o bits.o lzw.o seq.o
	gcc main.o lzw.o bits.o	seq.o -o lzw

main.o: main.c bits.h lzw.h main.h
	gcc -c $(CFLAGS) main.c

bits.o: bits.c bits.h
	gcc -c $(CFLAGS) bits.c

seq.o: seq.c seq.h
	gcc -c $(CFLAGS) seq.c

lzw.o: lzw.c lzw.h seq.h
	gcc -c $(CFLAGS) lzw.c

clean:
		rm lzw *.o
