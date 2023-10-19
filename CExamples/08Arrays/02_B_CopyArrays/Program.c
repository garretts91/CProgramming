#include <stdio.h>

#define ARRAY_SIZE 2
#define RESULT_ARRAY_SIZE ARRAY_SIZE * 2

int array_1[] = { 1,3 };
int array_2[] = { 2,4};
int array_3[ARRAY_SIZE * 2] = { 0 };
int array_1_index = 0;
int array_2_index = 0;
int array_3_index = 0;

void main()
{
	while (array_3_index < RESULT_ARRAY_SIZE)
	{
		if (array_1_index < ARRAY_SIZE && array_2_index < ARRAY_SIZE)
		{
			if (array_1[array_1_index] < array_2[array_2_index])
			{
				array_3[array_3_index] = array_1[array_1_index];
				array_1_index++;
				array_3_index++;
			}
			else if (array_2[array_2_index] < array_1[array_1_index])
			{
				array_3[array_3_index] = array_2[array_2_index];
				array_2_index++;
				array_3_index++;
			}
			else if (array_1[array_1_index] == array_2[array_2_index])
			{
				array_3[array_3_index] = array_1[array_1_index];
				array_1_index++;
				array_3_index++;

				array_3[array_3_index] = array_2[array_2_index];
				array_2_index++;
				array_3_index++;
			}
		}
		else if (array_1_index < ARRAY_SIZE)
		{
			array_3[array_3_index] = array_1[array_1_index];
			array_1_index++;
			array_3_index++;
		}
		else if (array_2_index < ARRAY_SIZE)
		{
			array_3[array_3_index] = array_2[array_2_index];
			array_2_index++;
			array_3_index++;
		}
	}
	
}