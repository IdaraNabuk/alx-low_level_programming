#include <stdio.h>

/**
 * main -Prints all arguments it receives.
 * @argc: NUmber of arguments.
 * @argv: arr arguments.
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	for (int i = 0; i < argc; ++i)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}
