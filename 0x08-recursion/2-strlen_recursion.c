#include "main.h"

/**
 * Recursive function that returns the length of a string.
 * @s: The string to be measured.
 *
 * Return: The length of the string.
 */
int _strlen_recursion(char *s)
{
    int length = 0;

    // Base case: check if the current character is not null
    if (*s != '\0')
    {
        length++;                           // Increment length for the current character
        length += _strlen_recursion(s + 1);  // Recursive call with the next character
    }

    return length;
}
