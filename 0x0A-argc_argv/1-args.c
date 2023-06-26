#include <stdio.h>

/**
  * main - Prints number of arguments
  * @argc: The argument count
  * @argv: Argument vector
  *
  * Return: 0 always
  */

int main(int argc, char *argv[])
{
	(void)argv;

	printf("%d\n", argc - 1);

	return (0);
}
