#include "main.h"
/**
 * _strcmp - compares two strings.
 * @s1: first string.
 * @s2: second string.
 * Return: 0 if s1 = s2 else,
 * returns another number.
 */

int _strcmp(char *s1, char *s2)
{
	int index = 0, num = 0;

	while (num == 0)
	{
		if ((*(s1 + index) == '\0') && (*(s2 + index) == '\0'))
			break;
		num = *(s1 + index) - *(s2 + index);
		index++;
	}

	return (num);
}
