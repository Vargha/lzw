#include "seq.h"


Seq* createSeq(char firstChar)
{
  Seq* mySeq = malloc(sizeof(Seq));										// allocate memory for the new sequence
  mySeq->data =  malloc(sizeof(char));								// allocate memory for data
  mySeq->data[0] = firstChar;
	mySeq->count=1;

	return mySeq;
}

/* ********** DELETE SEQUENCE ********** */
void delSeq(Seq* poorSeq)
{
	free(poorSeq->data);																// free the data first, so still have access to the actual sequence
	free(poorSeq);																			// free the actual sequence
}

/* ********** CONCATINATE SEQUENCE ********** */
Seq* concatSeq(Seq* oldSeq, char newChar)							// w Concatinated with c
{
	Seq* newSeq = malloc(sizeof(Seq));									// allocate memory for the new sequence
  newSeq->data = malloc(oldSeq->count + 1);						// allocate memory for data
	newSeq->count = oldSeq->count + 1;
	memcpy (newSeq->data, oldSeq->data, oldSeq->count);	// memcpy(dest, src, length-in-bytes);
	newSeq->data[newSeq->count-1] = newChar;						// appending the character to end of data
	//delSeq(oldSeq);																		// Free the memory
	return newSeq;
}

/* ********** CONPY SEQUENCE ********** */
void copySeq(Seq* x, Seq* w)													// copy x on w
{
	//free(w->data);																		// free the memory, by deleting the old data
	Seq* temp = malloc(sizeof(Seq));
	//w = malloc(sizeof(Seq));
	temp->data = malloc(x->count);											// allocate memory for the new data			
	memcpy(temp->data, x->data, x->count);							// Now, copy x->data to w->data
	temp->count = x->count;
	w=temp;
	return;
}

/* ********** COMPARE TWO SEQUENCES FOR EQUALITY ********** */
char compareSeq(Seq* firstSeq, Seq* secondSeq)
{
	if(firstSeq->count != secondSeq->count)				return 'N';	// if they have a different length, return Not equal
	int i=0;																						// index counter
	while(i < firstSeq->count)
	{
		if(firstSeq->data[i] != secondSeq->data[i])	return 'N';	// if any of the characters are not equal, they are Not equal
		i++;
	}
	return 'E';																					// if it passes all conditions, then sequences are equal
}

/* ********** RETURN THE FIRST CHARACTER OF THE SEQUENCE ********** */
unsigned char firstInSequence(Seq* sequence)					// This was in Dr. Lang's header file, but not sure if I'm going to use it
{
	return (sequence->data[0]);
}

void printSeq(Seq* seq, FILE* outFile)								// print the sequence to screen / file
{
	for(int i=0; i < seq->count; i++)
	{
		fputc(seq->data[i], outFile);
	}
}


