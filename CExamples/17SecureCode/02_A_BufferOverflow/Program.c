/*
Find the bug!
*/

#include <stdio.h>
#include <string.h>

void populate(char string[], char starting_char, int size);

#define STRING_SIZE 4
#define PASSWORD_SIZE 10

char string_1[STRING_SIZE] = { 0 };
char string_2[STRING_SIZE] = { 0 };
char password[PASSWORD_SIZE] = { 0 };

int main() 
{	
	strcpy(password, "monkey");

	populate(string_1, 'A', STRING_SIZE);
	populate(string_2, 'E', STRING_SIZE);
	
	printf("String 1: %s \n", string_1);
	printf("String 2: %s \n", string_2);
	printf("Password: %s \n", password);

	return 0;
}

void populate(char string[], char starting_char, int size)
{
	for (int index = 0; index <= size; index++)
	{
		string[index] = starting_char + index;
	}
}
