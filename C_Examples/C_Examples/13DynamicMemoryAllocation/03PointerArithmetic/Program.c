#pragma warning(disable:6011) //Turn off warning: possible dereferencing of null pointer
#include <stdio.h>
#include <stdlib.h>

void main()
{

	const int ARRAY_SIZE = 5;
	const int SCORE_OFFSET = 50;
	const int MAX_SCORE = 100;

	int* scores = (int*)malloc(sizeof(int) * ARRAY_SIZE);

	//Input
	for (int index = 0; index < ARRAY_SIZE; index++)
	{
		int score = SCORE_OFFSET + rand() % (MAX_SCORE - SCORE_OFFSET);
		scores[index] = score;
	}

	//Process
	int* ptr = scores;

	int total = 0;

	for (int index = 0; index < ARRAY_SIZE; index++)
	{
		total += *ptr;
		ptr++;
	}

	double average = (double)total / ARRAY_SIZE;

	//Output
	printf("Average: %lf\n", average);

	free(scores);

}