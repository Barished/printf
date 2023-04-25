#include "main.h"

/**
 * binary_recursive - Recursive function to convert unsigned integer to binary
 * @num: The unsigned integer to be converted to binary
 * @lenght: The length of the binary representation of the integer
 *
 * Return: The length of the binary representation of the integer on success,
 * or -1 if the input is NULL
 */

int binary_recursive(unsigned int num, int lenght)
{
	if (num / 2)
	{
		len = binary_recursive(num / 2, len + 1);
	}
	_write(num % 2 + '0');

	return (len);
}

/**
 * print_binary - Print an unsigned integer in binary format
 * @count: The variable argument list containing the unsigned integer
 *
 * Return: The length of the binary representation of the integer plus 1
 */

int print_binary(va_list count)
{
	int lenght = 0;

	unsigned int num = va_arg(count, unsigned int);

	lenght = binary_recursive(num, lenght) + 1;
	return (lenght);
}
