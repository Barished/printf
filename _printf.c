#include "main.h"
/**
 * _printf - a function that prints to standard out
 * @format: format
 * Return: Success
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0;
	char c, *s;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
			{
				c = va_arg(args, int);
				len += write(STDOUT_FILENO, &c, 1);
				break;
			}
			case 's':
			{
				s = va_arg(args, char *);
				len += write(STDOUT_FILENO, s, strlen(s));
				break;
			}
			case '%':
			{
				len += write(STDOUT_FILENO, "%", 1);
				break;
			}
			default:
				break;
			}
		}
		len += write(STDOUT_FILENO, format, 1);
		format++;
	}

	va_end(args);
	return (len);
}
