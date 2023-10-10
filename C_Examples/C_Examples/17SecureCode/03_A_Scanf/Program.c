/*
Find the bug!
*/

#include <stdio.h>
#include <string.h>

#define STRING_SIZE 4
#define PASSWORD_SIZE 10

char userId[STRING_SIZE] = {0};
char password[PASSWORD_SIZE] = { 0 };
	
int main() 
{	
	strcpy(password, "monkey");
	
	//Input
	printf("Enter your user ID: ");
	int returnValue = scanf("%s", userId);

	//Process & Output
	printf("User ID: %s", userId);
	printf("\n");	
	printf("Password: %s", password);

	return 0;
}
