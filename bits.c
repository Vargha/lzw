#include "bits.h"
#include <stdlib.h>
#include <assert.h>

/*Bits* newBits (FILE* fd){
	Bits* result = (Bits*) malloc(sizeof(Bits));
	result -> fd = fd;
	result -> extraBits = 0;
	result -> bitCount = 0;
  return result;
}

void deleteBits (Bits* bt){
  free (bt);
}

bool readBits(Bits* bt, unsigned int nBits, unsigned int* count){
	unsigned int code = 0;
	char firstByte = fgetc (bt->fd);
	char secondByte = fgetc (bt->fd);
	code = (firstByte << 8) | secondByte;
	*bits = code;
  return true;
}

bool writeBits(Bits* bt, unsigned int nBits, unsigned int count){
	assert (count == 16);
	assert (bt != NULL);
	unsigned int firstByte = (bits >> 8) & 0xFF;
	unsigned int secondByte = bits & 0xFF;
	fputc (firstByte, bt->fd);
	fputc (secondByte, bt->fd);
  return true;
}

bool flushBits(Bits* bt){
  return true;
}*/
