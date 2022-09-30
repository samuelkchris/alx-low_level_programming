#include "main.h"
#include <stdio.h>
/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte, to the
 * buffer pointed to by dest.
 * @destination: destination.
 * @source: source.
 * Return: the pointer to dest.
 */
char *_strcpy(char *destination, char *source)
{
	int count = 0;

	while (count >= 0)
	{
		*(destination + count) = *(source + count);
		if (*(source + count) == '\0')
			break;
		count++;
	}
	return (destination);
}
