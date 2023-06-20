#include <stdio.h>
#include "dog.h"

/**
 * print_dog - Prints the details of a struct dog
 * @d: Pointer to the struct dog variable to be printed
 *
 * Description: Prints the name, age, and owner of the dog.
 *              If an element is NULL, it prints (nil) instead.
 *              If d is NULL, it does nothing.
 */

void print_dog(struct dog *d)
{
	if (d == NULL)
	return;

	printf("Name: %s\n", (d->name != NULL) ? d->name : "(nil)");
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", (d->owner != NULL) ? d->owner : "(nil)");
}
