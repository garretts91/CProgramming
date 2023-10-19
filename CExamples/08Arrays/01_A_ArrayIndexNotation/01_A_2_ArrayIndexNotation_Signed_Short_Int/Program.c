#define ARRAY_SIZE 3

short int array[] = { 1,2,3 };

int main()
{
	short int index = 0;
	short int total = 0;

	for (index = 0; index < ARRAY_SIZE; index++)
	{
		total += array[index];
	}

	return total;
}