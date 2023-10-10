#define ARRAY_SIZE 3

int array[] = { 1,2,3 };

int main()
{
	int index = 0;
	int total = 0;
	int* ptr = array;
	
	for (index = 0; index < ARRAY_SIZE; index++)
	{
		total += *ptr;
		ptr++;
	}

	return total;
}