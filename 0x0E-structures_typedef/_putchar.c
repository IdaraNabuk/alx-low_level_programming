#include <unistd.h>

/**
 * _putchar.c - Writes the character c to standout
 */

int _putchar(char c)
{
	return(write(1, &c, 1));
}
