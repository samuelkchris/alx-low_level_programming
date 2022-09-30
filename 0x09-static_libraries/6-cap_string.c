#include "main.h"
/**
 * cap_string - capitalizes all words of a string
 * @string: input string.
 * Return: the pointer to dest.
 */

char *cap_string(char *string)
{
	int count = 0, i;
	int separate_words[] = {32, 9, 10, 44, 59, 46, 33, 63, 34, 40, 41, 123, 125};

	if (*(string + count) >= 97 && *(string + count) <= 122)
		*(string + count) = *(string + count) - 32;
	count++;
	while (*(string + count) != '\0')
	{
		for (i = 0; i < 13; i++)
		{
			if (*(string + count) == separate_words[i])
			{
				if ((*(string + (count + 1)) >= 97) && (*(string + (count + 1)) <= 122))
					*(string + (count + 1)) = *(string + (count + 1)) - 32;
				break;
			}
		}
		count++;
	}
	return (string);
}
