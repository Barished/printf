#include "main.h"

/**
 * _memcpy - copy memory area
 * @dest: Destination to copy to
 * @src: Source to copy from
 * @n: number of bytes to copy
 * Return: The _memcpy() function returns a pointer to dest.
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int q;

	for (q = 0; q < n; q++)
		dest[q] = src[q];

	dest[q] = '\0';

	return (dest);
}


/**
 * rev_string - reverses a string
 * @s: string to reverse
 *
 * Return: A pointer to a character
 */

char *rev_string(char *s)
{
	int lent;
	int rev;
	char tmp;
	char *dest;

	for (lent = 0; s[lent] != '\0'; lent++)
	{}

	dest = malloc(sizeof(char) * lent + 1);

	if (dest == NULL)
		return (NULL);

	_memcpy(dest, s, lent);
	for (rev = 0; rev < lent; rev++, lent--)
	{
		tmp = dest[lent - 1];
		dest[lent - 1] = dest[rev];
		dest[rev] = tmp;
	}

	return (dest);
}


/**
 * print_reversed - Calls a function to reverse and print a string
 * @args: variable number of argument passed to the function
 * Return: The amount of characters printed
 */

int print_reversed(va_list args)
{
	unsigned int lent;
	char *str;
	char *ptr;

	str = va_arg(args, char *);

	if (str == NULL)
		return (-1);

	ptr = rev_string(str);

	if (ptr == NULL)
		return (-1);

	for (lent = 0; ptr[lent] != '\0'; lent++)
		_write(ptr[lent]);

	free(ptr);
	return (lent);
}
