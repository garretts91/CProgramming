#include <stdio.h>

int main() 
{
	//Local Variables
	int numberOne = 0;
	int numberTwo = 0;
	
	//Input
	printf("Enter number one: ");
	int returnValue = scanf("%d", &numberOne);

	printf("Enter number two: ");
	returnValue = scanf("%d", &numberTwo);

	//Process
	numberTwo = ~numberTwo;
	numberTwo = numberTwo + 1;
	int result = numberOne + numberTwo;

	//Output
	printf("Number one - number two: %d", result);
	printf("\n");

	char c = getchar();
	c = getchar();
}