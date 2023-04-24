#include "main.h"
/**
 * _printf - a function that prints to standard out
 * @format: format
 * Return: Success
 */
int _printf(const char *format, ...)
{
	int c, count = 0;
	va_list args;
	char *s;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(args, int);
				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				s = va_arg(args, char *);
				while (*s != '\0')
				{
					putchar(*s);
					s++;
					count++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
		}
		putchar(*format);
		count++;
		format++;
	}
	va_end(args);
	return (count);
}
