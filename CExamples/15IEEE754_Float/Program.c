
/*This demonstrates how the float data type is represented and implemented.
Most floating-point processors use the IEEE 754 Floating-point standard.  For a
IEEE 754 32-bit float, the most significant bit (left bit, high bit) is used to
represent the sign of the value,
either negative or positive, the next 8 bits are used to represent the exponent in a
biased-127 representation, and the last 23 bits are used to represent the normalized
mantissa,
without the leading "1", which is the fractional part of the mantissa.

For example, the value 1.0 is represented as:
sign:			0
exponent:		01111111
fraction:		0000000000000000000000
representation:	0 01111111 00000000000000000000000

For example, the value 1.5 is represented as:
sign:			0
exponent:		01111111
fraction:		1000000000000000000000
representation:	0 01111111 10000000000000000000000

For example, the value 2.0 is represented as:
sign:			0
exponent:		10000000
fraction:		0000000000000000000000
representation:	0 10000000 00000000000000000000000

For example, the value 2.5 is represented as:
sign:			0
exponent:		10000000
fraction:		0100000000000000000000
representation:	0 10000000 01000000000000000000000

For example, the value -2.5 is represented as:
sign:			1
exponent:		10000000
fraction:		0100000000000000000000
representation:	1 10000000 01000000000000000000000


*/
#include <stdio.h>
#include <stdint.h>

#define		FLOAT_VALUE 1.0f
#define		BITS_PER_BYTE 8
#define		BITS_PER_FLOAT (4 * BITS_PER_BYTE)
#define		EXPONENT_BITS 8
#define		FRACTION_BITS 23

void main()
{
	
	unsigned int mask = 0;
	unsigned char bit = '\0';
	unsigned char signBit = '\0';
	unsigned char exponent[EXPONENT_BITS + 1] = { 0 };
	unsigned char fraction[FRACTION_BITS + 1] = { 0 };

	//The float value to be converted to binary
	float f = FLOAT_VALUE;
	void* ptr = (void*)(&f);
	unsigned int* ptr_uint = (unsigned int*)ptr;
	unsigned int number = *ptr_uint;

	//Get the most significant bit (sign bit):
	mask = 1;
	mask = mask << BITS_PER_FLOAT - 1;
	mask = mask & number;
	mask = mask >> BITS_PER_FLOAT - 1;
	signBit = (char)(mask + 48);

	//mask the next 8 bits of for the exponent:
	mask = 1;
	mask = mask << BITS_PER_FLOAT - (EXPONENT_BITS + 1);
	for (int i = 1; i <= EXPONENT_BITS; i++) {
		int result = number & mask;

		if (result == 0)
			bit = 'O';
		else
			bit = '1';

		exponent[EXPONENT_BITS - i] = bit;

		mask = mask << 1;//Shift bits over to the left one position.
	}

	//mask the next 23 bits of for the fraction:
	mask = 1;
	for (int i = 1; i <= FRACTION_BITS; i++)
	{
		int result = number & mask;

		if (result == 0)
			bit = 'O';
		else
			bit = '1';

		fraction[FRACTION_BITS - i] = bit;

		mask = mask << 1;//Shift bits over to the left one position.
	}

	printf("Sizeof unsigned int: %d\n", sizeof(unsigned int));
	printf("Sizeof float: %d\n\n", sizeof(float));

	printf("Binary representation of %f is:\n", FLOAT_VALUE);
	printf("Sign bit: \t\t\t%c\n", signBit);
	printf("Biased-127 exponent: \t\t%s\n", exponent);
	printf("Normalized mantissa: \t\t%s\n", fraction);
	printf("Gives a binary representation: \t%c %s %s\n", signBit, exponent, fraction);

	int c = getchar();
}