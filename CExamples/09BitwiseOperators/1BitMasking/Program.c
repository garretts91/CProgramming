int main() 
{
	unsigned char letter = 'A';
	unsigned char mask = 0x80;
	unsigned char masked_result = 0;
	unsigned char bits = 0;

	for(int bitCount = 0; bitCount < 8; bitCount++)
	{
		masked_result = letter & mask;

		bits = bits | masked_result;

		mask = mask >> 1;
	}

	return bits;
}