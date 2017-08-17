#ifndef SEQ_H
#define SEQ_H
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdbool.h>

	typedef struct Seq{
		unsigned int count;																	// Number of characters in sequence
		unsigned char* data;																// The sequence data
	}Seq;

	Seq* createSeq (char firstChar);
	void delSeq(Seq* poorSeq);														// Delete a sequence
	Seq* concatSeq(Seq* oldSeq, char newChar);						// w Concatinated with c
	void copySeq(Seq* x, Seq* w);													// copy x on w
	char compareSeq(Seq* firstSeq, Seq* secondSeq);				// compare two sequences for equality
	unsigned char firstInSequence(Seq* sequence);					// This was in Dr. Lang's header file, but not sure if I'm going to use it
	void printSeq(Seq* seq, FILE* outFile);								// print the sequence to screen / file


#endif
