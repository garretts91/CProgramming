#pragma warning(disable:6011) //Turn off warning: possible dereferencing of null pointer
#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y);

int main()
{
	int* x = (int*)malloc(sizeof(int));

	if (x != NULL) *x = 1;

	int* y = (int*)malloc(sizeof(int));
	if (y != NULL) *y = 2;

	printf("Address of x (&x): %p\n", x);
	printf("Dereferencing x: %d\n\n", *x);

	printf("Address of y (&y): %p\n", y);
	printf("Dereferencing y: %d\n\n", *y);
	
	printf("Swapping the values that x and y point to...\n\n");

	swap(x, y);

	printf("Address of x (&x): %p\n", x);
	printf("Dereferencing x: %d\n\n", *x);

	printf("Address of y (&y): %p\n", y);
	printf("Dereferencing y: %d\n\n", *y);

	//Suspends program execution.
	int c = getchar();

	return 0;
}

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}