#include <stdio.h>

/**
 * main - Entry point
 * Return: Success (0)
 */

int main(void)
{
	int i;

	for (i = 0; i < 26; i++)
	{
		putchar(i + 'a');
	}
	for (i = 0; i < 26; i++)
	{
		putchar(i + 'A');
	}

	putchar('\n');
	return (0);
}
