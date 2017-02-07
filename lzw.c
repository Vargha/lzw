#include "lzw.h"

/* ********** ENCODE INPUT ********** */
void encode(FILE* inFile, FILE* outFile)
{
	Dict* dict = createDict(HASHMAX);									// initialize dictionary D and insert characters 0 through 255
	int nextCode = 256;
	char c = fgetc(inFile);
	Seq* w = createSeq(c);														// Read the the first byte of data
	unsigned int codePoniter = 0;

	while(feof(inFile) != 1)													// while not end of the file
	{
		c = fgetc(inFile);
		Seq* x = concatSeq (w, c);											// w concatindated with c
		if (checkExist(x, &codePointer, dict) == 'F')		// if Found x in dictionary d
		{
			copySeq(x, w);																// copy x on w
			delSeq(x);																		// Prevent memory lost
		}
		else																						// if Not Found x in dictionary D
		{
			checkExist(w, &cdPointer, dict);							// go to w in the dictionary
			outputBits (codePointer, outFile);						// output w's code
			insertSeq(x, nextCode, dict);									// insert Sequence x into dictionary D, assigning nextCode as its code
			nextCode++;																		// increment nextCode by 1, for the next empty spot
			delSeq(w);
			Seq* w = createSeq(c);												// Create a new Sequence w, with just the character c
		}
	}
	checkExist(w, &cdPointer, dict);									// find Sequence w in d
	outputBits(codePointer, outFile);									// , and output its assigned code
	delSeq(w);																				// free the allocaed memory
	killDic(dict);
//	printf("test->data:\t%c\n", test->data[1]);	// TEST
	fclose(inFile);
	fclose(outFile);
	return;																						// DONE ENCODING
}


/* ********** DECODE OUTPUT ********** */
void decode(FILE* inFile)
{

	return;
}


