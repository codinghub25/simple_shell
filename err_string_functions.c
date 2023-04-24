#include "shell.h"
 
/**
 *_eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *string)
{
        	int index = 0;
 
        	if (!string)
                    	return;
        	while (string[index] != '\0')
        	{
                    	_eputchar(string[index]);
                    	index++;
        	}
}
 
/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char character)
{
        	static int i;
        	static char buffer[WRITE_BUF_SIZE];
 
        	if (character == BUF_FLUSH || i >= WRITE_BUF_SIZE)
        	{
                    	write(2, buffer, i);
                    	i = 0;
        	}
        	if (character != BUF_FLUSH)
                    	buffer[i++] = character;
        	return (1);
}
 
/**
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char character, int fd)
{
        	static int i;
        	static char buffer[WRITE_BUF_SIZE];
 
        	if (character == BUF_FLUSH || i >= WRITE_BUF_SIZE)
        	{
                    	write(fd, buffer, i);
                    	i = 0;
        	}
        	if (character != BUF_FLUSH)
                    	buffer[i++] = character;
        	return (1);
}
 
/**
 *_putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *string, int fd)
{
        	int index = 0;
 
        	if (!string)
                    	return (0);
        	while (*string)
        	{
                    	index += _putfd(*string++, fd);
        	}
        	return (index);
}
