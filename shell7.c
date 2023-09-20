#include "ourshell.h"
/**
 * func_memcpy - function that copies information between void pointers.
 * @newptr: the destination pointer.
 * @ptr: the source pointer.
 * @size: size of new pointer.
 * Return: no return.
 */
void func_memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int r;

	for (r = 0; r < size; r++)
		char_newptr[r] = char_ptr[r];
}
/**
 * func_realloc - function;that reallocates the memory block.
 * @ptr: pointer to the memory allocated previously.
 * @old_size: size, in bytes, of the allocated space of ptr.
 * @new_size: new size, in bytes, of the new memory block.
 * Return: NULL ptr if malloc fails, else return ptr without changes if new_size == old_size
 */
void *func_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size < old_size)
		func_memcpy(newptr, ptr, new_size);
	else
		func_memcpy(newptr, ptr, old_size);

	free(ptr);
	return (newptr);
}
/**
 * func_reallocdp - function thatreallocates a memory block of a double pointer.
 * @ptr: double pointer to the memory allocated previously.
 * @old_size: size, in bytes, of the allocated space of ptr.
 * @new_size: new size, in bytes, of the new memory block.
 * Return: ptr without changes if new_size == old_size, else, return NULL if malloc fails
 */
char **func_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int r;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (r = 0; r < old_size; r++)
		newptr[r] = ptr[r];

	free(ptr);

	return (newptr);
}
