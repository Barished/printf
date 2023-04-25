#include "main.h"


/**
 * print_char - Print characters
 * @args: Stores a list of characters
 *
 * Return: num of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (_write(c));
}


/**
 * print_string - print string
 * @args: Stores a list of characters
 * Return: num of parameters printed
 */
int print_string(va_list args)
{
	int i, run = 0;
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i]; i++)
		run += _write(str[i]);

	return (run);

}


/**
 * print_percent - function to print %
 * @args: unused
 *
 * Return: always 1
 */
int print_percent(__attribute__((unused))va_list args)
{
	char c = '%';

	_write(c);
	return (1);
}


/**
 * print_integer - prints an integer
 * @args: integer to print
 *
 * Return: number of chars and digits printed
 */
int print_integer(va_list args)
{
	int a[10];
	int e, d, t, h, i;

	t = va_arg(args, int);
	i = 0;
	d = 1000000000;
	a[0] = t / d;

	for (e = 1; e < 10; e++)
	{
		d /= 10;
		a[e] = (t / d) % 10;
	}
	if (t < 0)
	{
		_write('-');
		i++;

		for (e = 0; e < 10; e++)
			a[e] *= -1;
	}
	for (e = 0, h = 0; e < 10; e++)
	{
		h += a[e];

		if (h != 0 || e == 9)
		{
			_write('0' + a[e]);
			i++;
		}
	}

	return (i);
}


/**
 * print_decimal - prints a decimal
 * @args: decimal to print
 *
 * Return: number of characters and digits printed
 */
int print_decimal(va_list args)
{
	int a[10];
	int e, d, t, h, i;

	t = va_arg(args, int);
	i = 0;
	d = 1000000000;
	a[0] = t / d;

	for (e = 1; e < 10; e++)
	{
		d /= 10;
		a[e] = (t / d) % 10;
	}
	if (t < 0)
	{
		_write('-');
		i++;

		for (e = 0; e < 10; e++)
			a[e] *= -1;
	}
	for (e = 0, h = 0; e < 10; e++)
	{
		h += a[e];

		if (h != 0 || e == 9)
		{
			_write('0' + a[e]);
			i++;
		}
	}

	return (i);
}
