#include "dict.h"

/* ********** CREATE THE DICTIONARY ********** */
Dict* createDict(unsigned int hashMax)
{
	Dict* myDict = malloc(sizeof(Dict));
	myDict->dataTbl=calloc(hashMax,sizeof(DictData*));
	for (int code=0; code<256; code++)																		// create one sequence for each dictionary element
	{
		Seq* mySeq = createSeq(code);
		addToDict(myDict, mySeq, code);																			// add a element into the created dictionary
	}
	return myDict;
}

/* ********** ADD TO DICTIONARY ********** */
void addToDict(Dict* myDict, Seq* mySeq, unsigned int code)
{
	unsigned int bh = bernHash(mySeq, HASHMAX);														// Create the hash
	DictData* data = newEntry(mySeq,code);
	data->next = myDict->dataTbl[bh];
	myDict->dataTbl[bh] = data;
}

/* ********** BENRSTEIN'S HASH ********** */
unsigned int bernHash(Seq* mySeq, unsigned int myMod)										// the modulus value in this case is HASHMAX
{
	unsigned int myHash=5381;																							// Cool: 5381 is 709th prime (Bernstein Hash's magic Number)
	int c;
	for (int i=0; i<(mySeq->count); i++)
	{
		c = mySeq->data[i];
		myHash = ((myHash << 5) + myHash) + c;
	}
	myHash=myHash%myMod;
	return myHash;
}

/* ********** DICTIONARY DATA ********** */
DictData* newEntry(Seq* seq, unsigned int code)													// Dictionary data (dictionary entry)
{
	DictData* result = (DictData*) malloc(sizeof(DictData));							// allocate memory for this dictionary data
	result->key = seq;																										// result is a DictData
	result->code = code;
	result->next = NULL;																									// No next node yet
	return result;
}

/* ********** CHECK DICTIONARY FOR A SEQUENCE ********** */
char checkExist(Seq* seq, unsigned int* codePointer, Dict* dict){
	unsigned int bh = bernHash(seq, HASHMAX);															// bh is the index for the dictionary array, based on the seq
	DictData* myData = dict->dataTbl[bh];
	while(myData)																													// while there is more
	{
		if(compareSeq(seq, myData->key) == 'E')															// Compare if the passed sequence is Equal to the current key in the table
		{
			*codePointer = myData->code;																			// if you find the passed sequence, output the code of the found sequence
			return 'F';																												// return F if Seq* x (from lzw.c) was Found
		}
		myData = myData->next;	
	}
	return 'N';																														// return F if Seq* x (from lzw.c) was Not found
}

/* ********** DELETE THE ENTIRE DICTIONARY ********** */
void killDict(Dict* dict)																								// to free the allocate memory
{
	DictData* dd = NULL;																									// a temporary dictionary data to hold data while removing
	for(int i=0; i<HASHMAX; i++)																					// go through the dictionaty and delete data
	{
		while((dict->dataTbl[i]) != NULL)
		{
			dd = dict->dataTbl[i]->next;																			// hold the next DictData in a temporary spot to not lose it after delete
			delSeq(dict->dataTbl[i]->key);																		// delete the sequence
			free(dict->dataTbl[i]);																						// free the allocated memory
			dict->dataTbl[i]=dd;																							// get ready for the next data
		}	
	}
	free(dict->dataTbl);																									// free the allocated memory for the dataTable now
	free(dict);																														// free the allocated memory for the dictionary now
}

/* ********** INSERT SEQUENCE INTO THE DICTIONARY ********** */
void insertSeq(Seq* seq, unsigned int code, Dict* dict)									// Insert a sequence into the dictionary
{
	unsigned int hash = bernHash(seq, HASHMAX);														// hash the sequence based on the sequence
	DictData* dd = newEntry(seq,code);
	dd->next = dict->dataTbl[hash];
	dict->dataTbl[hash] = dd;
}

/* ********** DELETE THE ENTIRE DICTIONARY ********** */
void decDicDel(Dict* dict, int tblSize)																	// Unallocate the memory for the decoding dictionary
{
	DictData* temp = NULL;
	for(int i=0; i<HASHMAX; i++)
	{
		while((dict->dataTbl[i]) != NULL)
		{
			temp = dict->dataTbl[i]->next;
			delSeq(dict->dataTbl[i]->key);
			free(dict->dataTbl[i]);
			dict->dataTbl[i]=temp;
		}	
	}
	free(dict->dataTbl);
	free(dict);	
}
