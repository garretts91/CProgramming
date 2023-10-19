#include <stdio.h>

#define ARRAY_SIZE 3

int array_1[] = { 1,2, 3 };
int array_2[ARRAY_SIZE] = { 0};
int index = 0;

void main()
{
	for (index = 0; index < ARRAY_SIZE; index++)
	{
		array_2[index] = array_1[index];
	}
	
	for (index = 0; index < ARRAY_SIZE; index++)
	{
		printf("Array value at index %d: %d \n", index, array_2[index]);
	}

	int c = getchar();
}