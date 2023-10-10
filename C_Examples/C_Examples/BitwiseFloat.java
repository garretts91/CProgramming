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

public class Main
{
	public static void main(String[] args)
	{
		final float		FLOAT_VALUE = 1.5f;
		final int		BITS_PER_BYTE = 8;
		final int		BITS_PER_FLOAT = 4 * BITS_PER_BYTE;
		final int		EXPONENT_BITS = 8;
		final int		FRACTION_BITS = 23;
		int				mask = 0;
		char			bit = '\0';
		char			signBit = '\0';
		char[ ]			exponent = new char[EXPONENT_BITS + 1];
		char[ ]			fraction = new char[FRACTION_BITS + 1];
	
		//The float value to be converted to binary
		int number= Float.floatToIntBits(FLOAT_VALUE);

		//Get the most significant bit (sign bit):
		mask = 1;
		mask = mask << BITS_PER_FLOAT - 1;
		mask = mask & number;
		mask = mask >>> BITS_PER_FLOAT - 1;
		signBit = (char)(mask + 48);

		//mask the next 8 bits of for the exponent:
		mask = 1;
		mask = mask << BITS_PER_FLOAT - (EXPONENT_BITS + 1);
		for(int i=1;i <= EXPONENT_BITS;i++){
			int result = number & mask;
			
			if(result == 0)
				bit = 'O';
			else
				bit = '1';
			
			exponent[EXPONENT_BITS - i] = bit;
			
			mask = mask << 1;//Shift bits over to the left one position.
		}

		//mask the next 23 bits of for the fraction:
		mask = 1;
		for(int i=1; i <= FRACTION_BITS; i++)
		{
			int result = number & mask;
			
			if(result == 0)
				bit = 'O';
			else
				bit = '1';
		
			fraction[FRACTION_BITS - i] = bit;
			
			mask = mask << 1;//Shift bits over to the left one position.
		}

		System.out.println("Binary representation of " + FLOAT_VALUE + " is:\n");
		System.out.println("Sign bit: \t\t\t" + signBit);
		System.out.println("Biased-127 exponent: \t\t" + exponent);
		System.out.println("Normalized mantissa: \t\t" + fraction);
		System.out.println("Gives a binary representation: " + signBit + ' ' 
						   + exponent + ' ' + fraction);

	    Input.pause();
	}
}