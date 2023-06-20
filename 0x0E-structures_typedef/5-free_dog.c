#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Frees the memory allocated for a struct dog
 * @d: Pointer to the struct dog to be freed
 *
 * Description: Frees the memory allocated for the name and owner strings,
 *              and then frees the memory allocated for the struct dog itself.
 *              Does nothing if the input pointer is NULL.
 */

void free_dog(dog_t *d)
{
	if (d == NULL)
	return;

	free(d->name);
	free(d->owner);
	free(d);
}
