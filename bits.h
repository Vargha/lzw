#ifndef BITS_H
#define BITS_H

	#include <stdio.h>
	#include <stdbool.h>

	bool writeBits(unsigned int codePointer, FILE* outFile);
	bool readBits(unsigned int* crtCode, FILE* inFile);

#endif
