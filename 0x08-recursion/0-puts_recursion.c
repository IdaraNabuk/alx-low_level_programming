#include "main.h"

/**
 * Recursive function that prints a string, followed by a new line.
 * @s: The string to be printed.
 */

void _puts_recursion(char *s)
{
    // Base case: check if the current character is the null terminator
    if (*s == '\0')
    {
        _putchar('\n');  // Print a new line
        return;         // Exit the function
    }

    _putchar(*s);               // Print the current character
    _puts_recursion(s + 1);     // Recursive call with the next character
}
