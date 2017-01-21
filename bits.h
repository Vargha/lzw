#ifndef BITS_H
#define BITS_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct _bits
{
  unsigned int extraBits;
  unsigned int bitCount;
  FILE* fd;
} Bits;

Bits* newBits (FILE* fd);

void deleteBits (Bits* bt);

bool readBits(Bits* bt, unsigned int nBits, unsigned int* count);

bool writeBits(Bits* bt, unsigned int nBits, unsigned int count);

bool flushBits(Bits* bt);


#endif
