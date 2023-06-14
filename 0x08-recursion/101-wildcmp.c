#include "main.h"

/**
 * wildcmp - Compares two strings and checks
 * if they can be considered identical
 * @s1: The first string to compare.
 * @s2: The second string to compare (may contain wildcard character '*').
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise.
 */

int wildcmp(char *s1, char *s2)
{
	/* If both strings are empty, they are considered identical */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* If s2 is the wildcard character '*', check for all possibilities */
	if (*s2 == '*')
	{
		/* If the remaining of s2 is only '*', consider it identical */
		if (*(s2 + 1) == '\0')
			return (1);

		/* Recursive calls to check all possibilities */
		if (*s1 != '\0' && wildcmp(s1 + 1, s2) == 1)
			return (1);
		if (wildcmp(s1, s2 + 1) == 1)
			return (1);
	}

	/* If characters match or one of the strings ends, continue the comparison */
	if (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (1);
		return (wildcmp(s1 + 1, s2 + 1));
	}

	return (0); /* Strings are not identical */
}
