#define ARRAY_SIZE 3

unsigned char array[] = { 1,2,3 };

int main()
{
	int index = 0;
	unsigned char total = 0;

	for (index = 0; index < ARRAY_SIZE; index++)
	{
		total += array[index];
	}

	return total;
}