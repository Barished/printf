#include "main.h"


/**
 * print_unint - prints an unsigned integer
 * @args: variable number of arguments
 *
 * Return: number of characters printed
 */

int print_unint(va_list args)
{
	int a = 0;
	unsigned int num = va_arg(args, unsigned int);
	int b = 1;

	while (num / b > 9)
	{
		b *= 10;
	}

	while (b > 0)
	{
		_write(num / b + '0');
		a++;
		num %= b;
		b /= 10;
	}
	return (a);
}
