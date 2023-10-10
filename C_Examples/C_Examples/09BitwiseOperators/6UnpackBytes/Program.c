#include <stdio.h>

void UnpackBytes(unsigned short value, unsigned char* lowOrderByte, unsigned char* highOrderByte);

int main() 
{
	//Input
	unsigned short number = 0xABCD;

	//Process
	unsigned char lowOrderByte = 0;
	unsigned char highOrderByte = 0;

	UnpackBytes(number, &lowOrderByte, &highOrderByte);

	//Output
	printf("Low order byte:  %#x", lowOrderByte);
	printf("\n");
	
	printf("High order byte: %#x", highOrderByte);
	printf("\n");

	char c = getchar();
}

void UnpackBytes(unsigned short value, unsigned char* lowOrderByte, unsigned char* highOrderByte)
{
	unsigned short mask = 0x00FF;

	unsigned short result = value & mask;

	*lowOrderByte = (unsigned char)result;
	
	mask <<= 8;

	result = value & mask;

	result = result >> 8;
	
	*highOrderByte = (unsigned char)result;
}
