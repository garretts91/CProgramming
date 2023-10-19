#include <stdio.h>
#include "SimpleStruct.h"

void main()
{
	struct SimpleStruct simpleStruct = { 0,0 };

	SimpleStructInitialize(&simpleStruct, 1, 2);

	printf("x: %d\n", simpleStruct.x);
	printf("y: %d\n", simpleStruct.y);

	int c = getchar();
}