#include <stdio.h>

/**
 * main - Entry point
 * Return: Success (0)
 */

int main(void)
{
	int i;

	for (i = 0; i < 16; i++)
	{
		putchar(i < 10 ? i + '0' : i + 'a' - 10);
	}

	putchar('\n');
	return (0);
}
