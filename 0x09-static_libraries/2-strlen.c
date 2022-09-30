#include "main.h"

/**
 * _strlen - returns the string length
 * @str: input string.
 * Return: length of a string.
 */
int _strlen(char *str)
{
	int count = 0;

	while (*(str + count) != '\0')
		count++;
	return (count);
}
