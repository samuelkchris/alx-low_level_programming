#include "main.h"
/**
 * string_toupper-changes all lowercase letters
 * to uppercase.
 * @string: input string.
 * Return: the pointer to dest.
 */

char *string_toupper(char *string)
{
	int count = 0;

	while (*(string + count) != '\0')
	{
		if ((*(string + count) >= 97) && (*(string + count) <= 122))
			*(string + count) = *(string + count) - 32;
		count++;
	}

	return (string);
}
