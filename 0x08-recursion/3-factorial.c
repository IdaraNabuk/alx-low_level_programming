#include "main.h"

/**
 * factorial -  Returns the factorial of a given number.
 * @n: The number to find the factorial of.
 *
 * Return: If n < 0, -1 to indicate an error for negative numbers
 *	If n == 0, 1 as the base case for factorial of 0
 *	If n > 0, Recursive call to calculate factorial
 */

int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	} else if (n == 0)
	{
		return (1);
	}

	return (n * factorial(n - 1));
}
