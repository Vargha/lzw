#ifndef DICT_H
#define DICT_H
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include "seq.h"
	#define HASHMAX 65535																										// The maximum size for hash table = (2^16)-1

	typedef struct DictData{
		Seq* key;
		unsigned int code;																										// place in hash table. hashCode
		struct DictData* next;																								// create a new node for the next data
	}DictData;

	typedef struct Dict{
		unsigned int counter;																									// index counter
		unsigned int Size;																										// hash table size (HASHMAX)
		DictData** dataTbl;																										// struct for the hash data
	}Dict;

	Dict* createDict(unsigned int hashMax);
	void addToDict(Dict* myDict, Seq* mySeq, unsigned int code);						// add q sequence to dictionary
	unsigned int bernHash(Seq* mySeq, unsigned int myMod);									// the modulus value in this case is HASHMAX
	DictData* newEntry(Seq* seq, unsigned int code);												// Dictionary data (dictionary entry)
	char checkExist(Seq* seq, unsigned int* codePointer, Dict* dict);				// Check dictionary for a sequence existance
	void killDict(Dict* dict);																							// Delete the entire dictionary, to free the allocate memory
	void insertSeq(Seq* seq, unsigned int code, Dict* dict);								// Insert a sequence into the dictionary
	void decDicDel(Dict* dict, int tblSize);																// Unallocate the memory for the decoding dictionary

#endif
