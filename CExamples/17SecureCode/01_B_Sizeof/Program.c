/*
Proper use of sizeof

Compile for 32-bit and 64-bit

CERT32 Strings C Secure Coding Standard[Seacord 2008]:
ARR01 - C.Do not apply the sizeof operator to a pointer when taking the size of an array.
*/

#include <stdio.h>

void clear(int array[], int size);
void populate(int array[], int size);
void output(int array[], int size);

#define ARRAY_SIZE 5

int main()
{
	int scores[ARRAY_SIZE];

	int size = sizeof(scores) / sizeof(scores[0]);
	//int size = sizeof(scores) / sizeof(int);

	clear(scores, size);

	populate(scores, size);
   
	output(scores, size);

	return 0;
}

void clear(int array[], int size) 
{
	for (int index = 0; index < size; ++index) 
	{
		array[index] = 0;
	}
}

void populate(int array[], int size)
{
	for (int index = 0; index < size; ++index)
	{
		array[index] = index + 1;
	}
}

void output(int array[], int size)
{
	for (int index = 0; index < size; ++index)
	{
		printf("Array value at index %d: %d\n", index, array[index]);
	}
}
