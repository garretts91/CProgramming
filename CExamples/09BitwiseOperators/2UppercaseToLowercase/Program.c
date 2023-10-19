#include <stdio.h>

void SpitBits(unsigned char value);

int main() 
{
	const char SIXTH_BIT_MASK = 0x20;

	//Input
	printf("Enter an uppercase letter: ");
	char upperCaseLetter = getchar();
	
	//Process
	char lowerCaseLetter = upperCaseLetter | SIXTH_BIT_MASK;
	
	//Output
	printf("Binary representation of the uppercase character \'%c\' is: ", upperCaseLetter);
	SpitBits(upperCaseLetter);
	
	printf("Binary representation of the lowercase character \'%c\' is: ", lowerCaseLetter);
	SpitBits(lowerCaseLetter);		

	char c = getchar();
	c = getchar();
}

void SpitBits(unsigned char value)
{
	unsigned char mask = 0x80;

	for (int bitCount = 0; bitCount < 8; bitCount++)
	{
		unsigned char result = value & mask;

		if (result != 0)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}

		mask = mask >> 1;
	}
	
	printf("\n");
}