#ifndef MYMAIN
#define MYMAIN
  #include <stdio.h>
	#include "seq.h"	
	#define HASHMAX 65535												// The maximum size for hash table = (2^16)-1

	void encode(FILE* inFile, FILE* outFile);		// Read and encode the input
	void decode((FILE* inFile, FILE* outFile);	// Decode the the compressed input, into the output

#endif
