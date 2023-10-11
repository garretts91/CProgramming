/*
Compile for 32 - bit and 64 - bit
*/

#include <stdio.h>
#include <string.h>

#define STRING_SIZE 4
#define PASSWORD_SIZE 12

char string_1[STRING_SIZE] = { 0 };
char string_2[STRING_SIZE] = { 0 };
char password[PASSWORD_SIZE] = { 0 };

int main() 
{	
	char* s1 = "ABCDE";
	char* s2 = "EFGHI";

	strcpy_s(password, PASSWORD_SIZE, "monkey");
	strcpy_s(string_1, STRING_SIZE, s1);
	strcpy_s(string_2, STRING_SIZE, s2);

	printf("String 1: %s \n", string_1);
	printf("String 2: %s \n", string_2);
	printf("Password: %s \n", password);

	return 0;
}

