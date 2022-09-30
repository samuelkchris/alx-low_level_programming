#include "main.h"

/**
 * _isalpha - main
 * @c: The character in ASCII code
 * description: check for lowercase or uppercase character
 * Return: 1 for lowercase or uppercase character
 * 0 for the rest
 */
int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
	{
		return (1);
	}
	else
	{
		return (0);
	}
	_putchar('\n');
}
