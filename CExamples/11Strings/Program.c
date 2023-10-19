#include <stdio.h>

#define STRING_SIZE 10

int main() 
{	
	//Input
	char string[STRING_SIZE] = {0};
	
	printf("Enter a string or characters: ");
	//int returnValue = scanf("%s", string); //Only reads up to the space character
	char* returnValue = fgets(string, sizeof(string), stdin);

	if (returnValue == NULL) return -1;

	//Process & Output
	int index = 0;
	
	printf("Echoing string input: %s", string);
	printf("\n");
	
	while (string[index] != '\0')
	{
		char character = string[index];
		
		printf("Index: %d \t Character: %c", index, character);
		printf("\n");
		
		index++;
	}
	
	char c = getchar();

	return 0;
}
