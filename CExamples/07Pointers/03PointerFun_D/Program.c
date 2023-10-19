#pragma warning(disable:6011) //Turn off warning: possible dereferencing of null pointer
#include <stdio.h>

void GetLargest(int** source1, int** source2, int*** destination);

int main()
{
	int x = 1;
	int y = 2;
	int* ptr_1 = &x;
	int* ptr_2 = &y;
	int** ptr_3 = NULL;

	printf("x = 1, y = 2, ptr_1 = &x, ptr_2 = &y, ptr_3 = NULL\n\n");
	printf("&x:      %p\n", &x);
	printf("&y:      %p\n", &y);
	printf("&ptr_1:  %p\n", &ptr_1);
	printf("&ptr_2:  %p\n", &ptr_2);
	printf("&ptr_3:  %p\n", &ptr_3);
	printf("ptr_1:   %p\n", ptr_1);
	printf("ptr_2:   %p\n", ptr_2);
	printf("ptr_3:   %p\n", ptr_3);
	printf("*ptr_1:  %d\n", *ptr_1);
	printf("*ptr_2:  %d\n\n", *ptr_2);
	//printf("*ptr_3:  %p\n", *ptr_3);
	//printf("**ptr_3: %d\n\n", **ptr_3);

	GetLargest(&ptr_1, &ptr_2, &ptr_3);

	printf("ptr_3:                         %p\n", ptr_3);
	printf("Address of pointer to largest: %p\n", ptr_3);
	printf("Address of largest:            %p\n", *ptr_3);
	printf("Largest value:                 %d\n", **ptr_3);

	return 0;
}

void GetLargest(int** source1, int** source2, int*** destination)
{
	if (**source1 > **source2) *destination = source1;
	else *destination = source2;
}
