#include <main.h>

/**
* wildcmp - Compares two strings, considering wildcard characters
* @s1: First string to be compared
* @s2: Second string to be compared
*
* Return: 1 if both strings are empty (considered identical)
*	Call helper function
*/

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (1);
	}

	return (compare(s1, s2));
}

/**
* compare - Compares and checks the next character
* @s1: First string to be compared
* @s2: Second string to be compared
*
* Return: 1 if the remaining of s2 is only '*'
*	0 if no match is found
*	0 if characters don't match or one of the strings ends
*/

bool compare(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '\0')
		{
			return (1);
		}
		while (*s1 != '\0')
		{
			if (wildcmp(s1, s2 + 1))
			{
				return (1);
			}
			s1++;
		}

		return (0);
	}
	if (*s1 == '\0' || *s2 == '\0' || *s1 != *s2)
	{
		return (0);
	}

	return (compare(s1 + 1, s2 + 1));
}
