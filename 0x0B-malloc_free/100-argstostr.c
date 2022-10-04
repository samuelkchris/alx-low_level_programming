#include "main.h"
#include <stdlib.h>

/**
 * argstostr - creates an array of chars.
 * @ac: size of the array.
 * @av: storaged char
 * Return: str
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, k = 0, len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			len++;
	}
	len += ac;

	str = malloc(sizeof(char) * len + 1);

	if (str == NULL)
		return (NULL);


	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			str[k++] = av[i][j];

		str[k++] = '\n';
	}
	str[len] = '\0';

	return (str);
}
