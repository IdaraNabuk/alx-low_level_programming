#include <stdio.h>

/**
 * main - Entry point
 * Return: Success (0)
 */

int main(void)
{
	int i;

	for (i = 25; i >= 0; i--)
	{
		putchar('a' + i);
	}

	putchar('\n');
	return 0;
}
