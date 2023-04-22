#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@str: the pointer to the memory area
 *@ch: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *str, char ch, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		str[i] = ch;
	return (str);
}

/**
 * ffree - frees a string of strings
 * @strings: string of strings
 */
void ffree(char **strings)
{
	char **ptr = strings;

	if (!strings)
		return;
	while (*strings)
		free(*strings++);
	free(ptr);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		new_ptr[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (new_ptr);
}
