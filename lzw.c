#include "lzw.h"

/* ********** ENCODE INPUT ********** */
void encode(FILE* inFile, FILE* outFile)
{
	Dict* dict = createDict(HASHMAX);									// initialize dictionary D and insert characters 0 through 255
	unsigned int nextCode = 256;
	int c = fgetc(inFile);
	Seq* w = createSeq(c);														// Read the the first byte of data
	unsigned int codePointer = 0;

	while((c=fgetc(inFile)) != EOF)										// while not end of the file
	{
		Seq* x = concatSeq (w, c);											// w concatindated with c
		if (checkExist(x, &codePointer, dict) == 'F')		// if Found x in dictionary d
		{
			delSeq(w);																		// unallocate the memory
			copySeq(x, w);																// copy x on w
			delSeq(x);																		// Prevent memory lost
		}
		else																						// if Not Found x in dictionary D
		{
			checkExist(w, &codePointer, dict);						// go to w in the dictionary
			writeBits (codePointer, outFile);							// output w's code
			insertSeq(x, nextCode, dict);									// insert Sequence x into dictionary D, assigning nextCode as its code
			nextCode++;																		// increment nextCode by 1, for the next empty spot
			delSeq(w);
			w = createSeq(c);												// Create a new Sequence w, with just the character c
		}
	}
	checkExist(w, &codePointer, dict);								// find Sequence w in d
	writeBits(codePointer, outFile);									// , and output its assigned code
	delSeq(w);																				// free the allocaed memory
	killDict(dict);
	fclose(inFile);
	fclose(outFile);
	return;																						// DONE ENCODING
}





/* ********** DECODE OUTPUT ********** */
void decode (FILE* inFile, FILE* outFile)
{
	int tblSize=256;																						// Size of the data table
	unsigned int prvCode, crtCode;															// previous and current codes
	char c;
	Dict* dict = malloc(sizeof(Dict));													// allocate size for the dictionary
	dict->dataTbl = calloc(HASHMAX,sizeof(DictData*));
	for(int i=0; i < tblSize; i++)															// insert the ASCII table
	{
		Seq* seq = createSeq(i);
		dict->dataTbl[i] = newEntry(seq, i);
	}
	readBits(&prvCode, inFile);																	// integer previousCode gets the first code read from input
	printSeq(dict->dataTbl[prvCode]->key, outFile);							// output Sequence T[previousCode]
	while(readBits(&crtCode, inFile))														// while there are more codes
	{
		if(crtCode < tblSize)
			c = firstInSequence(dict->dataTbl[crtCode]->key);
		else
			c = firstInSequence(dict->dataTbl[prvCode]->key);

		if(tblSize<HASHMAX)																				// if the table is not full
		{
			Seq* w = concatSeq (dict->dataTbl[prvCode]->key, c);		// seq W gets new seq using seq in table indexed by prvCode, concatenated with c
			dict->dataTbl[tblSize] = newEntry(w, prvCode);					// add seq W at the next index/code in table
			tblSize++;																							// increment table size
		}
		printSeq(dict->dataTbl[crtCode]->key, outFile);						//output seq in table indexed by crtCode
		prvCode = crtCode;																				//prvCode becomes crtCode
	}
	decDicDel(dict, tblSize);																		// Unallocate the memory for the decoding dictionary
	fclose(inFile);
	fclose(outFile);

	return;																											// DONE DECODING

}


