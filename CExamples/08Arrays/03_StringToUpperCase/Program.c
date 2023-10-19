#include <stdio.h>

#define ARRAY_SIZE 3

void to_upper(char*);

char chars[] = { "Howdy" };

void main()
{
	to_upper(chars);
	
}

void to_upper(char* char_array)
{
	char c = *char_array;

	while (c != 0)
	{
		if (c >= 'a' && c <= 'z')
		{
			c -= 32;
		}
	}

}