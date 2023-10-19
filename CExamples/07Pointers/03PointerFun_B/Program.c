#pragma warning(disable:6011) //Turn off warning: possible dereferencing of null pointer
#include <stdio.h>

int main()
{
	int x = 1;
	int y = 2;

	int* ptr_1 = &x;
	int* ptr_2 = &y;
	int** ptr_3 = &ptr_1;

	printf("x = 1, y = 2, ptr_1 = &x, ptr_2 = &y, ptr_3 = &ptr_1\n\n");
	printf("&x:      %p\n", &x);
	printf("&y:      %p\n", &y);
	printf("&ptr_1:  %p\n", &ptr_1);
	printf("&ptr_2:  %p\n", &ptr_2);
	printf("&ptr_3:  %p\n", &ptr_3);
	printf("ptr_1:   %p\n", ptr_1);
	printf("ptr_2:   %p\n", ptr_2);
	printf("ptr_3:   %p\n", ptr_3);
	printf("*ptr_1:  %d\n", *ptr_1);
	printf("*ptr_2:  %d\n", *ptr_2);
	printf("*ptr_3:  %p\n", *ptr_3);
	printf("**ptr_3: %d\n\n", **ptr_3);

	ptr_1 = ptr_2;
	y = 3;

	printf("x = 1, y = 3, ptr_1 = ptr_2 = &y, ptr_3 = &ptr_1\n\n");
	printf("&x:      %p\n", &x);
	printf("&y:      %p\n", &y);
	printf("&ptr_1:  %p\n", &ptr_1);
	printf("&ptr_2:  %p\n", &ptr_2);
	printf("&ptr_3:  %p\n", &ptr_3);
	printf("ptr_1:   %p\n", ptr_1);
	printf("ptr_2:   %p\n", ptr_2);
	printf("ptr_3:   %p\n", ptr_3);
	printf("*ptr_1:  %d\n", *ptr_1);
	printf("*ptr_2:  %d\n", *ptr_2);
	printf("*ptr_3:  %p\n", *ptr_3);
	printf("**ptr_3: %d\n\n", **ptr_3);

	ptr_1 = &x;
	ptr_2 = ptr_1;

	printf("x = 1, y = 3, ptr_1 = &x, ptr_2 = ptr_1, ptr_3 = &ptr_1\n\n");
	printf("&x:      %p\n", &x);
	printf("&y:      %p\n", &y);
	printf("&ptr_1:  %p\n", &ptr_1);
	printf("&ptr_2:  %p\n", &ptr_2);
	printf("&ptr_3:  %p\n", &ptr_3);
	printf("ptr_1:   %p\n", ptr_1);
	printf("ptr_2:   %p\n", ptr_2);
	printf("ptr_3:   %p\n", ptr_3);
	printf("*ptr_1:  %d\n", *ptr_1);
	printf("*ptr_2:  %d\n", *ptr_2);
	printf("*ptr_3:  %p\n", *ptr_3);
	printf("**ptr_3: %d\n\n", **ptr_3);

	return 0;
}
