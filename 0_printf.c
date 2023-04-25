#include "main.h"
/**
 * _printf - A function that prints formatted output to the standard output
 * @format: types of argument passed to the function
 *
 *  Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int output = 0, j;
	va_list count;
	int (*function)(va_list);

	va_start(count, format);

	if (format == NULL)
		return (-1);

	for (j = 0; format[j]; j++)
	{
		if (format[j] == '%')
		{
			j++;
			if (!(format[j]))
				return (-1);

			function = specifier(format[j]);

			if (function == NULL)
			{
				_write('%');
				_write(format[j]);
				output += 2;
			}
			else
				output += function(count);
		}
		else
		{
			_write(format[j]);
			output++;
		}
	}
	va_end(count);
	return (output);
}
