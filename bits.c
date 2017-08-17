
// Given By Dr. Lang
#include "bits.h"
#include <stdlib.h>
#include <assert.h>


bool writeBits(unsigned int codePointer, FILE* outFile)
{
	unsigned char byteOne = (codePointer >> 8) & 0xFF;
	unsigned char byteTwo = codePointer & 0xFF;
	fputc(byteOne, outFile);
	fputc(byteTwo, outFile);
	return true;
}

bool readBits(unsigned int* crtCode, FILE* inFile)
{
	int byteOne = fgetc(inFile);	
	if(byteOne==EOF)
		return false;
	int byteTwo = fgetc(inFile);
	if(byteTwo==EOF)
		return false;
	*crtCode = (byteOne << 8) | byteTwo;
	return true;
}

