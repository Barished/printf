#include "main.h"

/**
 * print_octal - prints an unsigned integer as octal
 * @args: va_list containing the unsigned integer to print
 *
 * Return: number of digits printed
 */
int print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int i, count = 0;
	int octal[100];

	if (num == 0)
	{
		_write('0');
		return (1);
	}

	while (num > 0)
	{
		octal[count] = num % 8;
		num /= 8;
		count++;
	}

	for (i = count - 1; i >= 0; i--)
		_write(octal[i] + '0');

	return (count);
}
