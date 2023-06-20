#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * _strdup - Duplicates a string
 * @str: String to be duplicated
 *
 * Description: Allocates memory for a new string
 *	and copies the contents of `str` into it.
 * Return: Returns a pointer to the newly allocated string.
 *	Returns NULL if memory allocation fails or `str` is NULL.
 */

char *_strdup(char *str)
{
	int len = 0;
	char *duplicate;
	int i;

	if (str == NULL)
	return (NULL);

	while (str[len] != '\0')
	len++;

	duplicate = malloc(sizeof(char) * (len + 1));

	if (duplicate == NULL)
	return (NULL);

	for (i = 0; i <= len; i++)
	duplicate[i] = str[i];

	return (duplicate);
}

/**
 * new_dog - Creates a new dog with the given name, age, and owner
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 *
 * Description: Allocates memory for a new struct dog,
 *              copies the name and owner strings, and initializes the age.
 * Return: Returns a pointer to the newly created dog.
 *	Returns NULL if memory allocation fails.
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog = malloc(sizeof(dog_t));

	if (name == NULL || owner == NULL)
	return (NULL);

	if (new_dog == NULL)
	return (NULL);

	new_dog->name = _strdup(name);
	if (new_dog->name == NULL)
	{
		free(new_dog);
		return (NULL);
	}

	new_dog->owner = _strdup(owner);
	if (new_dog->owner == NULL)
	{
		free(new_dog->name);
		free(new_dog);
		return (NULL);
	}
	new_dog->age = age;

	return (new_dog);
}
