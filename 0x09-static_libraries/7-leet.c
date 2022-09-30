#include "main.h"
/**
 * leet - encodes a string into 1337
 * @string: input string.
 * Return: the pointer to dest.
 */

char *leet(char *string)
{
	int count = 0, i;
	int lowercase[] = {97, 101, 111, 116, 108};
	int uppercase[] = {65, 69, 79, 84, 76};
	int numbers[] = {52, 51, 48, 55, 49};

	while (*(string + count) != '\0')
	{
		for (i = 0; i < 5; i++)
		{
			if (*(string + count) == lowercase[i] || *(string + count) == uppercase[i])
			{
				*(string + count) = numbers[i];
				break;
			}
		}
		count++;
	}

	return (string);
}
