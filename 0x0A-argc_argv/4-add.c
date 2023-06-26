#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of strings representing the arguments.
 *
 * Return: 0 on success, 1 on error
 */

int main(int argc, char *argv[])
{
	int add = 0;
	int i;
	int j;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		char *num = argv[i];

	for (j = 0; num[j] != '\0'; j++)
	{
		if (!isdigit(num[j]))
		{
			printf("Error\n");
			return (1);
		}
	}

		/* Convert the number to an integer and add it */
		add += atoi(num);
	}

	/* Print the result */
	printf("%d\n", add);

	return (0);
}
