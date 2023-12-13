#include "shell.h"

/**
 * ffree - frees a string of strings
 * @ppt: string of strings
 */
void ffree(char **ppt)
{
	char **by = ppt;

	if (!ppt)
		return;
	while (*ppt)
		free(*ppt++);
	free(by);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: the byte size of the previous block
 * @new_size: the byte size of the new block
 *
 * Return: pointer p
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *pt;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	pt = malloc(new_size);
	if (!pt)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		pt[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (pt);
}

/**
 **_memset - fills memory with a constant byte
 *@str: the pointer to the memory area
 *@by: the byte to fill *s with
 *@no: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *str, char by, unsigned int no)
{
	unsigned int j;

	for (j = 0; j < no; j++)
		str[j] = by;
	return (str);
}
