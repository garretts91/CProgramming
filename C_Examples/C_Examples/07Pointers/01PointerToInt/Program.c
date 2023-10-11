#pragma warning(disable:6011) //Turn off warning: possible dereferencing of null pointer
#include <stdio.h>


int main()
{
	int x = 1;

	int* ptr = &x;

	printf("Address of x (&x): %p\n", &x);
	printf("Pointer value (ptr): %p\n", ptr);
	printf("Dereferencing ptr: %d\n\n", *ptr);

	*ptr = 2;

	printf("Address of x (&x): %p\n", &x);
	printf("Pointer value (ptr): %p\n", ptr);
	printf("Dereferencing ptr: %d\n\n", *ptr);

	//Suspends program execution.
	int c = getchar();

	return 0;
}
