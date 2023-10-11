/*
Find the bug!
Compile for 32-bit and 64-bit

CERT32 Strings C Secure Coding Standard[Seacord 2008]:
ARR01 - C.Do not apply the sizeof operator to a pointer when taking the size of an array.
*/

#include <stdio.h>

void function1(int array[]);
void function2(int* array);

#define ARRAY_SIZE 5

int main()
{
	int size = 0;
	int scores[ARRAY_SIZE];

	size = sizeof(char);
	printf("Sizeof char: %d\n", size);

	size = sizeof(short);
	printf("Sizeof short: %d\n", size);

	size = sizeof(int);
	printf("Sizeof int: %d\n", size);

	size = sizeof(long);
	printf("Sizeof long: %d\n", size);

	size = sizeof(float);
	printf("Sizeof float: %d\n", size);

	size = sizeof(double);
	printf("Sizeof double: %ld\n", size);

	size = sizeof(char*);
	printf("Sizeof char*: %ld\n", size);

	size = sizeof(short*);
	printf("Sizeof short*: %d\n", size);

	size = sizeof(int*);
	printf("Sizeof int*: %d\n", size);

	size = sizeof(long*);
	printf("Sizeof long*: %d\n", size);

	size = sizeof(float*);
	printf("Sizeof float*: %d\n", size);

	size = sizeof(double*);
	printf("Sizeof double*: %ld\n", size);

	size = sizeof(scores);
	printf("Sizeof scores: %ld\n", size);

	int elementCount = sizeof(scores) / sizeof(scores[0]);
	printf("Number of elements in the scores array: %ld\n", elementCount);

	function1(scores);
	function2(scores);

	return 0;
}

void function1(int array[])
{
	int size = sizeof(array);
	printf("Array notation: Sizeof array parameter: %d\n", size);

	int elementCount = sizeof(array) / sizeof(array[0]);
	printf("Number of elements in the array: %ld\n", elementCount);
}

void function2(int* array)
{
	int size = sizeof(array);
	printf("Pointer notation: Sizeof array parameter: %d\n", size);

	int elementCount = sizeof(array) / sizeof(array[0]);
	printf("Number of elements in the array: %ld\n", elementCount);
}