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

/**
 * print_hex_lower - A function that prints a hexadecimal number in lower case
 * @args: unsigned integer to print in hexadecimal
 *
 * Return: number of characters printed
 */
int print_hex_lower(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char hex[100];
	int i = 0, j, count = 0;
	int temp;

	if (n == 0)
	{
		_write('0');
		return (1);
	}

	while (n != 0)
	{
		temp = 0;

		temp = n % 16;

		if (temp < 10)
			hex[i] = temp + 48;
		else
			hex[i] = temp + 87;

		i++;
		n /= 16;
	}

	for (j = i - 1; j >= 0; j--)
	{
		_write(hex[j]);
		count++;
	}

	return (count);
}

/**
 * print_hex_upper - A function that prints a hexadecimal number in upper case
 * @args: unsigned integer to print in hexadecimal
 *
 * Return: number of characters printed
 */
int print_hex_upper(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char hex[100];
	int i = 0, j, count = 0;
	int temp;

	if (n == 0)
	{
		_write('0');
		return (1);
	}

	while (n != 0)
	{
		temp = 0;

		temp = n % 16;

		if (temp < 10)
			hex[i] = temp + 48;
		else
			hex[i] = temp + 55;

		i++;
		n /= 16;
	}

	for (j = i - 1; j >= 0; j--)
	{
		_write(hex[j]);
		count++;
	}

	return (count);
}
