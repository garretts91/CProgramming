/*
Proper use of scanf_s
Compile for 32 - bit and 64 - bit
https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/scanf-s-scanf-s-l-wscanf-s-wscanf-s-l?view=msvc-170
*/

#include <stdio.h>
#include <string.h>

#define STRING_SIZE 4
#define PASSWORD_SIZE 10

char userId[STRING_SIZE] = {0};
char password[PASSWORD_SIZE] = { 0 };
	
int main() 
{	
	strcpy_s(password, PASSWORD_SIZE, "monkey");
	
	//Input
	printf("Enter your user ID: ");
	int returnValue = scanf_s("%s", userId, STRING_SIZE);
	
	//Process & Output
	printf("User ID: %s", userId);
	printf("\n");
	printf("Password: %s", password);

	return 0;
}
