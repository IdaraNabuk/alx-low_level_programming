#include "main.h"

/**
 * _pow_recursion -  Returns the value of x raised to the power of y.
 * @x: The number to be raised.
 * @y: The power.
 *
 * Return: If y < 0, -1 to indicate an error for negative exponent
 *	If y == 0, Return 1 as the base case for x^0
 *	If y > 0, Recursive call to calculate power
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	} else if (y == 0)
	{
		return (1);
	}

	return (x * _pow_recursion(x, y - 1));
}
