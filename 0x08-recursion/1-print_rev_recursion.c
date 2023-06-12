#include "main.h"

/**
 * Recursive function that prints a string in reverse.
 * @s: The string to be printed.
 */
void _print_rev_recursion(char *s)
{
    // Base case: check if the current character is not null
    if (*s != '\0')
    {
        _print_rev_recursion(s + 1);  // Recursive call with the next character
        _putchar(*s);  // Print the current character
    }
}
