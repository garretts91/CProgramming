#pragma warning(disable:6011) //Turn off warning: possible dereferencing of null pointer
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size = sizeof(char);
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
	printf("Sizeof double: %d\n", size);

	size = sizeof(void*);
	printf("Sizeof void*: %d\n", size);
	
	size = sizeof(char*);
	printf("Sizeof char*: %d\n", size);

	size = sizeof(short*);
	printf("Sizeof short*: %d\n", size);

	size = sizeof(int*);
	printf("Sizeof int*: %d\n", size);

	size = sizeof(long*);
	printf("Sizeof long*: %d\n", size);
	
	//Suspends program execution.
	int c = getchar();

	return 0;
}
