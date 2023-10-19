#define ARRAY_SIZE 3

int array[] = { 1,2,3 };

int main()
{
	//int array[] = { 1,2,3 };

	int index = 0;
	int total = 0;

	for (index = 0; index < ARRAY_SIZE; index++)
	{
		total += array[index];
	}

	return total;
}