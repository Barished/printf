#include "main.h"

/**
 * specifier - Select the appropriate function to handle a format specifier
 * @c: The format specifier character
 *
 * Return: A function pointer to the appropriate conversion function
 */

int (*specifier(char c))(va_list)
{
	if (c == 'd' || c == 'i')
		return (print_integer);
	else if (c == 's')
		return (print_string);
	else if (c == 'c')
		return (print_char);
	else if (c == '%')
		return (print_percent);
	else if (c == 'b')
		return (print_binary);
	else if (c == 'u')
		return (print_unint);
	else if (c == 'o')
		return (print_octal);
	else if (c == 'r')
		return (rot13);
	else if (c == 'R')
		return (print_reversed);
	else
		return (NULL);
}
