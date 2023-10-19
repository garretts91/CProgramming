#include <stdio.h>

unsigned short PackBytes(unsigned char c1, unsigned char c2);

int main() 
{
	//Input
	unsigned char c1 = 'A';
	unsigned char c2 = 'B';

	//Process
	unsigned short result = PackBytes(c1, c2);

	//Output
	printf("%#X", result);
	
	printf("\n");

	char c = getchar();
}

unsigned short PackBytes(unsigned char c1, unsigned char c2)
{
	unsigned short result = c1;

	result = result << 8;
	//result <<= 8;

	result = result | c2;
	//result |= c2;

	return result;
}
