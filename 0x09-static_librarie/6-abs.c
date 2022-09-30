#include "main.h"

/**
 *_abs - Check main
 * @i: An integer input
 * Description: returns absolute value of an integer
 * Return: Absolut value of integer
 */
int _abs(int i)
{
	if (i >= 0)
	{
		return (i);
	}
	else
	{
		return (i * -1);
	}
}
