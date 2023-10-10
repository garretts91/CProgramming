/*
Find the bug!
Compile for 32-bit and 64-bit

CERT32 Strings C Secure Coding Standard[Seacord 2008]:
ARR01 - C.Do not apply the sizeof operator to a pointer when taking the size of an array.
*/

#include <stdio.h>

void clear(int array[]);
void populate(int array[]);
void output(int array[]);

#define ARRAY_SIZE 5

int main()
{
	int scores[ARRAY_SIZE];

	clear(scores);

	populate(scores);
   
	output(scores);

	return 0;
}

void clear(int array[]) 
{
	int x = sizeof(array);
	int y = sizeof(array[0]);

	int size = sizeof(array) / sizeof(array[0]);

	for (int index = 0; index < size; ++index) 
	{
		array[index] = 0;
	}
}

void populate(int array[])
{
	int size = sizeof(array) / sizeof(array[0]);

	for (int index = 0; index < size; ++index)
	{
		array[index] = index + 1;
	}
}

void output(int array[])
{
	int size = sizeof(array) / sizeof(array[0]);

	for (int index = 0; index < size; ++index)
	{
		printf("Array value at index %d: %d\n", index, array[index]);
	}
}
