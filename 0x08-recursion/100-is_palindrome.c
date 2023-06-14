#include "main.h"
#include <string.h>

int is_palindrome(char *s);
bool check_palindrome(char *start, char *end);

/**
* is_palindrome - prints a palindrone
* @s: The string to be measured
*
* Return: 1 for an empty string (it's a palindrome)
* Call helper function
*/

int is_palindrome(char *s)
{
	if (*s == '\0')
	{
		return (1);
	}

	return (check_palindrome(s, s + strlen(s) - 1));
}

/**
 * check_palindrome - Checks if the string is a palindrone
 * @start: The start pointer
 * @end: The end pointer
 *
 * Return: true if all characters have been checked
* false if characters don't match
* Recursive call with next characters
*/

bool check_palindrome(char *start, char *end)
{
	if (start >= end)
	{
		return (true);
	}
	if (*start != *end)
	{
		return (false);
	}

	return (check_palindrome(start + 1, end - 1));
}
