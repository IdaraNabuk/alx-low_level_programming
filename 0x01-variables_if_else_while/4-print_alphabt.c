#include <stdio.h>

/**
 * main - Entry point
 * Return: Success (0)
 */

int main(void)
{
	int i;

	for (i = 'a'; i <= 'z'; i++)
	{
		if (i == 'q' || i == 'e')
		{
			continue;
		}
		putchar(i);
	}

	putchar('\n');
	return (0);
}
